/*******************************************************************************
* File Name: relay_ultra_ems.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_relay_ultra_ems_H) /* Pins relay_ultra_ems_H */
#define CY_PINS_relay_ultra_ems_H

#include "cytypes.h"
#include "cyfitter.h"
#include "relay_ultra_ems_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} relay_ultra_ems_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   relay_ultra_ems_Read(void);
void    relay_ultra_ems_Write(uint8 value);
uint8   relay_ultra_ems_ReadDataReg(void);
#if defined(relay_ultra_ems__PC) || (CY_PSOC4_4200L) 
    void    relay_ultra_ems_SetDriveMode(uint8 mode);
#endif
void    relay_ultra_ems_SetInterruptMode(uint16 position, uint16 mode);
uint8   relay_ultra_ems_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void relay_ultra_ems_Sleep(void); 
void relay_ultra_ems_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(relay_ultra_ems__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define relay_ultra_ems_DRIVE_MODE_BITS        (3)
    #define relay_ultra_ems_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - relay_ultra_ems_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the relay_ultra_ems_SetDriveMode() function.
         *  @{
         */
        #define relay_ultra_ems_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define relay_ultra_ems_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define relay_ultra_ems_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define relay_ultra_ems_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define relay_ultra_ems_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define relay_ultra_ems_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define relay_ultra_ems_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define relay_ultra_ems_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define relay_ultra_ems_MASK               relay_ultra_ems__MASK
#define relay_ultra_ems_SHIFT              relay_ultra_ems__SHIFT
#define relay_ultra_ems_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in relay_ultra_ems_SetInterruptMode() function.
     *  @{
     */
        #define relay_ultra_ems_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define relay_ultra_ems_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define relay_ultra_ems_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define relay_ultra_ems_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(relay_ultra_ems__SIO)
    #define relay_ultra_ems_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(relay_ultra_ems__PC) && (CY_PSOC4_4200L)
    #define relay_ultra_ems_USBIO_ENABLE               ((uint32)0x80000000u)
    #define relay_ultra_ems_USBIO_DISABLE              ((uint32)(~relay_ultra_ems_USBIO_ENABLE))
    #define relay_ultra_ems_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define relay_ultra_ems_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define relay_ultra_ems_USBIO_ENTER_SLEEP          ((uint32)((1u << relay_ultra_ems_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << relay_ultra_ems_USBIO_SUSPEND_DEL_SHIFT)))
    #define relay_ultra_ems_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << relay_ultra_ems_USBIO_SUSPEND_SHIFT)))
    #define relay_ultra_ems_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << relay_ultra_ems_USBIO_SUSPEND_DEL_SHIFT)))
    #define relay_ultra_ems_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(relay_ultra_ems__PC)
    /* Port Configuration */
    #define relay_ultra_ems_PC                 (* (reg32 *) relay_ultra_ems__PC)
#endif
/* Pin State */
#define relay_ultra_ems_PS                     (* (reg32 *) relay_ultra_ems__PS)
/* Data Register */
#define relay_ultra_ems_DR                     (* (reg32 *) relay_ultra_ems__DR)
/* Input Buffer Disable Override */
#define relay_ultra_ems_INP_DIS                (* (reg32 *) relay_ultra_ems__PC2)

/* Interrupt configuration Registers */
#define relay_ultra_ems_INTCFG                 (* (reg32 *) relay_ultra_ems__INTCFG)
#define relay_ultra_ems_INTSTAT                (* (reg32 *) relay_ultra_ems__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define relay_ultra_ems_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(relay_ultra_ems__SIO)
    #define relay_ultra_ems_SIO_REG            (* (reg32 *) relay_ultra_ems__SIO)
#endif /* (relay_ultra_ems__SIO_CFG) */

/* USBIO registers */
#if !defined(relay_ultra_ems__PC) && (CY_PSOC4_4200L)
    #define relay_ultra_ems_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define relay_ultra_ems_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define relay_ultra_ems_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define relay_ultra_ems_DRIVE_MODE_SHIFT       (0x00u)
#define relay_ultra_ems_DRIVE_MODE_MASK        (0x07u << relay_ultra_ems_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins relay_ultra_ems_H */


/* [] END OF FILE */
