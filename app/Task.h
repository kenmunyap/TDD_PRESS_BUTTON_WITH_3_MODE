#ifndef TASK_H
#define TASK_H

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


#endif //TASK_H