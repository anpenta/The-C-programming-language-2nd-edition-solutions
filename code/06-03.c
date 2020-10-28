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
 * Chapter 6 - exercise 3
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct lnode *newlnode(int line);
void appendlist(struct lnode **root, int line);
void printlist(struct lnode *node);

struct tnode *newtnode(char *word);
struct tnode *addtree(struct tnode *node, char *word, int line);
void treeprint(struct tnode *node);

#define MAX_LINES 10000 /* Maximum number of input lines */
char *lineptr[MAX_LINES]; /* lineptr: Array of pointers to lines */
int readlines(char *lineptr[], int maxlines);
void extrwords(struct tnode **root, char *line, int n);

/*
 * main: Prints all words in a document, and for each word, prints
 * a list of the line numbers on which it occurs - We exclude noise
 * words such as "the" and "and". Notice that we are using two
 * data structures for our task (a singly linked list and a binary
 * search tree)
 */
int main(void) {
	
  struct tnode *root = NULL;
  int nlines;
  int i;

  if ((nlines = readlines(lineptr, MAX_LINES)) >= 0) {
    for (i = 0; i < nlines; ++i)
      extrwords(&root, lineptr[i], i + 1);
  }
  putchar('\n');
  treeprint(root);
	
  return 0;
}

/* Text processing implementation */

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
 * and adds them into the binary search tree. Notice that here
 * we want the actual root of the tree to change while inserting
 * the first word and that is why we are passing a pointer to a pointer
 * as the first argument (in order to be able to pass the root by address
 * into the function). Notice also that we are using the built-in
 * strtok function to parse the line
 */
void extrwords(struct tnode **root, char *line, int n) {
  int checkword(char *s);

  char *w = strtok(line," \t,\'\":.;?()!");
  while (w != NULL) {
    if (checkword(w)) {
      *root = addtree(*root, w, n);
	}
    w = strtok(NULL, " \t,\'\":.;?()!");
  }
}

/*
 * checkword: Returns 1 if a string is a word with more than 3 characters
 * or 0 otherwise
 */
int checkword(char *s) {
  if (strlen(s) < 4) {
    return 0;
  }
	
  while (*s) {
    if (!(isalpha(*s) || *s == '-')) {
      return 0;
	}
    ++s;
  }
  return 1;
}

/* End of text processing implementation */

/* Singly linked list implementation */
 
/* lnode: Structure that represents a singly linked list node */
struct lnode {
  int line; /* line: Holds number of line */
  struct lnode *next; /* next: Pointer to next node */
};

/* newlnode: Creates a new lnode */
struct lnode *newlnode(int line) {
  struct lnode *new = (struct lnode *) malloc(sizeof(struct lnode));
  new->line = line;
  new->next = NULL;
  return new;
}

/*
 * appendlist: Adds a new node to the end of a singly linked list.
 * Notice that here if the root is NULL we want the actual root to change
 * and that is why we are passing a pointer to a pointer as the first
 * argument
 */
void appendlist(struct lnode **root, int line) {
  struct lnode *new = newlnode(line);
	
  /* If the root is NULL then add new as root */	
  if (*root == NULL) {
    *root = new;
    return;
  }
	
  /*
   * Else traverse the list and add new to the end and
   * make sure not to add any duplicates
   */
  struct lnode *temp = *root;
  while (temp->next != NULL && temp->line != line) {
    temp = temp->next;
  }

  if (temp->line != line) {
    temp->next = new;
  }
			
  return;
}

/*
 * printlist: Traverses the list and prints each node's data starting
 * from given node
 */
void printlist(struct lnode *node) {
  while (node != NULL) {
    printf("%d ", node->line);
    node = node->next;
  }
}

/* End of singly linked list implementation */

/* Binary search tree implementation */

/* tnode: Structure that represents a binary search tree node */
struct tnode {
  char *word; /* word: Pointer to the word string */
  struct lnode *lines; /* lines: Root node to the list of line numbers where word occurs */
  struct tnode *left; /* left: Pointer to the left child */
  struct tnode *right; /* right:  Pointer to the right child */
};

/* newtnode: Creates a new tnode*/
struct tnode *newtnode(char *word) {
  struct tnode *new = (struct tnode *) malloc(sizeof(struct tnode));
  new->word = word;
  new->lines = NULL;
  new->left = new->right = NULL;
  return new;
}

/*
 * addtree: Adds a new word to the binary search tree or appends the line
 * number to an existing one
 */
struct tnode *addtree(struct tnode *node, char *word, int line) {
  int test;

  /* If the word is new, add it to the tree and append the line number */
  if (node == NULL) {
    node = newtnode(word);
    node->lines = newlnode(line);
  } /* Else if the word is already in the tree append the line number */
    else if ((test = strcmp(word, node->word)) == 0) {
      appendlist(&node->lines, line);
  } /* Else if the word is lexicographically smaller recurse on the left child */
    else if (test < 0) {
      node->left = addtree(node->left, word, line);
  } /* Else if the word is lexicographically larger recurse on the right child */
    else {
      node->right = addtree(node->right, word, line);
  }
  return node;
}

/*
 * treeprint: Prints binary search tree starting from given node in-order.
 * For each node prints its word and the line numbers where the word appears
 */
void treeprint(struct tnode *node) {
  if (node != NULL) {
    treeprint(node->left);
		
    printf("Word: %s\tLine Numbers: ", node->word);
    printlist(node->lines);
    putchar('\n');
		
    treeprint(node->right);
  }
}

/* End of binary search tree implementation */


