#include<stdio.h>
void main(){
	int i, pass, temp, arr[5] = {10,20,35,23,12};
	printf("Elements of array are:- \n");
	for(i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");
	for(pass = 1; pass < 5; pass++){
		for(i = 0; i < 5 - pass; i++){
			if(arr[i] > arr[i+1]){
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
	printf("Sorted array is:- \n");
	for(i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
