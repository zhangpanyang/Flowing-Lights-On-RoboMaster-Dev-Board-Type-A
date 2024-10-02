//
// Created by Sunny on 24-10-2.
//

#ifndef LED_H
#define LED_H

#include "main.h"

class LED {
private:
	double gamma_;
    uint8_t counter_;

public:
	GPIO_TypeDef *port_;
	uint16_t pin_;
	uint8_t lightLevelMax_;
    uint8_t currentLightLevel_;
	LED();
	LED(GPIO_TypeDef *port, uint16_t pin, uint8_t lightLevelMax, double gamma);
    void setCurrentLightLevel(uint8_t currentLightLevel);
    void timerRoutine();
};



#endif //LED_H
