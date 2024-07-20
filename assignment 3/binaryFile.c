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

void binarySearch(ct a[100], char city[20], int n){
	int i,start=0,mid,end,flag=0;
	end = n-1;
	mid = (start + end)/2;
	while(!(start > end)){
		printf(" %d %d %d\n",start,mid,end);
		if(strcmp(a[mid].city,city) == 0){
			flag = 1;
			printf("%s found at %d position and the code is %d",city, mid+1, a[mid].code);
			break;
		}else if(strcmp(a[mid].city,city) < 0){
			end = mid - 1;
		}else if(strcmp(a[mid].city,city) > 0){
			start = mid+1;
		}
		mid = (start + end)/2;
	}
	printf("%s \n",(flag == 0)?"City not found":"");
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
	binarySearch(a,city,n);
}
