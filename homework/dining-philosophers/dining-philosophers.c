#include <pthread.h>
#include <semaphore.h>

#include "utility.h"

#define NUMBER_PHILOSOPHERS 7
#define NUMBER_CHOPSTICKS 7
#define THINKING 0
#define HUNGRY 1
#define EATING 2


int philosophers
int chopsticks

void chopstickGrab (int chopstick)
   pthreadMutex_lock(
   chopstickState[chopstick] += 1;


//randomwait(consumeBound);
