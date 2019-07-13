/* file: event_class.cc

   Does the simulation of individual events.

   This C++ version simulates the execution of a set of processes
   running with FIFO scheduling on a single CPU.

   This is intended mainly to provide an example of a simulator,
   and a starting point for development of a more complex
   simulator.

   It also illustrates the use of circular linked lists.
   These allow simpler insertions and deletions than null-terminated
   linked lists, but require that one work from the tail rather
   than the head.  That is, the head of the queue is accessed
   as the successor of the tail.  Two varieties are used:

      ready_queue  : doubly-linked
      process_list : singly-linked

   The ready_queue is doubly linked to make deletion from the
   middle possible in constant time.  We never delete anything
   from the process_list, so it is only singly linked.
   
   author: Ted Baker
   revision: $Revision: 1.2 $
   last modified by $Author: cop4610 $ on $Date: 2002/04/07 19:33:48 $

 */

#define _XOPEN_SOURCE 500
#include <stdlib.h>
#include <stdio.h>
#include "simulator_class.h"
#include "random_class.h"
#include "events_class.h"

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>

char * event_names [] = {
  "arrival_event    ",
  "completion_event ",
};

/****************
  Process::image
 ****************/

char * Process::image () {
  return event_names [event_kind];
}

/****************************
  Process::queue_insert_tail
 ****************************/

void Process::queue_insert_tail (Process *queue_tail) {
  /* insert p just before the tail of the ready queue */
  next = queue_tail;
  prev = queue_tail->prev;
  queue_tail->prev = this;
  prev->next = this;
}

/***********************
  Process::queue_delete
 ***********************/

void Process::queue_delete () {
  /* delete p from anywhere in any queue */
  assert (next != this);
  prev->next = next;
  next->prev = prev;
}

/**************************
  System::ready_queue_head
 **************************/

Process * System::ready_queue_head () {
  return ready_queue_tail->next;
}

/**************************
  System::ready_queue_head
 **************************/

int System::ready_queue_is_empty () {
  return (ready_queue_tail->next == ready_queue_tail);
}

/********************
  System::queue_dump
 ********************/

void System::queue_dump (char * msg, Process *p) {
  Process * t;
  fprintf (stdout, "%s:", msg);
  for (t = p->next; t && t != p; t=t->next)
    fprintf (stdout, "%d [%x]", t->id,  t);
  fprintf (stdout, "\n");
}  

/******************
  System::dispatch
 ******************/

void System::dispatch () {
  /* simulate process dispatching using FIFO policy */
  running_process->cpu_time += clock () - last_dispatching_time;
  last_dispatching_time = clock ();
  if (running_process != ready_queue_head ()) {
    /* we need to switch processes */
    running_process = ready_queue_head ();
    if (running_process != idle_process) {
      running_process->event_kind = completion_event;
      Simulator::schedule (running_process, clock () +
        running_process->execution_time - running_process->cpu_time);
    }
  }
}

void System::schedule_next_arrival() {
  Process *p = new Process;
  p->id = ++process_count;
  p->model = new Random_Process ();
  p->next_in_list = process_list->next_in_list;
  process_list->next_in_list = p;
  process_list = p;
  p->event_kind = arrival_event;
  Simulator::schedule (p, clock () + p->model->get_interarrival_time ());
  /* add code here to initialize any new per-process
     data that you add */
}

/**********************
  System::print_report
 **********************/

void System::print_report () {
  int sum = 0;
  int diff;
  Process *p;
  fprintf (stdout, "-----------------------\n");
  for (p = process_list->next_in_list->next_in_list;
    p != idle_process;
    p = p->next_in_list)
  {
    diff = p->completion_time - p->arrival_time;
    fprintf (stdout, "proc %4d response time = %6d\n", p->id, diff);
    sum += diff;
  }
  fprintf (stdout, "-----------------------\n");
  fprintf (stdout, "average response time   = %6d\n", sum/CSP.get_nprocs ());
  fprintf (stdout, "completion_time         = %6d\n", clock ());
  fprintf (stdout, "total idle time         = %6d\n",
	   idle_process->cpu_time);
  fprintf (stdout, "percent idle time       = %6d%%\n",
	   idle_process->cpu_time * 100 / clock ());
  fprintf (stdout, "-----------------------\n");
}

/******************
  System::simulate 
 *******************/

void System::simulate (Simulator_Event *e) {

  Process *p = dynamic_cast <Process *> (e);

  assert (p != NULL);
  
  if (CSP.get_debugging_level() > 1) {
    fprintf (stderr, "       %s for proc %4d at time %6d\n",
       event_names[p->event_kind], p->id, clock ());
  }
  switch (p->event_kind) {

  case arrival_event: {
    p->arrival_time = clock ();
    p->cpu_time = 0;
    p->execution_time = clock () + (p->model->get_execution_time ());
    p->queue_insert_tail (ready_queue_tail);
    assert (p->execution_time >= 1);
    if (process_count < CSP.get_nprocs ()) schedule_next_arrival();
      /* schedule arrival of next process */
    break;
  }

  case completion_event: {
    p->completion_time = clock ();
    p->queue_delete ();
    break;
  }

  /* you will need to add cases here
     for any new kinds of events
     that you add to the simulation */
  
  default: {
    /* execution should never reach here */
    assert (0);
    break;
  }
  }
  dispatch ();
}

/************************
  System::run_simulation
 ************************/

void System::run () {
  if (!idle_process) {
    /* first time */
    idle_process = new Process;
    idle_process->id = -1;
    idle_process->execution_time = 0;
    idle_process->next_in_list = idle_process;
    process_list = idle_process;
    /* make idle process the tail of the ready queue */
    ready_queue_tail = idle_process;
    ready_queue_tail->next = ready_queue_tail;
    ready_queue_tail->prev = ready_queue_tail;
    /* make the idle process executing */
    running_process = idle_process;
    process_count = 0;
    last_dispatching_time = 0;
    schedule_next_arrival ();
    /* add new code here to initialize any global data
       that you add */
    Simulator::run ();
    print_report ();
  } else {
    fprintf (stderr, "attempt to repeat initialization\n");
    exit (-1);
  }
}

/*******************
  Event constructor
 ********************/

System::System () : Simulator () {
  assert (CSP.get_nprocs() >= 1);
  /* initialize random number generator */
  srand (31459);
  idle_process = NULL;
}


