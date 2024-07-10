#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;


void appendNode(Node** headRef, int toAdd) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = toAdd;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        Node* current = *headRef;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}


void printList(Node* head) {
    Node* current = head;
    printf("\n\n");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void sortList(){
		//sorts linked list in ascending order from least to greatest values
}
int i;

int main() {
    Node* head = NULL;
    int size;

    printf("Enter size: ");
    scanf("%d", &size);

    int data[size];
    printf("Enter elements: \n");
    for (i = 0; i < size; i++) {
        scanf("%d", &data[i]);
        appendNode(&head, data[i]);
    }

    printList(head);


    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
