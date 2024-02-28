/*******************************************************************************
* File Name: relay_ultra_ems.c  
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
#include "relay_ultra_ems.h"

static relay_ultra_ems_BACKUP_STRUCT  relay_ultra_ems_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: relay_ultra_ems_Sleep
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
*  \snippet relay_ultra_ems_SUT.c usage_relay_ultra_ems_Sleep_Wakeup
*******************************************************************************/
void relay_ultra_ems_Sleep(void)
{
    #if defined(relay_ultra_ems__PC)
        relay_ultra_ems_backup.pcState = relay_ultra_ems_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            relay_ultra_ems_backup.usbState = relay_ultra_ems_CR1_REG;
            relay_ultra_ems_USB_POWER_REG |= relay_ultra_ems_USBIO_ENTER_SLEEP;
            relay_ultra_ems_CR1_REG &= relay_ultra_ems_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(relay_ultra_ems__SIO)
        relay_ultra_ems_backup.sioState = relay_ultra_ems_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        relay_ultra_ems_SIO_REG &= (uint32)(~relay_ultra_ems_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: relay_ultra_ems_Wakeup
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
*  Refer to relay_ultra_ems_Sleep() for an example usage.
*******************************************************************************/
void relay_ultra_ems_Wakeup(void)
{
    #if defined(relay_ultra_ems__PC)
        relay_ultra_ems_PC = relay_ultra_ems_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            relay_ultra_ems_USB_POWER_REG &= relay_ultra_ems_USBIO_EXIT_SLEEP_PH1;
            relay_ultra_ems_CR1_REG = relay_ultra_ems_backup.usbState;
            relay_ultra_ems_USB_POWER_REG &= relay_ultra_ems_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(relay_ultra_ems__SIO)
        relay_ultra_ems_SIO_REG = relay_ultra_ems_backup.sioState;
    #endif
}


/* [] END OF FILE */
