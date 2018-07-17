#ifndef __EXECUTE_TASK_H__
#define __EXECUTE_TASK_H__

#include "stm32f4xx_hal.h"

extern int16_t football_moto_current[4];

void execute_task(const void* argu);

void football_motor_init(void);
void football_motor_control(void);

#endif
