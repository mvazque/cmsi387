#include "table.h"
//This manages what action the philosophers will each take next
void* transitions(void* philosopher){
   int philosopherId = *(int*)philosopher;
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
         finishEating(philosopherId);
      }
   }

}
//Philosopher is thinking
void ponder (int philosopher) {
   randomwait(bodyCount);
   //To decrease chance of deadlock each transition has a percent chance of not happening
   if( rand() % 50 > 20){
      philosopherStatus[philosopher] = HUNGRY;
   }
}
//Philosopher is attempting to grab chopsticks
void startEating (int philosopher) {
   if( rand() % 50 > 20){
      chopstickGrab(philosopher);
      chopstickGrab((philosopher + 1) % bodyCount);
      philosopherStatus[philosopher] = EATING;
   }
   randomwait(bodyCount);
}
//Philosopher is eating and may release chopsticks
void finishEating (int philosopher) {
   if( rand() % 50 > 20){
      chopstickRelease(philosopher);
      chopstickRelease((philosopher + 1) % bodyCount);
      philosopherStatus[philosopher] = THINKING;
   }
}
