#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}Node;


void insertLast(Node** headRef, int toAdd){
	Node * newNode = malloc(sizeof(Node));
	newNode -> data = toAdd; // toAdd  = 6 refer line 25
	newNode -> next = NULL;
	

	while(*headRef!=NULL){
        headRef= &(*headRef)->next;
	}
    
	*headRef = newNode;
	
//	for (;*headRef!=NULL;headRef= &(*headRef)->next)
	



}


int main(){
	Node*head = NULL;
	Node * newNode = malloc (sizeof(Node));
	newNode -> data = 5;
	newNode -> next = NULL;
	
	head = newNode;
	
	insertLast(&head, 6);
	insertLast(&head, 7);
	insertLast(&head, 8);
	insertLast(&head, 9);
	
	
	Node * trav = head;
	while (trav != NULL){
		printf("%d ", trav->data);
		trav=trav->next;
	}
} 
