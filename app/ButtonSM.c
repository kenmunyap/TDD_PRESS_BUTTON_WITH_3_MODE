#include <stdio.h>
#include <stdbool.h>
#include "button.h"
#include "ButtonSM.h"
#include "Message.h"
#include "delay.h"

void buttonInitData(ButtonData *data){
  data->state = RELEASE;
}

void buttonSM(ButtonData *data){
  switch(data->state){
  case RELEASE:
    if(isButtonPressed() == true){
		msg = CHANGE_MODE; //Pass a message to LED
		data->state = PRESS;
    }
    break;
    
  case PRESS:
	if(isButtonPressed() == true){
		msg = DO_NOTHING;
		data->state = RELEASE;
	}else{
		msg = DO_NOTHING;
		data->state = RELEASE;
	}
    break;
    
  default:
      printf("Error : unknown state encountered in buttonSM: %d\n", data->state);
  break;
  }
}