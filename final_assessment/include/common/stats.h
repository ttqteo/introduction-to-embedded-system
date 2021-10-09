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
 * @file stats.h 
 * @brief A header file for stats.c
 *
 * The header declares function in stats.c and contain their description.
 *
 * @author Tran Tu Quang
 * @date 14th Jun, 2021
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

void print_statistic(unsigned char *,int);

/**
 * @brief Print statistic of the array
 *
 * This function prints original array and sorted array. After that print statistic value by  
 * calling functions to find max, min, median and mean values
 *
 * @return NULL
 */

void print_array(unsigned char *, int);

/**
 * @brief Print an array of char received a defined sized
 *
 * This function takes as input an unsigned char array and integer size (length of array)
 * print it to screen
 *
 * @param i The integer number used in for loop as a condition value to read the array
 *
 * @return NULL
 */

void sort_array(unsigned char *,int);

/**
 * @brief Sort array from large to small
 *
 * This function takes as input an unsigned char array with integer size (length of array).
 * It uses two loop to compares each element, and swap both if the considering value is 
 * smaller than the following value
 *
 * @param i The counter integer for first loop
 * @param j The counter integer for second loop
 * @param temp The temporary integer to swap i and j element
 *
 * @return NULL
 */

int find_minimum(unsigned char *, int);

/**
 * @brief Find a minimum vale of unsigned char array
 *
 * This function takes as input an unsigned char array with integer size (length of array)
 * Return the final element of array after sorting descending.
 *
 * @return The minimum integer value of the array
 */

int find_maximum(unsigned char *, int);

/**
 * @brief Find a maximum vale of unsigned char array
 *
 * This function takes as input an unsigned char array with integer size (length of array)
 * Return the first element of array after sorting descending.
 *
 * @return The maximum integer value of the array
 */

float find_mean(unsigned char *, int);

/**
 * @brief Find a mean vale of unsigned char array
 *
 * This function takes as input an unsigned char array with integer size (length of array).
 * Calculating sum of all elements of array, then divide sum with size of array.
 *
 * @param sum The sum of all elements of array
 * @param i The counter integer for loop
 *
 * @return The mean float value of the array
 */

float find_median(unsigned char *, int);

/**
 * @brief Find a median vale of unsigned char array
 *
 * This function takes as input an unsigned char array with integer size (length of array).
 * If the size is even, the median value is equal to arithmetic mean of the two middle
 * values, else the value is the middle element of the array
 *
 *
 * @return The median float value of the array
 */


#endif /* __STATS_H__ */
