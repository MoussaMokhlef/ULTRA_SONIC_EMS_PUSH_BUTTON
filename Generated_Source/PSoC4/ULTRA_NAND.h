/*******************************************************************************
* File Name: ULTRA_NAND.h  
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

#if !defined(CY_PINS_ULTRA_NAND_H) /* Pins ULTRA_NAND_H */
#define CY_PINS_ULTRA_NAND_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ULTRA_NAND_aliases.h"


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
} ULTRA_NAND_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   ULTRA_NAND_Read(void);
void    ULTRA_NAND_Write(uint8 value);
uint8   ULTRA_NAND_ReadDataReg(void);
#if defined(ULTRA_NAND__PC) || (CY_PSOC4_4200L) 
    void    ULTRA_NAND_SetDriveMode(uint8 mode);
#endif
void    ULTRA_NAND_SetInterruptMode(uint16 position, uint16 mode);
uint8   ULTRA_NAND_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void ULTRA_NAND_Sleep(void); 
void ULTRA_NAND_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(ULTRA_NAND__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define ULTRA_NAND_DRIVE_MODE_BITS        (3)
    #define ULTRA_NAND_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ULTRA_NAND_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the ULTRA_NAND_SetDriveMode() function.
         *  @{
         */
        #define ULTRA_NAND_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define ULTRA_NAND_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define ULTRA_NAND_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define ULTRA_NAND_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define ULTRA_NAND_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define ULTRA_NAND_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define ULTRA_NAND_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define ULTRA_NAND_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define ULTRA_NAND_MASK               ULTRA_NAND__MASK
#define ULTRA_NAND_SHIFT              ULTRA_NAND__SHIFT
#define ULTRA_NAND_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ULTRA_NAND_SetInterruptMode() function.
     *  @{
     */
        #define ULTRA_NAND_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define ULTRA_NAND_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define ULTRA_NAND_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define ULTRA_NAND_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(ULTRA_NAND__SIO)
    #define ULTRA_NAND_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(ULTRA_NAND__PC) && (CY_PSOC4_4200L)
    #define ULTRA_NAND_USBIO_ENABLE               ((uint32)0x80000000u)
    #define ULTRA_NAND_USBIO_DISABLE              ((uint32)(~ULTRA_NAND_USBIO_ENABLE))
    #define ULTRA_NAND_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define ULTRA_NAND_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define ULTRA_NAND_USBIO_ENTER_SLEEP          ((uint32)((1u << ULTRA_NAND_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << ULTRA_NAND_USBIO_SUSPEND_DEL_SHIFT)))
    #define ULTRA_NAND_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << ULTRA_NAND_USBIO_SUSPEND_SHIFT)))
    #define ULTRA_NAND_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << ULTRA_NAND_USBIO_SUSPEND_DEL_SHIFT)))
    #define ULTRA_NAND_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(ULTRA_NAND__PC)
    /* Port Configuration */
    #define ULTRA_NAND_PC                 (* (reg32 *) ULTRA_NAND__PC)
#endif
/* Pin State */
#define ULTRA_NAND_PS                     (* (reg32 *) ULTRA_NAND__PS)
/* Data Register */
#define ULTRA_NAND_DR                     (* (reg32 *) ULTRA_NAND__DR)
/* Input Buffer Disable Override */
#define ULTRA_NAND_INP_DIS                (* (reg32 *) ULTRA_NAND__PC2)

/* Interrupt configuration Registers */
#define ULTRA_NAND_INTCFG                 (* (reg32 *) ULTRA_NAND__INTCFG)
#define ULTRA_NAND_INTSTAT                (* (reg32 *) ULTRA_NAND__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define ULTRA_NAND_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(ULTRA_NAND__SIO)
    #define ULTRA_NAND_SIO_REG            (* (reg32 *) ULTRA_NAND__SIO)
#endif /* (ULTRA_NAND__SIO_CFG) */

/* USBIO registers */
#if !defined(ULTRA_NAND__PC) && (CY_PSOC4_4200L)
    #define ULTRA_NAND_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define ULTRA_NAND_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define ULTRA_NAND_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define ULTRA_NAND_DRIVE_MODE_SHIFT       (0x00u)
#define ULTRA_NAND_DRIVE_MODE_MASK        (0x07u << ULTRA_NAND_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins ULTRA_NAND_H */


/* [] END OF FILE */
