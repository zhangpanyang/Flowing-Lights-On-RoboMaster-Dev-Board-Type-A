//
// Created by Sunny on 24-10-2.
//

#include "start.h"
#include "main.h"
#include "tim.h"
#include "LED.h"

LED leds[8];

void initLEDS()
{
	leds[0] = LED(LED_1_GPIO_Port, LED_1_Pin, 128, 1);
	leds[1] = LED(LED_2_GPIO_Port, LED_2_Pin, 128, 1);
	leds[2] = LED(LED_3_GPIO_Port, LED_3_Pin, 128, 1);
	leds[3] = LED(LED_4_GPIO_Port, LED_4_Pin, 128, 1);
	leds[4] = LED(LED_5_GPIO_Port, LED_5_Pin, 128, 1);
	leds[5] = LED(LED_6_GPIO_Port, LED_6_Pin, 128, 1);
	leds[6] = LED(LED_7_GPIO_Port, LED_7_Pin, 128, 1);
	leds[7] = LED(LED_8_GPIO_Port, LED_8_Pin, 128, 1);
}

void startup()
{
	HAL_TIM_Base_Start_IT(&htim1);
	initLEDS();
	while(1)
	{
//		initLEDS();
	}
}
