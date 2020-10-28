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
 * Chapter 2 - exercise 5
 
 */

#include <stdio.h>

int any(char s1[], char s2[]);

/* main: Tests the any function */
int main(void) {
  char s1[] = "This is a test";
  char s2[] = "jklit";
  char s3[] = "bc";
  char s4[] = "aT";
	
  printf("%d\n", any(s1,s2));
  printf("%d\n", any(s1,s3));
  printf("%d\n", any(s1,s4));
	
  return 0;
}

/*
 * any: Returns the first location in the string s1 
 * where any character from the string s2 occurs
 * or -1 if s1 contains no characters from s2
 */
int any(char s1[], char s2[]) {
  int i, k, pos = -1;
	
  for (k = 0; s2[k] != '\0'; ++k) {
    for (i = 0; s1[i] != '\0'; ++i) {
      if (s1[i] == s2[k] && (pos == -1 || pos > i)) {
        pos = i;
	  }
	}
  }
  return pos;	
}

		 

