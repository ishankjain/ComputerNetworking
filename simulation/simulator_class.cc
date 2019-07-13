/* file: simulator_class.cc

   Body of simulation engine, in C++.

   Uses a null-terminated doubly-linked list for the event queue.
   
   author: Ted Baker
   revision: 1.2
   last modified by cop4610 on 2002/04/07 19:33:48

*/

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "simulator_class.h"
#include "random_class.h"

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>


/************************
  Simulator_Event::image
 ************************/

char * Simulator_Event::image () {
  return "";
}

/**************************
  Simulator::time_infinity
 **************************/

int Simulator::time_infinity() {
  return INT_MAX;
};

/******************
  Simulator::clock
 ******************/

int Simulator::clock () {
  return now;
};

/***********************
  Simulator::queue_dump
 ***********************/

void Simulator::queue_dump () {
  Simulator_Event *e = event_queue_head;
  fprintf (stdout, "QUEUE: ");
  while (e) {
     fprintf (stdout, "%d [%s]", e->time, e->image ());
     e = e->next;
  }
  fprintf (stdout, "\n");
};


/*********************
  Simulator::schedule
 *********************
 
  schedules an event e at time t;
  when the time of the event arrives, the simulator calls
  Events.simulate (e.arg)
  
  implementation inserts event with give action into queue,
  keeping events in increasing order by time */

void Simulator::schedule (Simulator_Event *e, int t) {
  Simulator_Event *prev = NULL;
  Simulator_Event *next = event_queue_head;
  e->time = t;
  /* find proper insertion point in queue */
  while (next && next->time <= t) {
    prev = next; next = next->next;
  }
  while (next && next->time == t && next->event_kind < e->event_kind) {
    prev = next; next = next->next;
  }
  /* insert between prev and next */
  if (prev) prev->next = e;
  else {
    event_queue_head = e;
    next_event_time = t;
  }
  if (next) next->prev = e;
  e->next = next;
  e->prev = prev;
};

/*******************
  Simulator::cancel
 *******************

  cancels a previously scheduled event */

void Simulator::cancel (Simulator_Event *e){
  Simulator_Event *next, *prev;
  next = e->next; prev = e->prev;
  if (prev) prev->next = next;
  else {
    event_queue_head = next;
    if (next) next_event_time = next->time;
    else next_event_time = time_infinity ();
  }
  if (next) next->prev = prev;
};

/****************
  Simulator::run
 ****************/

void Simulator::run () {
  Simulator_Event * current_event;
  now = 0;
  next_event_time = time_infinity();
  assert (event_queue_head != NULL);
  while (event_queue_head) {
     current_event = event_queue_head;
     event_queue_head = event_queue_head->next;
     if (event_queue_head) next_event_time = event_queue_head->time;
     else next_event_time = time_infinity ();
     now = current_event->time;
     simulate (current_event);
  }
};

/*********************
  Simulator::simulate
**********************/

void Simulator::simulate (Simulator_Event *e) {
  /* should never be called */
  assert (0);
}

/**********************
  Simulator::Simulator
***********************/

Simulator::Simulator () {
  event_queue_head = NULL;
}

