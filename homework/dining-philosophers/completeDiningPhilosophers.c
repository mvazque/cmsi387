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

// JD: One last wrinkle here---multiple threads may be calling this
//     concurrently, and so sometimes you will have overlapping
//     philosopher printouts.  The fix to this is totally up our
//     class's alley: another mutex!  The screen is a "shared resource"
//     after all, it turns out.
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
   // JD: At this point, you are missing the required sanity-check
   //     code to make sure that the chopstick really is available
   //     before you grab it.  This will assure you whether or not
   //     the mutex lock is working.  You should never see the error
   //     with proper locking (just as with the bounded buffer sample
   //     code), but once you remove the lock, the code should kick in.
   chopstickStatus[chopstick] += 1;
}

void chopstickRelease(int chopstick){
   // JD: This function has two concerns: you should change the
   //     chopstick state *before* you release the lock---because
   //     otherwise you're outside of the critical section!  And like
   //     the prior function, you need sanity check code here, before
   //     you update the chopstick state.  Same deal as above.
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

// JD: Your code spacing is hit-or-miss.  Sometimes you have a space
//     after parentheses; sometimes you don't.  Sometimes there is a
//     space before a left brace; sometimes not.  Sometimes you put a
//     space after a keyword like if, while, or for; sometimes not.
//     (for the latter, BTW, you *should* add a space, because if,
//     while, and for are not functions)
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

