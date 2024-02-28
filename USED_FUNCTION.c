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
#include "USED_FUNCTION.h"
#include "CONVERT_F_INT.h"
#include "EEPROM.h"
#include "project.h"
#include "AD9833.h"


/******************************************************************************/
/*                          00_ UP_DOWN_BUTTON                                */
/*----------------------------------------------------------------------------*/
/* 1- Function Description -> handle up and downs buttons                     */
/* 2- Function Input       ->                                                 */
/*                     @param up_or_down                                      */
/* 3- Function Return      -> @void                                           */
/******************************************************************************/
void UP_DOWN_BUTTON(_Bool flag)
{

    switch(PAGE)
    {
        case 0:
            if(ULTRA_CALIBRATION)
            {
                if(flag)
                {
                    (FLAG_OF_VALUE_OF_CHANGE==OFF)?(FREQ_OF_CALLIBRATION_ULTRA+=1000):(FREQ_OF_CALLIBRATION_ULTRA+=100);
                }
                else
                {
                    (FLAG_OF_VALUE_OF_CHANGE==OFF)?(FREQ_OF_CALLIBRATION_ULTRA-=1000):(FREQ_OF_CALLIBRATION_ULTRA-=100);
                }
                
                SHOW_CALLIBRATION_ULTRA();
            }
            else if(!FLAG_TOTAL_TIME)
            {
             FLAG_EMS_OR_ULTRA=!FLAG_EMS_OR_ULTRA;
             SHOW_PAGE_1();
            }
        break;
        case 1:
            if(!FLAG_SELECT)
            {
             if(flag){if(CHOISE_OF_ULTRA>0) CHOISE_OF_ULTRA--;}
             else{if(CHOISE_OF_ULTRA<3)CHOISE_OF_ULTRA++;}
             SHOW_PAGE_ULTRA();
            }
            else if(FLAG_SELECT)
            {
                switch(CHOISE_OF_ULTRA)
                {
                    case 0:
                        if(flag)
                        {
                        ULTRA_INTENSITY+=STEP_OF_ULTRA_INTENSITY;
                        if(ULTRA_INTENSITY>3){ULTRA_INTENSITY=3;}    
                        }
                        else
                        {
                        ULTRA_INTENSITY-=STEP_OF_ULTRA_INTENSITY;
                        if(ULTRA_INTENSITY<STEP_OF_ULTRA_INTENSITY){ULTRA_INTENSITY=STEP_OF_ULTRA_INTENSITY;}   
                        }
              
                    break;
                    case 1:
                        if(flag)
                        {
                        DUTY_CYCLE+=10;
                        if(DUTY_CYCLE>100){ DUTY_CYCLE=100;  }      
                        }
                        else
                        {
                        DUTY_CYCLE-=10;
                        if(DUTY_CYCLE<10){ DUTY_CYCLE=10;  }       
                        }
              
              
                    break;
                    case 2:
                        if(flag)
                        {
                        ULTRA_TIME++;
                        if(ULTRA_TIME>10){ULTRA_TIME=10;}    
                        }
                        else
                        {
                        ULTRA_TIME--;
                        if(ULTRA_TIME<1){ULTRA_TIME=1;}    
                        }
              
                    break;
                    default:
                    //DO NOTHING
                    break;
                    
                }
                SHOW_PAGE_ULTRA();    
            }
        break;
        case 2:
            if(!FLAG_SELECT)
            {
             if(flag){if(CHOISE_OF_EMS>0) CHOISE_OF_EMS--;}
             else{if(CHOISE_OF_EMS<4)CHOISE_OF_EMS++;}
             SHOW_PAGE_EMS();
            }
            else if(FLAG_SELECT)
            {
                switch(CHOISE_OF_EMS)
                    {
                        case 0:
                            if(flag)
                            {
                            EMS_CURRENT++;
                            if(EMS_CURRENT>2){EMS_CURRENT=2;}    
                            }
                            else
                            {
                            EMS_CURRENT--;
                            if(EMS_CURRENT>10){EMS_CURRENT=0;}    
                            }
                 
                        break;
                        case 1:
                            if(flag)
                            {
                            EMS_MODE++;
                            if(EMS_MODE>2){EMS_MODE=2;}
                            }
                            else
                            {
                            EMS_MODE--;
                            if(EMS_MODE<10){EMS_MODE=0;}
                            }
                 
                        break;
                        case 2:
                            switch(EMS_CURRENT)
                            {
                                case 0:
                                        if(flag)
                                        {
                                        EMS_FREQ_F++;
                                        if(EMS_FREQ_F>2){EMS_FREQ_F=2;}
                                        }
                                        else
                                        {
                                        EMS_FREQ_F--;
                                        if(EMS_FREQ_F>10){EMS_FREQ_F=0;}
                                        }
                 
                                break;
                                case 1:
                                        if(flag)
                                        {
                                        EMS_FREQ_L++;
                                        if(EMS_FREQ_L>4){EMS_FREQ_L=4;}
                                        }
                                        else
                                        {
                                        EMS_FREQ_L--;
                                        if(EMS_FREQ_L>10){EMS_FREQ_L=0;}
                                        }
                 
                                break;
                                case 2:
                                        if(flag)
                                        {
                                        EMS_FREQ_H++;
                                        if(EMS_FREQ_H>3){EMS_FREQ_H=3;}
                                        }
                                        else
                                        {
                                        EMS_FREQ_H--;
                                        if(EMS_FREQ_H>10){EMS_FREQ_H=0;}
                                        }
                 
                                break;
                                default:
                                break;
                            }   
                        break;
                        case 3:
                            if(flag)
                            {
                            EMS_TIME+=5;
                            if(EMS_TIME>30){EMS_TIME=30;}
                            }
                            else
                            {
                            EMS_TIME-=5;
                            if(EMS_TIME<5){EMS_TIME=5;}
                            }
                 
                        break;
                        default:
                        //DO NOTHING
                        break;
                        
                    }
                    SHOW_PAGE_EMS();
        
            }
       
        break;
        default:break;
    }

    /*
   if(ULTRA_CALIBRATION)
    {
        if(flag)
        {
            (FLAG_OF_VALUE_OF_CHANGE==OFF)?(FREQ_OF_CALLIBRATION_ULTRA+=1000):(FREQ_OF_CALLIBRATION_ULTRA+=100);
        }
        else
        {
            (FLAG_OF_VALUE_OF_CHANGE==OFF)?(FREQ_OF_CALLIBRATION_ULTRA-=1000):(FREQ_OF_CALLIBRATION_ULTRA-=100);
        }
        
        SHOW_CALLIBRATION_ULTRA();
    }
    if(!FLAG_SELECT&&!ULTRA_CALIBRATION)
    {
    if(!PAGE&&!FLAG_TOTAL_TIME)
    {
     FLAG_EMS_OR_ULTRA=!FLAG_EMS_OR_ULTRA;
     SHOW_PAGE_1();
    }
    else if(PAGE==1&&!ULTRA_START_STOP)
    {
     if(flag){if(CHOISE_OF_ULTRA>0) CHOISE_OF_ULTRA--;}
     else{if(CHOISE_OF_ULTRA<3)CHOISE_OF_ULTRA++;}
     
     //if(CHOISE_OF_ULTRA<0){CHOISE_OF_ULTRA=3;}
    SHOW_PAGE_ULTRA();
    }
    else if(PAGE==2)
    {
     if(flag)
     {
      if(CHOISE_OF_EMS>0) CHOISE_OF_EMS--; 
     }
     else
     {
        if(CHOISE_OF_EMS<4)CHOISE_OF_EMS++; 
     }
    
    // if(CHOISE_OF_EMS<0){CHOISE_OF_EMS=4;}   
    SHOW_PAGE_EMS();
    }    
    }
    else
    {
    if(PAGE==1)
    {
        switch(CHOISE_OF_ULTRA)
        {
            case 0:
                if(flag)
                {
                ULTRA_INTENSITY+=STEP_OF_ULTRA_INTENSITY;
                if(ULTRA_INTENSITY>3){ULTRA_INTENSITY=3;}    
                }
                else
                {
                ULTRA_INTENSITY-=STEP_OF_ULTRA_INTENSITY;
                if(ULTRA_INTENSITY<STEP_OF_ULTRA_INTENSITY){ULTRA_INTENSITY=STEP_OF_ULTRA_INTENSITY;}   
                }

            break;
            case 1:
                if(flag)
                {
                DUTY_CYCLE+=10;
                if(DUTY_CYCLE>100){ DUTY_CYCLE=100;  }      
                }
                else
                {
                DUTY_CYCLE-=10;
                if(DUTY_CYCLE<10){ DUTY_CYCLE=10;  }       
                }
 

            break;
            case 2:
                if(flag)
                {
                ULTRA_TIME++;
                if(ULTRA_TIME>10){ULTRA_TIME=10;}    
                }
                else
                {
                ULTRA_TIME--;
                if(ULTRA_TIME<1){ULTRA_TIME=1;}    
                }

            break;
            default:
            //DO NOTHING
            break;
            
        }
        SHOW_PAGE_ULTRA();
    }
    if(PAGE==2)
    {
        switch(CHOISE_OF_EMS)
        {
            case 0:
                if(flag)
                {
                EMS_CURRENT++;
                if(EMS_CURRENT>2){EMS_CURRENT=2;}    
                }
                else
                {
                EMS_CURRENT--;
                if(EMS_CURRENT>10){EMS_CURRENT=0;}    
                }

            break;
            case 1:
                if(flag)
                {
                EMS_MODE++;
                if(EMS_MODE>2){EMS_MODE=2;}
                }
                else
                {
                EMS_MODE--;
                if(EMS_MODE<10){EMS_MODE=0;}
                }

            break;
            case 2:
                switch(EMS_CURRENT)
                {
                    case 0:
                            if(flag)
                            {
                            EMS_FREQ_F++;
                            if(EMS_FREQ_F>2){EMS_FREQ_F=2;}
                            }
                            else
                            {
                            EMS_FREQ_F--;
                            if(EMS_FREQ_F>10){EMS_FREQ_F=0;}
                            }

                    break;
                    case 1:
                            if(flag)
                            {
                            EMS_FREQ_L++;
                            if(EMS_FREQ_L>4){EMS_FREQ_L=4;}
                            }
                            else
                            {
                            EMS_FREQ_L--;
                            if(EMS_FREQ_L>10){EMS_FREQ_L=0;}
                            }

                    break;
                    case 2:
                            if(flag)
                            {
                            EMS_FREQ_H++;
                            if(EMS_FREQ_H>3){EMS_FREQ_H=3;}
                            }
                            else
                            {
                            EMS_FREQ_H--;
                            if(EMS_FREQ_H>10){EMS_FREQ_H=0;}
                            }

                    break;
                    default:
                    break;
                }   
            break;
            case 3:
                if(flag)
                {
                EMS_TIME+=5;
                if(EMS_TIME>30){EMS_TIME=30;}
                }
                else
                {
                EMS_TIME-=5;
                if(EMS_TIME<5){EMS_TIME=5;}
                }

            break;
            default:
            //DO NOTHING
            break;
            
        }
        SHOW_PAGE_EMS();
    }
    }
*/
    
}
void SHOW_PAGE_1(void)
{
    LCD_ClearDisplay();
    if(!FLAG_EMS_OR_ULTRA)
    {
    LCD_Position(1,4);
    LCD_PutChar(LCD_CUSTOM_0);   
    }
    else
    {
    LCD_Position(2,4);
    LCD_PutChar(LCD_CUSTOM_0);  
    }
    LCD_Position(1,5);
    LCD_PrintString("ULTRA SONIC");
    LCD_Position(2,5);
    LCD_PrintString("    EMS  ");
}
void SHOW_PAGE_ULTRA(void)
{
    
    LCD_ClearDisplay();
    if(CHOISE_OF_ULTRA<3)
    {
    LCD_Position(CHOISE_OF_ULTRA ,0);
    LCD_PutChar(LCD_CUSTOM_0);     
    }
    else
    {
    LCD_Position(CHOISE_OF_ULTRA ,15);
    LCD_PutChar(LCD_CUSTOM_0);     
    }
    LCD_Position(0,1);
    LCD_PrintString("POWER :");
    char BUFFER[5];
    floatToStr(ULTRA_INTENSITY,BUFFER);
    LCD_PrintString(BUFFER);
    LCD_PutChar('W');   
    LCD_Position(1,1);
    LCD_PrintString("MODE  :");
    LCD_PrintNumber(DUTY_CYCLE);
    LCD_Position(2,1);
    LCD_PrintString("TIME  :");
    LCD_PrintNumber(ULTRA_TIME);
    LCD_Position(3,16);
    LCD_PrintString("BACK");
    
}
void SHOW_PAGE_EMS(void)
{
    LCD_ClearDisplay();
    if(CHOISE_OF_EMS<4)
    {
    LCD_Position(CHOISE_OF_EMS ,0);
    LCD_PutChar(LCD_CUSTOM_0);     
    }
    else
    {
    LCD_Position(3 ,15);
    LCD_PutChar(LCD_CUSTOM_0);     
    }
    LCD_Position(0,1);
    LCD_PrintString("CURR  :");
    LCD_PrintString(array_string_current[EMS_CURRENT]);
    LCD_Position(1,1);
    LCD_PrintString("MODE  :");
    LCD_PrintString(array_string_mode[EMS_MODE]);
    LCD_Position(2,1);
    LCD_PrintString("FREQ  :");
    switch(EMS_CURRENT)
     {
        case 0:
        LCD_PrintNumber(array_of_freqency_F[EMS_FREQ_F]);
        LCD_PrintString(" HZ");
        break;
        case 1:
        LCD_PrintNumber(array_of_freqency_L[EMS_FREQ_L]);
        LCD_PrintString(" HZ");
        break;
        case 2:
        LCD_PrintNumber(array_of_freqency_H[EMS_FREQ_H]);
        LCD_PrintString(" HZ");
        break;
        default:
        break;
     }
    LCD_Position(3,1);
    LCD_PrintString("TIME  :");
    LCD_PrintNumber(EMS_TIME);
    LCD_PrintString(" M");
    LCD_Position(3,16);
    LCD_PrintString("BACK");
}
void BUZZER_ON_OFF(void)
{
    BUZZER_Write(ON);
    CyDelay(3000);
    BUZZER_Write(OFF);
}
void SHOW_CALLIBRATION_ULTRA(void)
{
    LCD_ClearDisplay();   
    LCD_Position(1,0);
    LCD_PrintString(" VALUE OF FREQUENCY ");
    LCD_Position(2,6);
    unsigned int temp=(FREQ_OF_CALLIBRATION_ULTRA/100);
    LCD_PrintNumber(temp);
    LCD_PrintNumber(0);
    LCD_PrintNumber(0);
    
}
void SHOW_TOTAL_TIME(void)
{
     LCD_ClearDisplay();   
    LCD_Position(0,0);
    LCD_PrintString("  TOTAL ULTRA TIME ");
    LCD_Position(1,6);
    LCD_PrintNumber(ULTRA_TOTAL_HOUR);
    LCD_PutChar(':');
    LCD_PrintNumber(ULTRA_TOTAL_MIUTE);
    LCD_PutChar(':');
    LCD_PrintNumber(ULTRA_TOTAL_SEC);

}
/* [] END OF FILE */
