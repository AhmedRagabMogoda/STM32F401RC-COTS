/*
 *  SYSTICK_program.c
 *
 *  Created on: Nov 27, 2024
 *  Author: Ahmed Ragab
 */
#include "stm32f401xx.h"
#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"

/*extern uint32_t SystemCoreClock;*/

void SysTick_DelayMacroSecond(uint32_t Time)
{
	uint32_t Reload = (CLK_DEFAULT_HSI*Time)/MACRO_SECOND;
	if(Reload > MAX_VALUE)
	{
		Reload = MAX_VALUE;
	}
	STK->LOAD = Reload;
	STK->VAL = CLEAR;
	STK->CTRL |= (CTRL_MASK << CLKSOURCE_PIN_ACCESS);
	STK->CTRL |= (CTRL_MASK << ENABLE_PIN_ACCESS);
	while(!(STK->CTRL & (CTRL_MASK << COUNTFLAG_PIN_ACCESS)));
	STK->CTRL = CLEAR;
}

void SysTick_DelayMilliSecond(uint32_t Time)
{
	uint32_t Reload = (CLK_DEFAULT_HSI*Time)/MILLI_SECOND;
	if(Reload > MAX_VALUE)
	{
		Reload = MAX_VALUE;
	}
	STK->LOAD = Reload;
	STK->VAL = CLEAR;
	STK->CTRL |= (CTRL_MASK << CLKSOURCE_PIN_ACCESS);
	STK->CTRL |= (CTRL_MASK << ENABLE_PIN_ACCESS);
	while(!(STK->CTRL & (CTRL_MASK << COUNTFLAG_PIN_ACCESS)));
	STK->CTRL = CLEAR;
}







