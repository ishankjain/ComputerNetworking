/* file: prog4_class.cc

   The main program for the simulator, in C++.

   This version has been augmented to include a mechanism
   for initializing global variables via command-line arguments.
   
   author: Ted Baker
   revision: 1.1
   last modified by cop4610 on 2002/04/01 12:02:34

*/

#include "random_class.h"
#include "simulator_class.h"
#include "events_class.h"

/******
  main
 ******/

Command_Line_Help CLH;
Configurable_Simulation_Parameters CSP;

int
main(int argc, const char *argv[]) {
  CLH.initialize (argc, argv);
  CSP.initialize ();
  System My_Simulation;
  My_Simulation.run ();
  return 0;
}
