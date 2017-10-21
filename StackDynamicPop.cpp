#include <stdio.h>
#include <stdlib.h>

int *array;
int len = 2;
int head = 0;
int i;

int pop(){
	if (head <= len/4){
		int *array2 = (int*)malloc(sizeof(int)*len/2);
		for (i=0; i<head; i++){
			array2[i] = array[i];
		}
		free(array);
		array = array2;
		len = len/2;
	}
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
		len = len * 2;
	}
	array[head++] = item;
}

void printStack(){
	printf("Stack length: %d\n", len);
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
	push(100);
	printStack();
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
	printf("After popping last in:\n");
	printStack();
	push(34);
	push(12);
	push(32);
	push(50);
	push(56);
	printStack();
}
