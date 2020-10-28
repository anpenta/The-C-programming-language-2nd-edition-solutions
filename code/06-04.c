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
 * Chapter 6 - exercise 4
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 10000 /* Maximum number of input lines */
#define MAX_WORDS 5000 /* Maximum number of input words */
struct word *wordfreq[MAX_WORDS] = {NULL}; /* wordfreq: Array of pointers to word structures */
char *lineptr[MAX_LINES]; /* lineptr: Array of pointers to lines */

int readlines(char *lineptr[], int maxlines);
void extrwords(char *line, int n);
void printwords(struct word *wordfreq[]);
void decqsort(struct word *v[], int left, int right);

/*
 * main: Prints all distinct words from input, sorted in decreasing order
 * of frequency of occurence and precedes each word by its count.
 * For sorting we modify the qsort function from the book
 */
int main(void) {
	
  struct tnode *root = NULL;
  int nlines;
  int i;
  struct word **idx = wordfreq;

  if ((nlines = readlines(lineptr, MAX_LINES)) >= 0) {
    for (i = 0; i < nlines; ++i) {
      extrwords(lineptr[i], i + 1);
	}
  }
  putchar('\n');
	
  /* Determine the length of wordfreq */
  while (*idx) {
    ++idx;
  }
	
  /* Sort the words in decreasing frequency and print them */
  decqsort(wordfreq, 0, idx - wordfreq - 1);
  printwords(wordfreq);
	
  return 0;
}

/* word: Structure to hold a word and its count */
struct word {
  char *word;
  int count;
};

/*
 * readlines: Reads input lines, stores their pointers in the lineptr array
 * and returns the number of lines. Notice that we are using the built-in
 * getline function
 */
int readlines(char *lineptr[], int maxlines) {
  size_t len;
  int nlines = 0;
  char *line = NULL;

  while ((getline(&line, &len, stdin)) != -1) {
    if (nlines >= MAX_LINES) {
      return -1;
	} else {
        line[strlen(line) - 1] = '\0';
        lineptr[nlines++] = line;
        line = NULL;
	}
  }

  return nlines;
}

/*
 * extrwords: Cleans a line, extracts the words we need
 * and adds them into the wordfreq array as word structures.
 * Notice that we are using the built-in strtok function to parse the line
 */
void extrwords(char *line, int n) {
  int checkword(char *s);
  void addword(struct word *wordfreq[], char *w);

  char *w = strtok(line," \t,\'\":.;?()!");
  while (w != NULL) {
    if (checkword(w)) {
      addword(wordfreq, w);
	}
    w = strtok(NULL, " \t,\'\":.;?()!");
  }
}

/* checkword: Returns 1 if a string is a word or 0 otherwise */
int checkword(char *s) {
  while (*s) {
    if (!(isalpha(*s) || *s == '-')) {
    return 0;
	}
    ++s;
  }
  return 1;
}

/*
 * addword: Adds a new word structure to wordfreq or increase its frequency
 * if it is already in the array
 */
void addword(struct word *wordfreq[], char *w) {
  struct word **ptr = wordfreq;

  /* While there is a struct word in the wordfreq array */
  while (*ptr) {
    /* If it matches the current word increase the count */
    if (strcmp((*ptr)->word, w) == 0) {
      ++(*ptr)->count;
      break;
    }
    ++ptr;
  }

  /* If the word is not in the array then add a new structure with this word */
  if (!*ptr && ptr - wordfreq < MAX_WORDS) {
    struct word *temp = (struct word *)malloc(sizeof(struct word));
    temp->word = w;
    temp->count = 1;
    *ptr = temp;
  }
}

/* printwords: Prints the words in the wordfreq array preceded by their count */
void printwords(struct word *wordfreq[]) {
  while(*wordfreq) {
    printf("Frequency: %d\tWord: %s\n", (*wordfreq)->count, (*wordfreq)->word);
    ++wordfreq;
  }
}


/*
 * decqsort: Sorts the input array into decreasing order based on the
 * frequency of each word
 */
void decqsort(struct word *v[], int left, int right) {
  int i, last;
  void swap(struct word *v[], int i, int j);

  if (left >= right) {
    return;
  }
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left+1; i<= right; i++) {
    if (v[i]-> count > v[left]->count) {
      swap(v, ++last, i);
	}
  }
  swap(v, left, last);
  decqsort(v, left, last-1);
  decqsort(v, last+1, right);
}

/* swap: Interhanges v[i] and v[j] */
void swap(struct word *v[], int i, int j) {
  struct word *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
