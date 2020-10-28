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
 * Chapter 2 - exercise 7
 
 */

#include <stdio.h>

unsigned invert(unsigned x,int p,int n);

/* main: Tests the invert function */
int main(void) {
	
  printf("%d\n", invert(20,2,2));
  printf("%d\n", invert(134,6,4));
  printf("%d\n", invert(30,2,3));
  printf("%d\n", invert(55,4,3));
  return 0;
}

/*
 * invert: Returns x with the n bits that begin at position p 
 * inverted, leaving the other bits unchanged
 */
unsigned invert(unsigned x,int p,int n) {
  return ~x ^ ((~0 << p + 1) | ~(~0 << p + 1 - n)); 
}
