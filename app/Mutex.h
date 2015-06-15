#ifndef MUTEX_H
#define MUTEX_H

#include <stdint.h>
#include "Task.h"

typedef struct{
    Tcb *owner;
    List *queue;
}Mutex;

void mutexInit(Mutex *mutex);
void mutexAcquire(Mutex *mutex);
void mutexRelease(Mutex *mutex);



#endif //MUTEX_H