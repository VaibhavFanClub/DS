#include<stdio.h>
void main(){
	int start=0, flag=0, end, mid, i, n, num;
	printf("Enter how many elements in array:- ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d elements in array:- \n",n);
	for(i=0; i<n; i++)
		scanf("%d",&arr[i]);
	end = n-1;
	mid = (start + end)/2;
	printf("Enter number to be searched:- ");
	scanf("%d", &num);
	while(start <= end){
		if(arr[mid] == num){
			flag = 1;
			printf("Element found at %d position", mid+1);
			break;
		}else if(num < arr[mid]){
			end = mid - 1;
			mid = (start + end)/2;
		}else{
			start = mid + 1;
			mid = (start + end)/2;
		}
	}
	printf("%s \n",(!flag)?"Element not found":"");
}


