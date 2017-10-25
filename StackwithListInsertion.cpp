#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	char *name;
	struct student *next;
};

typedef struct student Student;

student *root = NULL;

student *pushStudent(student *root, int id, char *name){
	if(root == NULL){
		root = (struct student*)malloc(sizeof(Student));
		root -> next = NULL;
		root -> id = id;
		root -> name = name;
		return root;
	}
	
	student *current = root;
	
	while (current -> next != NULL){
		current = current -> next;
	}
	student *newStudent = (student*)malloc(sizeof(student));
	newStudent -> next = NULL;
	current -> next = newStudent;
	newStudent -> id = id;
	newStudent -> name = name;
	return root;
}

void printStack(student *root){
	if(root == NULL){
		printf("There is no student in the Stack\n");
	}
	while(root != NULL){
		printf ("iD: %d\nName: %s\n", root -> id, root -> name);
		root = root -> next;
	}
}

int main(){
	
	printStack(root);
	root = pushStudent(root, 130, "Lemme");
	root = pushStudent(root, 169, "Drop Everything");
	root = pushStudent(root, 196, "And Work");
	root = pushStudent(root, 341, "On Your Problem" );
	printStack(root);
}
