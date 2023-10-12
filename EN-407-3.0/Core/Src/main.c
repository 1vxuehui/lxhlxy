/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Track.h"
#include "motor.h"
#include "duoji.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* USER CODE BEGIN 4 */

/* USER CODE END 4 */


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
//fp32 feedback_1;
//fp32 feedback_2;
//fp32 set_speed_1;
//fp32 set_speed_2;



float H,L,R,G,B;
int color;
float max,min;
//pid_type_def motor[2];-
//const static fp32 motor_speed_pid[3] = {MOTOR_SPEED_PID_KP, MOTOR_SPEED_PID_KI, MOTOR_SPEED_PID_KD};
//const static fp32 motor_angle_pid[3] = {MOTOR_ANGLE_PID_KP,MOTOR_ANGLE_PID_KI, MOTOR_ANGLE_PID_KD};
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART6_UART_Init();
  MX_TIM1_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_TIM5_Init();
  MX_TIM6_Init();
  MX_TIM2_Init();
  MX_TIM9_Init();
  /* USER CODE BEGIN 2 */
	MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART6_UART_Init();
  MX_TIM1_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_TIM5_Init();
  MX_TIM6_Init();
  MX_TIM2_Init();
	//两个电机初始化pid
//PID_init(&motor[0],PID_POSITION,motor_speed_pid,40, 100);
//PID_init(&motor[1],PID_POSITION,motor_speed_pid,40, 100);

	
HAL_TIM_PWM_Start(&htim9,TIM_CHANNEL_1);
HAL_TIM_PWM_Start(&htim9,TIM_CHANNEL_2);
HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_1);
HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_2);
HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_3);
HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_4);
HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);
HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);

HAL_TIM_Base_Start_IT(&htim6);
whitebalance();
HAL_Delay(3000);
/* USER CODE END 2 */

  /* Infini__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_3,1000);te loop */

  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */	
HAL_Delay(1000);
		
	}  
  /* USER CODE END 3 */
}
//Tracking();
//HAL_Delay(1000);
//MG90S_Rotate_down4();
//HAL_Delay(100);
//DISC_Rotate_Anticlockwise(500);
//HAL_Delay(1000);
//color=rgb();
//if(color==1)//C线
//	{
//		DISC_Rotate_Clockwise(1000);
//		Trackinghou();
//		HAL_Delay(1000);
//		Tracking2();
//		HAL_Delay(100);
//		zuozhuan2();
//		HAL_Delay(100);
//		Tracking();
//		HAL_Delay(100);
//		Tracking3();
//		tuituitui();
//		HAL_Delay(1000);
//		Tracking5();
//		MG90S_Rotate_up4();
//		HAL_Delay(1000);
//		Trackinghou();
//		Tracking2();
//		HAL_Delay(100);
//		youzhuan2();
//		DISC_Rotate_Anticlockwise(105);
//	}
//else if(color==2)
//	{
//		DISC_Rotate_Clockwise(1000);
//		Trackinghou();
//		HAL_Delay(1000);
//		Tracking2();
//		HAL_Delay(100);
//		zuozhuan1();
//		HAL_Delay(100);
//		Tracking();
//		HAL_Delay(100);
//		Tracking3();
//		tuituitui();
//		HAL_Delay(1000);
//		Tracking5();
//		MG90S_Rotate_up4();
//		HAL_Delay(1000);
//		Trackinghou();
//		Tracking2();
//		HAL_Delay(100);
//		youzhuan1();
//		DISC_Rotate_Anticlockwise(105);
//	}
//else if(color==3)
//	{
//		DISC_Rotate_Clockwise(1000);
//		HAL_Delay(1000);
//		Tracking3();
//		tuituitui();
//		HAL_Delay(1000);
//		Tracking5();
//		MG90S_Rotate_up4();
//		HAL_Delay(1000);
//		Trackinghou();
//		Tracking2();
//		DISC_Rotate_Anticlockwise(105);
//	}
//else if(color==4)
//	{
//		DISC_Rotate_Clockwise(1000);
//		Trackinghou();
//		HAL_Delay(1000);
//		Tracking2();
//		HAL_Delay(100);
//		youzhuan1();
//		HAL_Delay(100);
//		Tracking();
//		HAL_Delay(100);
//		Tracking3();
//		tuituitui();
//		HAL_Delay(1000);
//		Tracking5();
//		MG90S_Rotate_up4();
//		HAL_Delay(1000);
//		Trackinghou();
//		Tracking2();
//		HAL_Delay(100);
//		zuozhuan1();
//		DISC_Rotate_Anticlockwise(105);
//	}
//else if(color==5)
//	{
//		DISC_Rotate_Clockwise(1000);
//		Trackinghou();
//		HAL_Delay(1000);
//		Tracking2();
//		HAL_Delay(100);
//		youzhuan2();
//		HAL_Delay(100);
//		Tracking();
//		HAL_Delay(100);
//		Tracking3();
//		tuituitui();
//		HAL_Delay(1000);
//		Tracking5();
//		MG90S_Rotate_up4();
//		HAL_Delay(1000);
//		Trackinghou();
//		Tracking2();
//		HAL_Delay(100);
//		zuozhuan2();
//		DISC_Rotate_Anticlockwise(105);
//	}
//	
//	
//	
//HAL_Delay(1000);
//youzhuan2();
//HAL_Delay(1000);
//Tracking();
//HAL_Delay(1000);
//MG90S_Rotate_down4();
//HAL_Delay(100);
//DISC_Rotate_Anticlockwise(500);
//HAL_Delay(1000);
//color=rgb();
//if(color==1)//E线
//	{
//		DISC_Rotate_Clockwise(1000);
//		Trackinghou();
//		HAL_Delay(1000);
//		Tracking2();
//		HAL_Delay(100);
//		zuozhuan2();
//		HAL_Delay(100);
//		zuozhuan2();
//		HAL_Delay(100);
//		Tracking();
//		HAL_Delay(100);
//		Tracking3();
//		tuituitui();
//		HAL_Delay(1000);
//		Tracking5();
//		MG90S_Rotate_up4();
//		HAL_Delay(1000);
//		Trackinghou();
//		Tracking2();
//		HAL_Delay(100);
//		youzhuan2();
//		DISC_Rotate_Anticlockwise(105);
//	}
//else if(color==2)
//	{
//		DISC_Rotate_Clockwise(1000);
//		Trackinghou();
//		HAL_Delay(1000);
//		Tracking2();
//		HAL_Delay(100);
//		zuozhuan2();
//		HAL_Delay(100);
//		zuozhuan1();
//		HAL_Delay(100);
//		Tracking();
//		HAL_Delay(100);
//		Tracking3();
//		tuituitui();
//		HAL_Delay(1000);
//		Tracking5();
//		MG90S_Rotate_up4();
//		HAL_Delay(1000);
//		Trackinghou();
//		Tracking2();
//		HAL_Delay(100);
//		youzhuan1();
//		DISC_Rotate_Anticlockwise(105);
//	}
//else if(color==3)
//	{
//		DISC_Rotate_Clockwise(1000);
//		Trackinghou();
//		HAL_Delay(1000);
//		Tracking2();
//		HAL_Delay(100);
//		zuozhuan2();
//		HAL_Delay(100);
//		Tracking();
//		HAL_Delay(100);
//		Tracking3();
//		tuituitui();
//		HAL_Delay(1000);
//		Tracking5();
//		MG90S_Rotate_up4();
//		HAL_Delay(1000);
//		Trackinghou();
//		Tracking2();
//		HAL_Delay(100);
//		DISC_Rotate_Anticlockwise(105);
//	}
//else if(color==4)
//	{
//		DISC_Rotate_Clockwise(1000);
//		Trackinghou();
//		HAL_Delay(1000);
//		Tracking2();
//		HAL_Delay(100);
//		zuozhuan1();
//		HAL_Delay(100);
//		Tracking();
//		HAL_Delay(100);
//		Tracking3();
//		tuituitui();
//		HAL_Delay(1000);
//		Tracking5();
//		MG90S_Rotate_up4();
//		HAL_Delay(1000);
//		Trackinghou();
//		Tracking2();
//		HAL_Delay(100);
//		zuozhuan1();
//		DISC_Rotate_Anticlockwise(105);
//	}
//else if(color==5)
//	{
//		DISC_Rotate_Clockwise(1000);
//		HAL_Delay(1000);
//		Tracking3();
//		tuituitui();
//		HAL_Delay(1000);
//		Tracking5();
//		MG90S_Rotate_up4();
//		HAL_Delay(1000);
//		Trackinghou();
//		Tracking2();
//		HAL_Delay(100);
//		zuozhuan2();
//		DISC_Rotate_Anticlockwise(105);
//	}
//	
//	
//	
//HAL_Delay(1000);
//zuozhuan2();
//HAL_Delay(1000);
//Tracking();
//HAL_Delay(1000);
//MG90S_Rotate_down4();
//HAL_Delay(100);
//DISC_Rotate_Anticlockwise(500);
//HAL_Delay(1000);
//color=rgb();	
//if(color==1)//A线
//	{
//		DISC_Rotate_Clockwise(1000);
//		HAL_Delay(1000);
//		Tracking3();
//		tuituitui();
//		HAL_Delay(1000);
//		Tracking5();
//		MG90S_Rotate_up4();
//		HAL_Delay(1000);
//		Trackinghou();
//		Tracking2();
//		HAL_Delay(100);
//		youzhuan2();
//		DISC_Rotate_Anticlockwise(105);
//	}
//else if(color==2)
//	{
//		DISC_Rotate_Clockwise(1000);
//		Trackinghou();
//		HAL_Delay(1000);
//		Tracking2();
//		HAL_Delay(100);
//		youzhuan1();
//		HAL_Delay(100);
//		Tracking();
//		HAL_Delay(100);
//		Tracking3();
//		tuituitui();
//		HAL_Delay(1000);
//		Tracking5();
//		MG90S_Rotate_up4();
//		HAL_Delay(1000);
//		Trackinghou();
//		Tracking2();
//		HAL_Delay(100);
//		youzhuan1();
//		DISC_Rotate_Anticlockwise(105);
//	}
//else if(color==3)
//	{
//		DISC_Rotate_Clockwise(1000);
//		Trackinghou();
//		HAL_Delay(1000);
//		Tracking2();
//		HAL_Delay(100);
//		youzhuan2();
//		HAL_Delay(100);
//		Tracking();
//		HAL_Delay(100);
//		Tracking3();
//		tuituitui();
//		HAL_Delay(1000);
//		Tracking5();
//		MG90S_Rotate_up4();
//		HAL_Delay(1000);
//		Trackinghou();
//		Tracking2();
//		HAL_Delay(100);
//		DISC_Rotate_Anticlockwise(105);
//	}
//else if(color==4)
//	{
//		DISC_Rotate_Clockwise(1000);
//		Trackinghou();
//		HAL_Delay(1000);
//		Tracking2();
//		HAL_Delay(100);
//		youzhuan2();
//		HAL_Delay(100);
//		youzhuan1();
//		HAL_Delay(100);
//		Tracking();
//		HAL_Delay(100);
//		Tracking3();
//		tuituitui();
//		HAL_Delay(1000);
//		Tracking5();
//		MG90S_Rotate_up4();
//		HAL_Delay(1000);
//		Trackinghou();
//		Tracking2();
//		HAL_Delay(100);
//		zuozhuan1();
//		DISC_Rotate_Anticlockwise(105);
//	}
//else if(color==5)
//	{
//		DISC_Rotate_Clockwise(1000);
//		Trackinghou();
//		HAL_Delay(1000);
//		Tracking2();
//		HAL_Delay(100);
//		youzhuan2();
//		HAL_Delay(100);
//		youzhuan2();
//		HAL_Delay(100);
//		Tracking();
//		HAL_Delay(100);
//		Tracking3();
//		tuituitui();
//		HAL_Delay(1000);
//		Tracking5();
//		MG90S_Rotate_up4();
//		HAL_Delay(1000);
//		Trackinghou();
//		Tracking2();
//		HAL_Delay(100);
//		zuozhuan2();
//		DISC_Rotate_Anticlockwise(105);
//	}
//	Tracking4();
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 72;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
