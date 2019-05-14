#include "Task.h"

void led1_thread_entry(void* parameter)
{

	while (1)
	{
		TogglePin(LED1);
		//rt_kprintf("led1_thread running\r\n");
		rt_thread_delay(100);
	}
}
void led2_thread_entry(void* parameter)
{

	while(1)
	{
		TogglePin(LED2);
		//rt_kprintf("led2_thread running\r\n");
		rt_thread_delay(150);
	}
}





