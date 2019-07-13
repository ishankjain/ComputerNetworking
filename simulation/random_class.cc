/* file: random_class.cc

   implementation of random process generation tools

   If you use this, you should use srand48() to set
   a nontrival value for the seed of the random number generator.

   author: Ted Baker
   revision: $Revision: 1.2 $
   last modified by $Author: cop4610 $ on $Date: 2002/04/07 19:33:48 $

*/

#define _XOPEN_SOURCE 500
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "random_class.h"

Command_Line_Help::Command_Line_Help () {
  argc = 0;
  argv = NULL;
}

void Command_Line_Help::initialize (const int argc, const char *argv[]) {
  this->argc = argc;
  this->argv = argv;
}

void Command_Line_Help::find_arg
(void * var, const char *name, const char *format) {
  int i;
  const char * c;
  for (i = 1; i < argc; i++) {
    if (!(c = strpbrk (argv[i], "="))) continue;
    c++;    /* skip over the "=" */
    if (! strncmp (argv[i], name, sizeof(name) - 1)) {
      if (sscanf (c, format, var) != 1)
	fprintf (stderr, "usage: %s\n", argv[i]);
      break;
    }
  }
}

void Configurable_Simulation_Parameters::initialize () {
  Command_Line_Help *c = &CLH;
  c->find_arg (&nprocs, "-nprocs=", "%d");
  c->find_arg (&page_size, "-page_size=", "%d");
  c->find_arg (&vmem_pages, "-vmem=", "%d");
  c->find_arg (&real_pages, "-real=", "%d");
  c->find_arg (&disk_time, "-disk=", "%d");
  c->find_arg (&mean_interarrival_time, "-miat=", "%lf");
  c->find_arg (&mean_execution_time, "-mexe=", "%lf");
  c->find_arg (&mean_code_size, "-code=", "%lf");
  c->find_arg (&mean_data_size, "-data=", "%lf");
  c->find_arg (&debugging_level, "-debug=", "%d");
}

Configurable_Simulation_Parameters::Configurable_Simulation_Parameters () {
  nprocs = 2;
  page_size = 4096; 
  vmem_pages = 1024;
  real_pages = 64;
  disk_time = 100;
  mean_interarrival_time = 10.0;
  mean_execution_time = 20.0;
  mean_code_size = 8.0;
  mean_data_size = 8.0;
  p_jump = 0.1;
  p_call = 0.1;
  debugging_level = 0;
  srand48 (31459);
}

int Configurable_Simulation_Parameters::get_nprocs () {
  return nprocs;
}

int Configurable_Simulation_Parameters::get_page_size () {
  return page_size;
}

int Configurable_Simulation_Parameters::get_vmem_pages () {
  return vmem_pages;
}

int Configurable_Simulation_Parameters::get_real_pages () {
  return real_pages;
}

int Configurable_Simulation_Parameters::get_disk_time () {
  return disk_time;
}

int Configurable_Simulation_Parameters::get_debugging_level () {
  return debugging_level;
}

Random_Process::Random_Process () {
  instruction_counter = 0;
  code_size = exp_dist (CSP.mean_code_size);
  data_size = exp_dist (CSP.mean_data_size);
  stack_top = code_size + data_size; 
  interarrival_time = exp_dist (CSP.mean_interarrival_time);
  execution_time = exp_dist (CSP.mean_execution_time);
}

int Random_Process::get_interarrival_time () {
  return interarrival_time;
}

int Random_Process::get_execution_time () {  
  return execution_time;
}

int Random_Process::get_page_reference () {
  int result = (int)(drand48() * (code_size + data_size)); 
  return result % (CSP.vmem_pages);
}

int Random_Process::exp_dist (double m) {
  int i;
  double d;
  // drand48 returns value in range [0.0, 1.0]
  d = -log (drand48()) * m;
  if (d > (double) RAND_MAX) {
    return RAND_MAX;
  }
  i = (int) d;
  if (((double) i) < d) return i + 1;
  return i;
}

