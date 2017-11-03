#include <stdio.h>
#include <stdlib.h>
#include "stacknew.h"

student *pushStack(student *root, int id){
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
	student *STail = (struct student*)malloc(sizeof(struct student));
	STail -> next = NULL;
	current -> next = STail;
	STail -> id = id;
	return root;
}

student *popStack(student *root){
	student *popped = NULL;
	
	if (root == NULL){
		printf("POP: Stack is empty\n");
		return 0;
	}
	if (root -> next == NULL){
		popped = root;
		free(popped);
		return 0;
	}
	
	student *current = root;
	
	while(current -> next -> next != NULL){
		current = current -> next;
	}
	popped = current -> next;
	current -> next = NULL;
	free(popped);
	return root;	
}

void printStack(student*root){
	if (root == NULL){
		printf("Print: Stack is empty\n");
	}
	printf("Head ");
	while (root != NULL){
		printf("%d ", root -> id);
		root = root -> next;
	}
	printf("Tail\n");
}





















