#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	char *name;
	student *next;
	student *prev;
};

typedef student Student;

void printList(student *root){
	if(root == NULL){
		printf("There is no Doubly Linked List\n");
	}
	while (root != NULL){
		printf("Id: %d\n", root -> id);
		printf("Name: %s\n", root -> name);
		root = root -> next;
	}
	printf("\n");
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
	
	while(current -> next != NULL && current -> next -> id < id){
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

int main(){
	student *root = NULL;
	
	root = insertStudent(root, 155, "Everything is");
	root = insertStudent(root, 100, "Relax");
	root = insertStudent(root, 269, "CTRL");
	root = insertStudent(root, 196, "Under");
	
	printList(root);
}
