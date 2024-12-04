/*
 * EXTI_interface.h
 *
 *  Created on: Dec 3, 2024
 *      Author: Ahmed Ragab
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


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
}EXTI_LineNum_t;

typedef enum{
	FALLING_TRIG,
	RISING_TRIG,
	FALLING_RISING_TRIG
}EXTI_TrigSrc_t;

typedef enum{
	ENABLE,
	DISABLE
}EXTI_InitState_t;

typedef struct{
	EXTI_LineNum_t PinNum;
	EXTI_TrigSrc_t TrigSrc;
	EXTI_InitState_t InitState;
	void (*CallBackFunc)(void);
}EXTI_Config_t;

/*===========================================================================*/
/**
 * @brief Initializes an EXTI line with the specified configuration.
 *
 * @param CopyConfig Pointer to the EXTI_Config_t structure containing:
 *                   - Trigger source (Falling, Rising, or Both).
 *                   - Initial state (Enable or Disable).
 *                   - Callback function pointer.
 * @return uint8_t Error state:
 *         - OK: If initialization is successful.
 *         - NOT_OK: If invalid trigger source or state is provided.
 *         - NULL_PTR_ERR: If CopyConfig or callback is NULL.
 */
uint8_t EXTI_u8Init(EXTI_Config_t* CopyConfig);

/**
 * @brief Sets the trigger source for a specific EXTI line.
 *
 * @param TrigSrc Trigger source type (Falling, Rising, or Both).
 * @param PinNum EXTI line number.
 * @return uint8_t Error state:
 *         - OK: If the trigger source is successfully configured.
 *         - NOT_OK: If an invalid trigger source is provided.
 */
uint8_t EXTI_u8SetTrigSrc(EXTI_TrigSrc_t TrigSrc, EXTI_LineNum_t PinNum);

/**
 * @brief Enables the interrupt for a specific EXTI line.
 *
 * @param InitState Interrupt state (Enable).
 * @param PinNum EXTI line number.
 */
void EXTI_voidEnableInit(EXTI_InitState_t InitState, EXTI_LineNum_t PinNum);

/**
 * @brief Disables the interrupt for a specific EXTI line.
 *
 * @param InitState Interrupt state (Disable).
 * @param PinNum EXTI line number.
 */
void EXTI_voidDisableInit(EXTI_InitState_t InitState, EXTI_LineNum_t PinNum);

/**
 * @brief Clears the pending flag for a specific EXTI line.
 *
 * @param PinNum EXTI line number.
 */
void EXTI_voidClearPandingFlag(EXTI_LineNum_t PinNum);

/**
 * @brief Retrieves the pending flag status for a specific EXTI line.
 *
 * @param PinNum EXTI line number.
 * @param CopyFlagState Pointer to store the flag state.
 * @return uint8_t Error state:
 *         - OK: If the flag is successfully retrieved.
 *         - NULL_PTR_ERR: If CopyFlagState is NULL.
 */
uint8_t EXTI_8uGetPandingFlag(EXTI_LineNum_t PinNum, uint8_t* CopyFlagState);


#endif /* EXTI_INTERFACE_H_ */
