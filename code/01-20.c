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
 * Chapter 1 - exercise 20
 
 */

#include <stdio.h>

#define MAX_LEN 1000
#define N 4

int readinput(char input[], int cap);
int detab(char input[], int curr, int cap);

/*
 * main: Replaces tabs in the input with the proper number of spaces
 * to the next tab stop, provided that tab stops are every N columns.
 * Notice that N is a symbolic constant  and it should always be greater than 0
 */
int main(void) {
	
  int len;
  char input[MAX_LEN];
	
  while ((len = readinput(input, MAX_LEN)) > 0) {
    printf("\n%s\n", input);
  }
		
  return 0;
}

/*
 * readinput: Reads input into the input array while transforming tabs to spaces
 * and returns its length
 */
int readinput(char input[], int cap) {
  int c, i;
	
  i = 0;
  while (i < cap - 1 && (c = getchar()) != EOF) {
    if (c == '\t') {
      i = detab(input, i, MAX_LEN);
	} else {
        input[i] = c;
        ++i;
	}
  }
	
  input[i] = '\0';

  return i;
}

/*
 * detab: Replaces tabs with the appropriate number of spaces
 * and returns updated length of input array
 */
int detab(char input[], int curr, int cap) {
	
  if (N > 1) {
    int i, n_spaces;

      for (i = 0; i < N; ++i) {
        if (curr % N == i) {
          n_spaces = N - i;
		}
	  }
      if (curr + n_spaces < cap) {
        for (i = 0; i < n_spaces; ++i) {
          input[curr] = ' ';
          ++curr;
		}
	  }
  }
  return curr;
}
