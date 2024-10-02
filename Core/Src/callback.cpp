//
// Created by Sunny on 24-10-2.
//

#include "main.h"
#include "tim.h"

#include "LED.h"

extern LED leds[8];

int count = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim == &htim1)
	{
		for(auto & led : leds)
			led.timerRoutine();

		count++;
		if (count == 5000)
		{
			for(auto & led : leds)
				led.setCurrentLightLevel(0);
		}
		if (count == 10000)
		{
			for(auto & led : leds)
				led.setCurrentLightLevel(127);
			// HAL_GPIO_TogglePin(LED_2_GPIO_Port, LED_2_Pin);
			count = 0;
		}


	}
}