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
    printf("\n");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void sortList(Node** headRef) {
    if (*headRef == NULL) {
        return;
    }
    
    Node* current;
    Node* next;
    int temp;
    int swapped;

    do {
        swapped = 0;
        current = *headRef;
        while (current->next != NULL) {
            next = current->next;
            if (current->data > next->data) {
                temp = current->data;
                current->data = next->data;
                next->data = temp;
                swapped = 1;
            }
            current = next;
        }
    } while (swapped);
}

void evenList(Node** headRef) {
    Node* current = *headRef;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data % 2 != 0) { // Odd number
            if (prev == NULL) { // Removing the head
                *headRef = current->next;
                free(current);
                current = *headRef;
            } else { // Removing an intermediate or last node
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else { // Even number
            prev = current;
            current = current->next;
        }
    }
}

// This function can be used to remove all even elements from the list
void oddList(Node** headRef) {
    Node* current = *headRef;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data % 2 == 0) { // Even number
            if (prev == NULL) { // Removing the head
                *headRef = current->next;
                free(current);
                current = *headRef;
            } else { // Removing an intermediate or last node
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else { // Odd number
            prev = current;
            current = current->next;
        }
    }
}

int main() {
    Node* head = NULL;
    int size;
	int i;
    printf("Enter size: ");
    scanf("%d", &size);

    int data[size];
    printf("Enter elements: \n");
    for (i = 0; i < size; i++) {
        scanf("%d", &data[i]);
        appendNode(&head, data[i]);
    }

    printf("Printed List: ");
    printList(head);
    
    sortList(&head);
    printf("Sorted list: ");
    printList(head);
    
    oddList(&head);
    printf("Odd List: ");
    printList(head);
    
    evenList(&head);
    printf("Even List: ");
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
