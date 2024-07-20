#include<stdio.h>
#include<stdlib.h>

void main(){
	int arr[7] = {11,5,45,26,12,34,19}, i, n = 26, flag = 0;
	printf("Array elements are:- \n");
	for(i=0; i<7; i++){
		printf("%d ", arr[i]);
	}
	for(i=0; i<7; i++){
		if(arr[i] == n){
			flag = 1;
			printf("\nElement found at %d position\n", i+1);
			break;
		}
	}
	if(!flag)
		printf("\nElement not found\n");
}
