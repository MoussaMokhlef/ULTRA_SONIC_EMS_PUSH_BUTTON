/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/



#include"I2C.c"
#include "EEPROM.h"


/******************************************************************************/
/*                       02_ external_eeprom_write                            */
/*----------------------------------------------------------------------------*/
/* 1- Function Description -> write on external eeprom                        */
/* 2- Function Input       ->                                                 */
/*                     @param chip_address                                    */
/*                     @param data_address                                    */
/*                     @param data                                            */
/* 3- Function Return      -> @void                                           */
/******************************************************************************/
void External_eeprom_write( unsigned char chip_address,unsigned char data_address,unsigned char data)
{
    CyDelay(10); //this is just a precaution
    
    I2C_I2CMasterSendStart(chip_address,I2C_I2C_WRITE_XFER_MODE,20);//write the slave chip address
    I2C_I2CMasterWriteByte(data_address,20);//write the address inside the chip
    I2C_I2CMasterWriteByte(data,20);//write the data
    I2C_I2CMasterSendStop(20);
    CyDelay(10);//any stop need a delay before reading or else it didn't take mch time 
    //every sto we shou;ld wait 9 clocks
}

/******************************************************************************/
/*                       03_ external_eeprom_read                             */
/*----------------------------------------------------------------------------*/
/* 1- Function Description -> read on external eeprom                         */
/* 2- Function Input       ->                                                 */
/*                     @param chip_address                                    */
/*                     @param data_address                                    */
/*                     @param pointer to data                                 */
/* 3- Function Return      -> @current_state                                  */
/******************************************************************************/

char External_eeprom_read(unsigned char chip_address,unsigned char data_address,unsigned char*ptr)
{
    char current_state;
    CyDelay(10); //this is just a precaution
    current_state= I2C_I2CMasterSendStart(chip_address,I2C_I2C_WRITE_XFER_MODE,50);
    current_state=I2C_I2CMasterWriteByte(data_address,50);//write the address i want to reaD FROM 
    CyDelay(10);//this delay is to wait for the stop every sto we shou;ld wait 9 clocks
    current_state= I2C_I2CMasterSendRestart(chip_address,I2C_I2C_READ_XFER_MODE,50);
    //current_state=I2C_I2CMasterReadByte(I2C_I2C_ACK_DATA);
    current_state=I2C_I2CMasterReadByte(I2C_I2C_NAK_DATA,ptr,50);
    I2C_I2CMasterSendStop(20);
    return current_state;
    
}

void External_eeprom_write_multiplebytes( unsigned char chip_address,unsigned char bytes_number,
    unsigned char data_start_address,int data)
{ 
   
    for( ;bytes_number>0;bytes_number--)
    {
        char send=data>>(8*(bytes_number-1));
        External_eeprom_write(chip_address,data_start_address,send);
        data_start_address++;//we start from the address send    
    }
}
int External_eeprom_read_multiplebytes( unsigned char chip_address,unsigned char bytes_number,
    unsigned char start_data_address)
{
    unsigned char temp;
int result=0;
    for( ;bytes_number>0;bytes_number--)
    {
       External_eeprom_read(chip_address,start_data_address,&temp);
       result=(result<<8)|temp;
    start_data_address++;
        
    }
   return result; 
}
/* [] END OF FILE */