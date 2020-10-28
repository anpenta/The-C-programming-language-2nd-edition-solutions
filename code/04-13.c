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
 * Chapter 4 - exercise 13
 
 */

#include <stdio.h>
#include <string.h>

void reverse(char s[], int left, int right);

/* main: Tests the recursive reverse function */
int main(void) {
  char s1[] = "Test";

  printf("%s\n", s1);
  reverse(s1, 0, strlen(s1) - 1);
  printf("%s\n", s1);
	
  return 0;
}

/* reverse: Reverses the string s by using recursion */
void reverse(char s[], int left, int right) {

  if (left < right) {
    reverse(s, left + 1, right - 1);
  } else {
      int temp = s[left];
      s[left] = s[right];
      s[right] = temp;
  }

  int temp = s[left];
  s[left] = s[right];
  s[right] = temp;
}
