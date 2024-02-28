/*******************************************************************************
* File Name: SELECT_PIN.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SELECT_PIN_ALIASES_H) /* Pins SELECT_PIN_ALIASES_H */
#define CY_PINS_SELECT_PIN_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define SELECT_PIN_0			(SELECT_PIN__0__PC)
#define SELECT_PIN_0_PS		(SELECT_PIN__0__PS)
#define SELECT_PIN_0_PC		(SELECT_PIN__0__PC)
#define SELECT_PIN_0_DR		(SELECT_PIN__0__DR)
#define SELECT_PIN_0_SHIFT	(SELECT_PIN__0__SHIFT)
#define SELECT_PIN_0_INTR	((uint16)((uint16)0x0003u << (SELECT_PIN__0__SHIFT*2u)))

#define SELECT_PIN_INTR_ALL	 ((uint16)(SELECT_PIN_0_INTR))


#endif /* End Pins SELECT_PIN_ALIASES_H */


/* [] END OF FILE */
