#include "Track.h"
#include "main.h"
#include "motor.h"
#include "pid.h"
#include "tim.h"

extern TIM_HandleTypeDef htim6;
int16_t speed,speed1,speed2;
int angle1, angle2;
int16_t feedback_1;
int16_t feedback_2;
int16_t you_set_speed_1;
int16_t zuo_set_speed_2;
int flag_ = 0;
float flag[14];

pid_type_def motor[2];
const static fp32 motor_speed1_pid[3] = {MOTOR_SPEED1_PID_KP, MOTOR_SPEED1_PID_KI, MOTOR_SPEED1_PID_KD};
const static fp32 motor_speed2_pid[3] = {MOTOR_SPEED2_PID_KP, MOTOR_SPEED2_PID_KI, MOTOR_SPEED2_PID_KD};

int16_t GetEncoderSpeed(uint16_t ccr)
{
	if (ccr > 10000)
	{
		speed = 20000 - ccr;
	}
	else 
	{
		speed = ccr;
	}
	return speed;
}
void Tracking_Init(void)
{
PID_init(&motor[0],PID_POSITION,motor_speed1_pid,3000, 100);
PID_init(&motor[1],PID_POSITION,motor_speed2_pid,3000, 100);
}
void Tracking(void)
{
PID_clear(&motor[0]);
PID_clear(&motor[1]);
angle1 =0;
	angle2=0;
		Tracking_Init();
	
while(1)
{	
    speed1 = GetEncoderSpeed(TIM3->CNT);
	  angle1+=speed1;
		TIM3->CNT=0;
  	angle2+=speed2;
    speed2 = GetEncoderSpeed(TIM1->CNT);
		TIM1->CNT=0;
		feedback_1 = speed1;//右轮
		feedback_2 = speed2;

		PID_calc(&motor[0], feedback_1, you_set_speed_1);
		PID_calc(&motor[1], feedback_2, zuo_set_speed_2);
		TIM9->CCR1= motor[0].out;
		TIM9->CCR2= motor[1].out;
		HAL_Delay(50);
if(((HAL_GPIO_ReadPin(huidu11_GPIO_Port,huidu11_Pin)) == 1 ||(HAL_GPIO_ReadPin(huidu17_GPIO_Port,huidu17_Pin)) == 1)&&(angle1>5500||angle2>5500))
{
	car_go_ahead();

   break;
}


else if ( (HAL_GPIO_ReadPin(huidu13_GPIO_Port,huidu13_Pin)) == 0 &&(HAL_GPIO_ReadPin(huidu14_GPIO_Port,huidu14_Pin)) == 1 && (HAL_GPIO_ReadPin(huidu15_GPIO_Port,huidu15_Pin)) == 0 
||	(HAL_GPIO_ReadPin(huidu13_GPIO_Port,huidu13_Pin)) == 1 &&(HAL_GPIO_ReadPin(huidu14_GPIO_Port,huidu14_Pin)) == 1 && (HAL_GPIO_ReadPin(huidu15_GPIO_Port,huidu15_Pin)) == 1 )
{
	//直走
	you_set_speed_1 = 50;
	zuo_set_speed_2 = 50;
	car_go_straight();
}
else if ( (HAL_GPIO_ReadPin(huidu13_GPIO_Port,huidu13_Pin)) == 1 &&(HAL_GPIO_ReadPin(huidu14_GPIO_Port,huidu14_Pin)) == 0 && (HAL_GPIO_ReadPin(huidu15_GPIO_Port,huidu15_Pin)) == 0||
					(HAL_GPIO_ReadPin(huidu12_GPIO_Port,huidu12_Pin)) == 1)
{
	//右转
	you_set_speed_1 = 50;
	zuo_set_speed_2 = 30;
	car_go_straight();
}
else if((HAL_GPIO_ReadPin(huidu13_GPIO_Port,huidu13_Pin)) == 0 &&(HAL_GPIO_ReadPin(huidu14_GPIO_Port,huidu14_Pin)) == 0 && (HAL_GPIO_ReadPin(huidu15_GPIO_Port,huidu15_Pin)) == 1 ||
				(HAL_GPIO_ReadPin(huidu16_GPIO_Port,huidu16_Pin)) == 1  )
{
	//左转
	you_set_speed_1 = 30;
	zuo_set_speed_2 = 50;
	car_go_straight();
}
else
{
//
	you_set_speed_1 = 60;
	zuo_set_speed_2 = 60;
	car_go_straight();
}

}
	 }
void Trackinghou(void)
{
PID_clear(&motor[0]);
PID_clear(&motor[1]);
Tracking_Init();
	angle1 =0;
	angle2=0;
while(1)
{
    speed1 = GetEncoderSpeed(TIM3->CNT);
	angle1 +=speed1;	
	TIM3->CNT=0;
    speed2 = GetEncoderSpeed(TIM1->CNT);
	angle2 +=speed2;	
	TIM1->CNT=0;
	
		feedback_1 = speed1;
		feedback_2 = speed2;
		PID_calc(&motor[0], feedback_1, you_set_speed_1);
		PID_calc(&motor[1], feedback_2, zuo_set_speed_2);
		TIM9->CCR1= motor[0].out;
		TIM9->CCR2= motor[1].out;
		HAL_Delay(50);
if(((HAL_GPIO_ReadPin(huidu22_GPIO_Port,huidu22_Pin)) == 1 &&(HAL_GPIO_ReadPin(huidu24_GPIO_Port,huidu24_Pin)) == 1 && (HAL_GPIO_ReadPin(huidu25_GPIO_Port,huidu25_Pin)) == 1)&&((angle1>=1000)||(angle2>1000)) )
{
	angle1=0;
	angle2=0;
		car_go_ahead();
   break;	
}

else if ( (HAL_GPIO_ReadPin(huidu22_GPIO_Port,huidu22_Pin)) == 0 &&(HAL_GPIO_ReadPin(huidu24_GPIO_Port,huidu24_Pin)) == 1 && (HAL_GPIO_ReadPin(huidu25_GPIO_Port,huidu25_Pin)) == 0  )
{
	//后
	you_set_speed_1 = 60;
	zuo_set_speed_2 = 60;
	car_go_after();
}
else if ( (HAL_GPIO_ReadPin(huidu22_GPIO_Port,huidu22_Pin)) == 0 &&(HAL_GPIO_ReadPin(huidu24_GPIO_Port,huidu24_Pin)) == 0 && (HAL_GPIO_ReadPin(huidu25_GPIO_Port,huidu25_Pin)) == 0  )
{
	//后
	you_set_speed_1 = 60;
	zuo_set_speed_2 = 60;
	car_go_after();
}
else if ( (HAL_GPIO_ReadPin(huidu22_GPIO_Port,huidu22_Pin)) == 1 &&(HAL_GPIO_ReadPin(huidu24_GPIO_Port,huidu24_Pin)) == 0 && (HAL_GPIO_ReadPin(huidu25_GPIO_Port,huidu25_Pin)) == 0)
{
	//左转
	you_set_speed_1 = 60;
	zuo_set_speed_2 = 40;
	car_go_after();
	flag_ = 1;
}
else if((HAL_GPIO_ReadPin(huidu22_GPIO_Port,huidu22_Pin)) == 0 &&(HAL_GPIO_ReadPin(huidu24_GPIO_Port,huidu24_Pin)) == 0 && (HAL_GPIO_ReadPin(huidu25_GPIO_Port,huidu25_Pin)) == 1)
{
	//右转
	
	you_set_speed_1 = 40;
	zuo_set_speed_2 = 60;
	car_go_after();
	flag_ = 2;
}
else
{
	//后
	you_set_speed_1 = 60;
	zuo_set_speed_2 = 60;
	car_go_after();
}

}
}

void Trackinghou2(void)
{
PID_clear(&motor[0]);
PID_clear(&motor[1]);
Tracking_Init();
	angle1=0;
	angle2=0;
while(1)
{
    speed1 = GetEncoderSpeed(TIM3->CNT);
	angle1+=speed1;
		TIM3->CNT=0;
    speed2 = GetEncoderSpeed(TIM1->CNT);
	angle2+=speed2;
		TIM1->CNT=0;
		feedback_1 = speed1;
		feedback_2 = speed2;
		PID_calc(&motor[0], feedback_1, you_set_speed_1);
		PID_calc(&motor[1], feedback_2, zuo_set_speed_2);
		TIM9->CCR1= motor[0].out;
		TIM9->CCR2= motor[1].out;
		HAL_Delay(50);
if(((HAL_GPIO_ReadPin(huidu22_GPIO_Port,huidu22_Pin)) == 0 &&(HAL_GPIO_ReadPin(huidu24_GPIO_Port,huidu24_Pin)) == 0 && (HAL_GPIO_ReadPin(huidu25_GPIO_Port,huidu25_Pin)) == 0 )&&((angle1>=4000)||(angle2>=4000)))
{
	angle1=0;
	angle2=0;
		car_go_ahead();
   break;	
}

else if ( (HAL_GPIO_ReadPin(huidu22_GPIO_Port,huidu22_Pin)) == 0 &&(HAL_GPIO_ReadPin(huidu24_GPIO_Port,huidu24_Pin)) == 1 && (HAL_GPIO_ReadPin(huidu25_GPIO_Port,huidu25_Pin)) == 0  )
{
	//后
	you_set_speed_1 = 60;
	zuo_set_speed_2 = 60;
	car_go_after();
}
else if ( (HAL_GPIO_ReadPin(huidu22_GPIO_Port,huidu22_Pin)) == 0 &&(HAL_GPIO_ReadPin(huidu24_GPIO_Port,huidu24_Pin)) == 0 && (HAL_GPIO_ReadPin(huidu25_GPIO_Port,huidu25_Pin)) == 0  )
{
	//后
	you_set_speed_1 = 60;
	zuo_set_speed_2 = 60;
	car_go_after();
}
else if ( (HAL_GPIO_ReadPin(huidu22_GPIO_Port,huidu22_Pin)) == 1 &&(HAL_GPIO_ReadPin(huidu24_GPIO_Port,huidu24_Pin)) == 0 && (HAL_GPIO_ReadPin(huidu25_GPIO_Port,huidu25_Pin)) == 0)
{
	//左转
	you_set_speed_1 = 60;
	zuo_set_speed_2 = 40;
	car_go_after();
	flag_ = 1;
}
else if((HAL_GPIO_ReadPin(huidu22_GPIO_Port,huidu22_Pin)) == 0 &&(HAL_GPIO_ReadPin(huidu24_GPIO_Port,huidu24_Pin)) == 0 && (HAL_GPIO_ReadPin(huidu25_GPIO_Port,huidu25_Pin)) == 1)
{
	//右转
	
	you_set_speed_1 = 40;
	zuo_set_speed_2 = 60;
	car_go_after();
	flag_ = 2;
}
else
{
	//后
	you_set_speed_1 = 60;
	zuo_set_speed_2 = 60;
	car_go_after();
}

}
}
	 
void Trackinghou3(void)
{
PID_clear(&motor[0]);
PID_clear(&motor[1]);
Tracking_Init();
	angle1=0;
	angle2=0;
while(1)
{
    speed1 = GetEncoderSpeed(TIM3->CNT);
	angle1+=speed1;
		TIM3->CNT=0;
    speed2 = GetEncoderSpeed(TIM1->CNT);
	angle2+=speed2;
		TIM1->CNT=0;
		feedback_1 = speed1;
		feedback_2 = speed2;
		PID_calc(&motor[0], feedback_1, you_set_speed_1);
		PID_calc(&motor[1], feedback_2, zuo_set_speed_2);
		TIM9->CCR1= motor[0].out;
		TIM9->CCR2= motor[1].out;
		HAL_Delay(50);
if(((HAL_GPIO_ReadPin(huidu22_GPIO_Port,huidu22_Pin)) == 1 &&(HAL_GPIO_ReadPin(huidu24_GPIO_Port,huidu24_Pin)) == 1&& (HAL_GPIO_ReadPin(huidu25_GPIO_Port,huidu25_Pin)) == 1 )&&((angle1>=2000)||(angle2>=2000)))
{
	angle1=0;
	angle2=0;
		car_go_ahead();
   break;	
}

else if ( (HAL_GPIO_ReadPin(huidu22_GPIO_Port,huidu22_Pin)) == 0 &&(HAL_GPIO_ReadPin(huidu24_GPIO_Port,huidu24_Pin)) == 1 && (HAL_GPIO_ReadPin(huidu25_GPIO_Port,huidu25_Pin)) == 0  )
{
	//后
	you_set_speed_1 = 50;
	zuo_set_speed_2 = 50;
	car_go_after();
}
else if ( (HAL_GPIO_ReadPin(huidu22_GPIO_Port,huidu22_Pin)) == 0 &&(HAL_GPIO_ReadPin(huidu24_GPIO_Port,huidu24_Pin)) == 0 && (HAL_GPIO_ReadPin(huidu25_GPIO_Port,huidu25_Pin)) == 0  )
{
	//后
	you_set_speed_1 = 50;
	zuo_set_speed_2 = 50;
	car_go_after();
}
else if ( (HAL_GPIO_ReadPin(huidu22_GPIO_Port,huidu22_Pin)) == 1 &&(HAL_GPIO_ReadPin(huidu24_GPIO_Port,huidu24_Pin)) == 0 && (HAL_GPIO_ReadPin(huidu25_GPIO_Port,huidu25_Pin)) == 0)
{
	//左转
	you_set_speed_1 = 50;
	zuo_set_speed_2 = 30;
	car_go_after();
	flag_ = 1;
}
else if((HAL_GPIO_ReadPin(huidu22_GPIO_Port,huidu22_Pin)) == 0 &&(HAL_GPIO_ReadPin(huidu24_GPIO_Port,huidu24_Pin)) == 0 && (HAL_GPIO_ReadPin(huidu25_GPIO_Port,huidu25_Pin)) == 1)
{
	//右转
	
	you_set_speed_1 = 30;
	zuo_set_speed_2 = 50;
	car_go_after();
	flag_ = 2;
}
else
{
	//后
	you_set_speed_1 = 50;
	zuo_set_speed_2 = 50;
	car_go_after();
}

}
}
void zuozhuan1(void)
{
	
PID_clear(&motor[0]);
PID_clear(&motor[1]);
	angle1 =0;
	angle2=0;
		you_set_speed_1 = 30;
		zuo_set_speed_2 = 30;
		Tracking_Init();
	while(1)
	{
	  angle1+=speed1;
		angle2+=speed2;
if ((angle1>=382||angle2>=382)&&(HAL_GPIO_ReadPin(huidu14_GPIO_Port,huidu14_Pin)) == 1)
		{
			angle1=0;
		  angle2=0;
			car_go_ahead();
			break;
		}
		else 
		{
		speed1 = GetEncoderSpeed(TIM3->CNT);
		TIM3->CNT=0;
    speed2 = GetEncoderSpeed(TIM1->CNT);
		TIM1->CNT=0;
		feedback_1 = speed1;//右轮
		feedback_2 = speed2;
		turn_left();
		PID_calc(&motor[0], feedback_1, you_set_speed_1);
		PID_calc(&motor[1], feedback_2, zuo_set_speed_2);
		TIM9->CCR1= motor[0].out;
		TIM9->CCR2= motor[1].out;
		HAL_Delay(50);
		turn_left();
		}
		 }
	 }
void zuozhuan2(void)
{
PID_clear(&motor[0]);
PID_clear(&motor[1]);
	angle1 =0;
	angle2=0;
		you_set_speed_1 = 30;
		zuo_set_speed_2 = 30;
		Tracking_Init();
	
	while(1)
	{
		angle1+=speed1;
		angle2+=speed2;
if ((angle1>=810||angle2>=810)&&(HAL_GPIO_ReadPin(huidu14_GPIO_Port,huidu14_Pin)) == 1)
		{
			angle1=0;
		angle2=0;
			car_go_ahead();
			break;
		}
		else 
		{
		speed1 = GetEncoderSpeed(TIM3->CNT);
			
		TIM3->CNT=0;
    speed2 = GetEncoderSpeed(TIM1->CNT);
		TIM1->CNT=0;
		feedback_1 = speed1;//右轮
		feedback_2 = speed2;
		turn_left();
		PID_calc(&motor[0], feedback_1, you_set_speed_1);
		PID_calc(&motor[1], feedback_2, zuo_set_speed_2);
		TIM9->CCR1= motor[0].out;
		TIM9->CCR2= motor[1].out;
		HAL_Delay(50);
		turn_left();
		}
		 }
	 }
void zuozhuan3(void)
{
PID_clear(&motor[0]);
PID_clear(&motor[1]);
	angle1 =0;
	angle2=0;
		you_set_speed_1 = 30;
		zuo_set_speed_2 = 30;
		Tracking_Init();
	
	while(1)
	{
		angle1+=speed1;
		angle2+=speed2;
if ((angle1>=1600||angle2>=1600)&&(HAL_GPIO_ReadPin(huidu14_GPIO_Port,huidu14_Pin)) == 1)
		{
			angle1=0;
		angle2=0;
			car_go_ahead();
			break;
		}
		else 
		{
		speed1 = GetEncoderSpeed(TIM3->CNT);
			
		TIM3->CNT=0;
    speed2 = GetEncoderSpeed(TIM1->CNT);
		TIM1->CNT=0;
		feedback_1 = speed1;//右轮
		feedback_2 = speed2;
		turn_left();
		PID_calc(&motor[0], feedback_1, you_set_speed_1);
		PID_calc(&motor[1], feedback_2, zuo_set_speed_2);
		TIM9->CCR1= motor[0].out;
		TIM9->CCR2= motor[1].out;
		HAL_Delay(50);
		turn_left();
		}
		 }
	 }
	 void youzhuan1(void)
{
PID_clear(&motor[0]);
PID_clear(&motor[1]);
	angle1 =0;
	angle2=0;
		you_set_speed_1 = 30;
		zuo_set_speed_2 = 30;
		Tracking_Init();
	
	while(1)
	{
		angle1+=speed1;
		angle2+=speed2;
		if ((angle1>=382||angle2>=382)&&(HAL_GPIO_ReadPin(huidu14_GPIO_Port,huidu14_Pin)) == 1)
		{
			angle1=0;
			angle2=0;
			car_go_ahead();
			break;
		}
		else 
		{
		speed1 = GetEncoderSpeed(TIM3->CNT);
		TIM3->CNT=0;
    speed2 = GetEncoderSpeed(TIM1->CNT);
		TIM1->CNT=0;
		feedback_1 = speed1;//右轮
		feedback_2 = speed2;
		turn_right();
		PID_calc(&motor[0], feedback_1, you_set_speed_1);
		PID_calc(&motor[1], feedback_2, zuo_set_speed_2);
		TIM9->CCR1= motor[0].out;
		TIM9->CCR2= motor[1].out;
		HAL_Delay(50);
		turn_right();
		}
		 }
	 }
	  void youzhuan2(void)
{
PID_clear(&motor[0]);
PID_clear(&motor[1]);
	angle1 =0;
	angle2=0;
		you_set_speed_1 = 30;
		zuo_set_speed_2 = 30;
		Tracking_Init();		
	while(1)
	{
		angle1+=speed1;
		angle2+=speed2;
if ((angle1>=800||angle2>=800)&&(HAL_GPIO_ReadPin(huidu14_GPIO_Port,huidu14_Pin)) == 1)
		{
			angle1=0;
			angle2=0;
			car_go_ahead();
			break;
		}
		else 
		{
		speed1 = GetEncoderSpeed(TIM3->CNT);
			
		TIM3->CNT=0;
    speed2 = GetEncoderSpeed(TIM1->CNT);
		TIM1->CNT=0;
		feedback_1 = speed1;//右轮
		feedback_2 = speed2;
		turn_right();
		PID_calc(&motor[0], feedback_1, you_set_speed_1);
		PID_calc(&motor[1], feedback_2, zuo_set_speed_2);
		TIM9->CCR1= motor[0].out;
		TIM9->CCR2= motor[1].out;
		HAL_Delay(50);
		turn_right();
		}
		 }
}

  void youzhuan3(void)
{
PID_clear(&motor[0]);
PID_clear(&motor[1]);
	angle1 =0;
	angle2=0;
		you_set_speed_1 = 30;
		zuo_set_speed_2 = 30;
		Tracking_Init();		
	while(1)
	{
		angle1+=speed1;
		angle2+=speed2;
if ((angle1>=1600||angle2>=1600)&&(HAL_GPIO_ReadPin(huidu14_GPIO_Port,huidu14_Pin)) == 1)
		{
			angle1=0;
			angle2=0;
			car_go_ahead();
			break;
		}
		else 
		{
		speed1 = GetEncoderSpeed(TIM3->CNT);
			
		TIM3->CNT=0;
    speed2 = GetEncoderSpeed(TIM1->CNT);
		TIM1->CNT=0;
		feedback_1 = speed1;//右轮
		feedback_2 = speed2;
		turn_right();
		PID_calc(&motor[0], feedback_1, you_set_speed_1);
		PID_calc(&motor[1], feedback_2, zuo_set_speed_2);
		TIM9->CCR1= motor[0].out;
		TIM9->CCR2= motor[1].out;
		HAL_Delay(50);
		turn_right();
		}
		 }
}

void Tracking2(void)
{
	PID_clear(&motor[0]);
PID_clear(&motor[1]);
	you_set_speed_1 = 40;
	zuo_set_speed_2 = 40;
	Tracking_Init();
	angle1=0;
	angle2=0;
		while(1)
	{
		angle1+=speed1;
		angle2+=speed2;
		
		
		if (angle1>=420&&angle2>=420)
		{
			angle1=0;
			angle2=0;
			car_go_ahead();
			break;
		}
		else 
		{
		speed1 = GetEncoderSpeed(TIM3->CNT);
		TIM3->CNT=0;
    speed2 = GetEncoderSpeed(TIM1->CNT);
		TIM1->CNT=0;
		feedback_1 = speed1;//右轮
		feedback_2 = speed2;
		PID_calc(&motor[0], feedback_1, you_set_speed_1);
		PID_calc(&motor[1], feedback_2, zuo_set_speed_2);
		TIM9->CCR1= motor[0].out;
		TIM9->CCR2= motor[1].out;
		HAL_Delay(50);
		car_go_after();	
		}		
	}
}

void Tracking7(void)
{
	PID_clear(&motor[0]);
PID_clear(&motor[1]);
	you_set_speed_1 = 40;
	zuo_set_speed_2 = 40;
	Tracking_Init();
	angle1=0;
	angle2=0;
		while(1)
	{
		angle1+=speed1;
		angle2+=speed2;
		
		
		if (angle1>=200&&angle2>=200)
		{
			angle1=0;
			angle2=0;
			car_go_ahead();
			break;
		}
		else 
		{
		speed1 = GetEncoderSpeed(TIM3->CNT);
		TIM3->CNT=0;
    speed2 = GetEncoderSpeed(TIM1->CNT);
		TIM1->CNT=0;
		feedback_1 = speed1;//右轮
		feedback_2 = speed2;
		PID_calc(&motor[0], feedback_1, you_set_speed_1);
		PID_calc(&motor[1], feedback_2, zuo_set_speed_2);
		TIM9->CCR1= motor[0].out;
		TIM9->CCR2= motor[1].out;
		HAL_Delay(50);
		car_go_after();	
		}		
	}
}

void tuituitui(void)
{
PID_clear(&motor[0]);
PID_clear(&motor[1]);
Tracking_Init();
while(1)
{
    speed1 = GetEncoderSpeed(TIM3->CNT);
		TIM3->CNT=0;
    speed2 = GetEncoderSpeed(TIM1->CNT);
		TIM1->CNT=0;
		feedback_1 = speed1;//右轮
		feedback_2 = speed2;

		PID_calc(&motor[0], feedback_1, you_set_speed_1);
		PID_calc(&motor[1], feedback_2, zuo_set_speed_2);
		TIM9->CCR1= motor[0].out;
		TIM9->CCR2= motor[1].out;
		HAL_Delay(50);
if((HAL_GPIO_ReadPin(huidu11_GPIO_Port,huidu11_Pin)) == 1 || (HAL_GPIO_ReadPin(huidu17_GPIO_Port,huidu17_Pin)) == 1)
{
	car_go_ahead();
   break;

}
else if ( (HAL_GPIO_ReadPin(huidu13_GPIO_Port,huidu13_Pin)) == 0 &&(HAL_GPIO_ReadPin(huidu14_GPIO_Port,huidu14_Pin)) == 1 && (HAL_GPIO_ReadPin(huidu15_GPIO_Port,huidu15_Pin)) == 0 
||	(HAL_GPIO_ReadPin(huidu13_GPIO_Port,huidu13_Pin)) == 1 &&(HAL_GPIO_ReadPin(huidu14_GPIO_Port,huidu14_Pin)) == 1 && (HAL_GPIO_ReadPin(huidu15_GPIO_Port,huidu15_Pin)) == 1 )
{
	//直走
	you_set_speed_1 = 60;
	zuo_set_speed_2 = 60;
	car_go_straight();
}
else if ( (HAL_GPIO_ReadPin(huidu13_GPIO_Port,huidu13_Pin)) == 1 &&(HAL_GPIO_ReadPin(huidu14_GPIO_Port,huidu14_Pin)) == 0 && (HAL_GPIO_ReadPin(huidu15_GPIO_Port,huidu15_Pin)) == 0||
					(HAL_GPIO_ReadPin(huidu12_GPIO_Port,huidu12_Pin)) == 1)
{
	//右转
	you_set_speed_1 = 60;
	zuo_set_speed_2 = 40;
	car_go_straight();
}
else if((HAL_GPIO_ReadPin(huidu13_GPIO_Port,huidu13_Pin)) == 0 &&(HAL_GPIO_ReadPin(huidu14_GPIO_Port,huidu14_Pin)) == 0 && (HAL_GPIO_ReadPin(huidu15_GPIO_Port,huidu15_Pin)) == 1 ||
				(HAL_GPIO_ReadPin(huidu16_GPIO_Port,huidu16_Pin)) == 1  )
{
	//左转
	you_set_speed_1 = 40;
	zuo_set_speed_2 = 60;
	car_go_straight();
}
else
	{
	//直走
	you_set_speed_1 = 60;
	zuo_set_speed_2 = 60;
	car_go_straight();
}	 
}
}
void Tracking3(void)
 {
PID_clear(&motor[0]);
PID_clear(&motor[1]);

		you_set_speed_1 = 30;
		zuo_set_speed_2 = 30;
		Tracking_Init();
	int a = 0;
		while(1)
	{
		a++;
		if (a>10)
		{
			car_go_ahead();
			break;
		}
		else 
		{
		speed1 = GetEncoderSpeed(TIM3->CNT);
		TIM3->CNT=0;
    speed2 = GetEncoderSpeed(TIM1->CNT);
		TIM1->CNT=0;
		feedback_1 = speed1;//右轮
		feedback_2 = speed2;
		PID_calc(&motor[0], feedback_1, you_set_speed_1);
		PID_calc(&motor[1], feedback_2, zuo_set_speed_2);
		TIM9->CCR1= motor[0].out;
		TIM9->CCR2= motor[1].out;
		HAL_Delay(50);
	car_go_straight();
		}		
	}
}
	 
void Tracking4(void)
{
	PID_clear(&motor[0]);
PID_clear(&motor[1]);
	you_set_speed_1 = 40;
	zuo_set_speed_2 = 40;
	Tracking_Init();
	int a = 0; 
		while(1)
	{
		a++;
		if (a>10)
		{
			car_go_ahead();
			break;
		}
		else 
		{
		speed1 = GetEncoderSpeed(TIM3->CNT);
		TIM3->CNT=0;
    speed2 = GetEncoderSpeed(TIM1->CNT);
		TIM1->CNT=0;
		feedback_1 = speed1;//右轮
		feedback_2 = speed2;
		PID_calc(&motor[0], feedback_1, you_set_speed_1);
		PID_calc(&motor[1], feedback_2, zuo_set_speed_2);
		TIM9->CCR1= motor[0].out;
		TIM9->CCR2= motor[1].out;
		HAL_Delay(50);
		car_go_straight();	
		}		
	}
}
void Tracking5(void)
{
PID_clear(&motor[0]);
PID_clear(&motor[1]);
angle1 =0;
	angle2=0;
		Tracking_Init();
	
while(1)
{	
    speed1 = GetEncoderSpeed(TIM3->CNT);
	  angle1+=speed1;
		TIM3->CNT=0;
  	angle2+=speed2;
    speed2 = GetEncoderSpeed(TIM1->CNT);
		TIM1->CNT=0;
		feedback_1 = speed1;//右轮
		feedback_2 = speed2;

		PID_calc(&motor[0], feedback_1, you_set_speed_1);
		PID_calc(&motor[1], feedback_2, zuo_set_speed_2);
		TIM9->CCR1= motor[0].out;
		TIM9->CCR2= motor[1].out;
		HAL_Delay(50);
if(((HAL_GPIO_ReadPin(huidu11_GPIO_Port,huidu11_Pin)) == 1 ||(HAL_GPIO_ReadPin(huidu17_GPIO_Port,huidu17_Pin)) == 1)&&(angle1>70||angle2>70))
{
	car_go_ahead();
   break;
}


else if ( (HAL_GPIO_ReadPin(huidu13_GPIO_Port,huidu13_Pin)) == 0 &&(HAL_GPIO_ReadPin(huidu14_GPIO_Port,huidu14_Pin)) == 1 && (HAL_GPIO_ReadPin(huidu15_GPIO_Port,huidu15_Pin)) == 0 
||	(HAL_GPIO_ReadPin(huidu13_GPIO_Port,huidu13_Pin)) == 1 &&(HAL_GPIO_ReadPin(huidu14_GPIO_Port,huidu14_Pin)) == 1 && (HAL_GPIO_ReadPin(huidu15_GPIO_Port,huidu15_Pin)) == 1 )
{
	//直走
	you_set_speed_1 = 60;
	zuo_set_speed_2 = 60;
	car_go_straight();
}
else if ( (HAL_GPIO_ReadPin(huidu13_GPIO_Port,huidu13_Pin)) == 1 &&(HAL_GPIO_ReadPin(huidu14_GPIO_Port,huidu14_Pin)) == 0 && (HAL_GPIO_ReadPin(huidu15_GPIO_Port,huidu15_Pin)) == 0||
					(HAL_GPIO_ReadPin(huidu12_GPIO_Port,huidu12_Pin)) == 1)
{
	//右转
	you_set_speed_1 = 60;
	zuo_set_speed_2 = 25;
	car_go_straight();
}
else if((HAL_GPIO_ReadPin(huidu13_GPIO_Port,huidu13_Pin)) == 0 &&(HAL_GPIO_ReadPin(huidu14_GPIO_Port,huidu14_Pin)) == 0 && (HAL_GPIO_ReadPin(huidu15_GPIO_Port,huidu15_Pin)) == 1 ||
				(HAL_GPIO_ReadPin(huidu16_GPIO_Port,huidu16_Pin)) == 1  )
{
	//左转
	you_set_speed_1 = 25;
	zuo_set_speed_2 = 60;
	car_go_straight();
}
else
{
//
	you_set_speed_1 = 60;
	zuo_set_speed_2 = 60;
	car_go_straight();
}
}

}
void Tracking6(void)
{
PID_clear(&motor[0]);
PID_clear(&motor[1]);
angle1 =0;
	angle2=0;
		Tracking_Init();
	
while(1)
{	
    speed1 = GetEncoderSpeed(TIM3->CNT);
	  angle1+=speed1;
		TIM3->CNT=0;
  	angle2+=speed2;
    speed2 = GetEncoderSpeed(TIM1->CNT);
		TIM1->CNT=0;
		feedback_1 = speed1;//右轮
		feedback_2 = speed2;

		PID_calc(&motor[0], feedback_1, you_set_speed_1);
		PID_calc(&motor[1], feedback_2, zuo_set_speed_2);
		TIM9->CCR1= motor[0].out;
		TIM9->CCR2= motor[1].out;
		HAL_Delay(50);
if((((HAL_GPIO_ReadPin(huidu22_GPIO_Port,huidu22_Pin)) == 1 )&&(HAL_GPIO_ReadPin(huidu25_GPIO_Port,huidu25_Pin) == 1)&&(HAL_GPIO_ReadPin(huidu24_GPIO_Port,huidu24_Pin) == 1))&&(angle1>2850||angle2>2850))
{
		angle1=0;
		angle2=0;
		car_go_ahead();
   break;
	
}


else if ( (HAL_GPIO_ReadPin(huidu13_GPIO_Port,huidu13_Pin)) == 0 &&(HAL_GPIO_ReadPin(huidu14_GPIO_Port,huidu14_Pin)) == 1 && (HAL_GPIO_ReadPin(huidu15_GPIO_Port,huidu15_Pin)) == 0 
||	(HAL_GPIO_ReadPin(huidu13_GPIO_Port,huidu13_Pin)) == 1 &&(HAL_GPIO_ReadPin(huidu14_GPIO_Port,huidu14_Pin)) == 1 && (HAL_GPIO_ReadPin(huidu15_GPIO_Port,huidu15_Pin)) == 1 )
{
	//直走
	you_set_speed_1 = 60;
	zuo_set_speed_2 = 60;
	car_go_straight();
}
else if ( (HAL_GPIO_ReadPin(huidu13_GPIO_Port,huidu13_Pin)) == 1 &&(HAL_GPIO_ReadPin(huidu14_GPIO_Port,huidu14_Pin)) == 0 && (HAL_GPIO_ReadPin(huidu15_GPIO_Port,huidu15_Pin)) == 0||
					(HAL_GPIO_ReadPin(huidu12_GPIO_Port,huidu12_Pin)) == 1)
{
	//右转
	you_set_speed_1 = 50;
	zuo_set_speed_2 = 25;
	car_go_straight();
}
else if((HAL_GPIO_ReadPin(huidu13_GPIO_Port,huidu13_Pin)) == 0 &&(HAL_GPIO_ReadPin(huidu14_GPIO_Port,huidu14_Pin)) == 0 && (HAL_GPIO_ReadPin(huidu15_GPIO_Port,huidu15_Pin)) == 1 ||
				(HAL_GPIO_ReadPin(huidu16_GPIO_Port,huidu16_Pin)) == 1  )
{
	//左转
	you_set_speed_1 = 25;
	zuo_set_speed_2 = 50;
	car_go_straight();
}
else
{
//
	you_set_speed_1 = 60;
	zuo_set_speed_2 = 60;
	car_go_straight();
}
}

}
	

