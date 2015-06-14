#ifndef State_H
#define State_H

#include <stdint.h>

typedef enum{
  Initial,
  PRESS,
  RELEASE,
  LED_ON,
  LED_OFF,
  LED_BLINKING_ON,
  LED_BLINKING_OFF,
}State;

#endif // State_H