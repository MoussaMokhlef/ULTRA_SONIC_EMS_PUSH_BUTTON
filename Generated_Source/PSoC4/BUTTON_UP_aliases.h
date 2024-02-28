/*******************************************************************************
* File Name: BUTTON_UP.h  
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

#if !defined(CY_PINS_BUTTON_UP_ALIASES_H) /* Pins BUTTON_UP_ALIASES_H */
#define CY_PINS_BUTTON_UP_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define BUTTON_UP_0			(BUTTON_UP__0__PC)
#define BUTTON_UP_0_PS		(BUTTON_UP__0__PS)
#define BUTTON_UP_0_PC		(BUTTON_UP__0__PC)
#define BUTTON_UP_0_DR		(BUTTON_UP__0__DR)
#define BUTTON_UP_0_SHIFT	(BUTTON_UP__0__SHIFT)
#define BUTTON_UP_0_INTR	((uint16)((uint16)0x0003u << (BUTTON_UP__0__SHIFT*2u)))

#define BUTTON_UP_INTR_ALL	 ((uint16)(BUTTON_UP_0_INTR))


#endif /* End Pins BUTTON_UP_ALIASES_H */


/* [] END OF FILE */
