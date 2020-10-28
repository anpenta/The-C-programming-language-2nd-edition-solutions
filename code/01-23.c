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
 * Chapter 1 - exercise 23
 
 */

#include <stdio.h>

#define MAX_LEN 1000
#define TRUE 1
#define FALSE 0

int readinput(char input[], int cap);
void cleaninput(char input[], int len);

/* main: Removes all comments from a C program */
int main(void) {
	
  int len;
  char input[MAX_LEN];
	
  while ((len = readinput(input, MAX_LEN)) > 0) {
    cleaninput(input, len);
    printf("\n%s\n", input);
  }
		
  return 0;
}

/* readInput: Reads input into the input array and returns its length */
int readinput(char input[], int cap) {
  int c, i;
	
  i = 0;
  while (i < cap - 1 && (c = getchar()) != EOF) {
    input[i] = c;
    ++i;
  }
	
  input[i] = '\0';

  return i;
}

/* cleaninput: Cleans the input from comments */
void cleaninput(char input[], int len) {
  int i, begin, end, quote;
		
  quote = FALSE;
  for (i = 0; i < len - 1; ++i) {
    if (input[i] == '"' && quote == FALSE) {
      quote = TRUE;
	  } else if (input[i] == '"' && quote == TRUE) {
        quote = FALSE;
	  } else if (input[i] == '/' && input[i + 1] == '*' && quote == FALSE) {
        int k;
				
        begin = i;
        end = -1;
        k = i + 2;
        while (k < len) {
          ++k;
					
          if (input[k] == '*' && input[k + 1] == '/') {
            end = k + 1;
		  }
        }

        if (end != -1) {
          for (k = begin; k < end + 1; ++k) {
            input[k] = '\b';
		  }
		}
	  }
  }
}
