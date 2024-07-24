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

    printf("NULL\n");
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

  for (int i = 1; i < strLen; i++) {
    current->next = createNode(str[i]);
    current = current->next;
  }

  current->next = NULL;
  
  return head;
}

struct Node* removeCharacter(struct Node* head, char letter) {
  struct Node* current = head;
  struct Node* prev = NULL;

  while (current != NULL) {
    if (current->letter == letter) {
      if (prev == NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        current = head;
      } else {
        prev->next = current->next;
        free(current);
        current = prev->next;
      }
    } else {
      prev = current;
      current = current->next;
    }
  }

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

  char removeChar;
  printf("Enter character to remove: ");
  scanf(" %c", &removeChar);

  head = removeCharacter(head, removeChar);

  printList(head);

  free(str);
  return 0;
}
