/**
  ******************************************************************************
  * @file    mc_stm_types.h
  * @author  Motor Control SDK Team, ST Microelectronics
  * @brief   Includes HAL/LL headers relevant to the current configuration.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
#ifndef __MC_STM_TYPES_H
#define __MC_STM_TYPES_H

#ifndef USE_FULL_LL_DRIVER
#define USE_FULL_LL_DRIVER
#endif

#ifdef MISRA_C_2004_BUILD
#error "The code is not ready for that..."
#endif

  #include "stm32f4xx_ll_system.h"
  #include "stm32f4xx_ll_adc.h"
  #include "stm32f4xx_ll_tim.h"
  #include "stm32f4xx_ll_gpio.h"
  #include "stm32f4xx_ll_usart.h"
  #include "stm32f4xx_ll_dac.h"
  #include "stm32f4xx_ll_dma.h"
  #include "stm32f4xx_ll_bus.h"

/**
  * @brief  Driver macro reserved for internal use: set a pointer to
  *         a register from a register basis from which an offset
  *         is applied.
  * @param  __REG__ Register basis from which the offset is applied.
  * @param  __REG_OFFFSET__ Offset to be applied (unit number of registers).
  * @retval Pointer to register address
  */
#define __DMA_PTR_REG_OFFSET(__REG__, __REG_OFFFSET__)                         \
 ((__IO uint32_t *)((uint32_t) ((uint32_t)(&(__REG__)) + ((__REG_OFFFSET__) << 2U))))

#define __LL_DMA_IT_TC_BIT(__STREAM_NB__) \
  (((__STREAM_NB__&0x3) == 0U) ? 5 : \
   ((__STREAM_NB__&0x3) == 1U) ? 11 :\
   ((__STREAM_NB__&0x3) == 2U) ? 21 : 27)

#define __LL_DMA_IT_HT_BIT(__STREAM_NB__) \
  (((__STREAM_NB__&0x3) == 0U) ? 4 : \
   ((__STREAM_NB__&0x3) == 1U) ? 10 :\
   ((__STREAM_NB__&0x3) == 2U) ? 20 : 26)

#define __LL_DMA_IT_TE_BIT(__STREAM_NB__) \
  (((__STREAM_NB__&0x3) == 0U) ? 3 : \
   ((__STREAM_NB__&0x3) == 1U) ? 9 :\
   ((__STREAM_NB__&0x3) == 2U) ? 19 : 25)

__STATIC_INLINE void LL_DMA_ClearFlag_TC(DMA_TypeDef *DMAx, uint32_t Stream)
{
  /* Clear TC bits with bits position depending on parameter "Stream".      */
  register __IO uint32_t *preg = __DMA_PTR_REG_OFFSET(DMAx->LIFCR,(Stream<=3)?0:1);

  WRITE_REG (*preg, 1 << __LL_DMA_IT_TC_BIT(Stream) );
}

__STATIC_INLINE void LL_DMA_ClearFlag_TE(DMA_TypeDef *DMAx, uint32_t Stream)
{
  /* Clear TE bits with bits position depending on parameter "Stream".      */
  register __IO uint32_t *preg = __DMA_PTR_REG_OFFSET(DMAx->LIFCR,(Stream<=3)?0:1);

  WRITE_REG (*preg, 1 << __LL_DMA_IT_TE_BIT(Stream) );
}

__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC(DMA_TypeDef *DMAx, uint32_t Stream )
{
  register __IO uint32_t *preg = __DMA_PTR_REG_OFFSET(DMAx->LISR,(Stream<=3)?0:1);
  return ((READ_BIT(*preg, 1 << __LL_DMA_IT_TC_BIT(Stream) ) == (1 << __LL_DMA_IT_TC_BIT(Stream))) ? 1UL : 0UL);
}

__STATIC_INLINE void LL_DMA_ClearFlag_HT(DMA_TypeDef *DMAx, uint32_t Stream)
{
  /* Clear TC bits with bits position depending on parameter "Stream".      */
  register __IO uint32_t *preg = __DMA_PTR_REG_OFFSET(DMAx->LIFCR,(Stream<=3)?0:1);

  WRITE_REG (*preg, 1 << __LL_DMA_IT_HT_BIT(Stream) );
}

__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT(DMA_TypeDef *DMAx, uint32_t Stream )
{
  register __IO uint32_t *preg = __DMA_PTR_REG_OFFSET(DMAx->LISR,(Stream<=3)?0:1);
  return ((READ_BIT(*preg, 1 << __LL_DMA_IT_HT_BIT(Stream) ) == (1 << __LL_DMA_IT_HT_BIT(Stream))) ? 1UL : 0UL);
}

/**
 * @name Predefined Speed Units
 *
 * Each of the following symbols defines a rotation speed unit that can be used by the
 * functions of the API for their speed parameter. Each Unit is defined by expressing
 * the value of 1 Hz in this unit.
 *
 * These symbols can be used to set the #SPEED_UNIT macro which defines the rotation speed
 * unit used by the functions of the API.
 *
 * @anchor SpeedUnit
 */
/** @{ */
/** Revolutions Per Minute: 1 Hz is 60 RPM */
#define _RPM 60
/** Tenth of Hertz: 1 Hz is 10 01Hz */
#define _01HZ 10
/** Hundreth of Hertz: 1 Hz is 100 001Hz */
#define _001HZ 100
/** @} */

/* USER CODE BEGIN DEFINITIONS */
/* Definitions placed here will not be erased by code generation */
/**
 * @brief Rotation speed unit used at the interface with the application
 *
 * This symbols defines the value of 1 Hertz in the unit used by the functions of the API for
 * their speed parameters.
 *
 * For instance, if the chosen unit is the RPM, SPEED_UNIT is defined to 60, since 1 Hz is 60 RPM.
 *
 * @note This symbol should not be set to a literal numeric value. Rather, it should be set to one
 *       of the symbols predefined for that purpose such as #_RPM, #_01HZ,... See @ref SpeedUnit for
 *       more details.
 */
#define SPEED_UNIT _01HZ

/**
 * @brief use a circle limitation that privileges Vd component instead of Vdq angle (uses more MIPS)
 *
 *        to use a circle limitation that keeps Vdq angle uncomment the define below
 *        (Beware: this uses more MIPS)
 */

/* USER CODE END DEFINITIONS */

#endif /* __MC_STM_TYPES_H */
/******************* (C) COPYRIGHT 2019 STMicroelectronics *****END OF FILE****/