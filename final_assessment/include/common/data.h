/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.h
 * @brief Abstraction of memory read and write operations
 *
 * @author Tran Tu Quang
 * @date Oct 5 2021
 *
 */

#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>
#include <math.h>

/**
 * @brief Integer-to-ASCII function 
 *
 * Convert a data from a standard integer type into an ASCII string,
 * supports a variety of numbers and bases
 *
 * @param data     The 32-bit, signed number to be converted to ASCII
 * @param ptr      The pointer to the output string
 * @param base     The base of the number passed in, support base between 2 to 16
 *
 * @return uint8_t Return length of converted data (including negative sign & null terminator)
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);


/**
 * @brief ASCII-to-Integer function 
 *
 * Convert an ASCII strign to a number
 *
 * @param ptr      Point to the begin of character string to convert
 * @param digits   Number of digits in the string
 * @param base     The base of the number, support base between 2 to 16
 *
 * @return int32_t Return a converted 32-bit signed integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif


