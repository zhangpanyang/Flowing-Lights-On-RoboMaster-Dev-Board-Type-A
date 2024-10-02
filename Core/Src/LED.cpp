//
// Created by Sunny on 24-10-2.
//

#include "LED.h"
#include "main.h"
#include <cmath>

LED::LED()
{
	port_ = nullptr;
	pin_ = 0;
	lightLevelMax_ = 0;
	currentLightLevel_ = 0;
	realCurrentLight_ = 0;
	gamma_ = 0;
	counter_ = 0;
}
LED::LED(GPIO_TypeDef *port, uint16_t pin, uint8_t lightLevelMax, double gamma) {
	port_ = port;
    pin_ = pin;
	lightLevelMax_ = lightLevelMax;
    currentLightLevel_ = 0;
	realCurrentLight_ = 0;
    gamma_ = gamma;
    counter_ = 0;
}

void LED::calcRealCurrentLight()
{
	realCurrentLight_ = (uint8_t)std::round(std::pow(currentLightLevel_/128.0, gamma_)*128);
}


void LED::setCurrentLightLevel(uint8_t currentLightLevel) {
	currentLightLevel_ = currentLightLevel;
	calcRealCurrentLight();
}

uint8_t LED::getCurrentLightLevel() const
{
	return currentLightLevel_;
}

void LED::timerRoutine() {
    if(counter_ == lightLevelMax_) {
    	HAL_GPIO_WritePin(port_, pin_, GPIO_PIN_RESET);
        counter_ = 0;
	}
    if(counter_ == realCurrentLight_) {
		HAL_GPIO_WritePin(port_, pin_, GPIO_PIN_SET);
	}
	counter_++;
}