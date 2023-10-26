#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "duoji.h"

void DISC_Rotate(int pwm_t)//该舵机每条命令之间必须加HAL_Delay且至少为500
{
	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,pwm_t);
}

void MG_RISE()
{
	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,1700);
}
void MG_DOWN()
{
	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,900);
}
/*
pwm_t取值：
400：2在前 1在右
900：3在前 2在右
1350: 4在前	3在右
1750：5在前	4在右
2150：1在前 5在右
1000/750：1颜色
1400/1150：2颜色
1800/1600：3颜色
2200/2000：4颜色
/2500：5颜色
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
void MG90S_Rotate_down1(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_1,1000);}

void MG90S_Rotate_up2(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_2,2100);}
void MG90S_Rotate_down2(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_2,1200);}

void MG90S_Rotate_up3(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,1500);}
void MG90S_Rotate_down3(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,500);}

void MG90S_Rotate_up4(){__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,2200);}
void MG90S_Rotate_down4(){__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,1200);}

void MG90S_Rotate_up5(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,1600);}
void MG90S_Rotate_down5(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,650);}

void MG90S_Rotate_OPEN6(){__HAL_TIM_SetCompare(&htim5,TIM_CHANNEL_1,2300);}
void MG90S_Rotate_CLOSE6(){__HAL_TIM_SetCompare(&htim5,TIM_CHANNEL_1,1575);}

void MG90S_Rotate_OPEN7(){__HAL_TIM_SetCompare(&htim10,TIM_CHANNEL_1,1700);}
void MG90S_Rotate_CLOSE7(){__HAL_TIM_SetCompare(&htim10,TIM_CHANNEL_1,2800);}