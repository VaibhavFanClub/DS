#include<stdio.h>
#include<stdlib.h>

void display(int a[], int n){
	for(int i = 0; i < n; i++)
		printf("%d ",a[i]);
	printf("\n");
}

void merge(int a[], int mid, int low, int high){
	int i, j, k, b[100];
	i = low;
	j = mid + 1;
	k = low;
	
	while(i <= mid && j <= high){
		if(a[i] < a[j]){
			b[k] = a[i];
			k++;
			i++;
		} else{
			b[k] = a[j];
			k++;
			j++;
		}
	}
	
	while(i <= mid){
		b[k] = a[i];
		k++;
		i++;
	}
	
	while(j <= high){
		b[k] = a[j];
		k++;
		j++;
	}
	
	for(i = low; i <= high; i++)
		a[i] = b[i];
}

void mergeSort(int a[], int low, int high){
	int mid;
	if(low < high){
		mid = (low + high) / 2;
		mergeSort(a, low, mid);
		mergeSort(a, mid + 1, high);
		merge(a, mid, low, high);
	}
}

int main(){
	int n = 5, i;
	printf("Enter the 5 elements:- \n");
	int a[n];
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("Your array:- \n");
	display(a,n);
	mergeSort(a, 0, n - 1);
	printf("Your sorted array:- \n");
	display(a, n);
}