/*
 *  BIT_MATH.h
 *
 *  Created on: Nov 24, 2024
 *  Author: Ahmed Ragab
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(port_register,bit_number)	port_register|=(1<<bit_number)
#define	CLR_BIT(port_register,bit_number)	port_register&=(~(1<<bit_number))
#define	TOG_BIT(port_register,bit_number)	port_register^=(1<<bit_number)
#define GET_BIT(port_register,bit_number)	((port_register&(1<<bit_number))>>bit_number)


#endif /* BIT_MATH_H_ */
