#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct n{
	int x;
	n* next;
};

typedef n node;

int main(){
	node *root;
	root = (node*)malloc(sizeof(node));
	root -> x = 10;
	root -> next = (node*)malloc(sizeof(node));
	root -> next -> x = 20;
	root -> next -> next = (node*)malloc(sizeof(node));
	root -> next -> next -> x = 30;
	printf("root: %d\n", root -> x );
	printf("root -> next: %d\n", root -> next -> x);
	printf("root -> next -> next: %d\n", root -> next -> next -> x);
	root -> next -> next -> next = NULL;
	node *iter;
	iter = root;
	int i = 0;
	while (iter != NULL){
		i++;
		printf("%d. element is: %d\n", i, iter->x*10);
		iter = iter -> next;
		
	}
	
	getch();
	return 0; 
}


