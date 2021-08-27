//
// Created by Terry Delaney on 3/27/21.
//

#ifndef HW_5_HW5_H
#define HW_5_HW5_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int counter;
int threadwait;
pthread_t threadid[10];

void * threadroutine();

#endif //HW_5_HW5_H
