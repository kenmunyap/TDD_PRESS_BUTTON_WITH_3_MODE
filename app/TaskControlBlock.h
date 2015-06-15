#ifndef TaskControlBlock_H
#define TaskControlBlock_H

typedef struct{
  TaskState state;
  unit32_t stack;
}Tcb;

typedef enum{
  RUNNING,
  READY,
  SPAWNED,
  TERMINATED,
  BLOCKING,
  SLEEPING,
}TaskState;


#endif //TaskControlBlock_H