#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>
#include <pthread.h>

   #define MAX_NUMBER_PHILOSOPHERS 10

   int philosopherLocation[MAX_NUMBER_PHILOSOPHERS];
   int philosopherStatus[MAX_NUMBER_PHILOSOPHERS];
   int chopstickStatus[MAX_NUMBER_PHILOSOPHERS];
   pthread_mutex_t chopsticks[MAX_NUMBER_PHILOSOPHERS];
   int bodyCount;


#endif
