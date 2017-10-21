#include <stdio.h>

int array[5];
int len = 5;
int head = 0;
int i;

int pop(){
	printf("After popping last in\n");
	return array[head--];
}

int push(int item){
	array[head++] = item;
}

void printArray(){
	printf ("Tail\n");
	for(i=0; i<head; i++){
		printf("%d\n", array[i]);
	}
	printf ("Head\n\n");
}
int main(){
	push(10);
	push(20);
	push(35);
	push(45);
	push(50);
	printArray();
	pop();
	printArray();
}
