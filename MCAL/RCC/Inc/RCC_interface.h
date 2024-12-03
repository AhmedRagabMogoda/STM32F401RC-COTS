/*
 *  RCC_interface.h
 *
 *  Created on: Nov 23, 2024
 *  Author: Ahmed Ragab
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/************************include*****************************************/
#include "STM32F401XX.h"
/************************************************************************/

/**********************CLOCK STATUS**************************************/
typedef enum{
	RCC_OFF,
	RCC_ON
}CLKState_t;
/************************************************************************/

/*********************CLOCK TYPE*****************************************/
typedef enum{
	HSI,
	HSE,
	PLL
}CLKType_t;
/************************************************************************/

/*********************HSE clock bypass***********************************/
typedef enum{
	not_bypassed,
	bypassed
}Bypass_t;
/************************************************************************/

/*********************AHB1***********************************************/
typedef enum{
	GPIOA_Peripheral,
	GPIOB_Peripheral,
	GPIOC_Peripheral,
	GPIOD_Peripheral,
	GPIOE_Peripheral,
	GPIOH_Peripheral,
	CRC=12,
	DMA1=21,
	DMA2
}AHB1_Peripheral_t;
/************************************************************************/

/*********************APB1***********************************************/
typedef enum{
	TIM2,TIM3,TIM4,TIM5,WWDG=11,SPI2=14,SPI3,USART2=17,I2C1=21,I2C2,I2C3,PWR=28
}APB1_Peripheral_t;
/************************************************************************/

/*********************APB2***********************************************/
typedef enum{
	 TIM1,USART1=4,USART6,ADC1=8,SDIO=11,SPI1,SPI4,SYSCFG,TIM9=16,TIM10,TIM11
}APB2_Peripheral_t;
/************************************************************************/

/************************************************************************/
/**
 * @brief : Configures and manages the RCC clock sources.
 * @param : CLKtype: The type of clock to configure (HSI, HSE, or PLL).
 * @param : CLKstatus: The desired status of the clock (RCC_ON or RCC_OFF).
 * @retval: RCC_ERRORSTATUS_OK if successful,
 *          RCC_ERRORSTATUS_NOT_OK if an invalid clock type is provided,
 *          RCC_ERRORSTATUS_TIME_OUT if a timeout occurs.
 **/
/*======================================================================*/
uint8_t RCC_SETCLK(CLKType_t CLKtype,CLKState_t CLKstatus);
/************************************************************************/

/************************************************************************/
/**
 * @brief : Set the system clock source.
 * @param : CLK_TYPE: The clock source (HSI, HSE, or PLL).
 * @retval: RCC_ERRORSTATUS_OK if successful,
 *          RCC_ERRORSTATUS_TIME_OUT if a timeout occurs.
 **/
/*======================================================================*/
uint8_t RCC_SETSYSCLK(CLKType_t CLKTYPE);
/************************************************************************/

/************************************************************************/
/**
 * @brief : Configures the HSE oscillator (enable/disable bypass mode).
 * @param : CONFIG: Configuration for HSE (0: disable bypass, 1: enable bypass).
 *         - 0: HSE oscillator directly drives the system.
 *         - 1: External clock source bypasses the HSE oscillator.
 *@retval : None
 **/
/*======================================================================*/
void RCC_HSECONFIG(Bypass_t CONFIG);
/************************************************************************/

/************************************************************************/
/**
 * @brief : Configure the PLL clock.
 * @param : PLLSRC: Clock source for PLL (0: HSI, 1: HSE).
 * @param : PLLMUL: Multiplication factor for PLL.
 * @retval: None
 **/
/*======================================================================*/
void RCC_PLLCONFIG (CLKType_t CLKType,uint8_t PLL_MUL);
/************************************************************************/

/************************************************************************/
/**
 * @brief  Enable the clock for a specific peripheral on the AHB bus.
 * @param  PERIPHERAL: The peripheral bit position in the AHB1ENR register.
 * @retval None
 **/
/*======================================================================*/
void RCC_AHP1ENABLECLK(AHB1_Peripheral_t peripheral);
/************************************************************************/

/************************************************************************/
/**
 * @brief  Disable the clock for a specific peripheral on the AHB bus.
 * @param  PERIPHERAL: The peripheral bit position in the AHB1ENR register.
 * @retval None
 **/
/*======================================================================*/
void RCC_AHP1DISABLECLK(AHB1_Peripheral_t peripheral);
/************************************************************************/

/************************************************************************/
/**
 * @brief  Enable the clock for a specific peripheral on the APB1 bus.
 * @param  PERIPHERAL: The peripheral bit position in the APB1ENR register.
 * @retval None
 **/
/*======================================================================*/
void RCC_APB1ENABLECLK(APB1_Peripheral_t peripheral);
/************************************************************************/

/************************************************************************/
/**
 * @brief  Disable the clock for a specific peripheral on the APB1 bus.
 * @param  PERIPHERAL: The peripheral bit position in the APB1ENR register.
 * @retval None
 **/
/*======================================================================*/
void RCC_APB1DISABLECLK(APB1_Peripheral_t peripheral);
/************************************************************************/

/************************************************************************/
/**
 * @brief  Enable the clock for a specific peripheral on the APB2 bus.
 * @param  PERIPHERAL: The peripheral bit position in the APB2ENR register.
 * @retval None
 **/
/*======================================================================*/
void RCC_APB2ENABLECLK(APB2_Peripheral_t peripheral);
/************************************************************************/

/************************************************************************/
/**
 * @brief  Disable the clock for a specific peripheral on the APB2 bus.
 * @param  PERIPHERAL: The peripheral bit position in the APB2ENR register.
 * @retval None
 **/
/*======================================================================*/
void RCC_APB2DISABLECLK(APB2_Peripheral_t peripheral);
/************************************************************************/

#endif /* MCAL_RCC_RCC_INTERFACE_H_ */
