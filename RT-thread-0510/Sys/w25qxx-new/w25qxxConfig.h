#ifndef _W25QXXCONFIG_H
#define _W25QXXCONFIG_H

#define		FLASH_CS_GPIO_Port			GPIOG
#define		FLASH_CS_Pin				GPIO_PIN_13
#define		_W25QXX_SPI										hspi2
#define		_W25QXX_CS_GPIO									FLASH_CS_GPIO_Port
#define		_W25QXX_CS_PIN									FLASH_CS_Pin
#define		_W25QXX_USE_FREERTOS							0
#define		_W25QXX_DEBUG									1
#endif
