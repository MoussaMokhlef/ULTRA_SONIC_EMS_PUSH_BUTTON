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
#include "project.h"
#include "USED_FUNCTION.h"
#include "project.h"
#include "EEPROM.h"
#include "AD9833.h"
#include "main.h"

void stateMachine(void);

//void stateMachine(void);
/************************************************************/
/*                     prototype of isr                     */
/************************************************************/
CY_ISR_PROTO (TIMER_HANDLER);
CY_ISR_PROTO (START_STOP_HANDLER);
CY_ISR_PROTO (SELECT_HANDLER);
CY_ISR_PROTO (UP_BOTTON_HANDLER);
CY_ISR_PROTO (DOWN_BOTTON_HANDLER);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    

    PWM_1_Start();
    LCD_Start();
    I2C_Start();
    I2C_Enable();
    PWM_2_Start();
    STOP_AD9833();
    IDAC_1_Start();IDAC_1_SetValue(OFF);  
    Timer_1_Start();
    Control_Reg_2_Write(ON);
    Control_Reg_1_Write(ON);
    IDAC_1_SetValue(OFF);
    STEP_DOWN_Write(OFF);
    unsigned char CHECK_FIRST;
    if(External_eeprom_read(EEPROM,0xEE,&CHECK_FIRST))
    {
    LCD_ClearDisplay();
    LCD_Position(0,0);
    LCD_PrintString(" ...WARNNING... ");
    LCD_Position(1,0);
    LCD_PrintString("FAULT ON EEPROM ");
     CyDelay(5000);  
    }
    if(CHECK_FIRST!=0xCC)
    {
        External_eeprom_write(EEPROM,0xEE,0xCC);
        External_eeprom_write(EEPROM,ADD_EEPROM_ULTRA_POWER,10);
        External_eeprom_write(EEPROM,ADD_EEPROM_ULTRA_DUTY_CICLE,50);
        External_eeprom_write(EEPROM,ADD_EEPROM_ULTRA_TIME,10);
        External_eeprom_write_multiplebytes(EEPROM,4,ADD_EEPROM_TOTAL_HOUR,0);
        External_eeprom_write(EEPROM,ADD_EEPROM_TOTAL_MINUTE,0);
        External_eeprom_write(EEPROM,ADD_EEPROM_TOTAL_SECOND,0);
        FREQ_OF_CALLIBRATION_ULTRA=DEFULT_VALUE_OF_FREQ;
        ULTRA_CALIBRATION=ON;
        SHOW_CALLIBRATION_ULTRA();
        //External_eeprom_write_multiplebytes(EEPROM,0xEE,0xCC);
    }
    FREQ_OF_CALLIBRATION_ULTRA=External_eeprom_read_multiplebytes(EEPROM,4,ADD_EEPROM_ULTRA_FREQ_OF_CALLIBRATION)*100;
    if(BUTTON_DOWN_Read()&&BUTTON_UP_Read())
    {
        ULTRA_CALIBRATION=ON;
        SHOW_CALLIBRATION_ULTRA();
        isr_button_down_ClearPending();
        isr_button_up_ClearPending();
    }
    unsigned char ultra_temp=0;
    External_eeprom_read(EEPROM,ADD_EEPROM_ULTRA_POWER,&ultra_temp);
    ULTRA_INTENSITY=(float)ultra_temp/4;
    External_eeprom_read(EEPROM,ADD_EEPROM_ULTRA_DUTY_CICLE,&DUTY_CYCLE);
    External_eeprom_read(EEPROM,ADD_EEPROM_ULTRA_TIME,&ULTRA_TIME);
    ULTRA_TOTAL_HOUR=External_eeprom_read_multiplebytes(EEPROM,4,ADD_EEPROM_TOTAL_HOUR);
    External_eeprom_read(EEPROM,ADD_EEPROM_TOTAL_MINUTE,&ULTRA_TOTAL_MIUTE);
    External_eeprom_read(EEPROM,ADD_EEPROM_TOTAL_SECOND,&ULTRA_TOTAL_SEC);
    if(START_STOP_Read()&&SELECT_PIN_Read())
    {
        FLAG_TOTAL_TIME=ON;
        SHOW_TOTAL_TIME();
        isr_start_stop_ClearPending();
        isr_select_ClearPending();
    }
    if(!ULTRA_CALIBRATION&&!FLAG_TOTAL_TIME){SHOW_PAGE_1();};
    isr_start_stop_StartEx(START_STOP_HANDLER);
    isr_select_StartEx(SELECT_HANDLER);
    ISR_SCHEDULAR_StartEx(TIMER_HANDLER);
    isr_button_up_StartEx(UP_BOTTON_HANDLER);
    isr_button_down_StartEx(DOWN_BOTTON_HANDLER);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
     
    for(;;)
    {
        /* Place your application code here. */
        asm("NOP");
    
    }
}

/************************************************************/
/*         interrupt service routine of timer               */
/************************************************************/

CY_ISR(TIMER_HANDLER)
{
       TIMER_COUNTER++;
    
        if(TOUCH_UP_Read())
        {
            ULTRA_CONFERMATION_FLAG=ON;
            STEP_DOWN_Write(ON);
        }
        else
        {
            ULTRA_CONFERMATION_FLAG=OFF;
            DAC_VALUE=OFF;
            IDAC_1_SetValue(0);  
            STEP_DOWN_Write(OFF);
        }
        if(ULTRA_START_STOP&&ULTRA_CONFERMATION_FLAG)
        {
            if((DAC_VALUE<DAC_UPERR_LIMIT)){IDAC_1_SetValue(DAC_VALUE);DAC_VALUE+=10;}
            else{IDAC_1_SetValue(DAC_UPERR_LIMIT);}
            
        }
    if(TIMER_COUNTER==20)
    {
     TIMER_COUNTER=0;
     if(ULTRA_START_STOP&&ULTRA_CONFERMATION_FLAG)  
     {
        SECOND--;
        if(++ULTRA_TOTAL_SEC==60)
        {
            ULTRA_TOTAL_SEC=0;
            ULTRA_TOTAL_MIUTE++;
            if(ULTRA_TOTAL_MIUTE==60){ULTRA_TOTAL_HOUR++;}
        }
        
        if(SECOND==0)
        {
            MINTE--;
            SECOND=60;
            if(MINTE==0)
            {
               STOP_AD9833();
               ULTRA_START_STOP=OFF; 
               STEP_DOWN_Write(OFF); 
               IDAC_1_SetValue(0);
               Control_Reg_2_Write(0); 
               SHOW_PAGE_ULTRA();
               BUZZER_ON_OFF();
               External_eeprom_write_multiplebytes(EEPROM,4,ADD_EEPROM_TOTAL_HOUR,ULTRA_TOTAL_HOUR);
               External_eeprom_write(EEPROM,ADD_EEPROM_TOTAL_MINUTE,ULTRA_TOTAL_MIUTE);
               External_eeprom_write(EEPROM,ADD_EEPROM_TOTAL_SECOND,ULTRA_TOTAL_SEC);
            }
        }
     } 
    }
    
    if(TIMER_COUNTER%10==0)
    {
        FLAG_TEMP=!FLAG_TEMP;
        if(PAGE!=0&&FLAG_SELECT)
        {
        
        if(FLAG_TEMP){
            LCD_Position((CHOISE_OF_ULTRA|CHOISE_OF_EMS),1);
            LCD_PrintString("      ");

        }
        else{
            if(PAGE==1){SHOW_PAGE_ULTRA();}
            else{SHOW_PAGE_EMS();}
            
        }      
        }
        if(ULTRA_START_STOP&&ULTRA_CONFERMATION_FLAG&&FLAG_TEMP)
        {
          LCD_Position(2,8);
          LCD_PrintString("     ");
        }
        else if(ULTRA_START_STOP&&ULTRA_CONFERMATION_FLAG&&!FLAG_TEMP)
        {
         LCD_Position(2,8);
         if(MINTE-1<10){LCD_PrintNumber(0);LCD_Position(2,9);}
         LCD_PrintNumber(MINTE-1);
         LCD_Position(2,10);
         LCD_PutChar(':');
         LCD_Position(2,11);
         if(SECOND-1<10){LCD_PrintNumber(0);LCD_Position(2,12);}
         LCD_PrintNumber(SECOND-1);
        }
        else if(ULTRA_START_STOP&&!ULTRA_CONFERMATION_FLAG&&PAGE==1)
        {
         LCD_Position(2,8);
         if(MINTE-1<10){LCD_PrintNumber(0);LCD_Position(2,9);}
         LCD_PrintNumber(MINTE-1);
         LCD_Position(2,10);
         LCD_PutChar(':');
         LCD_Position(2,11);
         if(SECOND-1<10){LCD_PrintNumber(0);LCD_Position(2,12);}
         LCD_PrintNumber(SECOND-1);
        }
        
    }
  
   Timer_1_ClearInterrupt(Timer_1_INTR_MASK_CC_MATCH);
}

/*******************************************************************/
/*      interrupt service routine of start stop external pin       */
/*******************************************************************/
CY_ISR(START_STOP_HANDLER)
{  
    CURRENT_BUTTON_STATE=STATE_START_BUTTON;
    stateMachine();
    /*
    if(PAGE==1&&CHOISE_OF_ULTRA!=3)
    {
      ULTRA_START_STOP=!ULTRA_START_STOP;
      if(ULTRA_START_STOP)
      {
       SECOND=60;
       FLAG_SELECT=OFF;
       SHOW_PAGE_ULTRA();
       MINTE=ULTRA_TIME;
       AD9833_reset(); 
       AD9833_setFrequency(998000,square);
       PWM_2_WritePeriod((1000));
       PWM_2_WriteCompare1((100-(DUTY_CYCLE))*10);
       Control_Reg_2_Write(0);
       DAC_UPERR_LIMIT=(FUN(ULTRA_INTENSITY));
       BUZZER_Write(ON);
       CyDelay(50);
       BUZZER_Write(OFF);  
      }
      else
      {
      
       STOP_AD9833();
       STEP_DOWN_Write(OFF); 
       IDAC_1_SetValue(0);
       Control_Reg_2_Write(0);
       SHOW_PAGE_ULTRA();
       External_eeprom_write_multiplebytes(EEPROM,4,7,ULTRA_TOTAL_HOUR);
       External_eeprom_write(EEPROM,0x0B,ULTRA_TOTAL_MIUTE);
       External_eeprom_write(EEPROM,0x0C,ULTRA_TOTAL_SEC);
      }
    }
    if(ULTRA_CALIBRATION)
    {
      FLAG_EMS_OR_ULTRA=OFF; SHOW_PAGE_1();
      ULTRA_CALIBRATION=OFF;
      External_eeprom_write_multiplebytes(EEPROM,4,0,FREQ_OF_CALLIBRATION_ULTRA/100);
    }
    if(FLAG_TOTAL_TIME)
    {
       FLAG_EMS_OR_ULTRA=OFF; SHOW_PAGE_1();  FLAG_TOTAL_TIME=OFF;
    }
    */
    while(START_STOP_Read());
    START_STOP_ClearInterrupt();
}
/*******************************************************************/
/*        interrupt service routine of select external pin         */
/*******************************************************************/
CY_ISR(SELECT_HANDLER)
{
    if(!ULTRA_START_STOP&&!FLAG_START_STOP)
    {
    CURRENT_BUTTON_STATE=STATE_SELECT_BUTTON;
    stateMachine();    
    }

/*
    if(PAGE==1&&CHOISE_OF_ULTRA<3&&!ULTRA_START_STOP){FLAG_SELECT=!FLAG_SELECT;}
    else if(PAGE==2&&CHOISE_OF_EMS<4){FLAG_SELECT=!FLAG_SELECT;} 
    
    if(!FLAG_SELECT&&PAGE==1&&!ULTRA_START_STOP)
    {
        SHOW_PAGE_ULTRA();
    }
    else if(!FLAG_SELECT&&PAGE==2){SHOW_PAGE_EMS();} 
    if(PAGE==0&&!FLAG_TOTAL_TIME&&!ULTRA_CALIBRATION)
    {
    if(FLAG_EMS_OR_ULTRA==0){PAGE=1;SHOW_PAGE_ULTRA();  }
    else{PAGE=2;SHOW_PAGE_EMS();}
    }
    else
    {
    if((PAGE==1)&&(CHOISE_OF_ULTRA==3)){PAGE=0; CHOISE_OF_ULTRA=0; FLAG_EMS_OR_ULTRA=OFF; SHOW_PAGE_1();}
    if((PAGE==2)&&(CHOISE_OF_EMS==4)){PAGE=0; CHOISE_OF_EMS=0; FLAG_EMS_OR_ULTRA=OFF; SHOW_PAGE_1();}    
    }
    if(ULTRA_CALIBRATION)
    {
        FLAG_OF_VALUE_OF_CHANGE=!FLAG_OF_VALUE_OF_CHANGE;
    }
    */
    while(SELECT_PIN_Read());
    SELECT_PIN_ClearInterrupt();
}
/*******************************************************************/
/*           interrupt service routine of up external pin          */
/*******************************************************************/
CY_ISR(UP_BOTTON_HANDLER)
{
    if(!ULTRA_START_STOP&&!FLAG_START_STOP)
    {
    CURRENT_BUTTON_STATE=STATE_UP_BUTTON;
    stateMachine();
    }
    //UP_DOWN_BUTTON(ON);
    /*
    if(ULTRA_CALIBRATION)
    {
        (FLAG_OF_VALUE_OF_CHANGE==OFF)?(FREQ_OF_CALLIBRATION_ULTRA+=1000):(FREQ_OF_CALLIBRATION_ULTRA+=100);
        SHOW_CALLIBRATION_ULTRA();
    }
    if(!FLAG_SELECT&&!ULTRA_CALIBRATION)
    {
    if(!PAGE)
    {
     FLAG_EMS_OR_ULTRA=!FLAG_EMS_OR_ULTRA;
     SHOW_PAGE_1();
    }
    else if(PAGE==1&&!ULTRA_START_STOP)
    {
     if(CHOISE_OF_ULTRA>0) CHOISE_OF_ULTRA--;
     //if(CHOISE_OF_ULTRA<0){CHOISE_OF_ULTRA=3;}
    SHOW_PAGE_ULTRA();
    }
    else if(PAGE==2)
    {
     if(CHOISE_OF_EMS>0) CHOISE_OF_EMS--;
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
                 ULTRA_INTENSITY+=0.25;
                if(ULTRA_INTENSITY>3){ULTRA_INTENSITY=3;}
            break;
            case 1:
                DUTY_CYCLE+=10;
                if(DUTY_CYCLE>100){ DUTY_CYCLE=100;  }   

            break;
            case 2:
                ULTRA_TIME++;
                if(ULTRA_TIME>10){ULTRA_TIME=10;}
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
                 EMS_CURRENT++;
                if(EMS_CURRENT>2){EMS_CURRENT=2;}
            break;
            case 1:
                EMS_MODE++;
                if(EMS_MODE>2){EMS_MODE=2;}
            break;
            case 2:
                switch(EMS_CURRENT)
                {
                    case 0:
                    EMS_FREQ_F++;
                    if(EMS_FREQ_F>2){EMS_FREQ_F=2;}
                    break;
                    case 1:
                    EMS_FREQ_L++;
                    if(EMS_FREQ_L>4){EMS_FREQ_L=4;}
                    break;
                    case 2:
                    EMS_FREQ_H++;
                    if(EMS_FREQ_H>3){EMS_FREQ_H=3;}
                    break;
                    default:
                    break;
                }   
            break;
            case 3:
            EMS_TIME+=5;
            if(EMS_TIME>30){EMS_TIME=30;}
            break;
            default:
            //DO NOTHING
            break;
            
        }
        SHOW_PAGE_EMS();
    }
    }
*/
    while(BUTTON_UP_Read());
    BUTTON_UP_ClearInterrupt();
}
/*******************************************************************/
/*         interrupt service routine of down external pin          */
/*******************************************************************/
CY_ISR(DOWN_BOTTON_HANDLER)
{
    if(!ULTRA_START_STOP&&!FLAG_START_STOP)
    {
    CURRENT_BUTTON_STATE=STATE_DOWN_BUTTON;
    stateMachine();
    }
    //UP_DOWN_BUTTON(OFF);
    /*
    if(ULTRA_CALIBRATION)
    {
        FREQ_OF_CALLIBRATION_ULTRA-=100;
        SHOW_CALLIBRATION_ULTRA();
    }
    if(!FLAG_SELECT&&!ULTRA_CALIBRATION)
    {
    if(!PAGE)
    {
     FLAG_EMS_OR_ULTRA=!FLAG_EMS_OR_ULTRA;
     SHOW_PAGE_1();
    }
    else if(PAGE==1&&!ULTRA_START_STOP)
    {
     if(CHOISE_OF_ULTRA<3)CHOISE_OF_ULTRA++;
     //if(CHOISE_OF_ULTRA>3){CHOISE_OF_ULTRA=0;}
    SHOW_PAGE_ULTRA();
    }
    else if(PAGE==2)
    {
     if(CHOISE_OF_EMS<4)CHOISE_OF_EMS++;
     //if(CHOISE_OF_EMS>4){CHOISE_OF_EMS=0;}   
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
                 ULTRA_INTENSITY-=0.25;
                if(ULTRA_INTENSITY<0.25){ULTRA_INTENSITY=0.25;}
            break;
            case 1:
                DUTY_CYCLE-=10;
                if(DUTY_CYCLE<10){ DUTY_CYCLE=10;  }   
            break;
            case 2:
                ULTRA_TIME--;
                if(ULTRA_TIME<1){ULTRA_TIME=1;}
 
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
                 EMS_CURRENT--;
                if(EMS_CURRENT>10){EMS_CURRENT=0;}
            break;
            case 1:
                EMS_MODE--;
                if(EMS_MODE<10){EMS_MODE=0;}
            break;
            case 2:
                switch(EMS_CURRENT)
                {
                    case 0:
                    EMS_FREQ_F--;
                    if(EMS_FREQ_F>10){EMS_FREQ_F=0;}
                    break;
                    case 1:
                    EMS_FREQ_L--;
                    if(EMS_FREQ_L>10){EMS_FREQ_L=0;}
                    break;
                    case 2:
                    EMS_FREQ_H--;
                    if(EMS_FREQ_H>10){EMS_FREQ_H=0;}
                    break;
                    default:
                    break;
                }
                EMS_FREQ--;
                if(DUTY_CYCLE<10){ DUTY_CYCLE=10;  }    
            break;
            case 3:
            EMS_TIME-=5;
            if(EMS_TIME<5){EMS_TIME=5;}
            break;
            default:
            //DO NOTHING
            break;
            
        }
        SHOW_PAGE_EMS();
    }
    
  
    }
    */
    while(BUTTON_DOWN_Read());
    BUTTON_DOWN_ClearInterrupt();
}


void stateMachine(void)
{
   switch(CURRENT_BUTTON_STATE)
   {
    case STATE_DEFULT:
    SHOW_PAGE_1();
    break;
    case STATE_START_BUTTON:
    switch(PAGE)
    {
        case 0:
        // do nothing
        if(ULTRA_CALIBRATION)
        {
          FLAG_EMS_OR_ULTRA=OFF; SHOW_PAGE_1();
          ULTRA_CALIBRATION=OFF;
          External_eeprom_write_multiplebytes(EEPROM,4,0,FREQ_OF_CALLIBRATION_ULTRA/100);
        }
        else if(FLAG_TOTAL_TIME)
        {
          FLAG_EMS_OR_ULTRA=OFF; SHOW_PAGE_1();  FLAG_TOTAL_TIME=OFF;
        }
        break;
        case 1:
        ULTRA_START_STOP=!ULTRA_START_STOP;
        if(ULTRA_START_STOP)
        {
         SECOND=60;
         FLAG_SELECT=OFF;
         SHOW_PAGE_ULTRA();
         MINTE=ULTRA_TIME;
         AD9833_reset(); 
         AD9833_setFrequency(998000,square);
         PWM_2_WritePeriod((1000));
         (DUTY_CYCLE==100)?(PWM_2_WriteCompare1(0)):(PWM_2_WriteCompare1((100-(DUTY_CYCLE))*10));
         //PWM_2_WriteCompare1((100-(DUTY_CYCLE))*10);
         Control_Reg_2_Write(0);
         DAC_UPERR_LIMIT=(FUN(ULTRA_INTENSITY));
         BUZZER_Write(ON);
         CyDelay(50);
         BUZZER_Write(OFF);  
        }
        else
        {
        
         STOP_AD9833();
         STEP_DOWN_Write(OFF); 
         IDAC_1_SetValue(0);
         Control_Reg_2_Write(0);
         SHOW_PAGE_ULTRA();
         External_eeprom_write_multiplebytes(EEPROM,4,7,ULTRA_TOTAL_HOUR);
         External_eeprom_write(EEPROM,0x0B,ULTRA_TOTAL_MIUTE);
         External_eeprom_write(EEPROM,0x0C,ULTRA_TOTAL_SEC);
        }
        
        break;
        case 2:
        FLAG_START_STOP=!FLAG_START_STOP;
        break;
    }
    break;
    case STATE_SELECT_BUTTON:
    switch(PAGE)
    {
        case 0:
        if(ULTRA_CALIBRATION)
        {
            FLAG_OF_VALUE_OF_CHANGE=!FLAG_OF_VALUE_OF_CHANGE;
        }
        else if(!ULTRA_CALIBRATION&&!FLAG_TOTAL_TIME)
        {
            if(FLAG_EMS_OR_ULTRA==0){PAGE=1;SHOW_PAGE_ULTRA();  }
            else{PAGE=2;SHOW_PAGE_EMS();}   
        }
        else{}
        break;
        case 1:
            if(CHOISE_OF_ULTRA<3){FLAG_SELECT=!FLAG_SELECT;}   
            if(!FLAG_SELECT){SHOW_PAGE_ULTRA();}
            if(CHOISE_OF_ULTRA==3){PAGE=0; CHOISE_OF_ULTRA=0; FLAG_EMS_OR_ULTRA=OFF; SHOW_PAGE_1();}
            
    
        break;
        case 2:
            if(CHOISE_OF_EMS<4){FLAG_SELECT=!FLAG_SELECT;} 
            if(!FLAG_SELECT){SHOW_PAGE_EMS();}
            if(CHOISE_OF_EMS==4){PAGE=0; CHOISE_OF_EMS=0; FLAG_EMS_OR_ULTRA=OFF; SHOW_PAGE_1();}
            
            
        break;
        default:break;
    }
    break;
    case STATE_UP_BUTTON:
    UP_DOWN_BUTTON(ON);
    break;
    case STATE_DOWN_BUTTON:
    UP_DOWN_BUTTON(OFF);
    break;
   }

}

/* [] END OF FILE */
