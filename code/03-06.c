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
 * Chapter 3 - exercise 6
 
 */

#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

void itoa(int n, char s[], int w);
void reverse(char s[]);

/*
 * main: Tests the itoa function. Notice that we also
 * handle the case asked in exercise 3-4
 */
int main(void) {
  char s[MAX_LEN];
  int n1 = 23 , w1 = 1;
  int n2 = 23, w2 = 5;
  int n3 = -279, w3 = 8;

  itoa(n1,s,w1);
  printf("%s\n", s);

  itoa(n2, s, w2);
  printf("%s\n", s);

  itoa(n3, s, w3);
  printf("%s\n", s);

  return 0;
}

/*
 * itoa: Converts the integer n to characters in the string s
 * which has minimum field width w
 */
void itoa(int n, char s[], int w) {
  int j = 0;
  int sign = (n < 0) ? -1 : 1;
	
  do {
    s[j++] = sign * n % 10 + '0';
    n /= 10;
  } while (n != 0);
	
  if (sign == -1) {
    s[j++] = '-';
  }
	
  while (j < w) {
    s[j++] = ' ';
  }
  s[j] = '\0';
  reverse(s);
}

/* reverse a string s */
void reverse(char s[]) {
  int c, i, j;
	
  for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
    c = s[i], s[i] = s[j], s[j] = c;
  }
}
