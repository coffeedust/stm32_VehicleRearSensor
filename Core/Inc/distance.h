/*
 * distance.h
 *
 *  Created on: Dec 3, 2024
 *      Author: iotpc
 */

#ifndef INC_DISTANCE_H_
#define INC_DISTANCE_H_

#include "main.h"

// define function prototype
void delayUs(uint16_t);
void initDistance();
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *);
uint32_t	getDistance();

#endif /* INC_DISTANCE_H_ */
