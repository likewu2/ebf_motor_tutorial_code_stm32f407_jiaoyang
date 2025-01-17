/**
  ******************************************************************************
  * @file    bsp_motor_tim.c
  * @author  long
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   电机相关定时器配置
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火  STM32 F407 开发板  
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "./tim/bsp_motor_tim.h"
#include "./led/bsp_led.h"
#include "./usart/bsp_debug_usart.h"

TIM_HandleTypeDef  htimx_bldcm;
TIM_OC_InitTypeDef TIM_OCInitStructure;

/* 霍尔传感器相关定时器初始出 */
TIM_HandleTypeDef htimx_hall;

static uint16_t bldcm_pulse = 0;

/**
  * @brief  配置TIM复用输出PWM时用到的I/O
  * @param  无
  * @retval 无
  */
static void TIMx_GPIO_Config(void) 
{
  /*定义一个GPIO_InitTypeDef类型的结构体*/
  GPIO_InitTypeDef GPIO_InitStructure;

  /*开启定时器相关的GPIO外设时钟*/
  MOTOR_OCPWM1_GPIO_CLK_ENABLE();
  MOTOR_OCNPWM1_GPIO_CLK_ENABLE();
  MOTOR_OCPWM2_GPIO_CLK_ENABLE();
  MOTOR_OCNPWM2_GPIO_CLK_ENABLE();
  MOTOR_OCPWM3_GPIO_CLK_ENABLE();
  MOTOR_OCNPWM3_GPIO_CLK_ENABLE();

  /* 定时器功能引脚初始化 */															   
  GPIO_InitStructure.Pull = GPIO_NOPULL;
  GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;   // 推挽输出模式

  GPIO_InitStructure.Pin = MOTOR_OCNPWM1_PIN;
  HAL_GPIO_Init(MOTOR_OCNPWM1_GPIO_PORT, &GPIO_InitStructure);	

  GPIO_InitStructure.Pin = MOTOR_OCNPWM2_PIN;	
  HAL_GPIO_Init(MOTOR_OCNPWM2_GPIO_PORT, &GPIO_InitStructure);

  GPIO_InitStructure.Pin = MOTOR_OCNPWM3_PIN;	
  HAL_GPIO_Init(MOTOR_OCNPWM3_GPIO_PORT, &GPIO_InitStructure);	

  /* 通道 2 */
  GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;  

  GPIO_InitStructure.Pin = MOTOR_OCPWM1_PIN;
  GPIO_InitStructure.Alternate = MOTOR_OCPWM1_AF;	
  HAL_GPIO_Init(MOTOR_OCPWM1_GPIO_PORT, &GPIO_InitStructure);

  GPIO_InitStructure.Pin = MOTOR_OCPWM2_PIN;	
  GPIO_InitStructure.Alternate = MOTOR_OCPWM2_AF;	
  HAL_GPIO_Init(MOTOR_OCPWM2_GPIO_PORT, &GPIO_InitStructure);

  /* 通道 3 */
  GPIO_InitStructure.Pin = MOTOR_OCPWM3_PIN;	
  GPIO_InitStructure.Alternate = MOTOR_OCPWM3_AF;	
  HAL_GPIO_Init(MOTOR_OCPWM3_GPIO_PORT, &GPIO_InitStructure);
}

/*
 * 注意：TIM_TimeBaseInitTypeDef结构体里面有5个成员，TIM6和TIM7的寄存器里面只有
 * TIM_Prescaler和TIM_Period，所以使用TIM6和TIM7的时候只需初始化这两个成员即可，
 * 另外三个成员是通用定时器和高级定时器才有.
 *-----------------------------------------------------------------------------
 * TIM_Prescaler         都有
 * TIM_CounterMode			 TIMx,x[6,7]没有，其他都有（基本定时器）
 * TIM_Period            都有
 * TIM_ClockDivision     TIMx,x[6,7]没有，其他都有(基本定时器)
 * TIM_RepetitionCounter TIMx,x[1,8]才有(高级定时器)
 *-----------------------------------------------------------------------------
 */
static void TIM_Mode_Config(void)
{
  // 开启TIMx_CLK,x[1,8] 
  MOTOR_TIM_CLK_ENABLE(); 
  /* 定义定时器的句柄即确定定时器寄存器的基地址*/
  htimx_bldcm.Instance = MOTOR_TIM;
  /* 累计 TIM_Period个后产生一个更新或者中断*/		
  //当定时器从0计数到999，即为1000次，为一个定时周期
  htimx_bldcm.Init.Period = PWM_PERIOD_COUNT - 1;
  // 高级控制定时器时钟源TIMxCLK = HCLK=216MHz 
  // 设定定时器频率为=TIMxCLK/(TIM_Prescaler+1)=1MHz
  htimx_bldcm.Init.Prescaler = PWM_PRESCALER_COUNT - 1;	
  // 采样时钟分频
  htimx_bldcm.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;
  // 计数方式
  htimx_bldcm.Init.CounterMode=TIM_COUNTERMODE_UP;
  // 重复计数器
  htimx_bldcm.Init.RepetitionCounter=0;	
  // 初始化定时器TIMx, x[1,8]
  HAL_TIM_PWM_Init(&htimx_bldcm);

  /*PWM模式配置*/
  //配置为PWM模式1
  TIM_OCInitStructure.OCMode = TIM_OCMODE_PWM1;
  TIM_OCInitStructure.Pulse = 0;                         // 默认必须要初始为0
  TIM_OCInitStructure.OCPolarity = TIM_OCPOLARITY_HIGH;
  TIM_OCInitStructure.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  TIM_OCInitStructure.OCIdleState = TIM_OCIDLESTATE_SET;
  TIM_OCInitStructure.OCNIdleState = TIM_OCNIDLESTATE_RESET;

  HAL_TIM_PWM_ConfigChannel(&htimx_bldcm,&TIM_OCInitStructure,TIM_CHANNEL_1);    // 初始化通道 1 输出 PWM 
  HAL_TIM_PWM_ConfigChannel(&htimx_bldcm,&TIM_OCInitStructure,TIM_CHANNEL_2);    // 初始化通道 2 输出 PWM
  HAL_TIM_PWM_ConfigChannel(&htimx_bldcm,&TIM_OCInitStructure,TIM_CHANNEL_3);    // 初始化通道 3 输出 PWM
  
  /* 配置触发源 */
  HAL_TIMEx_ConfigCommutationEvent(&htimx_bldcm, TIM_COM_TS_ITRx, TIM_COMMUTATION_SOFTWARE);

  /* 开启定时器通道1输出PWM */
  HAL_TIM_PWM_Start(&htimx_bldcm,TIM_CHANNEL_1);

  /* 开启定时器通道2输出PWM */
  HAL_TIM_PWM_Start(&htimx_bldcm,TIM_CHANNEL_2);

  /* 开启定时器通道3输出PWM */
  HAL_TIM_PWM_Start(&htimx_bldcm,TIM_CHANNEL_3);
}

/**
  * @brief  停止pwm输出
  * @param  无
  * @retval 无
  */
void stop_pwm_output(void)
{
  /* 关闭定时器通道1输出PWM */
  __HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_1, 0);

  /* 关闭定时器通道2输出PWM */
  __HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_2, 0);
  
  /* 关闭定时器通道3输出PWM */
  __HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_3, 0);
  
  HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_RESET);    // 关闭下桥臂
  HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_RESET);    // 关闭下桥臂
  HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_RESET);    // 关闭下桥臂
}

/**
  * @brief  设置pwm输出的占空比
  * @param  pulse:要设置的占空比
  * @retval 无
  */
void set_pwm_pulse(uint16_t pulse)
{
  /* 设置定时器通道输出 PWM 的占空比 */
	bldcm_pulse = pulse;
}

/**
  * @brief  初始化高级控制定时器
  * @param  无
  * @retval 无
  */
void TIMx_Configuration(void)
{
	TIMx_GPIO_Config();
	TIM_Mode_Config();
}

/**
  * @brief  霍尔传感器引脚初始化
  * @param  无
  * @retval 无
  */
static void hall_gpio_init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  HALL_INPUTU_GPIO_CLK_ENABLE();
  HALL_INPUTV_GPIO_CLK_ENABLE();
  HALL_INPUTW_GPIO_CLK_ENABLE();
  
  /* 定时器通道 1 引脚初始化 */
  GPIO_InitStruct.Pin = HALL_INPUTU_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Alternate = HALL_INPUTU_AF;
  HAL_GPIO_Init(HALL_INPUTU_GPIO_PORT, &GPIO_InitStruct);
  
  /* 定时器通道 2 引脚初始化 */
  GPIO_InitStruct.Pin = HALL_INPUTV_PIN;
  HAL_GPIO_Init(HALL_INPUTV_GPIO_PORT, &GPIO_InitStruct);
  
  /* 定时器通道 3 引脚初始化 */
  GPIO_InitStruct.Pin = HALL_INPUTW_PIN;
  HAL_GPIO_Init(HALL_INPUTW_GPIO_PORT, &GPIO_InitStruct);
}

/**
  * @brief  霍尔传感器定时器初始化
  * @param  无
  * @retval 无
  */
static void hall_tim_init(void)
{
  TIM_HallSensor_InitTypeDef  hall_sensor_cfg;  
  
  /* 基本定时器外设时钟使能 */
  HALL_TIM_CLK_ENABLE();
  
  /* 定时器基本功能配置 */
  htimx_hall.Instance = HALL_TIM;
  htimx_hall.Init.Prescaler = HALL_PRESCALER_COUNT - 1;       // 预分频
  htimx_hall.Init.CounterMode = TIM_COUNTERMODE_UP;           // 向上计数
  htimx_hall.Init.Period = HALL_PERIOD_COUNT - 1;             // 计数周期
  htimx_hall.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;     // 时钟分频
  
  hall_sensor_cfg.IC1Prescaler = TIM_ICPSC_DIV1;            // 输入捕获分频
  hall_sensor_cfg.IC1Polarity = TIM_ICPOLARITY_BOTHEDGE;    // 输入捕获极性
  hall_sensor_cfg.IC1Filter = 10;                           // 输入滤波
  hall_sensor_cfg.Commutation_Delay = 0U;                   // 不使用延迟触发
  HAL_TIMEx_HallSensor_Init(&htimx_hall, &hall_sensor_cfg);
  
  HAL_NVIC_SetPriority(HALL_TIM_IRQn, 0, 0);    // 设置中断优先级
  HAL_NVIC_EnableIRQ(HALL_TIM_IRQn);            // 使能中断
}

/**
  * @brief  使能霍尔传感器
  * @param  无
  * @retval 无
  */
void hall_enable(void)
{
  /* 使能霍尔传感器接口 */
  __HAL_TIM_ENABLE_IT(&htimx_hall, TIM_IT_TRIGGER);
  __HAL_TIM_ENABLE_IT(&htimx_hall, TIM_IT_UPDATE);
  
  HAL_TIMEx_HallSensor_Start(&htimx_hall);

  LED1_OFF;
  
  HAL_TIM_TriggerCallback(&htimx_hall);   // 执行一次换相
}

/**
  * @brief  禁用霍尔传感器
  * @param  无
  * @retval 无
  */
void hall_disable(void)
{
  /* 禁用霍尔传感器接口 */
  __HAL_TIM_DISABLE_IT(&htimx_hall, TIM_IT_TRIGGER);
  __HAL_TIM_DISABLE_IT(&htimx_hall, TIM_IT_UPDATE);
  HAL_TIMEx_HallSensor_Stop(&htimx_hall);
}

uint8_t get_hall_state(void)
{
  uint8_t state = 0;
  
#if 1
  /* 读取霍尔传感器 U 的状态 */
  if(HAL_GPIO_ReadPin(HALL_INPUTU_GPIO_PORT, HALL_INPUTU_PIN) != GPIO_PIN_RESET)
  {
    state |= 0x01U << 0;
  }
  
  /* 读取霍尔传感器 V 的状态 */
  if(HAL_GPIO_ReadPin(HALL_INPUTV_GPIO_PORT, HALL_INPUTV_PIN) != GPIO_PIN_RESET)
  {
    state |= 0x01U << 1;
  }
  
  /* 读取霍尔传感器 W 的状态 */
  if(HAL_GPIO_ReadPin(HALL_INPUTW_GPIO_PORT, HALL_INPUTW_PIN) != GPIO_PIN_RESET)
  {
    state |= 0x01U << 2;
  }
#else
  state = (GPIOH->IDR >> 10) & 7;    // 读 3 个霍尔传感器的状态
#endif

  return state;    // 返回传感器状态
}

/**
  * @brief  初始化霍尔传感器定时器
  * @param  无
  * @retval 无
  */
void hall_tim_config(void)
{
	hall_gpio_init();	    // 初始化引脚
	hall_tim_init();      // 初始化定时器
}

int update = 0;     // 定时器更新计数

/**
  * @brief  霍尔传感器触发回调函数
  * @param  htim:定时器句柄
  * @retval 无
  */
void HAL_TIM_TriggerCallback(TIM_HandleTypeDef *htim)
{
  /* 获取霍尔传感器引脚状态,作为换相的依据 */
  uint8_t step = 0;
  step = get_hall_state();

	if(get_bldcm_direction() == MOTOR_FWD)
		{
			switch(step)
			{
				case 1:    /* U+ W- */
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_2, 0);                            // 通道 2 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_RESET);    // 关闭下桥臂
				
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_3, 0);                            // 通道 1 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_RESET);    // 关闭下桥臂

					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_1, bldcm_pulse);                  // 通道 1 配置的占空比
					HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_SET);      // 开启下桥臂
					break;
				
				case 2:     /* V+ U- */
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_3, 0);                            // 通道 3 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_RESET);    // 关闭下桥臂

					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_1, 0);                            // 通道 1 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_RESET);    // 关闭下桥臂
				
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_2, bldcm_pulse);                  // 通道 2 配置的占空比
					HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_SET);      // 开启下桥臂
				
					break;
				
				case 3:    /* V+ W- */
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_1, 0);                            // 通道 1 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_RESET);    // 关闭下桥臂

					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_3, 0);                            // 通道 1 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_RESET);    // 关闭下桥臂
					
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_2, bldcm_pulse);                  // 通道 2 配置的占空比
					HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_SET);      // 开启下桥臂
					break;
				
				case 4:     /* W+ V- */
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_1, 0);                            // 通道 1 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_RESET);    // 关闭下桥臂

					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_2, 0);                            // 通道 1 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_RESET);    // 关闭下桥臂
		 
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_3, bldcm_pulse);                  // 通道 3 配置的占空比
					HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_SET);      // 开启下桥臂 
					break;
				
				case 5:     /* U+  V -*/
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_3, 0);                            // 通道 3 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_RESET);    // 关闭下桥臂
				
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_2, 0);                            // 通道 1 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_RESET);    // 关闭下桥臂
				
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_1, bldcm_pulse);                  // 通道 1 配置的占空比
					HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_SET);      // 开启下桥臂
					break;
				
				case 6:     /* W+ U- */
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_2, 0);                            // 通道 2 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_RESET);    // 关闭下桥臂
				
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_1, 0);                            // 通道 1 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_RESET);    // 关闭下桥臂
				
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_3, bldcm_pulse);                  // 通道 3 配置的占空比
					HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_SET);      // 开启下桥臂
					break;
			}
		}
		else
		{
			switch(step)
			{
				case 1:   /* W+ U- */
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_2, 0);                            // 通道 2 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_RESET);    // 关闭下桥臂
				
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_1, 0);                            // 通道 1 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_RESET);    // 关闭下桥臂
				
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_3, bldcm_pulse);                  // 通道 3 配置的占空比
					HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_SET);      // 开启下桥臂
					break;
				
				case 2:    /* U+  V -*/
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_3, 0);                            // 通道 3 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_RESET);    // 关闭下桥臂
				
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_2, 0);                            // 通道 1 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_RESET);    // 关闭下桥臂
				
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_1, bldcm_pulse);                  // 通道 1 配置的占空比
					HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_SET);      // 开启下桥臂
					break;
				
				case 3:   /* W+ V- */
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_1, 0);                            // 通道 1 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_RESET);    // 关闭下桥臂

					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_2, 0);                            // 通道 1 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_RESET);    // 关闭下桥臂
		 
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_3, bldcm_pulse);                  // 通道 3 配置的占空比
					HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_SET);      // 开启下桥臂        

					break;
				
				case 4:    /* V+ W- */
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_1, 0);                            // 通道 1 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_RESET);    // 关闭下桥臂

					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_3, 0);                            // 通道 1 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_RESET);    // 关闭下桥臂
					
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_2, bldcm_pulse);                  // 通道 2 配置的占空比
					HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_SET);      // 开启下桥臂
					break;
				
				case 5:    /* V+ U- */
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_3, 0);                            // 通道 3 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_RESET);    // 关闭下桥臂

					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_1, 0);                            // 通道 1 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_RESET);    // 关闭下桥臂
				
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_2, bldcm_pulse);                  // 通道 2 配置的占空比
					HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_SET);      // 开启下桥臂
					break;
				
				case 6:    /* U+ W- */
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_2, 0);                            // 通道 2 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_RESET);    // 关闭下桥臂
				
					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_3, 0);                            // 通道 1 配置为 0
					HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_RESET);    // 关闭下桥臂

					__HAL_TIM_SET_COMPARE(&htimx_bldcm, TIM_CHANNEL_1, bldcm_pulse);                  // 通道 1 配置的占空比
					HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_SET);      // 开启下桥臂
					break;
			}
		}
  
  HAL_TIM_GenerateEvent(&htimx_bldcm, TIM_EVENTSOURCE_COM);    // 软件产生换相事件，此时才将配置写入

  update = 0;
}

/**
  * @brief  定时器更新中断回调函数
  * @param  htim:定时器句柄
  * @retval 无
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (update++ > 1)    // 有一次在产生更新中断前霍尔传感器没有捕获到值
  {
    printf("堵转超时\r\n");
    update = 0;
    
    LED1_ON;     // 点亮LED1表示堵转超时停止
    
    /* 堵转超时停止 PWM 输出 */
    hall_disable();       // 禁用霍尔传感器接口
    stop_pwm_output();    // 停止 PWM 输出
  }
}

/*********************************************END OF FILE**********************/
