#ifndef _sys_gpio_h
#define _sys_gpio_h
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"

#define		LED1						GPIOC
#define		LED1_PIN					GPIO_PIN_0
#define		LED2						GPIOC
#define		LED2_PIN					GPIO_PIN_1
#define		LED3						GPIOC
#define		LED3_PIN					GPIO_PIN_2
#define		LED4						GPIOC
#define		LED4_PIN					GPIO_PIN_3
#define		LED5						GPIOC
#define		LED5_PIN					GPIO_PIN_4
#define		LED6						GPIOC
#define		LED6_PIN					GPIO_PIN_5
#define		LED7						GPIOC
#define		LED7_PIN					GPIO_PIN_6
#define		LED8						GPIOC
#define		LED8_PIN					GPIO_PIN_7


#define 	SET_GPIO_OUT(x)				Set_GPIO_PIN(x,x##_PIN,GPIO_MODE_OUTPUT_PP,GPIO_SPEED_FREQ_LOW)
#define 	SET_GPIO_IN(x)				Set_GPIO_PIN(x,x##_PIN,GPIO_MODE_INPUT,GPIO_SPEED_FREQ_LOW)

#define 	SET_GPIO_H(x)               (x->BSRR = x##_PIN)
#define 	SET_GPIO_L(x)               (x->BRR  = x##_PIN)
#define		TogglePin(x)				(x->ODR ^= (x##_PIN))

#define 	READ_GPIO_PIN(x)			(((x->IDR & x##_PIN)!= GPIO_PIN_RESET) ? 1 : 0) 

void MX_GPIO_Init(void);
void Set_GPIO_PIN(GPIO_TypeDef *gpio, uint16_t nPin,uint32_t mode,uint32_t speed);
#endif





