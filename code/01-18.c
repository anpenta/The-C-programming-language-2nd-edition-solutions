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
 * Chapter 1 - exercise 18
 
 */

#include <stdio.h>

#define MAX_LEN 1000

int readline(char line[], int cap);
void cleanline(char line[], int len);

/*
 * main: Removes trailing blanks and tabs from each
 * line of input
 */
int main(void) {
  int len, c;
  char line[MAX_LEN];
	
  while ((len = readline(line, MAX_LEN)) > 0) {
    cleanline(line, len);
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


/* cleanline: Cleans a line that has been read */
void cleanline(char line[], int len) {
	
  while (line[len - 1] == '\0' || line[len - 1] == '\n' || line[len - 1] == '\t' || line[len - 1] == ' ') {
    --len;
  }
  line[len] = '\n';
  line[len + 1] = '\0';
}
		
	
