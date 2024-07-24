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
    return head;
}

struct Node* mergeLists(struct Node* listA, struct Node* listB) {
    struct Node* currentA = listA;
    while (currentA->next != NULL) {
        currentA = currentA->next;
    }

    currentA->next = listB;
    return listA;
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
    printf("--------------------\n");
    
    struct Node* mergedList = mergeLists(listA, listB);
    printList(mergedList);
    printf("--------------------\n");

    free(str);
    return 0;
}
