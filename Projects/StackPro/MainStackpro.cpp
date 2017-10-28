#include <stdio.h>
#include <stdlib.h>
#include "stackpro.h"

int main(){
	student *root = NULL;
	
	printStack(root);
	root = pushStudent(root, 130, "Lemme");
	root = pushStudent(root, 169, "Drop Everything");
	root = pushStudent(root, 196, "And Work");
	root = pushStudent(root, 341, "On Your Problem" );
	printStack(root);
	popStudent(root);
	printf("\nAfter Popped:\n");
	printStack(root);
}
