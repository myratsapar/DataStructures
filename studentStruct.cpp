#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 		

struct student{
	int id;
	char *name;
	char *surname;
	char *githubAddress;
	
	
	student *nextStudent;
};
typedef struct student Student;

int main(){
	Student *root;
	
	root = (struct student*)malloc(sizeof(struct student)); 
	root -> id = 130;
	root -> name = "Sigmah";
	root -> surname = "Mu";
	root -> githubAddress = "github.com/myratsapar";
	

	printf ("Student id: %d\n", root -> id);
	printf ("Student name: %s\n", root -> name);
	printf ("Student surname: %s\n", root -> surname);
	printf ("Student githubAddress: %s\n", root -> githubAddress);
	
	return 0;
}
