//
// Created by Sunny on 24-10-2.
//

#include "main.h"
#include "tim.h"

int count = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim == &htim1)
	{
		count++;
		if (count == 1000)
		{
			HAL_GPIO_TogglePin(LED_2_GPIO_Port, LED_2_Pin);
			count = 0;
		}


	}
}