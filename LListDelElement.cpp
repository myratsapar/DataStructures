#include <stdio.h> 
#include <stdlib.h> 

struct student{
	int id;
	char *name;
	
	student *next;
};

typedef struct student Student;

student *root = NULL;

void printList(student *root){
	if (root == NULL){
		printf ("There is no Linked List\n");
	}
	while (root != NULL){
		printf ("Student id: %d\n", root -> id);
		printf ("Student name: %s\n", root -> name);
		root = root -> next;
		printf ("\n");
	}
}

student *insertStudent(student *root, int id, char *name){
	if (root == NULL){
		root = (struct student*)malloc(sizeof(struct student));
		root -> id = id;
		root -> name = name;
		root -> next = NULL;
		return root;
	}
	if (id < root -> id){
		student *newStudent = (struct student*)malloc(sizeof(struct student));
		newStudent -> id = id;
		newStudent -> name = name;
		newStudent -> next = root;
		return newStudent; 
	}
	
	student *currentStudent = root;
	
	while (currentStudent -> next != NULL && currentStudent -> next -> id < id){
		currentStudent = currentStudent -> next; 
	}
	student *newStudent = (struct student*)malloc(sizeof(struct student));
	newStudent -> next = currentStudent -> next;
	currentStudent -> next = newStudent;
	newStudent -> id = id;
	newStudent -> name = name;
	return root;	
}

student *delStudent(student *root, int id, char *name){
	student *previousStudent = NULL;						 
	student *currentStudent = root;
	
	if (root == NULL){
		printf("There is no element in the Linked List\n");
		return 0;
	}
	if (id == root -> id){
		previousStudent = root;
		root = root -> next;
		free(previousStudent);
		return root;
		}
	while (currentStudent -> next != NULL && currentStudent -> next -> id != id){
		currentStudent = currentStudent -> next;	
	}
		
	if (currentStudent -> next == NULL){
		printf("delStudent: Unable to find element in the Linked List\n");
		return root;
	}
		previousStudent = currentStudent -> next;
		currentStudent -> next = currentStudent -> next -> next;
		free(previousStudent);
		return root;
}


int main(){
	root = insertStudent(root, 112, "Safar");
	root = insertStudent(root, 96, "Dude");
	root = insertStudent(root, 130, "Sigmah");
	root = delStudent(root, 130, "Sigmah");
	printList(root);
}
