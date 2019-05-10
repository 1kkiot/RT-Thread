#include "runtask.h"
#include "testw25qxx.h"

void led1_thread_entry(void* parameter)
{
	spi_flash_test();
	while (1)
	{
		TogglePin(LED1);
		HAL_Delay(20000);
		//rt_kprintf("led1_thread running\r\n");
		//rt_thread_delay(100);
	}
}
void led2_thread_entry(void* parameter)
{
	//W25qxx_Init();
	spi_flash_test();
	while(1)
	{
		TogglePin(LED2);
		//spi_flash_test();
		//rt_kprintf("led2_thread running\r\n");
		rt_thread_delay(500);
	}
}





