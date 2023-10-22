#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "duoji.h"

void DISC_Rotate(int pwm_t)//�ö��ÿ������֮������HAL_Delay������Ϊ500
{
	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,pwm_t);
}
/*
pwm_tȡֵ��
400��2��ǰ 1����
900��3��ǰ 2����
1350: 4��ǰ	3����
1750��5��ǰ	4����
2150��1��ǰ 5����
1050/750��1��ɫ
1400/1150��2��ɫ
1800/1600��3��ɫ
2200/2000��4��ɫ
1000/2350��5��ɫ
*/

////0,1500ֹͣ������1500Ϊ˳ʱ����ת��С��1500Ϊ��ʱ����ת
//void DISC_Rotate_Anticlockwise(int time)//��ʱ��
//{
//	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,1200);
//			HAL_Delay(time);
//	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,0);
//}9

//void DISC_Rotate_Clockwise(int time)//˳ʱ��
//{
//	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,1800);
//			HAL_Delay(time);
//	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,0);
//}


//1000�� 2000��
void MG90S_Rotate_up1(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_1,2200);}
void MG90S_Rotate_down1(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_1,800);}

void MG90S_Rotate_up2(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_2,2000);}
void MG90S_Rotate_down2(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_2,650);}

void MG90S_Rotate_up3(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,1400);}
void MG90S_Rotate_down3(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,400);}

void MG90S_Rotate_up4(){__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,2100);}
void MG90S_Rotate_down4(){__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,800);}

void MG90S_Rotate_up5(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,2000);}
void MG90S_Rotate_down5(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,650);}



