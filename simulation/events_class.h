/* file: events_class.h

   author: Ted Baker
   revision: $Revision: 1.2 $
   last modified by $Author: cop4610 $ on $Date: 2002/04/07 19:33:44 $

*/

#ifndef EVENTS_H
#define EVENTS_H

#include "simulator_class.h"
#include "random_class.h"

/*************
  event_kinds
 *************/

enum {
  arrival_event,
  completion_event
  /* to add the simulation of virtual memory,
     you will need to add more types of events here,
     such as a disk I/O completion event, and
     possibly (depending on whether you handle the
     simulation of page references as separate
     events or within the dispatcher)
     a page reference event */
};

/***************
  Process class
 ***************/

class Process : public Simulator_Event { /* process control block */
public:
  char * image ();
private:
  friend class System;
  int id,
      arrival_time,
      execution_time,
      cpu_time,
      completion_time;
  Process *next,    /* forward link in ready queue */
          *prev,    /* backward link in ready queue */
          *next_in_list;
  Random_Process *model;
  /* add data for virtual memory simulation here */
  void queue_insert_tail (Process *queue_tail);
  void queue_delete ();
};

/**************
  System class
 **************/

class System : public Simulator {
public:
  friend class Process;
  System ();
  virtual void simulate (Simulator_Event *e);
  virtual void run ();
private:

 /****************
   CPU scheduling
  ****************/

  Process *ready_queue_tail;
  Process *ready_queue_head ();
  Process *idle_process;
  Process *running_process;
  /* points to tail of a circular doubly linked list;
     always contains at least the idle process
     at the tail */
  int last_dispatching_time;
  void dispatch ();
  /* simulate process dispatching using FIFO policy */

 /******************
   queue management
  ******************/

  int ready_queue_is_empty ();
  void queue_dump (char * msg, Process *p);
  void schedule_next_arrival();

 /******************
   process creation
  ******************/

  int process_count;
  /* the number of processes created so far
     and the id of the next proc to be created */
  Process *process_list;
  /* tail of a circular list of all processes we have seen,
     linked by next_in_list */

  /************
   statistics
  ************/

  void print_report ();

};

#endif
