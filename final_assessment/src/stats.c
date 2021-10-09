/**
 * @file stats.c 
 * @brief A program with calculate minimum, maximum, mean, median of array 
 * integer, and sort descending
 *
 * The program received 40 char objects as input. The array'll be sorted and
 * return the minimum, maximum, median and mean value and print to screen. 
 * 
 *
 * @author Tran Tu Quang
 * @date 14th June, 2021
 *
 */



#include <stdio.h>
#include "stats.h"
#include "platform.h"

#define SIZE (40)

void print_statistic(unsigned char* array, int size){
	printf("The original array:");
	print_array(array, size);
	printf("\nThe sorted array:");
	sort_array(array, size);
	print_array(array, size);
	
	printf("\nMinimum: %d\n", find_minimum(array, size));
	printf("Maximum: %d\n", find_maximum(array, size));
	printf("Mean: %.3f\n", find_mean(array, size));
	printf("Median: %.3f\n", find_median(array, size));

	return;
}

void print_array(unsigned char* array, int size){
	for(int i = 0; i < size; i++){
		if ((i%5) == 0) printf("\n");
		printf("%d ",array[i]);
	}
	printf("\n");
}

void sort_array(unsigned char* array, int size){
	for(int i = 0; i < size; i++)
		for(int j = i + 1; j < size; j++)
			if (array[i] > array[j]) {
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
	return;
}

int find_minimum(unsigned char* array, int size){
	return array[size-1];
}

int find_maximum(unsigned char* array, int size){
	return array[0];
}

float find_mean(unsigned char* array, int size){
	int sum = 0;
	for(int i = 0; i < size; i++) sum+=array[i];
	return (sum/size);
}

float find_median(unsigned char* array, int size){
	if (size%2 == 0) return((array[size/2]+array[(size-1)/2])/2);
	else return array[size/2];
}
