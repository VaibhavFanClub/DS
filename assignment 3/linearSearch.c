#include<stdio.h>
void main(){
	int arr[10], i, n, flag = 0;
	printf("Enter 10 elements in array:- \n");
	for(i=0; i<10; i++)
		scanf("%d",&arr[i]);
	printf("Enter element to be searched:- ");
	scanf("%d",&n);
	for(i=0; i<10; i++){
		if(arr[i] == n){
			flag = 1;
			printf("Element found at %d position\n", i+1);
			break;
		}
	}
	if(!flag)
		printf("Element not found\n");
}
