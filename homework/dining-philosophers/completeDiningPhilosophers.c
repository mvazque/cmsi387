#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#include "utility.h"

#define MAX_NUMBER_PHILOSOPHERS 10
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define TRUE 1
#define FALSE 0

int numberPhilosophers;
int philosopherLocation[MAX_NUMBER_PHILOSOPHERS];
int philosopherStatus[MAX_NUMBER_PHILOSOPHERS];
int chopstickStatus[MAX_NUMBER_PHILOSOPHERS];
pthread_mutex_t chopsticks[MAX_NUMBER_PHILOSOPHERS];


int randomwait(int bound) {
    int wait = rand() % bound;
    sleep(wait);
    return wait;
}

void printPhilosophers () {
   int i;
   for (i = 0; i < numberPhilosophers; i++) {
      if (philosopherStatus[i] == THINKING) {
         printf(" ? ");
      } else if (philosopherStatus[i] == HUNGRY) {
         printf(" \\ ");
      } else if (philosopherStatus[i] == EATING) {
         printf(" \\/ ");
      }
   }
   printf("\n");
}

void chopstickGrab (int chopstick){
   pthread_mutex_lock(&chopsticks[chopstick]);
   chopstickStatus[chopstick] += 1;
}

void chopstickRelease(int chopstick){
   pthread_mutex_unlock(&chopsticks[chopstick]);
   chopstickStatus[chopstick] -= 1;
}


void ponder (int philosopher) {
   randomwait(numberPhilosophers);
   if( rand() % 50 > 20){
      philosopherStatus[philosopher] = HUNGRY;
   }
}

void startEating (int philosopher) {
   if( rand() % 50 > 20){
      chopstickGrab(philosopher);
      chopstickGrab((philosopher + 1) % numberPhilosophers);
      philosopherStatus[philosopher] = EATING;
   }
   randomwait(numberPhilosophers);
}

void finishEating (int philosopher) {
   if( rand() % 50 > 20){
      chopstickRelease(philosopher);
      chopstickRelease((philosopher + 1) % numberPhilosophers);
      philosopherStatus[philosopher] = THINKING;
   }
}

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

int main(int argc, char** argv) {
   if(argc < 2){
      numberPhilosophers = 5;
   }
   else if(atoi(argv[1]) == 1){
      numberPhilosophers = 5;
   }
   else{
      numberPhilosophers = atoi(argv[1]);
   }
   printf("Initiating Dining Philosophers\n");

   int i;
   pthread_t philosophers[numberPhilosophers];
   for(i = 0 ; i < numberPhilosophers ; i++){
      philosopherLocation[i] = i;
      pthread_mutex_init(&chopsticks[i], NULL);
      pthread_create(&philosophers[i], NULL,transitions,&philosopherLocation[i]);
   }
   for (i = 0; i < numberPhilosophers; i++) {
      pthread_join(philosophers[i], NULL);
   }
   return 0;
}

