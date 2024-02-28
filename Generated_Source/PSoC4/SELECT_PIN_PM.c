/*******************************************************************************
* File Name: SELECT_PIN.c  
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
#include "SELECT_PIN.h"

static SELECT_PIN_BACKUP_STRUCT  SELECT_PIN_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: SELECT_PIN_Sleep
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
*  \snippet SELECT_PIN_SUT.c usage_SELECT_PIN_Sleep_Wakeup
*******************************************************************************/
void SELECT_PIN_Sleep(void)
{
    #if defined(SELECT_PIN__PC)
        SELECT_PIN_backup.pcState = SELECT_PIN_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            SELECT_PIN_backup.usbState = SELECT_PIN_CR1_REG;
            SELECT_PIN_USB_POWER_REG |= SELECT_PIN_USBIO_ENTER_SLEEP;
            SELECT_PIN_CR1_REG &= SELECT_PIN_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(SELECT_PIN__SIO)
        SELECT_PIN_backup.sioState = SELECT_PIN_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        SELECT_PIN_SIO_REG &= (uint32)(~SELECT_PIN_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: SELECT_PIN_Wakeup
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
*  Refer to SELECT_PIN_Sleep() for an example usage.
*******************************************************************************/
void SELECT_PIN_Wakeup(void)
{
    #if defined(SELECT_PIN__PC)
        SELECT_PIN_PC = SELECT_PIN_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            SELECT_PIN_USB_POWER_REG &= SELECT_PIN_USBIO_EXIT_SLEEP_PH1;
            SELECT_PIN_CR1_REG = SELECT_PIN_backup.usbState;
            SELECT_PIN_USB_POWER_REG &= SELECT_PIN_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(SELECT_PIN__SIO)
        SELECT_PIN_SIO_REG = SELECT_PIN_backup.sioState;
    #endif
}


/* [] END OF FILE */
