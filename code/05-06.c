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
 * Chapter 5 - exercise 6
 
 */

#include <stdio.h>
#include <ctype.h> 
#include <string.h>

#define MAX_LEN 1000

int patoi(char *s);
char *pitoa(int n, char *s);
char *reverse(char *s);

/* main: Checks the pitoa, patoi and reverse functions */
int main(void) {
  char s1[] = "1236";
  char s2[MAX_LEN];
	
  printf("%d\n", patoi(s1));
  printf("%s\n", pitoa(100, s2));
  printf("%s\n", pitoa(-678, s2));
  printf("%s\n", pitoa(-3985920, s2));

  return 0;
}

/* patoi: Converts string s to integer */
int patoi(char *s) {
	
  for ( ; isspace(*s); ++s) {
    ;
  }

  int sign = (*s == '-') ? -1 : 1;
  if (*s == '-' || *s == '+') {
    ++s;
  }
	
  int n;
  for (n = 0; isdigit(*s); ++s) {
    n = 10 * n + (*s - '0');
  }

  return sign * n;	
}

/*
 * pitoa: Converts integer n to string s and returns s.
 * Notice that s must be long enough
 */
char *pitoa(int n, char *s) {
  int sign = (n < 0) ? -1 : 1;
  int steps = 0;
	
  do {
    *s++ = sign * n % 10 + '0';
    n /= 10;
    ++steps;
  } while (n != 0);
	
  if (sign == -1) {
    *s++ = '-';
    ++steps;
  }
	
  *s = '\0';

  return reverse(s - steps);
}

/*
 * reverse: Reverses a string s and return s. Notice that s must
 * be long enough
 */
char *reverse(char *s) {
  char *j = s + strlen(s) - 1;
  int c, steps = 0;

  for (; s < j; ++s, --j, ++steps) {
    c = *s, *s = *j, *j = c;
  }

  return s - steps;
}
