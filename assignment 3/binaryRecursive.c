#include<stdio.h>

int binarySearch(int arr[], int low, int high, int key){
	if(high >= low){
		int mid = (low + high)/2;
		if(arr[mid] == key)
			return mid;

		if(key < arr[mid])
			return binarySearch(arr, low, mid - 1, key);

		return binarySearch(arr, mid + 1, high, key);
	}
	return -1;
}

void main(){
	int n, key, i, result;
	printf("Enter number of elements:- ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d elements in sorted form:- \n",n);
	for(i=0; i<n; i++)
		scanf("%d",&arr[i]);

	printf("Enter the value to be searched:- ");
	scanf("%d",&key);

	result = binarySearch(arr, 0, n-1, key);

	if(result != -1)
		printf("Element %d is present at index %d\n",key, result);
	else
		printf("Element %d is not present in the array\n",key);
}
