#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	char *name;
	
	student *next;
	student *prev;
};

void printList(student *root){
	if (root == NULL){
		printf("There is no Doubly Linked List\n");
	}
	while (root != NULL){
		printf ("Id: %d\n", root -> id);
		printf ("Name: %s\n", root -> name);
		root = root -> next;
	}
	printf ("\n");
}

student *insertStudent(student *root, int id, char *name){
	if (root == NULL){
		root = (struct student*)malloc(sizeof(struct student));
		root -> next = NULL;
		root -> prev = NULL;
		root -> id = id;
		root -> name = name;
		return root;
	}
	if (id < root -> id){
		student *newStudent = (struct student*)malloc(sizeof(struct student));
		newStudent -> next = root;
		root -> prev = newStudent;
		newStudent -> id = id;
		newStudent -> name = name;
		return newStudent;
	}
	
	student *current = root;
	
	while (current -> next != NULL && current -> next -> id < id){
		current = current -> next;
	}
	student *newStudent = (struct student*)malloc(sizeof(struct student));
	newStudent -> next = current -> next;
	current -> next = newStudent;
	newStudent -> prev = current;
	
	if (newStudent -> next != NULL)		
	newStudent -> next -> prev = newStudent;
	newStudent -> id = id;
	newStudent -> name = name;
	return root;	
}

student *delStudent(student *root, int id, char *name){
	student *temp = NULL;
	student *current = root;
	if (id == root -> id){
		temp = root;
		root = root -> next;
		free(temp);
		return root;
	}
	while (current -> next != NULL && current -> next -> id !=id){
		current = current -> next;
	}
	if (current -> next == NULL){
		printf("Deletion: Unable to find\n");
	return root;
	}
	temp = current -> next;
	current -> next = current -> next -> next;
	free (temp);
	if(current -> next !=NULL)
	current -> next -> prev;
	return root;	
}

int main(){
	student *root = NULL;
	
	printList(root);
	root = insertStudent(root, 69, "Double");
	root = insertStudent(root, 55, "Lemme");
	root = insertStudent(root, 112, "Click");
	root = insertStudent(root, 911, "Mouth");
	root = insertStudent(root, 155, "Your");
	printList(root);
	root = delStudent(root, 911, "Mouth");
	printList(root);
}
