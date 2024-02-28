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
#include "AD9833_SCLK.h"
#include "AD9833_FSYNC.h"
#include "AD9833_SDATA.h"
#include "CyLib.h"
#include "AD9833.h"   
#include <math.h>
void send_data_register(int register_number)
{
    char i=0;
   
    ///////////////// msb first///////////////////////
    
     AD9833_FSYNC_Write(0);//CyDelay(10);
     for(i = 0; i < 16; i++)
    {
       if(register_number&0x8000)
          {AD9833_SDATA_Write(1);}
        else {AD9833_SDATA_Write(0);}
    
        loadbit;
        register_number <<= 1;
    }
    AD9833_FSYNC_Write(1);

       
}

void AD9833_reset() 
{
    send_data_register(0x100);
  CyDelay(10);
}


void AD9833_setFrequency(long int AD9833_frequency, int Waveform)
{

  long FreqWord = (AD9833_frequency * pow(2, 28)) / refFreq;

  int MSB = (int)((FreqWord & 0xFFFC000) >> 14);    //Only lower 14 bits are used for data
  int LSB = (int)(FreqWord & 0x3FFF);
  
  //Set control bits 15 ande 14 to 0 and 1, respectively, for frequency register 0
  LSB |= 0x4000;
  MSB |= 0x4000; 
  
send_data_register(0x2100);
send_data_register(LSB);  
send_data_register(MSB); 
send_data_register(Waveform);
}

                 // Function to stop AD9833 waveform generation
void STOP_AD9833() {
    unsigned char controlWord[] = { 0x21, 0x00 }; // Control word to disable output (example)
    send_data_register(controlWord[0]); // Send control word
    send_data_register(controlWord[1]); // Send additional bits
}

/* [] END OF FILE */
