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
#if !defined(EEPROM_H) /* Pins BUTTON_DOWN_H */
#define EEPROM_H


char External_eeprom_read(unsigned char chip_address,unsigned char data_address,unsigned char*ptr);

void External_eeprom_write( unsigned char chip_address,unsigned char data_address,unsigned char data);

void External_eeprom_write_multiplebytes( unsigned char chip_address,unsigned char bytes_number,
    unsigned char data_start_address,int data);

int External_eeprom_read_multiplebytes( unsigned char chip_address,unsigned char bytes_number,
    unsigned char start_data_address);

#endif