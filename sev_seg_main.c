/* USER CODE BEGIN Header
 *
 * 		AUTHOR - TUSHAR GUPTA
 * 		DATE   - 23/6/21
 * 		WEEK   - 2
 *  ASSIGNMENT - 1
 *
 *  Connection to seven segment display COMMON CATHODE
 *  PA0- a_Pin - LEDs 'a'th pin
 *  PA1- b_Pin - LEDs 'b'th pin
 *  PA2- c_Pin - LEDs 'c'th pin
 *  PA3- d_Pin - LEDs 'd'th pin
 *  PA4- e_Pin - LEDs 'e'th pin
 *  PA5- f_Pin - LEDs 'f'th pin
 *  PA6- g_Pin - LEDs 'g'th pin
 *  PA7- dp_Pin - LEDs 'dp'th pin
 *
 * */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void glowLed(int);
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

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

	int i=0;

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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

	  glowLed(i);
	  HAL_Delay(1000);
	  i++;
	  if(i==10)
		  i=0;

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

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
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 84;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
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

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, a_Pin|b_Pin|c_Pin|d_Pin
                          |e_Pin|f_Pin|g_Pin|dp_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : a_Pin b_Pin c_Pin d_Pin
                           e_Pin f_Pin g_Pin dp_Pin */
  GPIO_InitStruct.Pin = a_Pin|b_Pin|c_Pin|d_Pin
                          |e_Pin|f_Pin|g_Pin|dp_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

void glowLed(int x)
{
	// display 0
	if(x==0)
	{
		HAL_GPIO_WritePin(GPIOA, a_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, b_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, c_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, d_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, e_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, f_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, g_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, dp_Pin, GPIO_PIN_RESET);
	}
	// display 1
	if(x==1)
		{
			HAL_GPIO_WritePin(GPIOA, a_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, c_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, d_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, e_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, f_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, g_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, dp_Pin, GPIO_PIN_RESET);
		}
	// display 2
	if(x==2)
		{
			HAL_GPIO_WritePin(GPIOA, a_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, c_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, d_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, e_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, f_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, g_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, dp_Pin, GPIO_PIN_RESET);
		}
	// display 3
	if(x==3)
		{
			HAL_GPIO_WritePin(GPIOA, a_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, c_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, d_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, e_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, f_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, g_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, dp_Pin,GPIO_PIN_RESET);
		}
	// display 4
	if(x==4)
		{
			HAL_GPIO_WritePin(GPIOA, a_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, c_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, d_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, e_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, f_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, g_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, dp_Pin, GPIO_PIN_RESET);
		}
	// display 5
	if(x==5)
		{
			HAL_GPIO_WritePin(GPIOA, a_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, c_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, d_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, e_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, f_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, g_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, dp_Pin, GPIO_PIN_RESET);
		}
	// display 6
	if(x==6)
		{
			HAL_GPIO_WritePin(GPIOA, a_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, c_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, d_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, e_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, f_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, g_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, dp_Pin,GPIO_PIN_RESET);
		}
	// display 7
	if(x==7)
		{
			HAL_GPIO_WritePin(GPIOA, a_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, c_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, d_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, e_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, f_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, g_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, dp_Pin, GPIO_PIN_RESET);
		}
	// display 8
	if(x==8)
		{
			HAL_GPIO_WritePin(GPIOA, a_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, c_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, d_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, e_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, f_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, g_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, dp_Pin, GPIO_PIN_RESET);
		}
	// display 9
	if(x==9)
		{
			HAL_GPIO_WritePin(GPIOA, a_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, c_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, d_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, e_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, f_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, g_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, dp_Pin, GPIO_PIN_RESET);
		}

}

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
