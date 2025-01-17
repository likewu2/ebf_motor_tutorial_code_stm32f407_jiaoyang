/*********************************************************************************************/

【*】 程序简介 
-工程名称：步进电机编码器测速
-实验平台: 野火STM32 F407 开发板
-MDK版本：5.30
--HAL库版本：1.7.6

【 ！】功能简介：
使用STM32的通用定时器定时，控制步进电机正反转和启停。使用通用定时器编码器模式来检测电机转速。
学习目的：学习通用定时器编码器模式的配置和使用。


【 ！】实验操作：
下载本程序，复位开发板即可。

【 ！！】注意事项：
步进电机驱动器使用32细分

/*********************************************************************************************/

串口（TTL-USB TO UART）：
CH340的收发引脚与STM32的发收引脚相连。
  RX<--->PB6
  TX<--->PB7

步进电机驱动器接口1:
  PUL+<--->VCOM
  PUL-<--->PI5
  DIR+<--->VCOM
  DIR-<--->PE1
  ENA+<--->VCOM
  ENA-<--->PE0
	
编码器连线接到开发板的编码器接口
  VCC   红 <---> VENC
  EGND  黑 <---> GND
  A     蓝 <---> PC6
  B     绿 <---> PC7
  Z     黄 <---> PC8
  屏 蔽 线 <---> GND

/*********************************************************************************************/

【*】 时钟

A.晶振：
-外部高速晶振：25MHz
-RTC晶振：32.768KHz

B.各总线运行时钟：
-系统时钟 = SYCCLK = AHB1 = 168MHz
-APB2 = 84MHz 
-APB1 = 42MHz

C.浮点运算单元：
  不使用


/*********************************************************************************************/

【*】 版本

-程序版本：1.0
-发布日期：2020.7.23

-版本更新说明：首次发布

/*********************************************************************************************/

【*】 联系我们

-野火论坛    :http://www.firebbs.cn
-淘宝店铺    :https://fire-stm32.taobao.com

/*********************************************************************************************/