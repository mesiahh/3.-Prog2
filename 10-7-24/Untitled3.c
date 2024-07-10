#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
} Node;


void linkedList(Node** headRef, int toAdd){ // Node** headRef because head is already a pointer in which the adress of head (&head) is passed in main 
	Node* newNode = malloc(sizeof(Node));
	newNode -> data = toAdd;
	newNode -> next = NULL;

	if (*headRef == NULL){
		*headRef = newNode;
	} else {
		Node* current = *headRef;
		while(current->next != NULL){
			current = current->next;
		}
		current->next = newNode;
	}
}


void printList(Node* head){
	Node * current = head;
	printf("\n");
	while (current != NULL){
		printf("%d ", current->data);
		current = current -> next;
	}
	printf("\n");
}

void sortList(Node** headRef){
	if (*headRef == NULL){
		return;
	}
	Node* current;
	Node* next;
	int temp;
	int swap;
	
	do{
		swap = 0;
		current = *headRef;
		while (current->next != NULL){
			next = current -> next;
			if (current -> data > next->data){
				temp = current ->data;
				current->data = next->data;
				next->data = temp;
				swap = 1;
			}
			current = next;
		}
	} while (swap);
}



void evenList(Node** headRef){
	Node* current = *headRef;
	Node* prev = NULL;
	
	while (current != NULL){
		if (current -> data % 2 != 0){
			if (prev == NULL){
				*headRef = current -> next;
				free(current);
				current = *headRef;
			} else{
				prev->next = current -> next;
				free(current);
				current = prev -> next;
			}
		} else{
			prev = current;
			current = current -> next;
		}
	}
}


void oddList(Node** headRef){
	Node* current = *headRef;
	Node* prev = NULL;
	
	while (current != NULL){
		if (current -> data % 2 == 0){
			if (prev == NULL){
				*headRef = current -> next;
				free(current);
				current = *headRef;
			} else{
				prev->next = current -> next;
				free(current);
				current = prev -> next;
			}
		} else{
			prev = current;
			current = current -> next;
		}
	}
}



 



int main(){
	Node* head = NULL;
	int size, i;
	printf("Enter size: ");
	scanf("%d", &size);
	
	int data[size];
	printf("Enter elements: \n");
	for (i = 0; i < size; i++){
		scanf("%d", &data[i]);
		linkedList(&head, data[i]);
	}
	
	
	printf("Linked List: ");
	printList(head);
	
	sortList(&head);
	printf("Sorted List: ");
	printList(head);
	
	evenList(&head);
	printf("List of Even: ");
	printList(head);
	
	oddList(&head);
	printf("List of Odd: ");
	printList(head);
}








