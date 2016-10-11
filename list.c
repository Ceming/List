#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next; };

int print_list(struct node *list){
  printf("%d", list -> i);
  while (list -> next){
    list = list -> next;
    printf(", %d", list -> i);
  }
  printf("\n");
  return 0;
}

struct node * insert_front(int new, struct node *list){
  struct node *newList = (struct node *)malloc(sizeof(struct node));
  newList -> i = new;
  newList -> next = list;
  return newList;
}

struct node * free_list(struct node *list){
  struct node *head, *count;
  head = count = list;
  list -> next = NULL;
  list -> i = NULL;
  free(list);
  while (list -> next){
    count = list -> next;
    list -> next = NULL;
    list -> i = NULL;
    free(list);
    list = count;
  }
  return head;
}

int main(){
  struct node *list = (struct node *) malloc(sizeof(struct node));
  list -> i = 7;
  list -> next = NULL;

  printf("list:");
  print_list(list);

  list = insert_front(10, list);
  printf("\nlist after inserting 10 in the front:");
  print_list(list);

  list = insert_front(-10, list);
  printf("\nlist after inserting -10 in the front:");
  print_list(list);

  list = free_list(list);
  printf("\nlist after freeing the entire list:");
  print_list(list);

  list == (struct node *) malloc(sizeof(struct node));
  list = insert_front(20, list);

  printf("\nlist after malloc and inserting 20 in the front:");
  print_list(list);

  list == (struct node *) malloc(sizeof(struct node));
  list = insert_front(40, list);

  printf("\nlist after malloc and inserting 40 in the front:");
  print_list(list);
  
  list = free_list(list);
  printf("\nlist after freeing the entire list:");
  print_list(list);
  
  return 0;
}


