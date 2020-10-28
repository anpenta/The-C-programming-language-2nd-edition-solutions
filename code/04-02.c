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
 * Chapter 4 - exercise 2
 
 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#ifndef M_E
#define M_E 2.71828
#endif

double atof(char s[]);

/* main: Tests the extended atof function */
int main(void) {
  char s1[] = "123.45e-6";
  char s2[] = "13.68E3";
  char s3[] = "2451";
  char s4[] = "782.45";

  printf("%f\n", atof(s1));
  printf("%f\n", atof(s2));
  printf("%f\n", atof(s3));
  printf("%f\n", atof(s4));
	
  return 0;
}

/*
 * atof: Converts a string s to its double-precision floating point equivalent
 * while handling scientific notation of the form 123.45e-6
 */
double atof(char s[]) {
  double val, power, exp = 1;
  int i, sign;
	
  for (i = 0; isspace(s[i]); i++) {
    ;
  }
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') {
    i++;
  }
  for (val = 0.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
  }
  if (s[i] == '.') {
    i++;
  }
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
	
  if ((s[i] == 'e' || s[i] == 'E') && s[i + 1] == '-') {
    exp = pow(M_E, -1 * (s[i + 2] - '0'));
  } else if ((s[i] == 'e' || s[i] == 'E')) {
      exp = pow(M_E, s[i + 1] - '0');
  }
	
  return (sign * val / power) * exp;
}
