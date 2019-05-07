#ifndef _task_h
#define _task_h
#include <rthw.h>
#include <rtthread.h>
#include "arm_base_define.h"
#include "SysGpio.h"
#include "uart.h"
#include "runtask.h"
int task_init(void);
extern rt_thread_t led1_thread;
extern rt_thread_t led2_thread;


#endif

