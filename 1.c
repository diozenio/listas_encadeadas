#include <stdio.h>
#include <stdlib.h>

struct Node {
  char letter;
  struct Node* next;
};

int main() {
  struct Node* head = (struct Node*)malloc(sizeof(struct Node));
  struct Node* second = (struct Node*)malloc(sizeof(struct Node));
  struct Node* third = (struct Node*)malloc(sizeof(struct Node));

  head->letter = 'a';
  head->next = second;

  second->letter = 'b';
  second->next = third;

  third->letter = 'c';
  third->next = NULL;

  free(head);
  free(second);
  free(third);

  return 0;
}