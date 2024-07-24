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

struct Node* createNode(char letter) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->letter = letter;
  newNode->next = NULL;
  return newNode;
}

struct Node* createList(char *str, int strLen) {
  struct Node* head = createNode(str[0]);

  struct Node* current = head;

  for (int i = 0; i < strLen; i++) {
    current->letter = str[i];
    if (i < strLen - 1) {
      current->next = createNode(str[i + 1]);
      current = current->next;
    }
  }

  current->next = NULL;
  
  return head;
}

int main() {
  char *str = NULL;
  size_t len = 0;
  ssize_t nread;

  printf("Enter a string: ");
  nread = getline(&str, &len, stdin);

  struct Node* head = createList(str, nread - 1);
  
  printList(head);

  free(str);
  return 0;
}