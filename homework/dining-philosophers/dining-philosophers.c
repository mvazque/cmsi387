#include <pthread.h>
#include <semaphore.h>

#include "utility.h"

#define THINKING 0
#define HUNGRY 1
#define EATING 2


int numberPhilosophers
int chopsticks

int main(int argc, char** argv) {
   if(argc < 2){
      numberPhilosophers = 5;
   }
   else{
      numberPhilosophers = atoi(argv[1]);
   }
   printf("Initiating Dining Philosophers\n");
   
   /* We won't really get here, but to avoid any warnings... */
   return 0;
}

void chopstickGrab (int chopstick){
   pthreadMutex_lock(
   chopstickState[chopstick] += 1;
   //randomwait(consumeBound);
}

void chopstickRelease(int chopstick){
   pthreadMutex_unlock(
   chopstickState[chopstick] -= 1;
   //randomwait(consumeBound);
}
