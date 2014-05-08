#include <pthread.h>
#include <semaphore.h>

#include "utility.h"

#define THINKING 0
#define HUNGRY 1
#define EATING 2


int numberPhilosophers;
int chopsticks;
struct tableInfo {
      int philosopherLocation[numberPhilosophers];
      int philosopherStatus[numberPhilosophers];
      int chopstickStatus[numberPhilosophers];
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


   int chopstickStatus;
   int i;
   data = {0};
   pthread_t philosophers[numberPhilosophers];
   pthread_mutex_t chopsticks[numberPhilosophers];

   for(i = 0 ; i < numberPhilosophers ; i++){
      data.philosopherLocation[i] = i;
      phtread_mutex_init(&chopsticks[i], NULL);
      pthread_create(&philosophers[i], NULL,philosophize, &philosopherLocation[i]);
   }
   
   /* We won't really get here, but to avoid any warnings... */
   return 0;
}

