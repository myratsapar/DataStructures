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
	student *SHead = (student*)malloc(sizeof(student));
	SHead -> next = NULL;
	current -> next = SHead;
	SHead -> id = id;
	SHead -> name = name;
	return root;
}

int popStudent(student *root){
	if(root == NULL){
		printf ("POP: There is no student in the Stack\n");
		return -1;
	}
	if(root -> next == NULL){
		int rvalue = root -> id;
		free(root);
		return rvalue;
	}
	student *current = root;
	while(current -> next -> next != NULL){
		current = current -> next;
	}
	student *poppedStudent = current -> next;
	current -> next = NULL;
	int rvalue = poppedStudent -> id;
	free(poppedStudent);
	return rvalue;
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
	popStudent(root);
	popStudent(root);
	printf("\nAfter Popped\n");
	printStack(root);
}

