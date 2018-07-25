#include "execute_task.h"
#include "can_device.h"
#include "uart_device.h"
#include "pid.h"
#include "sys.h"

int16_t football_moto_speed[4];
float football_moto_angle[4];
int16_t football_moto_current[4];

pid_t pid_football_speed[4] = { 0 };
pid_t pid_football_angle[4]  = { 0 };

void football_motor_init() {
    for (int i = 0; i < 4; ++i) {
<<<<<<< HEAD
			  // 这两个pid都还有调整的空间，只是偷个懒
				pid_init(&pid_football_speed[i], 300, 0, 10, 0, 0);
			  pid_init(&pid_football_angle[i], 7000, 0, 100, 0, 0);
	  }
=======
        // 杩欎袱涓猵id閮借繕鏈夎皟鏁寸殑绌洪棿锛屽彧鏄伔涓噿
        pid_init(&pid_football_speed[i], 300, 0, 10, 0, 0);
        pid_init(&pid_football_angle[i], 7000, 0, 100, 0, 0);
    }
>>>>>>> 9579fc93fd04298cd74b0f5a9d3001d3e51599bf
}

void football_motor_control() {
    football_moto_angle[0] = -rc.ch1 / RC_MAX_VALUE * 160;		// 闈炲畧闂ㄥ憳
    //football_moto_angle[0] = -rc.ch1 / RC_MAX_VALUE * 260;	// 瀹堥棬鍛�
    football_moto_angle[1] = -(rc.ch2 / RC_MAX_VALUE * 90);
    football_moto_angle[2] = -rc.ch3 / RC_MAX_VALUE * 160;
    football_moto_angle[3] = -(rc.ch4 / RC_MAX_VALUE * 90);
	
    for (int i = 0; i < 4; ++i) {
        // 瑙掑害pid鐨勮緭鍑洪噺浣滀负閫熷害pid鐨勮緭鍏ラ噺锛岀敱浜庣數鏈哄噺閫熸瘮锛屽total_angle闄�19.2
        football_moto_speed[i] = pid_calc(&pid_football_angle[i], moto_chassis[i].total_angle/19.2, football_moto_angle[i]);
        football_moto_current[i] = pid_calc(&pid_football_speed[i], moto_chassis[i].speed_rpm, football_moto_speed[i]);
    }			
}
