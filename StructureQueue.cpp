#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	student *next;
};

typedef struct student Student;

student *enque(student *root, int id){
	if (root == NULL){
		root = (struct student*)malloc(sizeof(struct student));
		root -> next = NULL;
		root -> id = id;
		return root;
	}
	
	student *current = root;
	
	while (current -> next != NULL){
		current = current -> next;
	}
	student *qtail = (struct student*)malloc(sizeof(struct student));
	qtail -> next = NULL;
	current -> next = qtail;
	qtail -> id = id;
	return root;
}

student *deque(student *root){
	if(root == NULL){
		printf("Queue is empty\n");
		return 0;
	}
	else{
		student *deq = root;
		root = root -> next;
		free(deq);
		return root;
	}
}

void printQueue(student *root){
	if (root == NULL){
		printf("Queue is empty\n");
	}
	printf("Head ");
	while (root != NULL){
		printf("%d ", root -> id);
		root = root -> next;
	}
	printf("Tail\n");	
}

int main(){
	student *root = NULL;
	
	root = enque(root, 11);
	root = enque(root, 13);
	root = enque(root, 15);
	root = enque(root, 17);
	root = enque(root, 19);
	root = enque(root, 21);
	
	printQueue(root);
	
	root = deque(root);
	root = deque(root);
	
	printQueue(root);
}

//15-01-18 21:48
