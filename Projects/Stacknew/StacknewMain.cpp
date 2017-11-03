#include <stdio.h>
#include <stdlib.h>
#include "stacknew.h"

int main(){
	student *root = NULL;
	
	printStack(root);
	root = pushStack(root, 136);
	root = popStack(root);
	printStack(root);
	root = popStack(root);
	root = pushStack(root, 911);
	root = pushStack(root, 169);
	root = pushStack(root, 119);
	root = pushStack(root, 32);
	root = pushStack(root, 14);
	root = pushStack(root, 196);
	printStack(root);
	root = popStack(root);
	printStack(root);
	root = pushStack(root, 200);
	printStack(root);
	root = popStack(root);
	root = popStack(root);
	root = popStack(root);
	printStack(root);
	root = pushStack(root, 34);
	printStack(root);
}
