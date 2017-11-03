#include <stdio.h>
#include <stdlib.h>
#include "queueList.h"

int main(){
	student *root = NULL;
	printQueue(root); 
	root = enque(root, 10);
	printQueue(root); 
	root = deque(root);
	printQueue(root); 
	root = enque(root, 20);
	root = enque(root, 30);
	root = enque(root, 40);
	root = enque(root, 50);
	root = deque(root);
		
	printQueue(root); 
}
