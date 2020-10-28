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
 * Chapter 5 - exercise 8
 
 */

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

/* main: Checks the day_of_year and month_day functions */
int main(void) {
  int month, day;
	
  printf("%d\n", day_of_year(2018, 2, 5));
  month_day(2018, 67, &month, &day);
  printf("%d/%d\n", day, month);

  printf("%d\n", day_of_year(0, 2, 5));
  printf("%d\n", day_of_year(0, 15, 5));
  printf("%d\n", day_of_year(2018, 2, 45));
	
  month_day(2016, 366, &month, &day);
  printf("%d/%d\n", day, month);
		
  month_day(2018, 366, &month, &day);
  printf("%d/%d\n", day, month);

  return 0;
}

/*
 * daytab: Holds the number of days per month in non-leap year
 * and leap year
 */
static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/*
 * day_of_year: Sets day of year from month & day. Notice that
 * we perform error checking, returning -1 if something in the input
 * is wrong
 */
int day_of_year(int year, int month, int day) {
  int i, leap;
	
  if (year < 1 || month < 1 || month > 12 || day < 1) {
    return -1;
  }
	
  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  if (day > daytab[leap][month]) {
    return -1;
  }
 
  for (i = 1; i < month; ++i) {
    day += daytab[leap][i];
  }
  return day;
}

/*
 * month_day: Sets month, day from day of year. Notice that
 * we perform error checking, setting both month and day to -1
 * and returning if something in the input is wrong
 */
void month_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap;

  if (year < 1 || yearday < 1) {
    *pday = -1;
    *pmonth = -1;
    return;
  }

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  if (leap == 1 && yearday > 366 || leap == 0 && yearday > 365) {
    *pday = -1;
    *pmonth = -1;
    return;
  }

  for (i = 1; yearday > daytab[leap][i]; ++i) {
    yearday -= daytab[leap][i];
  }
  *pmonth = i;
  *pday = yearday;
}

