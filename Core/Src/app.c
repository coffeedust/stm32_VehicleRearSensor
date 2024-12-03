/*
 * app.c
 *
 *  Created on: Nov 25, 2024
 *      Author: iotpc
 */

#include "app.h"

int cycleDistance = 0;
int cycleSound = 0;

// 1ms의 주기로 호출됨
void SystickCallback() {
	if(cycleDistance > 0) cycleDistance--;
	if(cycleSound > 0) cycleSound--;
}


void app() {
	uint8_t periodSound = 0;
	uint8_t distance;
	int periodOn = 0;
	// init
	initSound();
	initDistance();
	while(1) {
		// measure distance
		if(cycleDistance == 0) {
			cycleDistance = 100;
			distance = getDistance();
			// judgement distance
			if(distance > 20) periodOn = 1000 / 2;
			else if((distance <= 20) && (distance > 15)) periodOn = 800 / 2;
			else if((distance <= 15) && (distance > 10)) periodOn = 600 / 2;
			else if((distance <= 10) && (distance > 5)) periodOn = 400 / 2;
			else if(distance <= 5) periodOn = 0;
		}
		// generate sound
		if(cycleSound == 0) {
			cycleSound = periodOn;
			if(periodOn == 0) {
				startSound();
				cycleSound = 0;
			}
			else {
				if(periodSound == 1) startSound();
				else if(periodSound == 0) stopSound();
				periodSound ^= 1;
			}
		}
	}
}
