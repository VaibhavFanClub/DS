#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void display(int a[], int n){
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int partition(int a[], int down, int up){
	int pivot = a[down], j = up, i = down + 1, temp;
	do {
		while(a[i] < pivot)
			i++;
		while(a[j] > pivot)
			j--;
		if(i < j){
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	while(i < j);
	temp = a[down];
	a[down] = a[j];
	a[j] = temp;
	
	return j;
}

void quicksort(int a[], int down, int up){
	int pi;
	if(down < up){
		pi = partition(a, down, up);
		quicksort(a, down, pi-1);
		quicksort(a, pi+1, up);
	}
}

void main(){
	clock_t start_time = clock();
	int n = 5, i;
	printf("Enter the 5 elements:- \n");
	int a[n];
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("Your array:- \n");
	display(a, n);
	quicksort(a, 0, n-1);
	printf("Your sorted array:- \n");
	display(a, n);
	clock_t end_time = clock();
	double time_taken = ((double) end_time - start_time) / CLOCKS_PER_SEC;
	printf("Time taken to execute program: %f seconds\n", time_taken);
}
