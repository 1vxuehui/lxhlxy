#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "duoji.h"


//0,1500ֹͣ������1500Ϊ˳ʱ����ת��С��1500Ϊ��ʱ����ת
void DISC_Rotate_Anticlockwise(int time)//��ʱ��
{
	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,1200);
			HAL_Delay(time);
	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,0);
}

void DISC_Rotate_Clockwise(int time)//˳ʱ��
{
	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,1700);
			HAL_Delay(time);
	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,0);
}
/*
����timeȡֵ��
700���к󷽵���ɫ������
???����ɫ���������к󷽣�δ���ԣ�
*/

//1000�� 2000��
void MG90S_Rotate_up1(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_1,2000);}
void MG90S_Rotate_down1(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_1,1000);}

void MG90S_Rotate_up2(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_2,2000);}
void MG90S_Rotate_down2(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_2,1000);}

void MG90S_Rotate_up3(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,2000);}
void MG90S_Rotate_down3(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,1000);}

void MG90S_Rotate_up4(){__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,2000);}
void MG90S_Rotate_down4(){__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,1000);}

void MG90S_Rotate_up5(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,2000);}
void MG90S_Rotate_down5(){__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,1000);}



