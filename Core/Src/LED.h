//
// Created by Sunny on 24-10-2.
//

#ifndef LED_H
#define LED_H

#include "main.h"

class LED {
private:
	double gamma_;
	uint8_t realCurrentLight_;
    uint8_t currentLightLevel_;
    uint8_t counter_;
	void calcRealCurrentLight();

public:
	GPIO_TypeDef *port_;
	uint16_t pin_;
	uint8_t lightLevelMax_;
	LED();
	LED(GPIO_TypeDef *port, uint16_t pin, uint8_t lightLevelMax, double gamma);
    void setCurrentLightLevel(uint8_t currentLightLevel);
    uint8_t getCurrentLightLevel() const;
    void timerRoutine();
};



#endif //LED_H
