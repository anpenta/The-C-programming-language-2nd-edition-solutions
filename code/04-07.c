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
 * Chapter 4 - exercise 7
 
 */

/*
 * Note: While in exercises 4-3 to 4-6 we added functionalities progressively
 * this exercise brances off from exercise 4-6
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAXOP 100 /* Max size of operand or operator */
#define NUMBER '0'/* Signal that a number was found */
#define COMMAND '1' /* Signal that a lowercase letter or string was found */

int getop(char []);
void push(double);
double pop(void);
void command(char s[]);
void print(void);
void swap(void);
void duplicate(void);
void clear(void);
void assignval(int x, double n);
double getvalue(int x);

/*
 * main: reverse Polish calculator extended with modulus operator,
 * commands to print the top element of the stack (without popping),
 * to duplicate it, to swap the two top elements and to clear the stack,
 * math library functions sin(), cos(), exp() and pow() and variable functionality
 */
int main(void) {
  int type, prevtype;
  double op2, recent;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch(type) {
      case NUMBER:
        push(atof(s));
        break;
      case COMMAND:
        command(s);
        break;
      case '=':
        if (isalpha(prevtype) && isupper(prevtype)) {
          pop();
          assignval(prevtype, pop());
		} else {
            printf("error: variable name not supported");
		}
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
        recent = pop();
        printf("\t%.8g\n", recent);
        break;
      case '_':
        push(recent);
        break;
      default:
        if (isalpha(type) && isupper(type)) {
          push(getvalue(type));
		} else {
            printf("error: unknown command %s\n", s);
		}
        break;
	}
    prevtype = type;
  }
  return 0;
}
 
#define MAXVAL 100  /* Maximum depth of val stack */
#define MAXVAR 26 /* Maximum number of variables */
int sp = 0;         /* Next free stack position */
double val[MAXVAL]; /* Value stack */
double var[MAXVAR]; /* Variable array (every index corresponds to the letters A-Z) */

/* command: Executes the given command */
void command(char s[]) {
  /* If command is a single lowercase letter */
  if (strlen(s) == 1 && islower(s[0])) {
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
  } /* If command is a lowercase string */
    else if (strlen(s) > 1 && islower(s[0]))  {
		if (strcmp(s, "sin") == 0) {
        push(sin(pop()));
	  } else if (strcmp(s, "exp") == 0) {
          push(exp(pop()));
	  } else if (strcmp(s, "pow") == 0) {
          int op2 = pop();
          push(pow(pop(), op2));
	  } else if (strcmp(s, "cos") == 0) {
          push(cos(pop()));
	  } else {
          printf("error: math function not supported\n");
	  }
	} else {
        printf("error: command not found\n");	
	}
}

/* getvalue: Returns the current value of a given variable */
double getvalue(int x) {
  if (isalpha(x) && isupper(x)) {
    return var[x - 'A'];
  } else {
    printf("error: variable name not supported\n");
  }
}

/* assignval: Assigns given value to given variable */
void assignval(int x, double n) {
  if (isalpha(x) && isupper(x)) {
    var[x - 'A'] = n;
  } else {
    printf("error: variable name not supported\n");
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
    if (strlen(s) == 1 && isupper(s[0])) {
      return s[0];
	} else {
        return COMMAND;
	}
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
 
char buf[BUFSIZE]; /* buffer for ungetch and ungets */
int bufp = 0; /* next free position in buf */

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

/*
 * ungets: Pushes a string back to input. This function should know
 * about buf and bufp to handle the case where the string is too big
 * to put back
 */
void ungets(char s[]) {
  if (bufp + strlen(s) >= BUFSIZE) {
    printf("ungets: string has too many characters\n");
  } else {
      int i;
      for (i = strlen(s) - 1; i >= 0; --i) {
        buf[bufp++] = s[i];
	  }
  }
}
