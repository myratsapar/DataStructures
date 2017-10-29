#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	struct student *next;
};

typedef struct student Student;



student *enque(student *root, int id){
	if(root == NULL){						
	root = (struct student*)malloc(sizeof(struct student));					
	root -> next = NULL;
	root -> id = id;
	return root;
	}
	
	student *current = root;
	
	while(current -> next != NULL){
		current = current -> next;
	}
	student *QHead = (struct student*)malloc(sizeof(struct student));
	QHead -> next = NULL;
	current -> next = QHead;
	QHead -> id = id;
	return root;
	
}

void printQueue(student *root){
	if(root == NULL){
		printf("Queue is empty\n");
	}
	printf("Head ");
	while(root != NULL){
		printf("%d ", root -> id);
		root = root -> next;
	}
	printf("Tail");
}

int main(){
	student *root = NULL;
	
	root = enque(root, 100);
	root = enque(root, 200);
	root = enque(root, -100);
	root = enque(root, 500);
	
	printQueue(root);
}
