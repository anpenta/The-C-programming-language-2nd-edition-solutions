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
 * Chapter 3 - exercise 3
 
 */

#include <stdio.h>

#define MAX_LEN 1000

void expand(char s1[], char s2[]);

/* main: Tests the expand function */
int main(void) {
  char s1a[] = "a-z";
  char s1b[] = "a-b-c";
  char s1c[] = "a-z0-9";
  char s1d[] = "-a-z";
  char s2[MAX_LEN];

  printf("%s\n", s1a);
  expand(s1a,s2);
  printf("%s\n", s2);
	
  printf("%s\n", s1b);
  expand(s1b,s2);
  printf("%s\n", s2);
	
  printf("%s\n", s1c);
  expand(s1c,s2);
  printf("%s\n", s2);
	
  printf("%s\n", s1d);
  expand(s1d,s2);
  printf("%s\n", s2);
	
  return 0;
}

/*
 * expand: Expands shorthand notations like a-z in the string s1
 * into the equivalent complete list abc ... xyz in s2
 */
void expand(char s1[], char s2[]) {
  int i = 0, j = 0;
	
  while (s1[i] != '\0') {
    if (s1[i] >= 'a' && s1[i] <= 'z' || s1[i] >= 'A' && s1[i] <= 'Z' || s1[i] >= '0' && s1[i] <= '9') {
      int c = s1[i];
      while (s1[i + 1] == '-') {
        i += 2;
	  }
      while (c <= s1[i]) {
        s2[j++] = c++;
	  }
	}
    ++i;
  }
	
  s2[j] = '\0';	
}
