/*  
 * Copyright (C) 2018 Andreas Pentaliotis
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
	
/* 
 * The C programming language 2nd ED (1988) by Brian W. Kernighan and Dennis M. Ritchie
 * Chapter 1 - exercise 4
 
 */

#include <stdio.h>

#define LOWER 0
#define UPPER 100
#define STEP 10

/* main: Prints a celsius to fahrenheit conversion table */
int main(void) {
  float fahr, celsius;
	
  printf("Celsius\tFahrenheit\n");
	
  celsius = LOWER;
  while (celsius <= UPPER) {
    fahr = (9.0/5.0) * celsius + 32.0;
    printf("%.0f\t%.0f\n", celsius, fahr);
    celsius = celsius + STEP;
  }
	
  return 0;
}
