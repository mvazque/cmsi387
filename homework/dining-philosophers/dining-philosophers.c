#include <string.h>
#include "table.h"
#include "philosopherfunctions.h"
#define THINKING 0
#define HUNGRY 1
#define EATING 2


int numberPhilosophers;
//Sets the threads up. Some error checking on user inputs
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
   bodyCount = numberPhilosophers;
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

