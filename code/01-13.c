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
 * Chapter 1 - exercise 13
 
 */

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_LEN 100

/* main: Prints a horizontal histogram of the lengths of input words */
int main(void) {
  int c, state, n, i, k;
  int wlen[MAX_LEN];
	
  for (n = 0; n < MAX_LEN; ++n) {
    wlen[n] = 0;
  }
  n = i = 0;
  state = OUT;
	
  /* Calculation part */
  while ((c = getchar()) != EOF) {
		
    if (state == IN && (c == ' ' || c == '\t' || c == '\n')) {
      wlen[i] = n;
      n = 0;
      i = i + 1;
      state = OUT;
    } else if (!(c == ' ' || c == '\t' || c == '\n')) {
        n = n + 1;
        state = IN;
	}
  }
	
  /* Printing part */
  for (n = 0; n < 30; ++n) {
    putchar('-');
  }
  for (n = 0; n < i; ++n) {
    printf("\n%d |", n + 1);
    for (k = 0; k < wlen[n]; ++k) {
      printf("#");
	}
  }
  putchar('\n');
  for (n = 0; n < 30; ++n) {
    putchar('-');
  }
  putchar('\n');

  return 0;
}
