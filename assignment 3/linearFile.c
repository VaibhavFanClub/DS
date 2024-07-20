#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct cities{
	int code;
	char city[20];
};
typedef struct cities ct;

int readFile(ct a[100],char fileName[20]){
	int i=0;
	FILE *fp;
	fp = fopen(fileName,"r");
	if(fp == NULL){
		printf("Error opening file\n");
		exit(0);
	}
	printf("Contents of file are:- \n");
	while(!feof(fp)){
		fscanf(fp,"%d %s",&a[i].code,a[i].city);
		if (a[i].code != 16){ 
			printf("%d %s\n",a[i].code, a[i].city);
		}
		i++;
	}
	return i-1;
}

void linearSearch(ct a[100], char city[20], int n){
	int i;
	for(i=0; i<n; i++){
		if(strcmp(a[i].city,city) == 0){
			printf("%s found at %d position and the code is %d",city, i+1, a[i].code);
			break;
		}
	}
	printf("%s \n",(i == n)?"City not found":"");
}

void main()
{
	char fileName[20], city[20];
	ct a[100];
	int n;
	printf("Enter file name:- ");
	scanf("%s",fileName);
	n = readFile(a,fileName);
	printf("Enter city to be searched:- ");
	scanf("%s",city);
	linearSearch(a,city,n);
}
