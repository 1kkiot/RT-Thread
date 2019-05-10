#ifndef _uart_h
#define _uart_h

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f1xx_hal.h"
#include "Sys.h"

void MX_USART1_UART_Init(void);
extern UART_HandleTypeDef huart1;



#ifdef __cplusplus
}
#endif

#endif

