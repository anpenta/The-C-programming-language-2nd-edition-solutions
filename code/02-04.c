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
 * Chapter 2 - exercise 4
 
 */

#include <stdio.h>

void squeeze(char s1[], char s2[]);

/* main: Tests the squeeze function */
int main(void) {
  char s1[] = "This is a test";
  char s2[] = "jklit";
	
  printf("%s\n", s1);
  squeeze(s1,s2);
  printf("%s\n",s1);
	
  return 0;
}

/*
 * squeeze: Deletes each character in string s1 that matches
 * any character in the string s2
 */
void squeeze(char s1[], char s2[]) {
  int i, j, k;
	
  for (k = 0; s2[k] != '\0'; ++k) {
    for (i = j = 0; s1[i] != '\0'; ++i) {
      if (s1[i] != s2[k]) {
        s1[j++] = s1[i];
	  }
	}
    s1[j] = '\0';
  }	
}

		 

