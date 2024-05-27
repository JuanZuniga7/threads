//
// Created by rusted-cor on 5/26/24.
//
#include <stdio.h>
#include "threads.h"
#include <pthread.h>

int createThread(void *routine(void *), void *arg) {
    printf("Creating thread\n");
    pthread_t thread;
    pthread_create(&thread, NULL, routine, arg);
}
