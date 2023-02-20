#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  struct node* head = 0;
  int response = 0, value;

  do {
    printf("1) Insert number\n"); 
    printf("2) Display number\n"); 
    printf("3) Display all\n"); 
    printf("4) Remove number\n"); 
    printf("5) Remove all\n"); 
    printf("6) Quit\n");

    printf("Enter number: ");
    scanf("%d", &response);
    fflush(stdin);    

    switch(response) {
      case 1:
        printf("Enter number: ");
        scanf("%d", &response);
        fflush(stdin);    

        value = insert_item(&head, response);

        if(!value) printf("Error: Issue inserting item into list\n");
      
        break;
      case 2:
        printf("Enter number: ");
        scanf("%d", &response);
        fflush(stdin);    

        value = display_item(head, response);

        if(!value) printf("Error: Value not in list\n");

        break;
      case 3:
        value = display_all(head);

        if(!value) printf("Error: Issue displaying all items in list\n");

        break;
      case 4:
        printf("Enter number: ");
        scanf("%d", &response);
        fflush(stdin);    

        value = remove_item(&head, response);

        if(!value) printf("Value not in list\n");

        break;
      case 5:
        value = remove_all(&head);

        if(!value) printf("Error: Issue removing all items in list\n");

        break;
      case 6:
        printf("Goodbye\n");

        break;
      default:
        printf("Error: Invalid option\n");

        break;
    }

    fflush(stdout);
  }  
  while(response != 6);

  remove_all(&head);

  return 0;
}
