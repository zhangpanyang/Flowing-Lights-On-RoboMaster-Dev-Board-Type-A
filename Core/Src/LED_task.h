//
// Created by Sunny on 24-10-2.
//

#ifndef __LED_TASK_H__
#define __LED_TASK_H__

#include "LED.h"

inline LED leds[8];
inline int count = 0;

void initLEDs();
void LEDTaskRoutine();

#endif //__LED_TASK_H__
