#ifndef __BSP_PID_H
#define	__BSP_PID_H
#include "stm32f4xx.h"
#include "./usart/bsp_debug_usart.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    float target_val;           //目标值
    float actual_val;        		//实际值
    float err;             			//定义偏差值
    float err_last;          		//定义上一个偏差值
    float Kp,Ki,Kd;          		//定义比例、积分、微分系数
    float integral;          		//定义积分值
}_pid;

extern void PID_param_init(void);
extern float PID_realize(float temp_val);
extern void time_period_fun(void);

#endif
