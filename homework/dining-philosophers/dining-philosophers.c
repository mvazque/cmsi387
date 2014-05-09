#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#include "utility.h"
#include "table.h"

#define THINKING 0
#define HUNGRY 1
#define EATING 2


int numberPhilosophers;
int chopsticks;
struct tableInfo {
      int philosopherLocation[MAX_NUMBER_PHILOSOPHERS];
      int philosopherStatus[MAX_NUMBER_PHILOSOPHERS];
      int chopstickStatus[MAX_NUMBER_PHILOSOPHERS];
      pthread_mutex_t chopsticks[MAX_NUMBER_PHILOSOPHERS];
      int bodyCount;
} data;

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
   struct tableInfo data = {0};
   data.bodyCount = numberPhilosophers;
   pthread_t philosophers[numberPhilosophers];
   for(i = 0 ; i < numberPhilosophers ; i++){
      data.philosopherLocation[i] = i;
      pthread_mutex_init(&data.chopsticks[i], NULL);
     // pthread_create(&philosophers[i], NULL,philosophize, &data);
   }
   
   /* We won't really get here, but to avoid any warnings... */
   return 0;
}

