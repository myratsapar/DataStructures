#include <stdio.h>
#include <stdlib.h>

int *array;
int len = 2;
int head = 0;
int i;

int pop(){
	return array[head--];
}

void push(int item){
	if (head >= len){
		int *array2 = (int*)malloc(sizeof(int)*len*2);
		for(i=0; i<len; i++){								
			array2[i]=array[i];
		}
		free(array);
		array = array2;
		len *= 2;
		printf("Array length: %d\n", len);
	}
	array[head++] = item;
}

void printStack(){
	printf("Tail \n");
	for(i=0; i<head; i++){
		printf("%d\n", array[i]);
	}
	printf("Head\n\n");
}

int main(){
	array = (int*)(malloc(sizeof(int)*2));
	push(10);
	push(5);
	push(61);
	push(69);
	push(55);
	push(96);
	printStack();
	pop();
	pop();
	printf("After popping last in:\n");
	printStack();
	
}


















