//
// Created by Sunny on 24-10-2.
//

#include "main.h"
#include "tim.h"

#include "LED_task.h"


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim == &htim1)
	{
		for(auto & led : leds)
			led.timerRoutine();

		count++;

		// if(count == 12800)
		// {
		// 	lightness = 0;
		// 	count = 0;
		// }

		if (count == 1000)
		{
			for(auto & led : leds)
			{
				uint8_t lightLevel = led.getCurrentLightLevel();
				if(lightLevel == 0)
					led.setCurrentLightLevel(led.lightLevelMax_-1);
				else
					led.setCurrentLightLevel(lightLevel-1);
			}
			count = 0;
		}
	}
}