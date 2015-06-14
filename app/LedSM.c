#include <stdio.h>
#include "LedSM.h"
#include "Message.h"
#include "button.h"
#include "delay.h"

void ledInitData(LedData *data){
  data->state = LED_OFF;
}

void ledSM(LedData *data){
  switch(data->state){
    case LED_OFF:
      if(msg == CHANGE_MODE){
        data->state = LED_BLINKING_ON;
        msg = DO_NOTHING;
      }
      break;
    case LED_ON:
		if(msg == CHANGE_MODE){
			data->state = LED_OFF;
			msg = DO_NOTHING;
		}
      break;
    case LED_BLINKING_ON:
		if(msg == CHANGE_MODE){
			data->state = LED_ON;
			msg = DO_NOTHING;
		}else{
			if(delay() == 1){
				data->state = LED_BLINKING_OFF;
			}
		}
      break;
    case LED_BLINKING_OFF:
		if(msg == CHANGE_MODE){
			data->state = LED_ON;
			msg = DO_NOTHING;
		}else{
			if(delay() == 1){
				data->state = LED_BLINKING_ON;
			}
		}
      break;
    default:
      printf("Error : unknown state encountered in ledSM: %d\n", data->state);
      break;
  }
}