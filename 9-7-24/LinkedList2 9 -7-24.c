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

Node* createDummyHead() {
    return (Node*) malloc(sizeof(Node));
}

void insertAtBeginning(Node** headRef, const itemInfo newItem) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->item = newItem;
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
    Node* dummyHead = createDummyHead();
    
    // Example usage
    itemInfo newItem1 = {"Apple", 2025};
    insertAtBeginning(&dummyHead, newItem1);

    itemInfo newItem2 = {"Banana", 2026};
    insertAtBeginning(&dummyHead, newItem2);

    displayList(dummyHead->next); // Skip the dummy head

    // Free memory
    Node* current = dummyHead->next;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(dummyHead);

    return 0;
}
