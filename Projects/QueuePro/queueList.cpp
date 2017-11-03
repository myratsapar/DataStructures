#include <stdio.h>
#include <stdlib.h>
#include "queueList.h"

void printQueue(student *root){
	if (root == NULL){
		printf("Queue is empty\n");
	}
	printf("Head ");
	while(root != NULL){
		printf("%d ", root -> id);
		root = root -> next;
	}
	printf("Tail\n");
}

student *enque(student *root, int id){
	if (root == NULL){
		root = (struct student*)malloc(sizeof(struct student));
		root -> next = NULL;
		root -> id = id;
		return root;
	}
	
	student *current = root;
	
	while(current -> next != NULL){
		current = current -> next;
	}
	student *QTail = (struct student*)malloc(sizeof(struct student));
	QTail -> next = NULL;
	current -> next = QTail;
	QTail -> id = id;
	return root;
}

student *deque(student *root){
	if (root == NULL){
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






















