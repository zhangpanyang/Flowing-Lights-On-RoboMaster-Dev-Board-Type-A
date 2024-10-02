//
// Created by Sunny on 24-10-2.
//

#include "LED.h"
#include "main.h"

LED::LED(uint8_t lightLevelMax, double gamma) {
	lightLevelMax_ = lightLevelMax;
    gamma_ = gamma;
    currentLightLevel_ = 0;
}

void LED::setCurrentLightLevel(uint8_t currentLightLevel) {
	currentLightLevel_ = currentLightLevel;
}