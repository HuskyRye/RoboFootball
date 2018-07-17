#include "execute_task.h"
#include "can_device.h"
#include "uart_device.h"
#include "cmsis_os.h"
#include "calibrate.h"
#include "pid.h"
#include "sys.h"

void execute_task(const void* argu)
{
	  // 电机pid初始化
    football_motor_init();

    while(1) {
			  // 电机控制
				football_motor_control();
			
			  // 使用底盘电机的函数发送电流值
				send_chassis_moto_current(football_moto_current);
			
				osDelay(5);
    }
}
