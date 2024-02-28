/*******************************************************************************
* File Name: ULTRA_NAND.h  
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

#if !defined(CY_PINS_ULTRA_NAND_ALIASES_H) /* Pins ULTRA_NAND_ALIASES_H */
#define CY_PINS_ULTRA_NAND_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ULTRA_NAND_0			(ULTRA_NAND__0__PC)
#define ULTRA_NAND_0_PS		(ULTRA_NAND__0__PS)
#define ULTRA_NAND_0_PC		(ULTRA_NAND__0__PC)
#define ULTRA_NAND_0_DR		(ULTRA_NAND__0__DR)
#define ULTRA_NAND_0_SHIFT	(ULTRA_NAND__0__SHIFT)
#define ULTRA_NAND_0_INTR	((uint16)((uint16)0x0003u << (ULTRA_NAND__0__SHIFT*2u)))

#define ULTRA_NAND_INTR_ALL	 ((uint16)(ULTRA_NAND_0_INTR))


#endif /* End Pins ULTRA_NAND_ALIASES_H */


/* [] END OF FILE */
