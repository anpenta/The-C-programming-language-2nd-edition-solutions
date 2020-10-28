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
 * Chapter 5 - exercise 10
 
 */

#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h>
#include <string.h>

#define MAX_IN 1000 /* Maximum length of input expression */
#define NUMBER '0' /* Signal that a number was found */
#define NAN '1' /* Signal that a non-numeric value was found */
#define ILLEGAL '2' /* Signal than an illegal command was found */

double pop(void);
void push(double f);
int detarg(char *s);

/* main: Evaluates a reverse Polish expression from the command line */
int main(int argc, char *argv[]) {
  double temp;
	
  while (--argc > 0) {
    switch (detarg(*++argv)) {
      case NUMBER:
        push(atof(*argv));
        break;
      case NAN:
        switch ((*argv)[0]) {
          case ('+'):
            push(pop() + pop());
            break;
	      case ('-'):
            temp = pop();
            push(pop() - temp);
            break;
          case ('*'):
            push(pop() * pop());
            break;
          case ('/'):
            temp = pop();
            if (temp != 0.0) {
                push(pop() / temp);
			} else {
                printf("expr error: division by zero\n");
                return 1;
			}
            break;
          default:
	        printf("expr error: illegal command %s\n", *argv);
	        return 1;
		}
		break;
      default:
        printf("expr error: illegal command %s\n", *argv);
        return 1;
	}
  }
  printf("Answer: %.8g\n", pop());

  return 0;
}

/*
 * stack: Holds temporary information for calculations
 * idx: Holds current position in the stack
 */
static double stack[MAX_IN];
int idx = 0;

/* pop: Pops a number from the stack and returns it */
double pop(void) {
  if (idx > 0) {
    return stack[--idx];
  } else {
      printf("pop error: stack empty\n");
      return 0.0;
  }
}

/* push: Pushes a number to the stack */
void push(double f) {
  if (idx < MAX_IN) {
    stack[idx++] = f;
  } else {
      printf("push error: stack full\n");
  }
}

/* detarg: Determines the type of the next argument from input */
int detarg(char *s) {
  /*
   * If the first character in the argument is a digit
   * and if the argument consists of only digits or '.' return NUMBER
   */
  if (isdigit(*s++)) {
    while (isdigit(*s) || *s == '.') {
      ++s;
	}
    if (!(*s)) {
      return NUMBER;
	}
  }
	
  /*
   * If the first character in the argument is not a digit (checked above)
   * and the second character is NULL return NAN
   */
  if (!(*s)) {
    return NAN;
  }
  
  /* Else return ILLEGAL */
  return ILLEGAL;
}
