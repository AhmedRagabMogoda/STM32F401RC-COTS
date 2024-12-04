/*
 * SYSCFG_interface.h
 *
 *  Created on: Dec 3, 2024
 *      Author: Ahmed Ragab
 */

#ifndef SYSCFG_INTERFACE_H_
#define SYSCFG_INTERFACE_H_

typedef enum{
	PORTA=0,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTH
}SYSCFG_Port_t;

typedef enum{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}SYSCFG_Pin_t;
/*============================================================================*/
/**
 * @brief Configures the external interrupt (EXTI) port for a given pin.
 *
 * @param Port The SYSCFG port (e.g., GPIOA, GPIOB).
 * @param PinNum The pin number.
**/
void SYSCFG_VoidSetEXTIPort(SYSCFG_Port_t Port, SYSCFG_Pin_t PinNum);

#endif /* SYSCFG_INTERFACE_H_ */
