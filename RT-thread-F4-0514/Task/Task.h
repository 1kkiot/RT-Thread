#ifndef _task_h
#define _task_h
#include <rthw.h>
#include <rtthread.h>
#include "arm_base_define.h"
#include "SysGpio.h"
void led1_thread_entry(void* parameter);
void led2_thread_entry(void* parameter);

#endif

