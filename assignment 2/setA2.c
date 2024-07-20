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

void rarray(int a[], int n){
	srand(time(0));
	for(int i = 0; i < n; i++)
		a[i] = rand() % 10;
}


void main(){
	int n, i;
	printf("Enter the size of array:- ");	
	scanf("%d",&n);
	int a[n];
	rarray(a,n);
	printf("Your random array:- \n");
	display(a, n);
	quicksort(a, 0, n-1);
	printf("Your sorted array:- \n");
	display(a, n);
}
