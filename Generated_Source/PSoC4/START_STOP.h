/*******************************************************************************
* File Name: START_STOP.h  
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

#if !defined(CY_PINS_START_STOP_H) /* Pins START_STOP_H */
#define CY_PINS_START_STOP_H

#include "cytypes.h"
#include "cyfitter.h"
#include "START_STOP_aliases.h"


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
} START_STOP_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   START_STOP_Read(void);
void    START_STOP_Write(uint8 value);
uint8   START_STOP_ReadDataReg(void);
#if defined(START_STOP__PC) || (CY_PSOC4_4200L) 
    void    START_STOP_SetDriveMode(uint8 mode);
#endif
void    START_STOP_SetInterruptMode(uint16 position, uint16 mode);
uint8   START_STOP_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void START_STOP_Sleep(void); 
void START_STOP_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(START_STOP__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define START_STOP_DRIVE_MODE_BITS        (3)
    #define START_STOP_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - START_STOP_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the START_STOP_SetDriveMode() function.
         *  @{
         */
        #define START_STOP_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define START_STOP_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define START_STOP_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define START_STOP_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define START_STOP_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define START_STOP_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define START_STOP_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define START_STOP_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define START_STOP_MASK               START_STOP__MASK
#define START_STOP_SHIFT              START_STOP__SHIFT
#define START_STOP_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in START_STOP_SetInterruptMode() function.
     *  @{
     */
        #define START_STOP_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define START_STOP_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define START_STOP_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define START_STOP_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(START_STOP__SIO)
    #define START_STOP_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(START_STOP__PC) && (CY_PSOC4_4200L)
    #define START_STOP_USBIO_ENABLE               ((uint32)0x80000000u)
    #define START_STOP_USBIO_DISABLE              ((uint32)(~START_STOP_USBIO_ENABLE))
    #define START_STOP_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define START_STOP_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define START_STOP_USBIO_ENTER_SLEEP          ((uint32)((1u << START_STOP_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << START_STOP_USBIO_SUSPEND_DEL_SHIFT)))
    #define START_STOP_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << START_STOP_USBIO_SUSPEND_SHIFT)))
    #define START_STOP_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << START_STOP_USBIO_SUSPEND_DEL_SHIFT)))
    #define START_STOP_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(START_STOP__PC)
    /* Port Configuration */
    #define START_STOP_PC                 (* (reg32 *) START_STOP__PC)
#endif
/* Pin State */
#define START_STOP_PS                     (* (reg32 *) START_STOP__PS)
/* Data Register */
#define START_STOP_DR                     (* (reg32 *) START_STOP__DR)
/* Input Buffer Disable Override */
#define START_STOP_INP_DIS                (* (reg32 *) START_STOP__PC2)

/* Interrupt configuration Registers */
#define START_STOP_INTCFG                 (* (reg32 *) START_STOP__INTCFG)
#define START_STOP_INTSTAT                (* (reg32 *) START_STOP__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define START_STOP_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(START_STOP__SIO)
    #define START_STOP_SIO_REG            (* (reg32 *) START_STOP__SIO)
#endif /* (START_STOP__SIO_CFG) */

/* USBIO registers */
#if !defined(START_STOP__PC) && (CY_PSOC4_4200L)
    #define START_STOP_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define START_STOP_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define START_STOP_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define START_STOP_DRIVE_MODE_SHIFT       (0x00u)
#define START_STOP_DRIVE_MODE_MASK        (0x07u << START_STOP_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins START_STOP_H */


/* [] END OF FILE */
