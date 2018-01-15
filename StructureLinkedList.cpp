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
		printf("There is no Linked List\n");
	}
	while (root != NULL){
		printf("Student id: %d\n", root -> id);
		printf("Student name: %s\n", root -> name);
		root = root -> next;
		printf("\n");
	}
}

student *insertion(student *root, int id, char *name){
	if (root == NULL){
		root = (struct student*)malloc(sizeof(struct student));
		root -> id = id;
		root -> name = name;
		root -> next = NULL;
		return root;
	}
	if (id < root -> id){
		student *newstudent = (struct student*)malloc(sizeof(struct student));
		newstudent -> id = id;
		newstudent -> name = name;
		newstudent -> next = root;
		return newstudent;
	}
	
	student *current = root;
	
	while(current -> next != NULL && current -> next -> id < id){
		current = current -> next;
	}
	
	student *newstudent = (struct student*)malloc(sizeof(struct student));
	newstudent -> next = current -> next;
	current -> next = newstudent;
	newstudent -> id = id;
	newstudent -> name = name;
	return root;	
}

student *deletion(student *root, int id, char *name){
	student *del = NULL;
		
	if (root == NULL){
		printf("There is no LInked List");
		return 0;
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
	
	if (current -> next == NULL){
		printf("Unable to find an item");
		return root;
	}
	del = current -> next;
	current -> next = current -> next -> next;
	free(del);
	return root;
}

int main(){
	root = insertion(root, 3, "Ashgabad");
	root = insertion(root, 5, "Akhal");
	root = insertion(root, 9, "Balkan");
	root = insertion(root, 6, "Dashoguz");
	root = insertion(root, 11, "Lebap");
	root = insertion(root, 8, "Mary");
	root = deletion(root, 3, "Ashgabad");
	printList(root);
}
//13-01-18 4:34 PM
