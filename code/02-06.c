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
 * Chapter 2 - exercise 6
 
 */

#include <stdio.h>

unsigned setbits(unsigned x,int p,int n,unsigned y);

/* main: Tests the setbits function */
int main(void) {
	
  printf("%d\n", setbits(55,2,2,34));
  printf("%d\n", setbits(255,3,4,0));
  printf("%d\n", setbits(150,5,3,54));
  printf("%d\n", setbits(65,4,4,79));
  printf("%d\n", setbits(152,5,2,139));
  printf("%d\n", setbits(30,3,2,13));
	
  return 0;
}

/*
 * setbits: Returns x with the n bits that begin at position p 
 * set to the rightmost n bits of y, leaving the other
 * bits unchanged
 */
unsigned setbits(unsigned x,int p,int n,unsigned y) {
  return (x & ((~0 << p + 1) | ~(~0 << p + 1 - n))) | (y & ~(~0 << n)) << p + 1 - n; 
}
