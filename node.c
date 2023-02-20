#include "node.h"
#include <stdlib.h>

struct node* new_node(int data, struct node* next) {
  struct node* temp = (struct node*) malloc(sizeof(struct node));

  temp -> data = data;
  temp -> next = next;

  return temp;
}
