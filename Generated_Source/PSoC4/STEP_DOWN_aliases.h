/*******************************************************************************
* File Name: STEP_DOWN.h  
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

#if !defined(CY_PINS_STEP_DOWN_ALIASES_H) /* Pins STEP_DOWN_ALIASES_H */
#define CY_PINS_STEP_DOWN_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define STEP_DOWN_0			(STEP_DOWN__0__PC)
#define STEP_DOWN_0_PS		(STEP_DOWN__0__PS)
#define STEP_DOWN_0_PC		(STEP_DOWN__0__PC)
#define STEP_DOWN_0_DR		(STEP_DOWN__0__DR)
#define STEP_DOWN_0_SHIFT	(STEP_DOWN__0__SHIFT)
#define STEP_DOWN_0_INTR	((uint16)((uint16)0x0003u << (STEP_DOWN__0__SHIFT*2u)))

#define STEP_DOWN_INTR_ALL	 ((uint16)(STEP_DOWN_0_INTR))


#endif /* End Pins STEP_DOWN_ALIASES_H */


/* [] END OF FILE */
