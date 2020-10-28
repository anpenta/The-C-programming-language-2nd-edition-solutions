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
 * Chapter 1 - exercise 24
 
 */

#include <stdio.h>

#define MAX_LEN 1000
#define TRUE 1
#define FALSE 0

int readinput(char input[], int cap);
void checkinput(char input[], int len);

/*
 * main: Checks a C program for rudimentary syntax errors
 * Notice that the order of the symbols, quotes and comments is taken into account
 */
int main(void) {
	
  int len;
  char input[MAX_LEN];
	
  while ((len = readinput(input, MAX_LEN)) > 0) {
    checkinput(input, len);
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

/*
 * checkinput: Checks the input for syntax errors while taking into account the order
 * of the symbols, comments and quotes and print the warning if needed
 */
void checkinput(char input[], int len) {
  int i, dquote, squote, comment;
  char priority[len];
  int idx;
		
  dquote = FALSE;
  squote = FALSE;
  comment = FALSE;
  idx = -1;
  for (i = 0; i < len; ++i) {
    if (input[i] == '"' && dquote == FALSE && squote == FALSE && comment == FALSE) {
      dquote = TRUE;
	} else if (input[i] == '\'' && dquote == FALSE && squote == FALSE && comment == FALSE) {
        squote = TRUE;
	} else if (input[i] == '/' && input[i + 1] == '*' && dquote == FALSE && squote == FALSE && comment == FALSE) {
        comment = TRUE;
	} else if (input[i] == '"' && dquote == TRUE) {
        dquote = FALSE;
	} else if (input[i] == '\'' && squote == TRUE) {
      squote = FALSE;
	} else if (input[i] == '*' && input[i + 1] == '/' && comment == TRUE) {
        comment = FALSE;
	} else if (squote == FALSE && dquote == FALSE && comment == FALSE) {
        if (input[i] == '(') {
          ++idx;
          priority[idx] = '(';
		} else if (input[i] == '[') {
	        ++idx;
            priority[idx] = '[';
		} else if (input[i] == '{') {
            ++idx;
            priority[idx] = '{';
		} else if ((input[i] == ')' && priority[idx] == '(') || (input[i] == ']' && priority[idx] == '[')
		          || (input[i] == '}' && priority[idx] == '{')) {
					--idx;
		} else if (input[i] == ')' || input[i] == ']' || input[i] == '}') {
          printf("\nSyntax errors found\n");
          return;
		}
	}
  }
  if (idx != -1) {
    printf("\nSyntax errors found\n");
  }
}