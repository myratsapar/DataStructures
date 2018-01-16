#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	student *next;
};

typedef struct student Student;

student *root = NULL;

student *push(student *root, int id){
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
	student *head = (struct student*)malloc(sizeof(struct student));
	head -> next = NULL;
	current -> next = head;
	head -> id = id;
	return root;
}

student *pop(student *root){
	student *popped = NULL;
	
	if (root == NULL){
		printf("There is no Stack\n");
		return 0;
	}
	
	if (root -> next == NULL){
		popped = root;
		free(popped);
		return 0;
	}
	
	student *current = root;
	
	while (current -> next -> next != NULL){
		current = current -> next;
	}
	popped = current -> next;
	current -> next = NULL;
	free(popped);
	return root;
}

void printStack(student *root){
	if (root == NULL){
		printf("There is no Stack\n");
	}
	printf("Tail");
	while (root != NULL){
		printf("%d ", root -> id);
		root = root -> next;
	}
	printf("Head\n");
}

int main(){
	student *root = NULL;
	
	root = push(root, 11);
	root = push(root, 13);
	root = push(root, 15);
	root = push(root, 17);
	root = push(root, 19);
	root = push(root, 21);
	
	printStack(root);
	
	root = pop(root);
	root = pop(root);
	
	printStack(root);
}

//15-01-18 22:18
