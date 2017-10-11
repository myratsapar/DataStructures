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
	printf("\n");
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
		
		while (currentStudent -> next != root)
			currentStudent = currentStudent -> next;
			currentStudent -> next = newStudent;
			return newStudent; 
	}

		
		student *currentStudent = root; //araya ekleme
		
		while(currentStudent -> next != root && currentStudent -> next -> id < id){
			currentStudent = currentStudent -> next;
		}
			student *newStudent = (struct student*)malloc(sizeof(struct student));
			newStudent -> next = currentStudent -> next;
			currentStudent -> next = newStudent;
			newStudent -> id = id;
			newStudent -> name = name;
			return root;
}
int main(){
	student *root = NULL;
	root = insertStudent(root, 133, "Dude");
	root = insertStudent(root, 15, "Jack");
	root = insertStudent(root, 69, "Summer");
	printList(root);
}
