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
 * Chapter 5 - exercise 4
 
 */

#include <stdio.h>

int strend(char *s, char *t);

/* main: Tests the strend function */
int main(void) {
  char s[] = "This is a test";
  char t1[] = "test";
  char t2[] = "is";
  char t3[] = "testd";
  char t4[] = "A bigger sentence than s";

  printf("%d\n", strend(s, t1));
  printf("%d\n", strend(s, t2));
  printf("%d\n", strend(s, t3));
  printf("%d\n", strend(s, t4));

  return 0;
}

/*
 * strend: Returns 1 if the string t occurs at the end of string s
 * and 0 otherwise
 */
int strend(char *s, char *t) {
  int n = 0, i = 0;

  for ( ; *t; ++t) {
    ++n;
  }
  for ( ; *s; ++s) {
    ++i;
  }
	
  if (n <= i) {
    s -= n;
    t -= n;

    while (*s++ == *t++ && *s) {
      ;
	}
    if (!(*s)) {
      return 1;
	}
  }
		
  return 0;
}
