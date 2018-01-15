#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	char *name;
	
	student *next;
};

typedef struct student Student;

void printList(student *root){
	student *current = root;
	
	printf("Student id: %d Student name: %s\n", current -> id, current -> name);
	current = current -> next;
	
	while (current != root){
		printf("Student id: %d Studen name: %s\n", current -> id, current -> name);
	
		current = current -> next;
	}
	printf("\n");
}

student *insertion(student *root, int id, char *name){
	if (root == NULL){
		root = (struct student*)malloc(sizeof(struct student));
		root -> id = id;
		root -> name = name;
		root -> next = root;
		return root;
	}
	
	if (id < root -> id){
		student *newstudent = (struct student*)malloc(sizeof(struct student));
		newstudent -> next = root;
		newstudent -> id = id;
		newstudent -> name = name;
		
		student *current = root;
		
		while (current -> next != root)
		current = current -> next;
		current -> next = newstudent;
		return newstudent;
	}
	
	student *current = root;
	
	while (current -> next != root && current -> next -> id < id){
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
	student *current = root;
	
	if (id == root -> id){
		while(current -> next != root){
			if (current -> next -> id == id){
				del = current -> next;
				current -> next = current -> next -> next;
				free(del);
				continue;
			}
			current = current -> next;
			
		}
		current -> next = root -> next;
		free(root);
		return current -> next;
	}
	while (current -> next != root){
		if (current -> next -> id == id){
			del =  current -> next;
			current -> next = current -> next -> next;
			free(del);
			continue;
		}
		current = current -> next;
	}
	if (current -> next == root){
		printf("Unable to find an item");
		return root;
	}
	del = current -> next;
	current -> next = current -> next -> next;
	free(del);
	return root;
}

int main(){
	student *root = NULL;
	root = insertion(root, 13, "Seydi");
	root = insertion(root, 17, "Turkmenabad");
	root = insertion(root, 15, "Karabekewul");
	root = insertion(root, 19, "Sayat");
	root = insertion(root, 11, "Khalach");
	root = insertion(root, 23, "Farab");
	root = deletion(root, 11, "Khalach");
	printList(root);
}
//15-01-18 19:31
