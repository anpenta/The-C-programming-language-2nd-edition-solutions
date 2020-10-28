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
 * Chapter 2 - exercise 9
 
 */

#include <stdio.h>

int bitcount(unsigned x);

/* main: Tests the bitcount function */
int main(void) {
	
  printf("%d\n", bitcount(19));
  printf("%d\n", bitcount(92));
  printf("%d\n", bitcount(34));
  printf("%d\n", bitcount(199));
  printf("%d\n", bitcount(276));
  return 0;
}

/* bitcount: Returns the number of 1-bits in x */
int bitcount(unsigned x) {
  int b = 0;

  while (x != 0) {
    ++b;
    x &= x - 1;
  }

  return b;
}
