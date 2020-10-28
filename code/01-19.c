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
 * Chapter 1 - exercise 19
 
 */

#include <stdio.h>

#define MAX_LEN 1000

int readline(char line[], int cap);
void reverse(char string[], int len);

/* main: Reverses each input line, one at a time */
int main(void) {
  int len;
  char line[MAX_LEN];
	
  while ((len = readline(line, MAX_LEN)) > 0) {
    reverse(line, len);
    printf("%s", line);
  }
		
  return 0;
}

/* readLine: Reads a line into the line array and returns its length */
int readline(char line[], int cap) {
  int c, i;
	
  i = 0;
  while (i < cap - 1 && (c = getchar()) != EOF && c != '\n') {
    line[i] = c;
    ++i;
  }
	
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
	
  line[i] = '\0';

  return i;
}

/*
 * reverse: Reverses a character string. Except for the null character 
 * also exclude the newline character in this case
 */
void reverse(char string[], int len) {
  int i, c, k;
	
  while (string[len - 1] == '\0' || string[len - 1] == '\n') {
    --len;
  }
  for (i = 0; i < len - 1; ++i) {
    c = string[len - 1];
    for (k = len - 1; k > i; --k) {
      string[k] = string[k - 1];
	}
    string[i] = c;
  }
}
		
	
