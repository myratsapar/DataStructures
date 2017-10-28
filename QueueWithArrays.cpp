#include <stdio.h>
#include <stdlib.h>

int *arr = NULL;
int qtail = 0, qhead = 0, length = 2;

int dequeue(){
	if(qtail==qhead){
		printf("Queue empty\n");
		return -1;
	}
	
return arr[qhead++];
}

void enqueue(int a){
	if(arr == NULL){
		arr = (int*)malloc(sizeof(int)*length);
	}
	if(qtail>=length){
		length*=2;
		int *arr2 = (int*)malloc(sizeof(int)*length);
		for(int i=0; i<length/2; i++){
			arr2[i]=arr[i];
			free(arr);
			arr=arr2;
		}
	}
	arr[qtail++]=a;
} 

int main(){
	printf("Array items: ");
	for(int i=0; i<7; i++){
		enqueue(i*10);
		printf("%d ", arr[i]);
	}
	
	printf("\nLength: %d\nqtail: %d\nqhead: %d\n", length, qtail, qhead);

	for(int i=0; i<5; i++){
		dequeue();
	}
	printf("Array items after dequeue: ");
	for(int i=0; i<7; i++){
		printf("%d ", arr[i]);
	}
	printf("\nLength: %d\nqtail: %d\nqhead: %d\n", length, qtail, qhead);
}


