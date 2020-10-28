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
 * Chapter 4 - exercise 12
 
 */

#include <stdio.h>

#define MAX_LEN 1000

void itoa(int n, char s[]);

/* main: Tests the recursive itoa function */
int main(void) {
  char s[MAX_LEN];
  int n1 = -5672;
  int n2 = 452;
  int n3 = 672678;

  itoa(n1, s);
  printf("%s\n", s);

  itoa(n2, s);
  printf("%s\n", s);
  itoa(n3, s);
  printf("%s\n", s);
	
  return 0;
}

/*
 * itoa: Converts the integer n to characters in
 * the string s by using recursion
 */
void itoa(int n, char s[]) {
  static int j;
  int sign = (n < 0) ? -1 : 1;
	
  if (n / 10) {
    itoa(n / 10, s);
  } else {
      j = 0;
      if (sign == -1) {
        s[j++] = '-';
	  }
  }

  s[j++] = sign * n % 10 + '0';
  s[j] = '\0';
}
