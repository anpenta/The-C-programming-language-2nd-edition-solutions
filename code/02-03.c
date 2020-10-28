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
 * Chapter 2 - exercise 3
 
 */

#include <stdio.h>

int htoi(char s[]);

/* main: Tests the htoi function */
int main(void) {
  char hex1[] = "0x169b";
  char hex2[] = "0X3750";
  char hex3[] = "9E63";
  char hex4[] = "a50D";
  char hex5[] = "G13";
	
  printf("%d\n", htoi(hex1));
  printf("%d\n", htoi(hex2));
  printf("%d\n", htoi(hex3));
  printf("%d\n", htoi(hex4));
  printf("%d\n", htoi(hex5));
	
  return 0;
}

/*
 * htoi: Converts a string of hexadecimal digits (including an optional Ox or ox)
 * into its equivalent integer value and return it. If the string is
 * invalid returns -1
 */
int htoi(char s[]) {
  int i, n = 0;
	
  if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
    i = 2;
  } else {
      i = 0;
  }
  while (s[i] != '\0') {
    if (s[i] >= '0' && s[i] <= '9') {
      n = 16 * n + (s[i] - '0');
	} else if (s[i] >= 'a' && s[i] <= 'f') {
        n = 16 * n + (s[i] - 'a' + 10);
	} else if (s[i] >= 'A' && s[i] <= 'F') {
        n = 16 * n + (s[i] - 'A' + 10);
	} else {
        return -1;
	}
    ++i;
  }
		
  return n;
}

		 

