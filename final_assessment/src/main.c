/**
 * @file main.c
 * @brief Main entry point to the Final Assessment
 *
 * @author Tran Tu Quang
 * @date Oct 5 2021
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "stats.h"
#include "data.h"
#include "memory.h"

int main(){
  #ifdef COURSE1
    printf("calling course1()\n");
    course1();
    return 0;
  #endif

  return 0;
}


