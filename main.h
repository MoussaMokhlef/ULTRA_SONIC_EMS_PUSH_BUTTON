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
#if !defined(MAIN_H) /* Pins BUTTON_DOWN_H */
#define MAIN_H
#define         OFF                                     0
#define         ON                                      1
#define         EEPROM                                  0b1010000   
#define         DEFULT_VALUE_OF_FREQ                    1000000
#define         ADD_EEPROM_ULTRA_FREQ_OF_CALLIBRATION   0x00
#define         ADD_EEPROM_ULTRA_POWER                  0x04
#define         ADD_EEPROM_ULTRA_DUTY_CICLE             0x05
#define         ADD_EEPROM_ULTRA_TIME                   0x06
#define         ADD_EEPROM_TOTAL_HOUR                   0x07
#define         ADD_EEPROM_TOTAL_MINUTE                 0x0B
#define         ADD_EEPROM_TOTAL_SECOND                 0x0C
#define         FUN(x) (x*255/3)
    
typedef enum {
    STATE_DEFULT,
    STATE_START_BUTTON,
    STATE_SELECT_BUTTON,
    STATE_UP_BUTTON,
    STATE_DOWN_BUTTON,
} State_button;

State_button CURRENT_BUTTON_STATE=STATE_DEFULT;
_Bool          FLAG_EMS_OR_ULTRA=OFF;
_Bool          FLAG_START_STOP=OFF;
_Bool          FLAG_SELECT=OFF;
_Bool FLAG_TEMP=OFF;
_Bool ULTRA_START_STOP=OFF;
_Bool ULTRA_CONFERMATION_FLAG=OFF;
_Bool ULTRA_CALIBRATION=OFF;
_Bool FLAG_TOTAL_TIME=OFF;
_Bool FLAG_OF_VALUE_OF_CHANGE=OFF;
unsigned char  PAGE;
unsigned char TIMER_COUNTER;
unsigned char ULTRA_TIME=5;
unsigned char DUTY_CYCLE=50;
unsigned char EMS_CURRENT;
unsigned char EMS_MODE;
unsigned char EMS_FREQ;
unsigned char EMS_FREQ;
unsigned char EMS_FREQ_F;
unsigned char EMS_FREQ_L;
unsigned char EMS_FREQ_H;
unsigned char EMS_TIME=5;
unsigned char DAC_UPERR_LIMIT;
unsigned char DAC_VALUE;
unsigned char MINTE;
unsigned char SECOND;
unsigned long long int FREQ_OF_CALLIBRATION_ULTRA;
unsigned int  ULTRA_TOTAL_HOUR;
unsigned char ULTRA_TOTAL_MIUTE;
unsigned char ULTRA_TOTAL_SEC;
unsigned int  EMS_TOTAL_HOUR;
unsigned char EMS_TOTAL_MIUTE;
unsigned char EMS_TOTAL_SEC;
char  CHOISE_OF_ULTRA;
char  CHOISE_OF_EMS;
   
char *array_string_mode[]={        ("Continous"),    /*array contain to modes of project */
                                   ("3:3"),
                                   ("5:5")};

char *array_string_current[]=     {("FARADIC"),      /*array contain to types of current */
                                   ("LOW TENS"),
                                   ("HIGH TENS")};
char  array_of_freqency_F[3]=   {50,70,100};       /*array contain to types of frequency */
char  array_of_freqency_L[5]=   {1,3,5,10,20};       /*array contain to types of frequency */
char  array_of_freqency_H[4]=   {50,70,100,130};       /*array contain to types of frequency */

    
float ULTRA_INTENSITY=2.5;

#endif
/* [] END OF FILE */
