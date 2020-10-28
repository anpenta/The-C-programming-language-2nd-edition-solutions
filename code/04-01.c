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
 * Chapter 4 - exercise 1
 
 */

#include <stdio.h>

int strrindex(char s[], char t[]);

/* main: Tests the strrindex function */
int main(void) {
  char s1[] = "This is a test";
  char s2[] = "Test";
  char t[] = "is";
	
  printf("%d\n", strrindex(s1, t));
  printf("%d\n", strrindex(s2, t));
	
  return 0;
}

/*
 * strrindex: Returns the position of the rightmost occurrence of t in s,
 * or - 1 if there is none
 */
int strrindex(char s[], char t[]) {
  int i, j;
  int pos = -1;

  for (i = 0; s[i] != '\0'; ++i) {
    for (j = 0; t[j] != '\0'; ++j) {
      if (s[i + j] != t[j]) {
        break;
	  }
	}
    if (t[j] == '\0') {
	  pos = i;
	}
  }
	
  return pos;
}
