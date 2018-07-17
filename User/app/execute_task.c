#include "execute_task.h"
#include "can_device.h"
#include "uart_device.h"
#include "cmsis_os.h"
#include "calibrate.h"
#include "pid.h"
#include "sys.h"

void execute_task(const void* argu)
{
	  // ���pid��ʼ��
    football_motor_init();

    while(1) {
			  // �������
				football_motor_control();
			
			  // ʹ�õ��̵���ĺ������͵���ֵ
				send_chassis_moto_current(football_moto_current);
			
				osDelay(5);
    }
}
