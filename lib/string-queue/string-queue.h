#ifndef STRING_QUEUE_INCLUDED
#define STRING_QUEUE_INCLUDED

#include <stdlib.h>
#include <string.h>

typedef struct queue
{
  node *head;
} queue;

// private type definition
typedef struct node
{
  char *data;
  struct node *next;
} node;

int push(queue *queue, char **data);
char *pull(queue *queue);
int is_empty(queue *queue);
int size(queue *queue);

#endif