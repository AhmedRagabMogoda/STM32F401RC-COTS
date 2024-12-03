/*
 * NVIC_interface.h
 *
 *  Created on: Nov 30, 2024
 *      Author: Ahmed Ragab
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_


/**
 * @brief Enum for STM32F401RC Interrupt Numbers.
 *        This enum defines all the peripheral interrupt numbers as per NVIC table.
 **/
typedef enum {
    WWDG = 0,                /** Window Watchdog Interrupt */
    PVD,                     /** PVD through EXTI Line detection */
    TAMP_STAMP,              /** Tamper and TimeStamp interrupts through EXTI Line */
    RTC_WKUP,                /** RTC Wakeup interrupt through EXTI Line */
    FLASH,                   /** Flash global interrupt */
	RCC_INTERRUPT,           /** RCC global interrupt */
    EXTI0,                   /** EXTI Line0 interrupt */
    EXTI1,                   /** EXTI Line1 interrupt */
    EXTI2,                   /** EXTI Line2 interrupt */
    EXTI3,                   /** EXTI Line3 interrupt */
    EXTI4,                   /** EXTI Line4 interrupt */
    DMA1_Stream0,            /** DMA1 Stream0 global interrupt */
    DMA1_Stream1,            /** DMA1 Stream1 global interrupt */
    DMA1_Stream2,            /** DMA1 Stream2 global interrupt */
    DMA1_Stream3,            /** DMA1 Stream3 global interrupt */
    DMA1_Stream4,            /** DMA1 Stream4 global interrupt */
    DMA1_Stream5,            /** DMA1 Stream5 global interrupt */
    DMA1_Stream6,            /** DMA1 Stream6 global interrupt */
    ADC,                     /** ADC1 global interrupt */
    EXTI9_5 = 23,            /** EXTI Line[9:5] interrupts */
    TIM1_BRK_TIM9,           /** TIM1 Break interrupt and TIM9 global interrupt */
    TIM1_UP_TIM10,           /** TIM1 Update interrupt and TIM10 global interrupt */
    TIM1_TRG_COM_TIM11,      /** TIM1 Trigger and Commutation interrupts and TIM11 global interrupt */
    TIM1_CC,                 /** TIM1 Capture Compare interrupt */
    TIM2,                    /** TIM2 global interrupt */
    TIM3,                    /** TIM3 global interrupt */
    TIM4,                    /** TIM4 global interrupt */
    I2C1_EV,                 /** I2C1 event interrupt */
    I2C1_ER,                 /** I2C1 error interrupt */
    I2C2_EV,                 /** I2C2 event interrupt */
    I2C2_ER,                 /** I2C2 error interrupt */
    SPI1,                    /** SPI1 global interrupt */
    SPI2,                    /** SPI2 global interrupt */
    USART1,                  /** USART1 global interrupt */
    USART2,                  /** USART2 global interrupt */
    EXTI15_10,               /** EXTI Line[15:10] interrupts */
    RTC_Alarm,               /** RTC Alarms (A and B) through EXTI Line */
    OTG_FS_WKUP,             /** USB OTG FS Wakeup through EXTI line */
    DMA1_Stream7,            /** DMA1 Stream7 global interrupt */
    SDIO,                    /** SDIO global interrupt */
    TIM5,                    /** TIM5 global interrupt */
    SPI3,                    /** SPI3 global interrupt */
    DMA2_Stream0,            /** DMA2 Stream0 global interrupt */
    DMA2_Stream1,            /** DMA2 Stream1 global interrupt */
    DMA2_Stream2,            /** DMA2 Stream2 global interrupt */
    DMA2_Stream3,            /** DMA2 Stream3 global interrupt */
    DMA2_Stream4,            /** DMA2 Stream4 global interrupt */
    OTG_FS,                  /** USB OTG FS global interrupt */
    DMA2_Stream5,            /** DMA2 Stream5 global interrupt */
    DMA2_Stream6,            /** DMA2 Stream6 global interrupt */
    DMA2_Stream7,            /** DMA2 Stream7 global interrupt */
    USART6,                  /** USART6 global interrupt */
    I2C3_EV,                 /** I2C3 event interrupt */
    I2C3_ER,                 /** I2C3 error interrupt */
    FPU,                     /** FPU global interrupt */
    SPI4 = 84,               /** SPI4 global interrupt */
} Interrupt_t;

typedef enum{
	 ZERO,ONE,TWO,THREE,FOUR,FIVE
}Priority_t;

typedef enum{
	 Group8_Sub2=4,
	 Group4_Sub4,
	 Group2_Sub8,
	 NoneGroup_Sub16,
}PriorityGroup_t;


/*================================================================================================*/
/**
 * *********************************************
 * @brief Enable a specific interrupt in the NVIC.
 * @details Sets the corresponding bit in the Interrupt Set-Enable Register (ISER)
 *          to enable the desired interrupt.
 * @param InterruptNum The interrupt number to be enabled (0-240 depending on the MCU).
 *********************************************
 **/
void NVIC_EnableInterrupt(Interrupt_t InterruptNum);

/**
 * *********************************************
 * @brief Disable a specific interrupt in the NVIC.
 * @details Clears the corresponding bit in the Interrupt Clear-Enable Register (ICER)
 *          to disable the desired interrupt.
 * @param InterruptNum The interrupt number to be disabled (0-240 depending on the MCU).
 ***********************************************
 **/
void NVIC_DisableInterrupt(Interrupt_t InterruptNum);

/**
 * *********************************************
 * @brief Set a pending flag for a specific interrupt.
 * @details Sets the corresponding bit in the Interrupt Set-Pending Register (ISPR),
 *          indicating that the interrupt is pending.
 * @param InterruptNum The interrupt number to set as pending (0-240 depending on the MCU).
 *********************************************
 **/
void NVIC_SETPendingInterrupt(Interrupt_t InterruptNum);

/**
 * *********************************************
 * @brief Clear a pending flag for a specific interrupt.
 * @details Clears the corresponding bit in the Interrupt Clear-Pending Register (ICPR),
 *          removing the pending state of the interrupt.
 * @param InterruptNum The interrupt number to clear from pending (0-240 depending on the MCU).
 *********************************************
**/
void NVIC_CLRPendingInterrupt(Interrupt_t InterruptNum);

/**
 * *********************************************
 * @brief Get the active state of a specific interrupt.
 * @details Checks the corresponding bit in the Interrupt Active Bit Register (IABR),
 *          indicating if the interrupt is active.
 * @param InterruptNum The interrupt number to check the active state (0-240 depending on the MCU).
 * @return uint8_t 1 if the interrupt is active, 0 otherwise.
 *********************************************
 **/
uint8_t NVIC_GetActiveFlagInterrupt(Interrupt_t InterruptNum);

/**
 * *********************************************
 * @brief Set the priority of a specific interrupt.
 * @details Configures the priority of an interrupt by modifying the appropriate field
 *          in the Interrupt Priority Register (IPR).
 * @param InterruptNum The interrupt number to configure (0-240 depending on the MCU).
 * @param Priority The priority value to set (typically 0-15, MCU-specific).
 *********************************************
**/
void NVIC_SETPriorityInterrupt(Interrupt_t InterruptNum,Priority_t Priority);

/**
 * @brief   Sets the priority grouping configuration for the Cortex-M processor.
 *          The priority grouping determines the number of priority bits allocated
 *          to the preemption priority and the number of bits allocated to the
 *          sub-priority in the interrupt system.
 *
 *          The priority grouping is configured via the **AIRCR** register of the
 *          **System Control Block (SCB)**. The function uses the **PriorityGroup_t**
 *          enum to specify the priority grouping configuration. This function
 *          enables adjusting how interrupts are prioritized.
 *
 * @param   PriorityGroup    The priority grouping configuration.
 *          This value is an enumeration defined by the user to select the
 *          appropriate priority group configuration. The valid values for
 *          this parameter are:
 *              - PriorityGroup_0: All bits for preemption priority.
 *              - PriorityGroup_1: 1 bit for sub-priority and the rest for preemption priority.
 *              - PriorityGroup_2: 2 bits for sub-priority and the rest for preemption priority.
 *              - PriorityGroup_3: 3 bits for sub-priority and the rest for preemption priority.
 *              - PriorityGroup_4: 4 bits for sub-priority and the rest for preemption priority.
 *              - etc. (depending on the implementation)
 *
 * @return  None
 **/
void SCB_SetPriorityGroup(PriorityGroup_t PriorityGroup);

#endif /* NVIC_INTERFACE_H_ */
