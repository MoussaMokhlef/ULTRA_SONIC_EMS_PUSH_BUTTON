/*******************************************************************************
* File Name: ISR_SCHEDULAR.h
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
#if !defined(CY_ISR_ISR_SCHEDULAR_H)
#define CY_ISR_ISR_SCHEDULAR_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void ISR_SCHEDULAR_Start(void);
void ISR_SCHEDULAR_StartEx(cyisraddress address);
void ISR_SCHEDULAR_Stop(void);

CY_ISR_PROTO(ISR_SCHEDULAR_Interrupt);

void ISR_SCHEDULAR_SetVector(cyisraddress address);
cyisraddress ISR_SCHEDULAR_GetVector(void);

void ISR_SCHEDULAR_SetPriority(uint8 priority);
uint8 ISR_SCHEDULAR_GetPriority(void);

void ISR_SCHEDULAR_Enable(void);
uint8 ISR_SCHEDULAR_GetState(void);
void ISR_SCHEDULAR_Disable(void);

void ISR_SCHEDULAR_SetPending(void);
void ISR_SCHEDULAR_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the ISR_SCHEDULAR ISR. */
#define ISR_SCHEDULAR_INTC_VECTOR            ((reg32 *) ISR_SCHEDULAR__INTC_VECT)

/* Address of the ISR_SCHEDULAR ISR priority. */
#define ISR_SCHEDULAR_INTC_PRIOR             ((reg32 *) ISR_SCHEDULAR__INTC_PRIOR_REG)

/* Priority of the ISR_SCHEDULAR interrupt. */
#define ISR_SCHEDULAR_INTC_PRIOR_NUMBER      ISR_SCHEDULAR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable ISR_SCHEDULAR interrupt. */
#define ISR_SCHEDULAR_INTC_SET_EN            ((reg32 *) ISR_SCHEDULAR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the ISR_SCHEDULAR interrupt. */
#define ISR_SCHEDULAR_INTC_CLR_EN            ((reg32 *) ISR_SCHEDULAR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the ISR_SCHEDULAR interrupt state to pending. */
#define ISR_SCHEDULAR_INTC_SET_PD            ((reg32 *) ISR_SCHEDULAR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the ISR_SCHEDULAR interrupt. */
#define ISR_SCHEDULAR_INTC_CLR_PD            ((reg32 *) ISR_SCHEDULAR__INTC_CLR_PD_REG)



#endif /* CY_ISR_ISR_SCHEDULAR_H */


/* [] END OF FILE */
