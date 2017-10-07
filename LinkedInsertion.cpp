#include <stdio.h>
#include <stdlib.h>

struct node{ 
	int x;   
	node *next; 
};

typedef node Node; 

void printList(Node*root){
while (root != NULL){
	printf("%d\n", root -> x);
	root = root -> next;}	
}

void add(Node *root, int x){
	while(root -> next != NULL){
		root = root -> next;
		}
		root -> next = (node*)malloc(sizeof(node));
		root -> next -> x = x;
		root -> next -> next = NULL;
}
// We travel not to escape life, but for life not to escape us
int main(){
	Node *root; 
	root = (Node*)malloc(sizeof(Node)); 
	root -> next = NULL;
	root -> x = 100;	
	int i;
	
for(i = 0; i < 10; i++){
	add(root, i*10);
}
					
Node *iter = root;
		
for (i=0; i<5; i++)
iter = iter -> next;
node*temp=(node*)malloc(sizeof(node));
temp -> next = iter -> next;
iter -> next = temp;
temp -> x = 555;
printList(root);
return 0;
}

