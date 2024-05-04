#include "string-queue.h"

// private function, creates a node
node *create_node(char *data)
{
  node *new_node = (node *)malloc(sizeof(node));
  new_node->next = NULL;
  new_node->data = strdup(data);
  return new_node;
}

/*
  Creates a new queue.
  Returns NULL if there was an error during excecution.
*/
queue *create_queue()
{
  queue *new_queue = (queue *)malloc(sizeof(queue));
  if (new_queue != NULL)
  {
    new_queue->head = NULL;
  }
  return new_queue;
}

/*
  Pushes a value to the list.
  Returns 1 if an error occured, otherwise returns 0.
*/
int push(queue *queue, char *data)
{
  if (queue == NULL || data == NULL || data[0] == '\0')
    return 1;
  node *new_node = create_node(data);
  new_node->next = queue->head;
  queue->head = new_node;
  return 0;
}

/*
  Pulls a value from the queue.
  If an error occured, returns null.
*/
char *pull(queue *queue)
{
  if (queue == NULL || queue->head == NULL)
    return NULL;
  node *first = queue->head;
  char *value = strdup(first->data);
  queue->head = first->next;
  free(first->data);
  free(first);
  return value;
}

/*
  Checks if the queue is empty.
  Returns 1 if it is, otherwise returns 0.
*/
int is_empty(queue *queue)
{
  return (queue == NULL || queue->head == NULL);
}

/*
  Returns the number of elements the queue has.
*/
int size(queue *queue)
{
  if (queue == NULL)
    return 0;
  int count = 0;
  for (node *current = queue->head; current != NULL; current = current->next)
  {
    count++;
  }
  return count;
}

int print_queue(queue *queue)
{
  if (queue == NULL)
    return 1;
  printf("HEAD -> ");
  for (node *current = queue->head; current != NULL; current = current->next)
  {
    printf("%s -> ", current->data);
  }
  printf("NULL\n");
  return 0;
}