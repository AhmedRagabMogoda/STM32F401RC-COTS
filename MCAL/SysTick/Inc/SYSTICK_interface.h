/*
 * SYSTICK_interface.h
 *
 *  Created on: Nov 27, 2024
 *      Author: Ahmed Ragab
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

/**
 * @brief  Creates a delay in microseconds using the SysTick timer.
 *
 * This function configures the SysTick timer to generate a delay in microseconds.
 * It calculates the required reload value based on the desired delay time and the
 * system clock frequency. The delay is achieved by polling the COUNTFLAG bit of the
 * SysTick control register.
 *
 * @param  Time: Desired delay in microseconds.
 *               Must be a positive value. Maximum delay is limited by the
 *               24-bit reload value of the SysTick timer.
 *
 * @retval None
 **/
void SysTick_DelayMacroSecond(uint32_t Time);


/**
 * @brief  Creates a delay in milliseconds using the SysTick timer.
 *
 * This function configures the SysTick timer to generate a delay in milliseconds.
 * It calculates the required reload value based on the desired delay time and the
 * system clock frequency. The delay is achieved by polling the COUNTFLAG bit of the
 * SysTick control register.
 *
 * @param  Time: Desired delay in milliseconds.
 *               Must be a positive value. Maximum delay is limited by the
 *               24-bit reload value of the SysTick timer.
 *
 * @retval None
 **/
void SysTick_DelayMilliSecond(uint32_t Time);



#endif /* SYSTICK_INTERFACE_H_ */
