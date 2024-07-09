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

void insertStart(Node** headref, itemInfo newItem) {
    Node* newNode = malloc(sizeof(Node));
    newNode->item = newItem;
    newNode->next = *headref;
    
//    *headref = newNode;
    if (newItem.expYear <= 2024){ // expiration date 2027
    	*headref = newNode;
	}
    
	
}



int main() {
//    Node* dummyHead = malloc(sizeof(Node)); 
	Node* dummyHead = NULL;
//    dummyHead->next = NULL; remove dishit
    
    itemInfo newItem1 = {"apple de ap", 2034};
    insertStart(&dummyHead, newItem1);

    itemInfo newItem2 = {"Banana", 2028};
    insertStart(&dummyHead, newItem2);
    
    itemInfo newItem3 = {"Meat", 2022};
    insertStart(&dummyHead, newItem3);
    
    itemInfo newItem4 = {"Vegetables", 2021};
    insertStart(&dummyHead, newItem4);
    
    itemInfo newItem5 = {"Canned Goods", 2020};
    insertStart(&dummyHead, newItem5);
   
   

    Node* trav = dummyHead;
    while (trav != NULL) {
        printf("Item Name: %s, Expiration Year: %d\n\n", trav->item.itemName, trav->item.expYear);
        trav = trav->next;
    }



    return 0;
}
