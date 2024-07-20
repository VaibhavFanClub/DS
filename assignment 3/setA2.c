#include<stdio.h>
void main(){
	int arr[10] = {1,5,7,12,13,16,17,22,24}, i, num, start=0, flag=0, end=8, mid;
	printf("Array elements are:- \n");
	for(i=0; i<9; i++){
		printf("%d ", arr[i]);
	}
	mid = (start + end)/2;
	printf("\nEnter number to be searched:- ");
	scanf("%d", &num);
	while(start <= end){
		if(arr[mid] == num){
			flag = 1;
			printf("Element found at %d position", mid+1);
			break;
		}else if(num < arr[mid]){
			end = mid - 1;
			mid = (start + end)/2;
		}else{
			start = mid + 1;
			mid = (start + end)/2;
		}
	}
	printf("%s \n",(!flag)?"Element not found":"");
}
