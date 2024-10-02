//
// Created by Sunny on 24-10-2.
//

#ifndef LED_H
#define LED_H

#include "main.h"

class LED {
	private:
		uint8_t lightLevelMax_;
		double gamma_;
        uint8_t currentLightLevel_;

    public:
		LED(uint8_t lightLevelMax, double gamma);
        void setCurrentLightLevel(uint8_t currentLightLevel);
};



#endif //LED_H
