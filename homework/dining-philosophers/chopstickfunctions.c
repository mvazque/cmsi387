#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#include "utility.h"
#include "table.h"

void chopstickGrab (int chopstick){
   pthread_mutex_lock(&chopsticks[chopstick]);
   chopstickStatus[chopstick] += 1;
}

void chopstickRelease(int chopstick){
   pthread_mutex_unlock(&chopsticks[chopstick]);
   chopstickStatus[chopstick] -= 1;
}
