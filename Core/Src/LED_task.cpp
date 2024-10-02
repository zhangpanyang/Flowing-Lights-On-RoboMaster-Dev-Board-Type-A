//
// Created by Sunny on 24-10-2.
//

#include "LED_task.h"
#include "main.h"

void initLEDs()
{
	leds[0] = LED(LED_1_GPIO_Port, LED_1_Pin, 128, 2.2);
	leds[1] = LED(LED_2_GPIO_Port, LED_2_Pin, 128, 2.2);
	leds[2] = LED(LED_3_GPIO_Port, LED_3_Pin, 128, 2.2);
	leds[3] = LED(LED_4_GPIO_Port, LED_4_Pin, 128, 2.2);
	leds[4] = LED(LED_5_GPIO_Port, LED_5_Pin, 128, 2.2);
	leds[5] = LED(LED_6_GPIO_Port, LED_6_Pin, 128, 2.2);
	leds[6] = LED(LED_7_GPIO_Port, LED_7_Pin, 128, 2.2);
	leds[7] = LED(LED_8_GPIO_Port, LED_8_Pin, 128, 2.2);

	LEDTaskInit(0);
}

void LEDTaskInit(uint8_t d)
{
	if(d == 0)
	{
		for (int i = 0; i < 8; i++)
			leds[i].setCurrentLightLevel(i*16);
	}
	else
	{
		for (int i = 0; i < 8; i++)
			leds[i].setCurrentLightLevel((7-i)*16);
	}
}

void LEDOnButtonClick()
{
	ledTaskDirection ^= 1;
	LEDTaskInit(ledTaskDirection);
}

void LEDTaskRoutine()
{
	for(auto & led : leds)
		led.timerRoutine();

	ledTaskCount++;

	if (ledTaskCount == 1000)
	{
		for(auto & led : leds)
		{
			uint8_t lightLevel = led.getCurrentLightLevel();
			if(lightLevel == 0)
				led.setCurrentLightLevel(led.lightLevelMax_-1);
			else
				led.setCurrentLightLevel(lightLevel-1);
		}
		ledTaskCount = 0;
	}
}
