/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			sorting_algorithms.cpp
 * Author(s):		<your name>
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "stopwatch.h"
#include "general.h"
#include "sorting_algorithms.h"
#include <stdio.h>
#include <stdlib.h>

void 	init_random (int *array, unsigned long length){
  for (int i = 1; i <= length; i++) {
    array[i] = rand() % 100 + 1;
  }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void 	bubble_sort (int *array, unsigned long length){
  int i, j;
  for (i = 0; i < length-1; i++)
      for (j = 0; j < length-i-1; j++)
          if (array[j] > array[j+1])
             swap(&array[j], &array[j+1]);
}

void 	insertion_sort (int *array, unsigned long length){
   int key, j;
   for (int i = 1; i < length; i++)
   {
       key = array[i];
       j = i-1;

       while (j >= 0 && array[j] > key)
       {
           array[j+1] = array[j];
           j = j-1;
       }
       array[j+1] = key;
   }
}
