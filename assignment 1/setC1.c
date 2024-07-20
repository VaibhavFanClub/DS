#include<stdio.h>
void main(){
	int n, i, pass, temp;
	printf("Enter how many elements:- ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter elements of array:- \n");
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for(pass = 1; pass < n; pass++){
		for(i = 0; i < n - pass; i++){
			if(arr[i] > arr[i+1]){
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
	printf("Sorted array is:- \n");
	for(i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
