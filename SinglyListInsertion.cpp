#include <stdio.h>
#include <stdlib.h>



struct student{
	int id;
	char *name;
	
	student *next;
};

typedef struct student Student;

Student *root = NULL;


void printList(student *root){
	while (root != NULL){
		printf ("Student id:	%d\n", root -> id);
		printf ("Student name:	%s\n", root -> name);
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
	if ( id < root -> id){ 
		student *newStudent = (struct student*)malloc(sizeof(struct student)); 
		newStudent -> id = id;
		newStudent -> name = name;
		newStudent -> next = root;
		return newStudent;
	}
	
	student *iter = root;
	while(iter -> next != NULL && iter -> next -> id < id){
		iter = iter -> next;
	}
	student *newStudent = (struct student*)malloc(sizeof(struct student));
	newStudent -> next = iter -> next;
	iter -> next = newStudent;
	newStudent -> id = id;
	newStudent -> name = name;
	return root;	
}
int main(){
	root = insertStudent(root, 130, "Mu");
	root = insertStudent(root, 112, "Dude");
	root = insertStudent(root, 110, "Monica");
	root = insertStudent(root, 169, "Nadia");
	root = insertStudent(root, 96, "Sigmah");
	root = insertStudent(root, 110, "Anna");
	printList(root);
}
