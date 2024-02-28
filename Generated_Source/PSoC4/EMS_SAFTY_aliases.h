/*******************************************************************************
* File Name: EMS_SAFTY.h  
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

#if !defined(CY_PINS_EMS_SAFTY_ALIASES_H) /* Pins EMS_SAFTY_ALIASES_H */
#define CY_PINS_EMS_SAFTY_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define EMS_SAFTY_0			(EMS_SAFTY__0__PC)
#define EMS_SAFTY_0_PS		(EMS_SAFTY__0__PS)
#define EMS_SAFTY_0_PC		(EMS_SAFTY__0__PC)
#define EMS_SAFTY_0_DR		(EMS_SAFTY__0__DR)
#define EMS_SAFTY_0_SHIFT	(EMS_SAFTY__0__SHIFT)
#define EMS_SAFTY_0_INTR	((uint16)((uint16)0x0003u << (EMS_SAFTY__0__SHIFT*2u)))

#define EMS_SAFTY_INTR_ALL	 ((uint16)(EMS_SAFTY_0_INTR))


#endif /* End Pins EMS_SAFTY_ALIASES_H */


/* [] END OF FILE */
