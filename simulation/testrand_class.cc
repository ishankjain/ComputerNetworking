/* file: testrand_class.cc

   Simple sanity-check for random process class;
   outputs histogram we can "eyeball" to make sure it
   has the correct shape.

   author: Ted Baker
   revision: 1.1
   last modified by cop4610 on 2002/04/01 12:02:34

*/

#define _XOPEN_SOURCE 500
#include <stdlib.h>
#include <stdio.h>
#include "random_class.h"

#define HISTMOD 10000
#define MAXVAL 33
#define MEAN 3.0

int ntests = HISTMOD * 100;

Command_Line_Help CLH;
Configurable_Simulation_Parameters CSP;

int
main (int argc, char const *argv[]) {
  int i, j;
  int histogram [MAXVAL];
  int overs = 0;

  CLH.initialize (argc, argv);
  Random_Process p;

  for (i = 0; i < MAXVAL; i++) histogram[i] = 0;
  for (i = 0; i < ntests; i++) {
    int x = p.get_page_reference();
    if (x < 0) {
      fprintf (stderr, "negative value: %d\n", x);
      exit (-1);
    }
    if (x < MAXVAL) histogram[x]++;
    else overs++;
  }
  fprintf (stdout, "Histogram for %d tests\n", ntests);
  for (i = 0; i < MAXVAL; i++) {
    fprintf (stdout, "%6d", i);
    for (j = 0; j < histogram[i]; j+=HISTMOD) fprintf (stdout, "+");
    fprintf (stdout, "\n");
  }
  fprintf (stdout, "others");
  for (j = 0; j < overs; j+=HISTMOD) fprintf (stdout, "+");
  fprintf (stdout, "\n");
  return 0;
}
