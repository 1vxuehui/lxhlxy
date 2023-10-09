#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "duoji.h"


//71 19999 以及gpio改成high

//400-1500+100左转    1500-2500+100右转  1500和0停转
void MG995_Rotate_left(){

__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,300); //400-1500+100    1500-2500+100
HAL_Delay(75);
__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,250);
}

void MG995_Rotate_right(){
__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,2000);	
	HAL_Delay(75);
__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,250);
}


//500-2500小舵机上下
void SG90_Rotate_down1(){__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,1000);}
void SG90_Rotate_up1(){__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,500);}

void SG90_Rotate_down2(){__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,1400);}
void SG90_Rotate_up2(){__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,500);}

void SG90_Rotate_down3(){__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,1400);}
void SG90_Rotate_up3(){__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,500);}

void SG90_Rotate_down4(){__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,1400);}
void SG90_Rotate_up4(){__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,500);}

void SG90_Rotate_down5(){__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,1400);}
void SG90_Rotate_up5(){__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,500);}


/*void SG90_Rotatec1 (){
__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,195); 
HAL_Delay(500);
__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,185); 
HAL_Delay(500);
__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,100); 
}


void SG90_Rotatec2 (){
__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,195); 
HAL_Delay(500);
__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,185); 
HAL_Delay(500);
__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,100); 
}


void SG90_Rotatec3 (){
__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,195); 
HAL_Delay(500);
__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,185); 
HAL_Delay(500);
__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,100); 
}


void SG90_Rotatec4 (){
__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,195); 
HAL_Delay(500);
__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,185); 
HAL_Delay(500);
__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,100); 
}


void SG90_Rotatec5 (){
__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,195); 
HAL_Delay(500);
__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,185); 
HAL_Delay(500);
__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,100); 
}
//右转向下





void SG90_Rotated1 (){
__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,195); 
HAL_Delay(500);
__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,185); 
HAL_Delay(500);
__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,200); 
}
void SG90_Rotated2 (){
__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,195); 
HAL_Delay(500);
__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,185); 
HAL_Delay(500);
__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,200); 
}
void SG90_Rotated3 (){
__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,195); 
HAL_Delay(500);
__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,185); 
HAL_Delay(500);
__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,200); 
}
void SG90_Rotated4 (){
__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,195); 
HAL_Delay(500);
__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,185); 
HAL_Delay(500);
__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,200); 
}
void SG90_Rotated5 (){
__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,195); 
HAL_Delay(500);
__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,185); 
HAL_Delay(500);
__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,200); 
}*/

