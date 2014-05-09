/**
 * Utility implementation.
 */
#include "utility.h"
#include "table.h"

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int randomwait(int bound) {
    int wait = rand() % bound;
    sleep(wait);
    return wait;
}

void printPhilosophers () {
   int i;
   for (i = 0; i < bodyCount; i++) {
      if (philosopherStatus[i] == THINKING) {
         printf(" ? ");
      } else if (philosopherStatus[i] == HUNGRY) {
         printf(" ! ");
      } else if (philosopherStatus[i] == EATING) {
         printf(" \\/ ");
      }
   }
   printf("\n");
}
