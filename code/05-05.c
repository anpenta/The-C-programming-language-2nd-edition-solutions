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
 * Chapter 5 - exercise 5
 
 */

#include <stdio.h>

#define MAX_LEN 1000

char *pstrncpy(char *s, char *t, int n);
char *pstrncat(char *s, char *t, int n);
int pstrncmp(char *s, char *t, int n);

/* main: Checks the pstrncpy, pstrncat and pstrncmp functions */
int main(void) {
  char s1[MAX_LEN];
  char t1[] = "This is a test";
	
  char s2[MAX_LEN] = "Test";
  char t2[] = "-concatenated";
  char s3[MAX_LEN] = "Test";
  char t3[] = "-concatenated";
	
  char s4[] = "Testd";
  char t4[] = "Test";
  char t5[] = "Testt";
	
  printf("%s\n", pstrncpy(s1, t1, 20));
  printf("%s\n", pstrncpy(s1, t1, 3));

  printf("%s\n", pstrncat(s2, t2, 100));
  printf("%s\n", pstrncat(s3, t3, 3));

  printf("%d\n", pstrncmp(s4, t4, 100));
  printf("%d\n", pstrncmp(s4, t4, 3));
  printf("%d\n", pstrncmp(s4, t5, 4));
  printf("%d\n", pstrncmp(s4, t5, 5));
	
  return 0;
}

/*
 * pstrncpy: Copies at most n characters of string t to string s
 * and return s. Notice that s must be big enough and if t is
 * smaller than n, we pad s with NULLs
 */
char *pstrncpy(char *s, char *t, int n) {
  int i;

  for (i = 0; i < n && (*s = *t); ++i, ++s, ++t) {
    ;
  }
	
  while (i++ <= n) {
    *s++ = '\0';
  }

  return s - n - 1;
}

/*
 * pstrncat: Concatenates at most n characters of string t
 * to string s, terminates s with NULL and returns s. Notice that
 * s must be big enough
 */
char *pstrncat(char *s, char *t, int n) {
  int j = 0, i = 0;

  for ( ; *s; ++s, ++j) {
    ;
  }

  for (i = 0; i < n && (*s = *t); ++i, ++s, ++t) {
    ;
  }
	
  if (*s) {
    *++s = '\0';
  }
  return s - i - j;
}

/*
 * pstrncmp: Compares at most n characters of string s
 * to string t and returns < 0 if s < t, 0 if s == t, or > 0 if s > t
 */
int pstrncmp(char *s, char *t, int n) {

  for ( ; n > 0 && *s == *t; ++s, ++t, --n) {
    if (!*s) {
      return 0;
	}
  }
  if (n == 0 && *--s == *--t) {
    return 0;
  }
	
  return *s - *t;
}
