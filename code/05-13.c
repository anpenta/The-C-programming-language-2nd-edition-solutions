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
 * Chapter 5 - exercise 13
 
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int n);

#define MAX_LINES 10000 /* Maximum number of input lines */

char *lineptr[MAX_LINES]; /* lineptr: Array of pointers to lines */

/*
 * main: Prints the last n lines of the input. If not specified,
 * n defaults to 10
 */
int main(int argc, char *argv[]) {
  int n;

  /* If there are more than two arguments */
  if (argc > 2) {
    printf("error: the only parameter is -n\n");
    return 1;
  } /* Else if the parameter provided is correct */
    else if (argc == 2 && (*++argv)[0] == '-' && isdigit((*argv)[1])) {
      n = (*argv)[1] - '0';
  } /* Else if no parameter was provided */
    else if (argc == 1) {
      n = 10;
  } /* Else if an incorrect parameter was provided */
	else {
      printf("error: the correct parameter is -n where n is an integer\n");
      return 1;
  }

  if (readlines(lineptr, MAX_LINES) >= 0) {
    writelines(lineptr, n);
  }
	
  return 0;
}

/*
 * readlines: Reads input lines, stores their pointers in the lineptr array
 * and returns the number of lines. Notice that we are using the built-in
 * getline function
 */
int readlines(char *lineptr[], int maxlines) {
  size_t len;
  int nlines = 0;
  char *line = NULL;

  /*
   * In the built-in getline function we need to pass the addresses of
   * len and line as arguments. We also need to specify that the input
   * stream is the standard input (stdin)
   */
  while ((getline(&line, &len, stdin)) != -1) {
    if (nlines >= MAX_LINES) {
      return -1;
	} else {
        line[strlen(line) - 1] = '\0';
        lineptr[nlines++] = line;
        line = NULL;
	}
  }

  return nlines;
}

/* writelines: Outputs the n last lines from input */
void writelines(char *lineptr[], int n) {
  /* Calculate size of lineptr */
  int len = 0;
  while (*lineptr++) {
    ++len;
  }

  /* Check that lineptr has at least n lines */
  if (len >= n) {
    lineptr -= n + 1;
    while (n-- > 0) {
      printf("%s\n", *lineptr++);
	}
  }
}
