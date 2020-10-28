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

/* The C programming language 2nd ED (1988) by Brian W. Kernighan and Dennis M. Ritchie
 * Chapter 1 - exercise 9
 
 */

#include <stdio.h>

/* 
 * main: Copies input to output, replacing each string of one or more
 * blanks by a single blank
 */
int main(void) {
  int c;
  int d = -1;
	
  while ((c = getchar()) != EOF) {
    if (!(d == ' ' && c == ' ')) {
      putchar(c);
	}
    d = c;
  }

  return 0;
}
