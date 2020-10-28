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
 * Chapter 1 - exercise 14
 
 */

#include <stdio.h>

#define MAX_LEN 128
#define LOWER_CHAR_BOUND 33
#define UPPER_CHAR_BOUND 126

/*
 * main: Prints a horizontal histogram of the frequencies of different 
 * input characters
 */
int main(void) {
  int c, k, n;
  int cfreq[MAX_LEN];
	
  for (n = 0; n < MAX_LEN; ++n) {
    cfreq[n] = 0;
  }
  /* Calculation part */
  while ((c = getchar()) != EOF) {
    if (c >= LOWER_CHAR_BOUND && c <= UPPER_CHAR_BOUND) {
      cfreq[c] = cfreq[c] + 1;
    }
  }
	/* Printing part */
  for (n = 0; n < 30; ++n) {
    putchar('-');
  }
  for (n = 0; n < MAX_LEN; ++n) {
    if (cfreq[n] > 0) {
      printf("\n%c |", n);
      for (k = 0; k < cfreq[n]; ++k) {
        printf("#");
	  }
	}
  }
	
  putchar('\n');
  for (n = 0; n < 30; ++n) {
    putchar('-');
  }
  putchar('\n');

  return 0;
}
