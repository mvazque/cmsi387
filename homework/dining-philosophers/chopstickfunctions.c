#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#include "utility.h"
#include "table.h"
//Attempt to grab chopstick will happen may end up waiting for this to happen
void chopstickGrab (int chopstick){
   pthread_mutex_lock(&chopsticks[chopstick]);
   chopstickStatus[chopstick] += 1;
}
//Chopstick is released 
void chopstickRelease(int chopstick){
   pthread_mutex_unlock(&chopsticks[chopstick]);
   chopstickStatus[chopstick] -= 1;
}
