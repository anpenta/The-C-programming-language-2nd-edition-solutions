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
 * Chapter 2 - exercise 8
 
 */

#include <stdio.h>

unsigned rightrot(unsigned x,int n);

/* main: Tests the rightrot function */
int main(void) {
	
  printf("%d\n", rightrot(19,1));
  printf("%d\n", rightrot(22,2));
  printf("%d\n", rightrot(104,6));
  printf("%d\n", rightrot(428,5));
  return 0;
}

/*
 * Returns x with the n bits that begin at position p 
 * inverted, leaving the other bits unchanged. Notice
 * that we use the variable i to store the index (+1) of
 * the most significant bit in x
 */
unsigned rightrot(unsigned x,int n) {
  int i = 0, k = x;

  while (k) {
    k &= ~(1 << i++);
  }
  return (x | (x & ~(~0 << n)) << i) >> n; 
}
