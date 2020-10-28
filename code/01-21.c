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
 * Chapter 1 - exercise 21
 
 */

#include <stdio.h>

#define MAX_LEN 1000
#define N 4

int readinput(char input[], int cap);
int entab(char input[], int curr, int cap);

/*
 * main: Replaces strings of blanks by the minimum number of tabs and blanks to achieve
 * the same spacing, provided that tab stops are every N columns.
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
 * readinput: Reads input into the input array while transforming spaces to tabs
 * and returns its length
 */
int readinput(char input[], int cap) {
  int c, i;
	
  i = 0;
  while (i < cap - 1 && (c = getchar()) != EOF) {
    if (c == '\t') {
      i = entab(input, i, MAX_LEN);
	} else {
        input[i] = c;
        ++i;
	}
  }
	
  input[i] = '\0';

  return i;
}

/* 
 * entab: Replaces spaces with the appropriate number of tabs and spaces
 * and returns updated length of input array
 */
int entab(char input[], int curr, int cap) {
	
  if (N > 1) {
    int i, step, c, n_tabs;
		
    step = 1;
    while (curr + step < cap - 1 && (c = getchar()) == ' ') {
      ++step;
	}
    n_tabs = step / N;
    step = step % N;
		
    for (i = 0; i < n_tabs; ++i) {
      input[curr] = '\t';
      ++curr;
    }
		
    for (i = 0; i < step; ++i) {
      input[curr] = ' ';
      ++curr;
    }
		
    if (c != EOF) {
      input[curr] = c;
      ++curr;
    }
  }
	
  return curr;
}
