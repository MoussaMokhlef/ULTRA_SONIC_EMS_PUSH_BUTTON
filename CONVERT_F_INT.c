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

#include "CONVERT_F_INT.h"


/******************************************************************************/
/*                          02_ intToStr                                      */
/*----------------------------------------------------------------------------*/
/* 1- Function Description -> to convert from integer to string               */
/* 2- Function Input       ->                                                 */
/*                     @param num                                             */
/*                     @param *str                                            */
/* 3- Function Return      -> @void                                           */
/******************************************************************************/
void intToStr(int num, char *str){
    int i = 0;
    int temp_=num;
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
    } else {
        while (num != 0) {
            int rem = num % 10;
            str[i++] = rem + '0';
            num = num / 10;
        }
        if(temp_<10){str[i++]='0';}
        str[i] = '\0';

        // Reverse the string
        int start = 0;
        int end = i - 1;
        while (start < end) {
            char temp_ = str[start];
            str[start] = str[end];
            str[end] = temp_;
            start++;
            end--;
        }
    }
}

/******************************************************************************/
/*                          03_ floatToStr                                    */
/*----------------------------------------------------------------------------*/
/* 1- Function Description -> to convert from float to string                 */
/* 2- Function Input       ->                                                 */
/*                     @param floatValue                                      */
/*                     @param *buffer                                         */
/* 3- Function Return      -> @void                                           */
/******************************************************************************/
void floatToStr(float floatValue, char *buffer) {
    int intPart = (int)floatValue; // Extract integer part
    float decimalPart = floatValue - intPart; // Extract decimal part

    // Convert integer part to string
    intToStr(intPart, buffer);

    // Find the length of the string
    int len = 0;
    while (buffer[len] != '\0') {
        len++;
    }

    // Add decimal point
    buffer[len] = '.';
    buffer[len + 1] = '\0';

    // Convert decimal part to string (two decimal places)
    for (int i = 0; i < 2; i++) {
        decimalPart *= 10;
        int digit = (int)decimalPart;
        buffer[len + i + 1] = digit + '0';
        decimalPart -= digit;
    }

    buffer[len + 3] = '\0';
}
/* [] END OF FILE */
