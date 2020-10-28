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
 * Chapter 4 - exercise 4
 
 */

#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <string.h>

#define MAXOP 100 /* Max size of operand or operator */
#define NUMBER '0'/* Signal that a number was found */
#define ALPHA '1' /* Signal that a letter or string was found */
 
int getop(char []);
void push(double);
double pop(void);
void command(char s[]);
void print(void);
void swap(void);
void duplicate(void);
void clear(void);

/*
 * main: Reverse Polish calculator extended with modulus operator
 * and commands to print the top element of the stack (without popping),
 * to duplicate it, to swap the two top elements and to clear the stack
 */
int main(void) {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch(type) {
      case NUMBER:
        push(atof(s));
        break;
      case ALPHA:
        command(s);
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
	    op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0) {
          push(pop() / op2);
		} else {
            printf("error: zero divisor\n");
		}
		break;
      case '%':
        op2 = pop();
        if (op2 != 0.0) {
          push(fmod(pop(), op2));
		} else {
            printf("error: zero divisor\n");
		}
        break;
      case '\n' :
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("error: unknown command %s\n", s);
		break;
	}
  }
  return 0;
}
 
#define MAXVAL 100  /* Maximum depth of val stack */
 
int sp = 0;         /* Next free stack position */
double val[MAXVAL]; /* Value stack */

/* command: Executes the given command */
void command(char s[]) {
  if (strlen(s) == 1) {
    if (s[0] == 'p') {
      print();
	} else if (s[0] == 'd') {
        duplicate();
	} else if (s[0] == 's') {
        swap();
	} else if (s[0] == 'c') {
        clear();
	} else {
	    printf("error: command not found\n");
	}
  }
}

/* push: Pushes f onto value stack */
void push(double f) {
  if (sp < MAXVAL) {
    val[sp++] = f;
  } else {
      printf("error: stack full, can't push %g\n", f);
  }
}
 
/* pop: Pops and returnr top value from stack */
double pop(void) {
  if (sp > 0) {
    return val[--sp];
  } else {
      printf("error: stack empty\n");
      return 0.0;
  }
}
 
/* print: Prints the top element of the stack without popping */
void print(void) {
  if (sp > 0) {
    printf("Top stack element : %.8g\n", val[sp - 1]);
  } else {
    printf("error: stack empty\n");
  }
}

/* duplicate: Duplicates the top element of the stack */
void duplicate(void) {
  double elem = pop();
  push(elem);
  push(elem);
}

/* swap: Swaps the top two elements in the stack */
void swap(void) {
  double elem1 = pop();
  double elem2 = pop();
  push(elem1);
  push(elem2);
}

/* clear: Clears the stack */
void clear(void) {
  sp = 0;
}

#include <ctype.h>
 
int getch(void);
void ungetch(int);
 
/*
 * getop: Gets next character or numeric operand.
 * We pass s[] to getop to store input
 */
int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t') {
    ;
  }
  s[1] = '\0';
  if (!isdigit(c) && c != '.' && !isalpha(c)) {
    return c; /* Not a number, not a letter */
  }
  i = 0;
	
  /* Collect letter or string */
  if (isalpha(c)) {
    while (isalpha(s[++i] = c =getch())) {
      ;
	}
    s[i] = '\0';
    if (c != EOF) {
      ungetch(c);
	}
    return ALPHA;
  }

  if (isdigit(c)) {
    /* Collect integer part */ 
    while (isdigit(s[++i] = c = getch())) {
      ;
	}
  }

  if (c == '.') {
    /* Collect fraction part */
    while (isdigit(s[++i] = c = getch())) {
      ;
	}
  }
  s[i] = '\0';
  if (c != EOF) {
    ungetch(c);
  }
  
  return NUMBER;
}

#define BUFSIZE 100
 
char buf[BUFSIZE]; /* Buffer for ungetch */
int bufp = 0; /* Next free position in buf */

/* getch: Gets a (possibly pushed-back) character */
int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: Pushes character back in input */
void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
      buf[bufp++] = c;
  }
}