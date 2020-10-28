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
 * Chapter 3 - exercise 5
 
 */

#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

/* main: Tests the itob function */
int main(void) {
  char s[MAX_LEN];
  int n1 = 27 , b1 = 2;
  int n2 = 18, b2 = 8;
  int n3 = -23, b3 = 16;

  itob(n1, s, b1);
  printf("%s\n", s);

  itob(n2, s, b2);
  printf("%s\n", s);

  itob(n3, s, b3);
  printf("%s\n", s);

  return 0;
}

/*
 * itob: Converts the integer n into a base b character
 * representation in the string s
 */
void itob(int n, char s[], int b) {
  int j = 0;
  int sign = (n < 0) ? -1 : 1;
	
  do {
    s[j++] = sign * n % b + '0';
    n /= b;
  } while (n != 0);

  if (sign == -1) {
    s[j++] = '-';
  }
  s[j] = '\0';
  reverse(s);
}

/* reverse: Reverses a string s */
void reverse(char s[]) {
  int c, i, j;
	
  for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
    c = s[i], s[i] = s[j], s[j] = c;
  }
}
