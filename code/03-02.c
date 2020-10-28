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
 * Chapter 3 - exercise 2
 
 */

#include <stdio.h>

#define MAX_LEN 1000

void escape(char s[], char t[]);
void invescape(char s[], char t[]);

/* main: Tests the escape function and the invescape function */
int main(void) {
  char s1[] = "This\tis a\ntest\b";
  char s2[] = "This\\tis a\\ntest\\b";
  char t[MAX_LEN];

  printf("%s\n", s1);
  escape(s1,t);
  printf("%s\n", t);
	
  printf("%s\n", s2);
  invescape(s2,t);
  printf("%s\n", t);
	
  return 0;
}

/*
 * escape: Copies string s to t while converting characters like
 * newline and tab into visible escape sequences like \n and \t
 */
void escape(char s[], char t[]) {
int i = 0, j = 0;
	
  while (s[i] != '\0') {
    switch (s[i]) {
      case '\t':
        t[j] = '\\';
        t[j + 1] = 't';
        j += 2;
        ++i;
        break;
      case '\n':
        t[j] = '\\';
        t[j + 1] = 'n';
        j += 2;
	    ++i;
	    break;
      case '\b':
        t[j] = '\\';
        t[j + 1] = 'b';
	    j += 2;
        ++i;
	    break;
      default:
        t[j++] = s[i++];
	}
  }
  t[j] = '\0';		
}

/*
 * invescape: Copies string s to t while converting visible escape sequences
 * like \n and \t into characters like newline and tab
 */
void invescape(char s[], char t[]) {
  int i = 0, j = 0;
	
  while (s[i] != '\0') {
    switch (s[i]) {
      case '\\':
        switch (s[i + 1]) {
          case 't':
            t[j] = '\t';
            break;
          case 'n':
            t[j] = '\n';
            break;
          case 'b':
            t[j] = '\b';
	        break;
		}
        i += 2;
        ++j;
        break;
      default:
        t[j++] = s[i++];
	}
  }
  t[j] = '\0';		
}
