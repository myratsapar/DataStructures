#include <stdio.h>
#include <stdlib.h>

struct node {
	int x;
	node *next;
};

typedef node Node;

void printList(Node*root){
	while(root!=NULL){
		printf("%d\n", root->x);
		root = root -> next;
	}
}

node *sortInsert(node*root, int x){
if (root == NULL){
		root = (node*)malloc(sizeof(node));
		root -> next = NULL;
		root -> x = x;
		return root;
	}
if (root -> x > x){
	node*temp = (node*)malloc(sizeof(node));
	temp -> x = x;
	temp -> next = root;
	return temp; 
	}
node *iter = root;

while(iter -> next != NULL && iter -> next -> x < x ){
	iter = iter -> next;
}	
node *temp = (node*)malloc(sizeof(node));
temp -> next = iter -> next;
iter -> next = temp;
temp -> x = x;
return root;
}

int main(){
	node *root;
	root = NULL;
	root = sortInsert(root, 40);
	root = sortInsert(root, 30);
	root = sortInsert(root, 10);
	root = sortInsert(root, 150);
	root = sortInsert(root, 200);
	root = sortInsert(root, 100);
	printList(root);
	return 0;
}

