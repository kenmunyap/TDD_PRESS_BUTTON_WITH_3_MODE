#ifndef LedSM_H
#define LedSM_H

#include "State.h"
#include <stdint.h>

typedef struct{
  State state;
  uint32_t time;
}LedData;

void ledInitData(LedData *data);

void ledSM(LedData *data);

#endif // LedSM_H
