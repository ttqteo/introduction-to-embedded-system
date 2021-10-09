/**
 * @file data.c
 * @brief Main entry point to the C1M2 Assessment
 *
 * @author Tran Tu Quang
 * @date Oct 5 2021
 *
 */

#include <stdio.h>
#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
  //12 = 1 bit for sign, 10 bit for digits, 1 for null terminator
  uint8_t tempArray[12]; 
  uint8_t strLength = 0;
  uint8_t isNegativeFlag = 0;
  
  if (data == 0) {
    *ptr='0';
    *(ptr+1)=0;
    return 2;
  }
 
  if (data < 0) {
    data = data*-1;
    isNegativeFlag = 1;
  }

  tempArray[strLength] = 0x0;
  strLength++;

  while (data >= 1){
    uint8_t myChar = data%base;
    //char in [0..9]
    if (myChar >= 0 && myChar <= 9) 
      tempArray[strLength] = myChar + 0x30;

    //char in [A..F]
    if (myChar >= 10 && myChar <= 15) 
      tempArray[strLength] = myChar + 0x37;

    data = data/base;
    strLength++;
  }

  if (isNegativeFlag) {
    tempArray[strLength] = '-';
    strLength++;
  }

  for(uint8_t i = 0; i < strLength; i++)
    *(ptr+i) = tempArray[strLength - 1 - i];

  return strLength;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
  uint8_t isNegativeFlag = 0;
  uint32_t myNumber = 0;
  uint8_t *charPtr = ptr;

  if (*charPtr == '-') {
    isNegativeFlag = 1;
    digits--;
    charPtr++;
  }

  uint8_t i = 0;
  do {
    uint32_t multiplier = pow(base,(digits - 2 - i));
    uint8_t digit = *(charPtr + i);
    if (digit <= 'F' && digit >= 'A') 
      digit -= 0x37;
    else if (digit <= '9' && digit >= '0')
      digit -= 0x30;
    myNumber += multiplier*digit;
    i++;
  } while (*(charPtr + i - 1) != 0);

  if (isNegativeFlag)
   myNumber*=-1;

  return myNumber;
}
