/*******************************************************************************
* File Name: isr_button_up.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_isr_button_up_H)
#define CY_ISR_isr_button_up_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isr_button_up_Start(void);
void isr_button_up_StartEx(cyisraddress address);
void isr_button_up_Stop(void);

CY_ISR_PROTO(isr_button_up_Interrupt);

void isr_button_up_SetVector(cyisraddress address);
cyisraddress isr_button_up_GetVector(void);

void isr_button_up_SetPriority(uint8 priority);
uint8 isr_button_up_GetPriority(void);

void isr_button_up_Enable(void);
uint8 isr_button_up_GetState(void);
void isr_button_up_Disable(void);

void isr_button_up_SetPending(void);
void isr_button_up_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isr_button_up ISR. */
#define isr_button_up_INTC_VECTOR            ((reg32 *) isr_button_up__INTC_VECT)

/* Address of the isr_button_up ISR priority. */
#define isr_button_up_INTC_PRIOR             ((reg32 *) isr_button_up__INTC_PRIOR_REG)

/* Priority of the isr_button_up interrupt. */
#define isr_button_up_INTC_PRIOR_NUMBER      isr_button_up__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isr_button_up interrupt. */
#define isr_button_up_INTC_SET_EN            ((reg32 *) isr_button_up__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isr_button_up interrupt. */
#define isr_button_up_INTC_CLR_EN            ((reg32 *) isr_button_up__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isr_button_up interrupt state to pending. */
#define isr_button_up_INTC_SET_PD            ((reg32 *) isr_button_up__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isr_button_up interrupt. */
#define isr_button_up_INTC_CLR_PD            ((reg32 *) isr_button_up__INTC_CLR_PD_REG)



#endif /* CY_ISR_isr_button_up_H */


/* [] END OF FILE */
