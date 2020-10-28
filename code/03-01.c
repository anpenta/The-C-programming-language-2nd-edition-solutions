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
 * Chapter 3 - exercise 1
 
 */

#include <stdio.h>

int binsearch(int x, int v[], int n);

/* main: Tests the binsearch function */
int main(void) {
  int v1[] = {2,3,4,6,9};
  int v2[] = {1,4,6,17,20};
  int v3[] = {1,2,17,19,20};
  int x = 17, n = 5;
	
  printf("%d\n", binsearch(x,v1,n));
  printf("%d\n", binsearch(x,v2,n));
  printf("%d\n", binsearch(x,v3,n));
  return 0;
}

/* binseach: Finds x in the sorted array v, using binary search */
int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  mid = (low + high) / 2;
  while (low <= high && x != v[mid]) {
    mid = (low + high) / 2;
    if (x < v[mid]) {
      high = mid - 1;
	} else {
        low = mid + 1;
	}
  }
  if (x == v[mid]) {
    return mid;
  } else {
      return -1;
  }
}