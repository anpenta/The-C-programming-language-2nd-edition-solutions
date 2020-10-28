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
 * Chapter 7 - exercise 8
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 50 /* Maximum length of input lines */
#define MAX_PAGE 15 /* Maximum length of page */
int printfile(FILE *fp, char *filename);

/*
 * main: Prints a set of files, starting each new one on a new
 * page, with a title and running page count for each file
 */
int main(int argc, char *argv[]) {
  FILE *fp; /* Pointer to a file */
  char *prog = argv[0]; /* Name of the program */
  int c1, c2;

  /* If the no arguments were provided */
  if (argc == 1) {
    fprintf(stderr, "%s error: did not detect any filenames\n", argv[0]);
    exit(1);
  } else {
      /* For each file */
      while (--argc > 0) {
        /* Error handling for file opening */
        if ((fp = fopen(*++argv, "r")) == NULL) {
          fprintf(stderr, "%s: can't open %s\n", prog, *argv);
          exit(1);
		} else {
            printfile(fp, *argv);	
		}
	  }
  }
  return 0;
}

/* printfile: Prints a file in a new page with a title and running page count */
int printfile(FILE *fp, char *filename) {
  char lines[MAX_PAGE][MAX_LINE]; /* Array of arrays of lines to hold the lines of each file */
  char line[MAX_LINE]; /* Holds the line returned by fgets */	
  int idx = 0; /* For current index of lines */
  static int page = 1; /* Holds the current page number */

  /* Loop through the file and read one line at a time */
  while(fgets(line, MAX_LINE, fp)) {
    /* Error handling if a line in the file is too big */
    if (line[strlen(line) - 1] == '\0' && line[strlen(line) - 2] != '\n') {
      fprintf(stderr, "error: %s has too big lines\n", filename);
      exit(1);
	} /* Copy the string to the lines array (including the NULL char) */
      else if (idx < MAX_PAGE) {
        strncpy(lines[idx++], line, strlen(line) + 1);
	} /* Error handling if the file is too big to fit the page */
      else if (idx == MAX_PAGE) {
        fprintf(stderr, "error: %s too big to fit page\n", filename);
        exit(1);
	  }	
  }

  /* Error handling while reading */
  if (ferror(fp)) {
    fprintf(stderr, "Error while reading %s\n", filename);
    exit(1);
  } /* Error handling while closing the file */	
    else if (fclose(fp)) {
      fprintf(stderr, "Error while closing %s\n", filename);
      exit(1);
  } /* Write the file to the page */
    else {
      int n = 0;
	
      /* Print the title, lines and running page count */
      printf("File name: %s\n\n", filename); /* Title */
      while(n < idx) /* Content */ {
        printf("%s", lines[n++]);
	  }
      while(n++ < MAX_PAGE) {/* If content does not fit the page pad with \n */
        putchar('\n');
	  }
      putchar('\n');
      printf("Page: %d\n\n", page++);
	}
}

