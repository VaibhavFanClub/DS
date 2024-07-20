#include<stdio.h>
void main(){
	int arr[10], i, sum = 0;
	printf("Enter 10 elements in an array :- ");
	for(i = 0; i<10; i++){
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	printf("Sum of array elements are :- %d\n", sum);
}


