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
 * Chapter 7 - exercise 1
 
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
 * main: Converts upper case to lower or vice versa depending on the
 * parameter found in argv[0] (the name of the program)
 */
int main(int argc, char *argv[]) {
  int c;
  int lower = strcmp(argv[0], "./lower") == 0 || strcmp(argv[0], "lower") == 0;
  int upper = strcmp(argv[0], "./upper") == 0 || strcmp(argv[0], "upper") == 0;

  /* If there are more than one arguments */
  if ((lower || upper) && argc > 1) {
    printf("\nerror: no parameters should be provided\n");
    return 1;
  } /* Else if lower was provided */
    else if (lower) {
      putchar('\n');
      while ((c = getchar()) != EOF) {
        putchar(tolower(c));
	  }
  } /* Else if upper was provided */
    else if (upper) {
      putchar('\n');
      while ((c = getchar()) != EOF) {
        putchar(toupper(c));
	  }
  }

  return 0;
}
