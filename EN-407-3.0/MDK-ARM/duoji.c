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
500��2��ǰ 1����
875��3��ǰ 2����
1250: 4��ǰ	3����
1650��5��ǰ	4����
2050��1��ǰ 5����
825��1��ɫ
1300��2��ɫ
1700��3��ɫ
2100��4��ɫ
400��5��ɫ
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



