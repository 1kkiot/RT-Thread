#include "Sys.h"
#include "stm32f1xx_hal.h"
//void HAL_MspInit(void)
//{
//    HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
//    /* System interrupt init*/
//    __HAL_RCC_AFIO_CLK_ENABLE();
//    /* MemoryManagement_IRQn interrupt configuration */
//    HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
//    /* BusFault_IRQn interrupt configuration */
//    HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
//    /* UsageFault_IRQn interrupt configuration */
//    HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);
//    /* SVCall_IRQn interrupt configuration */
//    HAL_NVIC_SetPriority(SVCall_IRQn, 0, 0);
//    /* DebugMonitor_IRQn interrupt configuration */
//    HAL_NVIC_SetPriority(DebugMonitor_IRQn, 0, 0);
//    /* PendSV_IRQn interrupt configuration */
//    HAL_NVIC_SetPriority(PendSV_IRQn, 15, 0);
//    /* SysTick_IRQn interrupt configuration */
//    HAL_NVIC_SetPriority(SysTick_IRQn, 15, 0);
//    /**DISABLE: JTAG-DP Disabled and SW-DP Disabled**/
//    __HAL_AFIO_REMAP_SWJ_NOJTAG();
//}


//void SystemClock_Config(void)
//{

//	RCC_OscInitTypeDef RCC_OscInitStruct;
//	RCC_ClkInitTypeDef RCC_ClkInitStruct;

//	/**Initializes the CPU, AHB and APB busses clocks 
//	*/
//	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
//	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
//	RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
//	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
//	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
//	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
//	RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
//	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
//	{
//		_Error_Handler(__FILE__, __LINE__);
//	}

//	/**Initializes the CPU, AHB and APB busses clocks 
//	*/
//	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
//							  |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
//	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
//	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
//	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
//	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

//	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
//	{
//		_Error_Handler(__FILE__, __LINE__);
//	}

//	/**Configure the Systick interrupt time 
//	*/
//	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

//	/**Configure the Systick 
//	*/
//	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

//	/* SysTick_IRQn interrupt configuration */
//	HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
//}
/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}





