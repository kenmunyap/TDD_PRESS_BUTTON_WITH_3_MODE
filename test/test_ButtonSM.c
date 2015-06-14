#include "unity.h"
#include "Message.h"
#include "ButtonSM.h"
#include "LedSM.h"
#include "mock_button.h"
#include "mock_delay.h"

void setUp(void){}

void tearDown(void){}

void test_normal_function_is_pressButton_true(void){
  ButtonData buttonData;
  
  buttonInitData(&buttonData);

  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,PRESS);
  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,RELEASE);
  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,PRESS);
}

void test_pressButton_initial_is_false(void){
  ButtonData buttonData;
  
  buttonInitData(&buttonData);

  isButtonPressed_ExpectAndReturn(false);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,RELEASE);
}

void test_pressButton_initial_is_true_and_pressButton_is_false_output_is_RELEASE(void){
  ButtonData buttonData;
  
  buttonInitData(&buttonData);

  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,PRESS);
  isButtonPressed_ExpectAndReturn(false);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state,RELEASE);
}