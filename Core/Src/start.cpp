//
// Created by Sunny on 24-10-2.
//

#include "start.h"
#include "main.h"
#include "tim.h"
#include "LED_task.h"

void startup()
{
	HAL_TIM_Base_Start_IT(&htim1);
	initLEDs();
	while(1)
	{

	}
}
