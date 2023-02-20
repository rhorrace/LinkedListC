#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int insert_item(struct node** head, int data) {
  if(!head) return 0;

  struct node* temp = new_node(data, 0);

  if(!(*head)) {
    *head = temp;
    return 1;
  }

  struct node* current = *head;

  while(current->next) current = current -> next;

  current->next = temp;

  return 1;
}

int display_item(struct node* head, int data) {
  if(!head) return 0;

  struct node* current = head;

  while(current) {
    if(current -> data == data) {
      printf("%d\n", current -> data);
      return 1;
    }

    current = current -> next;
  }

  return 0;
}

int display_all(struct node* head) {
  if(!head) return 0;

  struct node* current = head;

  while(current) {
    printf("%d", current -> data);

    if(current -> next) printf(" -> ");

    current = current -> next;
  }

  printf("\n");

  return 1;
}

int remove_item(struct node** head, int data) {
  if(!head || !(*head)) return 0;

  struct node* current = *head;
  struct node* previous = 0;

  while(current->next && current->data != data) {
    previous = current;
    current = current -> next;
  }

  if(current->data != data) return 0;

  if (previous) {
    previous -> next = current -> next;
  } else {
    *head = current -> next;
  }
  current -> next  = 0;
  free(current);

  return 1;
}

int remove_all(struct node** head) {
  if(!head) return 0;

  while(*head) {
    struct node* temp = (*head) -> next;
    (*head) -> next = 0;
    free(*head);
    *head = temp;
  }

  return 1;
}
