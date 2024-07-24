#include <stdio.h>
#include <stdlib.h>

struct Node {
  char letter;
  struct Node* next;
};

void printLastElement(struct Node* head) {
  if (head == NULL) {
    printf("The list is empty.\n");
    return;
  }

  struct Node* current = head;
  while (current->next != NULL) {
    current = current->next;
  }

  printf("The last element is: %c\n", current->letter);
}

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

  printLastElement(head);

  free(head);
  free(second);
  free(third);

  return 0;
}
