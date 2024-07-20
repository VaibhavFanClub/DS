#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee{
	int eno;
	char ename[15]; 
};
typedef struct employee emp;
int readFile(emp *a){
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
		fscanf(fp,"%d %s",&a[i].eno, a[i].ename);
		i++;
	}
	return i-1;
}
void bubbleSort(emp *a, int n){
	int i, pass;
	emp temp;
	for(pass = 1; pass < n; pass++){
		for(i = 0; i < n - pass; i++){
			if(strcmp(a[i].ename, a[i+1].ename) > 0){
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
			}
		}
	}
}
void main(){
	emp a[50];
	int n = readFile(a);
	bubbleSort(a, n);
	printf("Sorted list is:- \n");
	for(int i = 0; i < n; i++)
		printf("%d %s\n", a[i].eno, a[i].ename);
}
