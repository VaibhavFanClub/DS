#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct person{
	int pno, page;
};
typedef struct person p;
int readFile(p *a){
	char fname[15];
	int i = 0;
	printf("Enter file name:- ");
	scanf("%s", fname);
	FILE *fp;
	fp = fopen(fname, "r");
	if(fp == NULL){
		printf("Error opening the file\n");
		exit(0);
	}
	while(!feof(fp)){
		fscanf(fp,"%d %d",&a[i].pno, &a[i].page);
		i++;
	}
	return i-1;
}
void insertionSort(p *a, int n){
	int i, j;
	p current;
	for(i = 1; i < n; i++){
		current = a[i];
		for(j = i-1; a[j].page > current.page && j >= 0; j--){
			a[j+1] = a[j];
		}
		a[j+1] = current;
	}
}
void main(){
	p a[50];
	int n = readFile(a);
	insertionSort(a, n);
	printf("Sorted list is:- \n");
	for(int i = 0; i < n; i++)
		printf("%d %d\n", a[i].pno, a[i].page);
}
