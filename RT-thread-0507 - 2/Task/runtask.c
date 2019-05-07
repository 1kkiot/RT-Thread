#include "runtask.h"

void led1_thread_entry(void* parameter)
{
	u8 i = 0;
	while (1)
	{
		i++;
		if(i >= 20)
		{
			rt_thread_suspend(led2_thread);//挂起任务二
		}
		if(i >= 50)
		{
			i=0;
			rt_thread_resume(led2_thread);
		}
		TogglePin(LED1);
		//rt_kprintf("led1_thread running = %04d\r\n",i);
		rt_thread_delay(100);
	}
}
void led2_thread_entry(void* parameter)
{
	while(1)
	{
		TogglePin(LED2);
		//rt_kprintf("led2_thread running\r\n");
		rt_thread_delay(200);
	}
}





