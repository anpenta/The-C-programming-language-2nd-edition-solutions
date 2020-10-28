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
 * Chapter 7 - exercise 6
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 5000 /* Maximum length of input lines */
int comparefiles(FILE *fp1, FILE *fp2);

/* main: Compares two files, printing the first line where they differ */
int main(int argc, char *argv[]) {
  FILE *fp1, *fp2; /* Pointers to the two files */
  char *prog = argv[0]; /* Name of the program */
  int c1, c2;

  /* If the correct arguments weren't provided */
  if (argc != 3) {
    fprintf(stderr, "%s error: did not detect two filenames\n", argv[0]);
    exit(1);
  }
	
  /* Error handling for file opening */
  if ((fp1 = fopen(*++argv, "r")) == NULL) {
    fprintf(stderr, "%s: can't open %s\n", prog, *argv);
    exit(1);
  } else if ((fp2 = fopen(*++argv, "r")) == NULL) {
      fprintf(stderr, "%s: can't open %s\n", prog, *argv);
      exit(1);
  }

  /* check if the two files have the same content */
  comparefiles(fp1,fp2);
	
  return 0;
}

/*
 * comparefiles: checks if two files have the same content line by line
 * and returns 1 if true and 0 otherwise
 */
int comparefiles(FILE *fp1, FILE *fp2) {
  char line1[MAX_LEN], line2[MAX_LEN]; /* Hold the lines read from each file */
  char *ptr1, *ptr2; /* Hold the result of fgets */

  /* Loop through the two files and read one line from each file at a time */
  for(;;) {
    ptr1 = fgets(line1, MAX_LEN, fp1);
    ptr2 = fgets(line2, MAX_LEN, fp2);
    /* If any of the two fgets returned NULL break out of the loop */
    if (!ptr1 || !ptr2) {
      break;
	}
    /*
     * If fgets did not return NULL in both cases and if the two lines differ
     * print answer to stdout and break out of the loop
     */
    if (ptr1 && ptr2 && strcmp(ptr1, ptr2) != 0) {
      printf("First different lines:\nFirst file: %sSecond file: %s", line1, line2);
      break;
    }
  }

  /* If fgets returned NULL only for the first file */
  if (!ptr1 && ptr2) {
    printf("First file has fewer lines than second file\n");
  }
  /* Else if fgets returned NULL only for the second file */
  else if (!ptr2 && ptr1) {
    printf("Second file has fewer lines than first file\n");
  }
  /* Else if fgets returned NULL for both files */
  else if (!ptr1 && !ptr2) {
    printf("The two files have the same content\n");
  }
}
