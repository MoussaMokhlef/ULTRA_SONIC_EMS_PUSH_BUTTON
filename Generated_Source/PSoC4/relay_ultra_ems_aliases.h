/*******************************************************************************
* File Name: relay_ultra_ems.h  
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

#if !defined(CY_PINS_relay_ultra_ems_ALIASES_H) /* Pins relay_ultra_ems_ALIASES_H */
#define CY_PINS_relay_ultra_ems_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define relay_ultra_ems_0			(relay_ultra_ems__0__PC)
#define relay_ultra_ems_0_PS		(relay_ultra_ems__0__PS)
#define relay_ultra_ems_0_PC		(relay_ultra_ems__0__PC)
#define relay_ultra_ems_0_DR		(relay_ultra_ems__0__DR)
#define relay_ultra_ems_0_SHIFT	(relay_ultra_ems__0__SHIFT)
#define relay_ultra_ems_0_INTR	((uint16)((uint16)0x0003u << (relay_ultra_ems__0__SHIFT*2u)))

#define relay_ultra_ems_INTR_ALL	 ((uint16)(relay_ultra_ems_0_INTR))


#endif /* End Pins relay_ultra_ems_ALIASES_H */


/* [] END OF FILE */
