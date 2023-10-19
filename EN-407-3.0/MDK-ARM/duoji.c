#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "duoji.h"

void DISC_Rotate(int pwm_t)//该舵机每条命令之间必须加HAL_Delay且至少为500
{
	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,pwm_t);
}
/*
pwm_t取值：
500：2在前 1在右
875：3在前 2在右
1250: 4在前	3在右
1650：5在前	4在右
2050：1在前 5在右
825：1颜色
1300：2颜色
1700：3颜色
2100：4颜色
400：5颜色
*/

////0,1500停止，大于1500为顺时针旋转，小于1500为逆时针旋转
//void DISC_Rotate_Anticlockwise(int time)//逆时针
//{
//	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,1200);
//			HAL_Delay(time);
//	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,0);
//}9

//void DISC_Rotate_Clockwise(int time)//顺时针
//{
//	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,1800);
//			HAL_Delay(time);
//	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,0);
//}


//1000下 2000上
void MG90S_Rotate_up1(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_1,2200);}
void MG90S_Rotate_down1(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_1,800);}

void MG90S_Rotate_up2(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_2,2000);}
void MG90S_Rotate_down2(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_2,650);}

void MG90S_Rotate_up3(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,2600);}
void MG90S_Rotate_down3(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,1400);}

void MG90S_Rotate_up4(){__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,2100);}
void MG90S_Rotate_down4(){__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,800);}

void MG90S_Rotate_up5(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,2000);}
void MG90S_Rotate_down5(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,650);}



