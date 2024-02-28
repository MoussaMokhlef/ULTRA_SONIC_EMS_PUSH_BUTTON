/*******************************************************************************
* File Name: TOUCH_UP.h  
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

#if !defined(CY_PINS_TOUCH_UP_ALIASES_H) /* Pins TOUCH_UP_ALIASES_H */
#define CY_PINS_TOUCH_UP_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define TOUCH_UP_0			(TOUCH_UP__0__PC)
#define TOUCH_UP_0_PS		(TOUCH_UP__0__PS)
#define TOUCH_UP_0_PC		(TOUCH_UP__0__PC)
#define TOUCH_UP_0_DR		(TOUCH_UP__0__DR)
#define TOUCH_UP_0_SHIFT	(TOUCH_UP__0__SHIFT)
#define TOUCH_UP_0_INTR	((uint16)((uint16)0x0003u << (TOUCH_UP__0__SHIFT*2u)))

#define TOUCH_UP_INTR_ALL	 ((uint16)(TOUCH_UP_0_INTR))


#endif /* End Pins TOUCH_UP_ALIASES_H */


/* [] END OF FILE */
