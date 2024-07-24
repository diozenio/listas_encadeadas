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

void compareLists(struct Node* listA, struct Node* listB) {
  struct Node* currentA = listA;
  struct Node* currentB = listB;

  while (currentA != NULL && currentB != NULL) {
    if (currentA->letter != currentB->letter) {
      printf("Lists are not equal\n");
      return;
    }

    currentA = currentA->next;
    currentB = currentB->next;
  }

  if (currentA != NULL || currentB != NULL) {
    printf("\nLists are not equal\n");
    return;
  }

  printf("\nLists are equal\n");
}

int main() {
  char *str = NULL;
  size_t len = 0;
  ssize_t nread;

  printf("Enter first string: ");
  nread = getline(&str, &len, stdin);

  struct Node* listA = createList(str, nread - 1);

  printf("Enter second string: ");
  nread = getline(&str, &len, stdin);

  struct Node* listB = createList(str, nread - 1);
  
  printf("\n--------------------\n");
  printList(listA);
  printf("\n");
  printList(listB);
  printf("\n--------------------\n");
  
  compareLists(listA, listB);

  free(str);
  return 0;
}