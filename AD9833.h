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
#if !defined(AD9833_H) /* Pins BUTTON_DOWN_H */
#define AD9833_H
   
#define refFreq   25000000          // On-board crystal reference frequency  
#define sine      0x2000                    // Define AD9833's waveform register value.
#define square    0x2028                  // When we update the frequency, we need to
#define triangle  0x2002                // define the waveform when we end writing.    
#define loadbit   AD9833_SCLK_Write(0);AD9833_SCLK_Write(1)
#define AD9833_CS_Write(val)   // Define a function to write to the AD9833 CS pin

    
void AD9833_reset() ;
void AD9833_setFrequency(long int AD9833_frequency, int Waveform);
void STOP_AD9833();
#endif
/* [] END OF FILE */
