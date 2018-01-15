#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	char *name;
	
	student *prev;
	student *next;
};

void printList(student *root){
	if (root == NULL){
		printf("There is no Doubly Linked List");
	}
	while (root != NULL){
		printf("Student id: %d\n", root -> id);
		printf("Student name: %s\n", root -> name);
		root = root -> next;
	}
	printf("\n");
}

student *insertion(student *root, int id, char *name){
	if (root == NULL){
		root = (struct student*)malloc(sizeof(struct student));
		root -> id = id;
		root -> name = name;
		root -> prev = NULL;
		root -> next = NULL;
		return root;
	}
	if (id < root -> id){
		student *newstudent = (struct student*)malloc(sizeof(struct student));
		newstudent -> id = id;
		newstudent -> name = name;
		newstudent -> next = root;
		root -> prev = newstudent;
		return newstudent;
	}
	
	student *current = root;
	
	while (current -> next != NULL && current -> next -> id < id){
		current = current -> next;
	}
	
	student *newstudent = (struct student*)malloc(sizeof(struct student));
	newstudent -> next = current -> next;
	newstudent -> prev = current;
	current -> next = newstudent;
	
	if (newstudent -> next != NULL)		
	newstudent -> next -> prev = newstudent;
	newstudent -> id = id;
	newstudent -> name = name;
	
	return root;
}

student *deletion(student *root, int id, char *name){
	student *del = NULL;
	
	if (root == NULL){
		printf("There is no Doubly Linked List");
	}
	
	if (root -> id == id){
		del = root;
		root = root -> next;
		free(del);
		return root;
	}
	
	student *current = root;
	
	while (current -> next != NULL && current -> next -> id != id){
		current = current -> next;
	}
	del = current -> next;
	current -> next = current -> next -> next;
	free(del);
	
	if(current -> next != NULL)
	current -> next -> prev = current;
	
	return root;
}

int main(){
	student *root = NULL;
	root = insertion(root, 69, "Turkmenbashi");
	root = insertion(root, 55, "Khazar");
	root = insertion(root, 11, "Balkanabad");
	root = insertion(root, 91, "Yangadzha");
	root = insertion(root, 15, "Bekdash");
	root = deletion(root, 11, "Balkanabad");
	printList(root);
}
//13-01-18 6:18 PM
