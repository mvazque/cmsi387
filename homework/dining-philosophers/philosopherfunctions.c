#include "table.h"

void* transitions(void* philosopher){
   /*int philosopherId = *(int*)philosopher;
   printPhilosophers();
   while(TRUE){
      printPhilosophers();
      if(philosopherStatus[philosopherId] == THINKING){
         ponder(philosopherId);
      }
      else if(philosopherStatus[philosopherId] == HUNGRY){
         startEating(philosopherId);
      }
      else if(philosopherStatus[philosopherId] == EATING){
         ponder(philosopherId);
      }
   }*/

}

void ponder (int philosopher) {
   randomwait(bodyCount);
   if(rand() % 50 > 10){
      philosopherStatus[philosopher] = HUNGRY;
   }
}

void startEating (int philosopher) {
   chopstickGrab(philosopher);
   chopstickGrab((philosopher + 1) % bodyCount);
   philosopherStatus[philosopher] = EATING;
   randomwait(bodyCount);
}

void finishEating (int philosopher) {
   chopstickRelease(philosopher);
   chopstickRelease((philosopher + 1) % bodyCount);
   philosopherStatus[philosopher] = THINKING;
}
