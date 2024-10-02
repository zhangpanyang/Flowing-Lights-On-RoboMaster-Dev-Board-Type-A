//
// Created by Sunny on 24-10-2.
//

#include "main.h"
#include "tim.h"

#include "LED.h"

extern LED leds[8];

int count = 0;
int lightness = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim == &htim1)
	{
		for(auto & led : leds)
			led.timerRoutine();

		// count++;

		// if(count == 12800)
		// {
		// 	lightness = 0;
		// 	count = 0;
		// }
		//
		// if (count%100 == 0)
		// {
		// 	for(auto & led : leds)
		// 		led.setCurrentLightLevel(lightness);
		//
		// 	lightness++;
		// }
	}
}