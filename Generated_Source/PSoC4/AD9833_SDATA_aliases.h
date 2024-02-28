/*******************************************************************************
* File Name: AD9833_SDATA.h  
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

#if !defined(CY_PINS_AD9833_SDATA_ALIASES_H) /* Pins AD9833_SDATA_ALIASES_H */
#define CY_PINS_AD9833_SDATA_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define AD9833_SDATA_0			(AD9833_SDATA__0__PC)
#define AD9833_SDATA_0_PS		(AD9833_SDATA__0__PS)
#define AD9833_SDATA_0_PC		(AD9833_SDATA__0__PC)
#define AD9833_SDATA_0_DR		(AD9833_SDATA__0__DR)
#define AD9833_SDATA_0_SHIFT	(AD9833_SDATA__0__SHIFT)
#define AD9833_SDATA_0_INTR	((uint16)((uint16)0x0003u << (AD9833_SDATA__0__SHIFT*2u)))

#define AD9833_SDATA_INTR_ALL	 ((uint16)(AD9833_SDATA_0_INTR))


#endif /* End Pins AD9833_SDATA_ALIASES_H */


/* [] END OF FILE */
