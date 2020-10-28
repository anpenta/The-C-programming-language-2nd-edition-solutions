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
 * Chapter 5 - exercise 3
 
 */

#include <stdio.h>

#define MAX_LEN 1000

void pstrcat(char *s, char *t);

/* main: Tests the strcat function */
int main(void) {
  char s[MAX_LEN] = "This is a test";
  char t[] = "-concatenated";
	
  printf("%s\n", s);
  pstrcat(s, t);
  printf("%s\n", s);
	
  return 0;
}

/* pstrcat: Concatenates t to end of s (s must be big enough) */
void pstrcat(char *s, char *t) {
  for ( ; *s; ++s) {
    ;
  }
  while (*s++ = *t++) {
    ;
  }
}
