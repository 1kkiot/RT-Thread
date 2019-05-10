#include "SysGpio.h"

void MX_GPIO_Init(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOG_CLK_ENABLE();

	SET_GPIO_OUT(LED1);
	SET_GPIO_OUT(LED2);
	SET_GPIO_OUT(LED3);
	SET_GPIO_OUT(LED4);
	SET_GPIO_OUT(LED5);
	SET_GPIO_OUT(LED6);
	SET_GPIO_OUT(LED7);
	SET_GPIO_OUT(CS);

	SET_GPIO_H(LED1);
	SET_GPIO_H(LED2);
	SET_GPIO_H(LED3);
	SET_GPIO_H(LED4);
	SET_GPIO_H(LED5);
	SET_GPIO_H(LED6);
	SET_GPIO_H(LED7);
	SET_GPIO_H(CS);
}

void Set_GPIO_PIN(GPIO_TypeDef *gpio, uint16_t nPin,uint32_t mode,uint32_t speed)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	HAL_GPIO_WritePin(gpio, nPin, GPIO_PIN_RESET);
	GPIO_InitStruct.Pin = nPin;
	GPIO_InitStruct.Mode = mode;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = speed;
	HAL_GPIO_Init(gpio, &GPIO_InitStruct);
}












