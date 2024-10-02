//
// Created by Sunny on 24-10-2.
//

#include "main.h"
#include "tim.h"

#include "LED_task.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == BUTTON_Pin)
	{
		LEDOnButtonClick();
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim == &htim1)
	{
		LEDTaskRoutine();
	}
}