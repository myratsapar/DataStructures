#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	
	node *left;
	node *right;
};

typedef struct node Node;

node *insert(node *root, int data){
	if (root == NULL){
		root = (struct node*)malloc(sizeof(struct node));
		root -> left = NULL;
		root -> right = NULL;
		root -> data = data;
		return root;
	}
	
	if (root -> data < data){
		root -> right = insert(root -> right, data);
		return root;
	}	
	
	root -> left = insert(root -> left, data);
	return root;
	
}

void traverse(node *root){
	if (root == NULL)
	return;
	
	traverse(root -> left);
	printf("%d ", root -> data);
	traverse(root -> right);
}

int find(node *root, int x){
	if(root == NULL)
	return -1;
	
	if (root -> data == x)
	return 1;	
	
	if(find(root -> right, x) == 1)
	return 1;
	
	if(find(root -> left, x) == 1)
	return 1;
	
	return -1;
}
 
int main(){
	node *root = NULL;
	
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);
	root = insert(root, 80);	
	
	traverse(root);
        printf("\nResult search: %d\n", find(root, 25));
}
