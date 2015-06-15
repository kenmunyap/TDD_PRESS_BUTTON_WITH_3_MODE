#include "unity.h"
#include "LedSM.h"
#include "ButtonSM.h"
#include "Message.h"
#include "mock_button.h"
#include "mock_delay.h"

void setUp(void){}

void tearDown(void){}

void test_module_generator_needs_to_be_implemented(void){
	LedData ledData;
	ButtonData buttonData;
	
	ledInitData(&ledData);
	buttonInitData(&buttonData);
	
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_OFF);
	isButtonPressed_ExpectAndReturn(true);
	buttonSM(&buttonData);
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_BLINKING_ON);
	isButtonPressed_ExpectAndReturn(false);
	buttonSM(&buttonData);
	delay_IgnoreAndReturn(1);
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_BLINKING_OFF);
	isButtonPressed_ExpectAndReturn(false);
	buttonSM(&buttonData);
	delay_IgnoreAndReturn(1);
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_BLINKING_ON);
	isButtonPressed_ExpectAndReturn(true);
	buttonSM(&buttonData);
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_ON);
	isButtonPressed_ExpectAndReturn(false);
	buttonSM(&buttonData);
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_ON);
	isButtonPressed_ExpectAndReturn(true);
	buttonSM(&buttonData);
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_OFF);
	
	

	
}
