#include<stdio.h>
void main()
{
	int i, j, current, n;
	printf("Enter how many elements:- ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter elements of array:- \n");
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for(i = 1; i < n; i++){
		current = arr[i];
		for(j = i-1; arr[j] > current && j >= 0; j--){
			arr[j+1] = arr[j];
		}
		arr[j+1] = current;
	}
	printf("Sorted array is:- \n");
	for(i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

