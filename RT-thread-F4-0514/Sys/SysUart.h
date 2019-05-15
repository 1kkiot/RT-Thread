#ifndef _sys_uart_h
#define _sys_uart_h
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_usart.h"
#include "arm_base_define.h"

extern UART_HandleTypeDef huart1;

void MX_USART1_UART_Init(void);
int hw_usart_init(void);
void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle);
void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle);


#endif



