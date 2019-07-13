/* file: random.h

   interface to random number generation tools

   This is the C++ version.
   
   If you use this, you should use srand48() to set
   a nontrival value for the seed of the random number generator.

   author: Ted Baker
   revision: $Revision: 1.1 $
   last modified by $Author: cop4610 $ on $Date: 2002/04/07 19:10:11 $

*/


#ifndef RANDOM_H
#define RANDOM_H

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>

#ifdef DEBUG
#define TRACE(MSG,VAL,LEVEL) \
  if (LEVEL <= CSP.get_debugging_level())\
    fprintf (stderr, "TRACE: %s, %d\n", MSG, (int)(VAL));
#else
#define TRACE(MSG,VAL,LEVEL)
#endif

class Command_Line_Help {
public:
  Command_Line_Help ();
  void initialize (const int, const char *[]);
  void find_arg (void *var, const char *name, const char *format);
private:
  int argc;
  char const ** argv;
};

extern Command_Line_Help CLH;

class Configurable_Simulation_Parameters {
public:
  Configurable_Simulation_Parameters ();
  void initialize ();
  int get_nprocs ();      // number of process arrivals
  int get_page_size ();   // number of addresses per page
  int get_vmem_pages ();  // pages in virtual address space
  int get_real_pages ();  // pages in real memory
  int get_disk_time ();   // time for disk i/o operation
  int get_debugging_level ();
private:
  friend class Random_Process;
  int nprocs;
  int page_size;
  int vmem_pages;
  int real_pages;
  int disk_time;
  int debugging_level;
  double mean_interarrival_time;
  double mean_execution_time;
  double mean_code_size;
  double mean_data_size;
  double p_jump;
  double p_call;
};

extern Configurable_Simulation_Parameters CSP;

/* The constructor sets the values of the variables
   to defaults, which may be overridden by values given
   in argv[0 .. argc]. */

class Random_Process {
public:
  Random_Process ();
  int get_interarrival_time ();
  int get_execution_time ();
  int get_page_reference ();
private:
  int exp_dist (double m);
  /* returns a random value in the range 1 .. RAND_MAX
      with approximately the inverse exponential distribution
      with mean value m.
         A(x) = 1 - e ** (-1/m) */
  int code_size;
  /* first code page is zero
     last code page is code_size - 1 */
  int data_size;
  /* first data page is code_size
     last data page is code_size + data_size - 1
     first stack page is code_size + data_size */
  int instruction_counter;
  int stack_top;
  int interarrival_time;
  int execution_time;
};

#endif
