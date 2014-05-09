#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>
#include <pthread.h>

#include "utility.h"
#include "philosopherfunctions.h"
#include "chopstickfunctions.h"

#define MAX_NUMBER_PHILOSOPHERS 10
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define TRUE 1
#define FALSE 0
//Global variables needed throughout the program
   int philosopherLocation[MAX_NUMBER_PHILOSOPHERS];
   int philosopherStatus[MAX_NUMBER_PHILOSOPHERS];
   int chopstickStatus[MAX_NUMBER_PHILOSOPHERS];
   pthread_mutex_t chopsticks[MAX_NUMBER_PHILOSOPHERS];
   int bodyCount;


#endif
