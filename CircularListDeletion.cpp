#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	char *name;
	student *next;
};

typedef struct student Student;

void printList(student *root){
	student *currentStudent = root;
	
	printf ("Student id: %d\n", currentStudent -> id);
	printf ("Student name: %s\n", currentStudent -> name);
	currentStudent = currentStudent -> next;
	
	while (currentStudent != root){
		printf ("Student id: %d\n", currentStudent -> id);
		printf ("Student name: %s\n", currentStudent -> name);
		currentStudent = currentStudent -> next;
	}
	printf ("\n");
}

student *insertStudent(student *root, int id, char *name){
	if (root == NULL){
		root = (struct student*)malloc(sizeof(struct student));
		root -> next = root;
		root -> id = id;
		root -> name = name;
		
		return root;
	}	
	if (id < root -> id){
		student *newStudent = (struct student*)malloc(sizeof(struct student));
		newStudent -> next = root;
		newStudent -> id = id;
		newStudent -> name = name;
		
		student *currentStudent = root;
		
		while(currentStudent -> next != root)
			currentStudent = currentStudent -> next;
			currentStudent -> next = newStudent;
		return newStudent;
	}
	student *currentStudent = root;
	
	while (currentStudent -> next != root && currentStudent -> next -> id < id){
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
	

	if (root -> id == id){
		while(currentStudent -> next != root){
			if (currentStudent -> next -> id == id){
				previousStudent = currentStudent -> next;
				currentStudent -> next = currentStudent -> next -> next;
				free(previousStudent);
				continue;
			}
			currentStudent = currentStudent -> next;
		}
		currentStudent -> next = root -> next;
		free(root);
	return currentStudent -> next; //root diydigi
	}
	
	while (currentStudent -> next != root){
		if (currentStudent -> next -> id == id){
			previousStudent = currentStudent -> next;
			currentStudent -> next = currentStudent -> next -> next;
			free(previousStudent);
		continue;
		}
		currentStudent = currentStudent -> next;
	}
	
	if (currentStudent -> next == root){
		printf ("Unable to find element in Circular Linked List or it is already removed\n");
		return root;		
	}
	
	previousStudent = currentStudent -> next;
	currentStudent -> next = currentStudent -> next -> next;
	free(previousStudent);
	return root;
	
	
}
int main (){
	student *root = NULL;
	root = insertStudent(root, 155, "Jason");
	root = insertStudent(root, 112, "Dude");
	root = insertStudent(root, 155, "Jason");
	root = insertStudent(root, 16, "Tkm");
	
	printList(root);
	root = delStudent(root, 155, "Jason");
	printList(root);
	
}




















