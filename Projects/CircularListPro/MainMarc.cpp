#include <stdio.h>
#include <stdlib.h>
#include "marc.h"

int main(){
	student *root = NULL;
	root = insertStudent(root, 155, "Jason");
	root = insertStudent(root, 112, "Dude");
	root = insertStudent(root, 155, "Jason");
	root = insertStudent(root, 16, "Tkm");
	
	printList(root);
	root = delStudent(root, 155, "Jason");
	printList(root);
}
