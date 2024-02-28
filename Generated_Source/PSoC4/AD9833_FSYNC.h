/*******************************************************************************
* File Name: AD9833_FSYNC.h  
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

#if !defined(CY_PINS_AD9833_FSYNC_H) /* Pins AD9833_FSYNC_H */
#define CY_PINS_AD9833_FSYNC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "AD9833_FSYNC_aliases.h"


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
} AD9833_FSYNC_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   AD9833_FSYNC_Read(void);
void    AD9833_FSYNC_Write(uint8 value);
uint8   AD9833_FSYNC_ReadDataReg(void);
#if defined(AD9833_FSYNC__PC) || (CY_PSOC4_4200L) 
    void    AD9833_FSYNC_SetDriveMode(uint8 mode);
#endif
void    AD9833_FSYNC_SetInterruptMode(uint16 position, uint16 mode);
uint8   AD9833_FSYNC_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void AD9833_FSYNC_Sleep(void); 
void AD9833_FSYNC_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(AD9833_FSYNC__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define AD9833_FSYNC_DRIVE_MODE_BITS        (3)
    #define AD9833_FSYNC_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - AD9833_FSYNC_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the AD9833_FSYNC_SetDriveMode() function.
         *  @{
         */
        #define AD9833_FSYNC_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define AD9833_FSYNC_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define AD9833_FSYNC_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define AD9833_FSYNC_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define AD9833_FSYNC_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define AD9833_FSYNC_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define AD9833_FSYNC_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define AD9833_FSYNC_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define AD9833_FSYNC_MASK               AD9833_FSYNC__MASK
#define AD9833_FSYNC_SHIFT              AD9833_FSYNC__SHIFT
#define AD9833_FSYNC_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in AD9833_FSYNC_SetInterruptMode() function.
     *  @{
     */
        #define AD9833_FSYNC_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define AD9833_FSYNC_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define AD9833_FSYNC_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define AD9833_FSYNC_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(AD9833_FSYNC__SIO)
    #define AD9833_FSYNC_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(AD9833_FSYNC__PC) && (CY_PSOC4_4200L)
    #define AD9833_FSYNC_USBIO_ENABLE               ((uint32)0x80000000u)
    #define AD9833_FSYNC_USBIO_DISABLE              ((uint32)(~AD9833_FSYNC_USBIO_ENABLE))
    #define AD9833_FSYNC_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define AD9833_FSYNC_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define AD9833_FSYNC_USBIO_ENTER_SLEEP          ((uint32)((1u << AD9833_FSYNC_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << AD9833_FSYNC_USBIO_SUSPEND_DEL_SHIFT)))
    #define AD9833_FSYNC_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << AD9833_FSYNC_USBIO_SUSPEND_SHIFT)))
    #define AD9833_FSYNC_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << AD9833_FSYNC_USBIO_SUSPEND_DEL_SHIFT)))
    #define AD9833_FSYNC_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(AD9833_FSYNC__PC)
    /* Port Configuration */
    #define AD9833_FSYNC_PC                 (* (reg32 *) AD9833_FSYNC__PC)
#endif
/* Pin State */
#define AD9833_FSYNC_PS                     (* (reg32 *) AD9833_FSYNC__PS)
/* Data Register */
#define AD9833_FSYNC_DR                     (* (reg32 *) AD9833_FSYNC__DR)
/* Input Buffer Disable Override */
#define AD9833_FSYNC_INP_DIS                (* (reg32 *) AD9833_FSYNC__PC2)

/* Interrupt configuration Registers */
#define AD9833_FSYNC_INTCFG                 (* (reg32 *) AD9833_FSYNC__INTCFG)
#define AD9833_FSYNC_INTSTAT                (* (reg32 *) AD9833_FSYNC__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define AD9833_FSYNC_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(AD9833_FSYNC__SIO)
    #define AD9833_FSYNC_SIO_REG            (* (reg32 *) AD9833_FSYNC__SIO)
#endif /* (AD9833_FSYNC__SIO_CFG) */

/* USBIO registers */
#if !defined(AD9833_FSYNC__PC) && (CY_PSOC4_4200L)
    #define AD9833_FSYNC_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define AD9833_FSYNC_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define AD9833_FSYNC_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define AD9833_FSYNC_DRIVE_MODE_SHIFT       (0x00u)
#define AD9833_FSYNC_DRIVE_MODE_MASK        (0x07u << AD9833_FSYNC_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins AD9833_FSYNC_H */


/* [] END OF FILE */
