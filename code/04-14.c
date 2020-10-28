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
 * Chapter 4 - exercise 14
 
 */

#include <stdio.h>

#define SWAP(t,x,y) ( {t temp = x; x = y; y = temp;} )

/* main: Tests the swap macro */
int main(void) {
  int x = 1, y = 2;

  printf("%d %d\n", x, y);
  SWAP(int, x , y);
  printf("%d %d", x, y);
	
  return 0;
}

