#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char itemName[30];
    int expYear; // expiration year when item will expire
} itemInfo;

typedef struct node {
    itemInfo item;
    struct node *next;
} Node;

void insertStart(Node** headRef, itemInfo newItem) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Failed to allocate memory for new node.\n");
        exit(1);
    }
    newNode->item = newItem; // Ensure newItem is properly initialized
    newNode->next = *headRef;
    *headRef = newNode;
}

void displayList(const Node* head) {
    const Node* temp = head;
    while (temp != NULL) {
        printf("Item Name: %s, Expiration Year: %d\n", temp->item.itemName, temp->item.expYear);
        temp = temp->next;
    }
}

int main() {
    Node* dummyHead = malloc(sizeof(Node));
    if (!dummyHead) {
        fprintf(stderr, "Failed to allocate memory for dummyHead.\n");
        exit(1);
    }
    dummyHead->next = NULL; // Initialize the next pointer of dummyHead to NULL
    
    itemInfo newItem1 = {"Apple", 2025};
    insertStart(&dummyHead, newItem1);

    itemInfo newItem2 = {"Banana", 2026};
    insertStart(&dummyHead, newItem2);

    // Assuming the issue was with newItem2, let's explicitly set it to avoid any uninitialized values


    insertStart(&dummyHead, newItem2);

    displayList(dummyHead->next); 

    // Free memory correctly
    Node* current = dummyHead->next;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(dummyHead); // Free the dummyHead itself

    return 0;
}
