//
// Created by Sunny on 24-10-2.
//

#include "LED.h"
#include "main.h"

LED::LED(GPIO_TypeDef *port, uint16_t pin, uint8_t lightLevelMax, double gamma) {
	port_ = port;
    pin_ = pin;
	lightLevelMax_ = lightLevelMax;
    gamma_ = gamma;

    currentLightLevel_ = 0;
    counter_ = 0;
}

void LED::setCurrentLightLevel(uint8_t currentLightLevel) {
	currentLightLevel_ = currentLightLevel;
}

void LED::timerRoutine() {
    if(counter_ == lightLevelMax_) {
    	HAL_GPIO_WritePin(port_, pin_, GPIO_PIN_RESET);
        counter_ = 0;
	}
    if(counter_ == currentLightLevel_) {
		HAL_GPIO_WritePin(port_, pin_, GPIO_PIN_SET);
	}
	counter_++;
}