#include <stdio.h>
#include <stdlib.h>

struct Node {
  char letter;
  struct Node* next;
};

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%c -> ", current->letter);
        current = current->next;
    }

    printf("NULL");
}

void freeList(struct Node* head) {
  struct Node* current = head;
  struct Node* nextNode;
  while (current != NULL) {
    nextNode = current->next;
    free(current);
    current = nextNode;
  }
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

  printList(head);

  freeList(head);
  return 0;
}