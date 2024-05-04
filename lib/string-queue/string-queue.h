#ifndef STRING_QUEUE_INCLUDED
#define STRING_QUEUE_INCLUDED

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// private type definition
typedef struct node
{
  char *data;
  struct node *next;
} node;

typedef struct queue
{
  node *head;
} queue;

queue *create_queue();
int push(queue *queue, char *data);
char *pull(queue *queue);
int is_empty(queue *queue);
int size(queue *queue);
int print_queue(queue *queue);

#endif