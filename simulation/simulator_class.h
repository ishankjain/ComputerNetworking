/* file: simulator_class.h

   Defines the visible interface of the simulator engine to the
   the code that simulates each event.

   This version is in C++.

   author: Ted Baker
   revision: 1.2
   last modified by cop4610 on 2002/04/07 19:33:44

 */

#ifndef SIMULATOR_H
#define SIMULATOR_H

class Simulator_Event {
public:
  virtual char * image ();
  int event_kind;
private:
  friend class Simulator;
  int time;
  Simulator_Event *next, *prev;
};

class Simulator {
public:
  Simulator ();
  int time_infinity ();
  int clock ();
  void schedule (Simulator_Event *e, int t);
  /* schedules an event to peform action act at time t;
     it returns a value identifying this event;
     the value can be used with function cancel_event;
     when the time of the event arrives, the simulator calls
     action.fun (action.arg) */
  void cancel (Simulator_Event *e);
  /* cancels a previously scheduled event */
  void queue_dump ();
  virtual void simulate (Simulator_Event *e);
  virtual void run ();
private:
  int now;
  int next_event_time;
  Simulator_Event *free_events,
                  *event_queue_head;
};

#endif
