#include "string-queue.h"

int main()
{
  char *my_string = "hello there";
  queue *new_queue = create_queue();
  push(new_queue, my_string);
  char *string1 = "mothrefucker";
  char *string2 = "pito loco";
  push(new_queue, string1);
  push(new_queue, string2);
  printf("before: \n");
  print_queue(new_queue);
  my_string = pull(new_queue);
  printf("the pulled string is: %s\n", my_string);
  print_queue(new_queue);
}