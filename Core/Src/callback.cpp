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
		LEDTaskRoutine();
	}
}