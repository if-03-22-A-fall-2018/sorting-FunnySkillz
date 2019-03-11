/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			compare_sorts_main.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/

/**
*** @file sorting_algorithms_main_driver.cpp
*** @brief File with main function built if <code>make</code> is called
*** @details <code>make</code> makes an executable by linking the main
*** function of this file. This function has to call the sorting algorithms on
*** arrays of the sizes as defined below.
*/

#include <stdio.h>
#include <string.h>

#include "stopwatch.h"
#include "sorting_algorithms.h"

#define HUGE			65535	// 2^16
#define VERY_LARGE 		16384	// 2^14
#define LARGE			8192	// 2^13
#define MIDDLE			4096	// 2^12
#define SMALL			2048	// 2^11
#define VERY_SMALL		1024	// 2^10
#define TINY			256 	// 2 ^8

/*
* Suggestion how to initialize the arrays which must be sorted with test data.
* 1. Create a array of size HUGE and initialize it with random data.
* 2. Copy from this array as many elements as needed into the seven target directories
*     (to make this efficiently, consider to use the function memcpy() of string.h).
*/

float getTime(int* array, unsigned long length, int number)
{
  init_random(array, length);

  if(number == 0)
  {
    start_stopwatch();
    bubble_sort(array, length);
  }
  else
  {
    start_stopwatch();
    insertion_sort(array, length);
  }

  return elapsed_time();
}

int main(int argc, char const *argv[])
{
    int huge[HUGE];
    int very_large[VERY_LARGE];
    int large[LARGE];
    int middle[MIDDLE];
    int small[SMALL];
    int very_small[VERY_SMALL];
    int tiny[TINY];

    int randomNumArray[HUGE];
    init_random(randomNumArray, HUGE);

    float tinyTime, very_smallTime, smallTime, middleTime, largeTime, very_largeTime, hugeTime;

    printf("Algorithm\tTiny\t\tV_Small\t\tSmall\t\tMiddle\t\tLarge\t\tV_Large\t\tHuge\n");

    int changeSort = 0;

    for (size_t i = 0; i < 2; i++) {
      memcpy(huge, randomNumArray, sizeof(int) * HUGE);
      memcpy(very_large, randomNumArray, sizeof(int) * VERY_LARGE);
      memcpy(large, randomNumArray, sizeof(int) * LARGE);
      memcpy(middle, randomNumArray, sizeof(int) * MIDDLE);
      memcpy(small, randomNumArray, sizeof(int) * SMALL);
      memcpy(very_small, randomNumArray, sizeof(int) * VERY_SMALL);
      memcpy(tiny,randomNumArray, sizeof(int) * TINY);

      if(changeSort == 0) {
        printf("BubbleSort\t");
      } else {
        printf("InsertionSort\t");
      }
      tinyTime = getTime(tiny, TINY, changeSort);
      very_smallTime = getTime(very_small, VERY_SMALL, changeSort);
      smallTime = getTime(small, SMALL, changeSort);
      middleTime = getTime(middle, MIDDLE, changeSort);
      largeTime = getTime(large, LARGE, changeSort);
      very_largeTime = getTime(very_large, VERY_LARGE, changeSort);
      hugeTime = getTime(huge, HUGE, changeSort);
;
      printf("%f\t%f\t%f\t%f\t%f\t%f\t%f\n",tinyTime, very_smallTime, smallTime, middleTime, largeTime, very_largeTime, hugeTime);
      changeSort = 1;
  }
}
