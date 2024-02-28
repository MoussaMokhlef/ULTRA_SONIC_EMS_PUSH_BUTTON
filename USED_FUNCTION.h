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


#if !defined(USED_FUNCTION_h) /* Pins BUTTON_DOWN_H */
#define USED_FUNCTION_h
   
#define         OFF                                     0
#define         ON                                      1
#define         EEPROM                                  0b1010000   
#define         DEFULT_VALUE_OF_FREQ                    1000000
#define         STEP_OF_ULTRA_INTENSITY                 0.25f
  



extern _Bool FLAG_EMS_OR_ULTRA;
extern _Bool FLAG_START_STOP;
extern _Bool FLAG_SELECT;
extern _Bool FLAG_TEMP;
extern _Bool ULTRA_START_STOP;
extern _Bool ULTRA_CONFERMATION_FLAG;
extern _Bool ULTRA_CALIBRATION;
extern _Bool FLAG_TOTAL_TIME;
extern _Bool FLAG_OF_VALUE_OF_CHANGE;
extern unsigned char PAGE;
extern unsigned char TIMER_COUNTER;
extern unsigned char ULTRA_TIME;
extern unsigned char DUTY_CYCLE;
extern unsigned char EMS_CURRENT;
extern unsigned char EMS_MODE;
extern unsigned char EMS_FREQ;
extern unsigned char EMS_FREQ;
extern unsigned char EMS_FREQ_F;
extern unsigned char EMS_FREQ_L;
extern unsigned char EMS_FREQ_H;
extern unsigned char EMS_TIME;
extern unsigned char DAC_UPERR_LIMIT;
extern unsigned char DAC_VALUE;
extern unsigned char MINTE;
extern unsigned char SECOND;
extern unsigned long long int FREQ_OF_CALLIBRATION_ULTRA;
extern unsigned int  ULTRA_TOTAL_HOUR;
extern unsigned char ULTRA_TOTAL_MIUTE;
extern unsigned char ULTRA_TOTAL_SEC;
extern char  CHOISE_OF_ULTRA;
extern char  CHOISE_OF_EMS;
    
extern char *array_string_mode[];

extern char *array_string_current[];
extern char  array_of_freqency_F[3];
extern char  array_of_freqency_L[5];
extern char  array_of_freqency_H[4];

  
extern float ULTRA_INTENSITY;
void stateMachine(void);
void UP_DOWN_BUTTON(_Bool flag);
void SHOW_PAGE_1(void);
void SHOW_PAGE_ULTRA(void);
void SHOW_PAGE_EMS(void);
void BUZZER_ON_OFF(void);
void SHOW_CALLIBRATION_ULTRA(void);
void SHOW_TOTAL_TIME(void);   
             
#endif
/* [] END OF FILE */
