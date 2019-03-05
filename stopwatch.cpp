/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			stopwatch.cpp
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "stopwatch.h"
#include "general.h"
#include "sorting_algorithms.h"
#include "time.h"

clock_t start, end;
double cpu_time_used;

void 	start_stopwatch (){
  start = clock();
}
void 	stop_stopwatch (){
  end = clock();
}
float elapsed_time (){
 stop_stopwatch();
 return cpu_time_used = ((float) (end - start)) /CLOCKS_PER_SEC;
}
