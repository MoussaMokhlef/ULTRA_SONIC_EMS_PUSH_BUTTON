/*******************************************************************************
* File Name: TOUCH_UP.h  
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

#if !defined(CY_PINS_TOUCH_UP_H) /* Pins TOUCH_UP_H */
#define CY_PINS_TOUCH_UP_H

#include "cytypes.h"
#include "cyfitter.h"
#include "TOUCH_UP_aliases.h"


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
} TOUCH_UP_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   TOUCH_UP_Read(void);
void    TOUCH_UP_Write(uint8 value);
uint8   TOUCH_UP_ReadDataReg(void);
#if defined(TOUCH_UP__PC) || (CY_PSOC4_4200L) 
    void    TOUCH_UP_SetDriveMode(uint8 mode);
#endif
void    TOUCH_UP_SetInterruptMode(uint16 position, uint16 mode);
uint8   TOUCH_UP_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void TOUCH_UP_Sleep(void); 
void TOUCH_UP_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(TOUCH_UP__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define TOUCH_UP_DRIVE_MODE_BITS        (3)
    #define TOUCH_UP_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - TOUCH_UP_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the TOUCH_UP_SetDriveMode() function.
         *  @{
         */
        #define TOUCH_UP_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define TOUCH_UP_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define TOUCH_UP_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define TOUCH_UP_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define TOUCH_UP_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define TOUCH_UP_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define TOUCH_UP_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define TOUCH_UP_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define TOUCH_UP_MASK               TOUCH_UP__MASK
#define TOUCH_UP_SHIFT              TOUCH_UP__SHIFT
#define TOUCH_UP_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in TOUCH_UP_SetInterruptMode() function.
     *  @{
     */
        #define TOUCH_UP_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define TOUCH_UP_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define TOUCH_UP_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define TOUCH_UP_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(TOUCH_UP__SIO)
    #define TOUCH_UP_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(TOUCH_UP__PC) && (CY_PSOC4_4200L)
    #define TOUCH_UP_USBIO_ENABLE               ((uint32)0x80000000u)
    #define TOUCH_UP_USBIO_DISABLE              ((uint32)(~TOUCH_UP_USBIO_ENABLE))
    #define TOUCH_UP_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define TOUCH_UP_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define TOUCH_UP_USBIO_ENTER_SLEEP          ((uint32)((1u << TOUCH_UP_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << TOUCH_UP_USBIO_SUSPEND_DEL_SHIFT)))
    #define TOUCH_UP_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << TOUCH_UP_USBIO_SUSPEND_SHIFT)))
    #define TOUCH_UP_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << TOUCH_UP_USBIO_SUSPEND_DEL_SHIFT)))
    #define TOUCH_UP_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(TOUCH_UP__PC)
    /* Port Configuration */
    #define TOUCH_UP_PC                 (* (reg32 *) TOUCH_UP__PC)
#endif
/* Pin State */
#define TOUCH_UP_PS                     (* (reg32 *) TOUCH_UP__PS)
/* Data Register */
#define TOUCH_UP_DR                     (* (reg32 *) TOUCH_UP__DR)
/* Input Buffer Disable Override */
#define TOUCH_UP_INP_DIS                (* (reg32 *) TOUCH_UP__PC2)

/* Interrupt configuration Registers */
#define TOUCH_UP_INTCFG                 (* (reg32 *) TOUCH_UP__INTCFG)
#define TOUCH_UP_INTSTAT                (* (reg32 *) TOUCH_UP__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define TOUCH_UP_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(TOUCH_UP__SIO)
    #define TOUCH_UP_SIO_REG            (* (reg32 *) TOUCH_UP__SIO)
#endif /* (TOUCH_UP__SIO_CFG) */

/* USBIO registers */
#if !defined(TOUCH_UP__PC) && (CY_PSOC4_4200L)
    #define TOUCH_UP_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define TOUCH_UP_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define TOUCH_UP_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define TOUCH_UP_DRIVE_MODE_SHIFT       (0x00u)
#define TOUCH_UP_DRIVE_MODE_MASK        (0x07u << TOUCH_UP_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins TOUCH_UP_H */


/* [] END OF FILE */
