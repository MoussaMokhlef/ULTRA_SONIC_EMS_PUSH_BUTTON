/*******************************************************************************
* File Name: EMS_OUT.h  
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

#if !defined(CY_PINS_EMS_OUT_H) /* Pins EMS_OUT_H */
#define CY_PINS_EMS_OUT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "EMS_OUT_aliases.h"


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
} EMS_OUT_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   EMS_OUT_Read(void);
void    EMS_OUT_Write(uint8 value);
uint8   EMS_OUT_ReadDataReg(void);
#if defined(EMS_OUT__PC) || (CY_PSOC4_4200L) 
    void    EMS_OUT_SetDriveMode(uint8 mode);
#endif
void    EMS_OUT_SetInterruptMode(uint16 position, uint16 mode);
uint8   EMS_OUT_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void EMS_OUT_Sleep(void); 
void EMS_OUT_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(EMS_OUT__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define EMS_OUT_DRIVE_MODE_BITS        (3)
    #define EMS_OUT_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - EMS_OUT_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the EMS_OUT_SetDriveMode() function.
         *  @{
         */
        #define EMS_OUT_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define EMS_OUT_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define EMS_OUT_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define EMS_OUT_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define EMS_OUT_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define EMS_OUT_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define EMS_OUT_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define EMS_OUT_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define EMS_OUT_MASK               EMS_OUT__MASK
#define EMS_OUT_SHIFT              EMS_OUT__SHIFT
#define EMS_OUT_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in EMS_OUT_SetInterruptMode() function.
     *  @{
     */
        #define EMS_OUT_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define EMS_OUT_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define EMS_OUT_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define EMS_OUT_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(EMS_OUT__SIO)
    #define EMS_OUT_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(EMS_OUT__PC) && (CY_PSOC4_4200L)
    #define EMS_OUT_USBIO_ENABLE               ((uint32)0x80000000u)
    #define EMS_OUT_USBIO_DISABLE              ((uint32)(~EMS_OUT_USBIO_ENABLE))
    #define EMS_OUT_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define EMS_OUT_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define EMS_OUT_USBIO_ENTER_SLEEP          ((uint32)((1u << EMS_OUT_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << EMS_OUT_USBIO_SUSPEND_DEL_SHIFT)))
    #define EMS_OUT_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << EMS_OUT_USBIO_SUSPEND_SHIFT)))
    #define EMS_OUT_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << EMS_OUT_USBIO_SUSPEND_DEL_SHIFT)))
    #define EMS_OUT_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(EMS_OUT__PC)
    /* Port Configuration */
    #define EMS_OUT_PC                 (* (reg32 *) EMS_OUT__PC)
#endif
/* Pin State */
#define EMS_OUT_PS                     (* (reg32 *) EMS_OUT__PS)
/* Data Register */
#define EMS_OUT_DR                     (* (reg32 *) EMS_OUT__DR)
/* Input Buffer Disable Override */
#define EMS_OUT_INP_DIS                (* (reg32 *) EMS_OUT__PC2)

/* Interrupt configuration Registers */
#define EMS_OUT_INTCFG                 (* (reg32 *) EMS_OUT__INTCFG)
#define EMS_OUT_INTSTAT                (* (reg32 *) EMS_OUT__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define EMS_OUT_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(EMS_OUT__SIO)
    #define EMS_OUT_SIO_REG            (* (reg32 *) EMS_OUT__SIO)
#endif /* (EMS_OUT__SIO_CFG) */

/* USBIO registers */
#if !defined(EMS_OUT__PC) && (CY_PSOC4_4200L)
    #define EMS_OUT_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define EMS_OUT_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define EMS_OUT_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define EMS_OUT_DRIVE_MODE_SHIFT       (0x00u)
#define EMS_OUT_DRIVE_MODE_MASK        (0x07u << EMS_OUT_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins EMS_OUT_H */


/* [] END OF FILE */
