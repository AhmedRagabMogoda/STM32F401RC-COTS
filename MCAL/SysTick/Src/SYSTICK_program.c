/*
 *  SYSTICK_program.c
 *
 *  Created on: Nov 27, 2024
 *  Author: Ahmed Ragab
 */

#include "stm32f401xx.h"
#include "ErrorState.h"
#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"


/**
 * @brief   Initializes SysTick for polling-based delay.
 * @param   Reload: The reload value for the timer (must be ≤ MAX_VALUE).
 * @note    Uses system clock as the clock source.
 * @retval  None
 */
static void SysTick_VoidPolling(uint32_t Reload)
{
    /* Load the specified reload value into the SysTick timer */
    STK->LOAD = Reload;
    /* Clear the current value register to start counting from zero */
    STK->VAL = CLEAR;
    /* Enable SysTick timer and select the clock source */
    STK->CTRL |= (CTRL_MASK << CLKSOURCE_PIN_ACCESS) | (CTRL_MASK << ENABLE_PIN_ACCESS);
    /* Wait until the count flag is set (timer expires) */
    while (!(STK->CTRL & (CTRL_MASK << COUNTFLAG_PIN_ACCESS)));
    /* Disable SysTick and clear the control register after completion */
    STK->CTRL = CLEAR;
}

uint8_t SysTick_u8DelayMilliSecond(uint32_t Time)
{
    uint8_t Local_u8ErrorState = OK;
    if (Time > CLEAR)
    {
    	/* Reload value corresponds to 1 millisecond */
    	uint32_t Reload = CLK_DEFAULT_HSI / MILLI_SECOND;
        /* Perform Time repetitions of 1 millisecond delays */
        while (Time > CLEAR)
        {
            SysTick_VoidPolling(Reload);
            Time--;
        }
    }
    else
    {
        Local_u8ErrorState = NOT_OK;
    }
    return Local_u8ErrorState;
}

uint8_t SysTick_u8DelayMicroSecond(uint32_t Time)
{
    uint8_t Local_u8ErrorState = OK;
    if (Time > CLEAR)
    {
    	/* Reload value corresponds to 1 microsecond */
    	uint32_t Reload = CLK_DEFAULT_HSI / MACRO_SECOND;
        /* Perform Time repetitions of 1-microsecond delays */
        while (Time > CLEAR)
        {
            SysTick_VoidPolling(Reload);
            Time--;
        }
    }
    else
    {
        Local_u8ErrorState = NOT_OK;
    }
    return Local_u8ErrorState;
}






