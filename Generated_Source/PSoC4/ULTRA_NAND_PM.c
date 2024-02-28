/*******************************************************************************
* File Name: ULTRA_NAND.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "ULTRA_NAND.h"

static ULTRA_NAND_BACKUP_STRUCT  ULTRA_NAND_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: ULTRA_NAND_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet ULTRA_NAND_SUT.c usage_ULTRA_NAND_Sleep_Wakeup
*******************************************************************************/
void ULTRA_NAND_Sleep(void)
{
    #if defined(ULTRA_NAND__PC)
        ULTRA_NAND_backup.pcState = ULTRA_NAND_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            ULTRA_NAND_backup.usbState = ULTRA_NAND_CR1_REG;
            ULTRA_NAND_USB_POWER_REG |= ULTRA_NAND_USBIO_ENTER_SLEEP;
            ULTRA_NAND_CR1_REG &= ULTRA_NAND_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(ULTRA_NAND__SIO)
        ULTRA_NAND_backup.sioState = ULTRA_NAND_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        ULTRA_NAND_SIO_REG &= (uint32)(~ULTRA_NAND_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: ULTRA_NAND_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to ULTRA_NAND_Sleep() for an example usage.
*******************************************************************************/
void ULTRA_NAND_Wakeup(void)
{
    #if defined(ULTRA_NAND__PC)
        ULTRA_NAND_PC = ULTRA_NAND_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            ULTRA_NAND_USB_POWER_REG &= ULTRA_NAND_USBIO_EXIT_SLEEP_PH1;
            ULTRA_NAND_CR1_REG = ULTRA_NAND_backup.usbState;
            ULTRA_NAND_USB_POWER_REG &= ULTRA_NAND_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(ULTRA_NAND__SIO)
        ULTRA_NAND_SIO_REG = ULTRA_NAND_backup.sioState;
    #endif
}


/* [] END OF FILE */
