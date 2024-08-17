#include<stdio.h>
#include<stdlib.h>

struct NODE{
	int data;
	struct NODE *next;
};
typedef struct NODE node;

node *getnode(){
	node *temp;
	temp = (node *)malloc(sizeof(node));
	printf("Enter data:- ");
	scanf("%d",&temp->data);
	temp->next = NULL;
	return temp;
}

node *create(node *list){
	node *temp, *last;
	char ch;
	do{
		temp = getnode();
		if(list == NULL)
			list = temp;
		else{
			for(last = list; last->next != NULL; last = last->next);
			last->next = temp;
		}
		printf("Do you want to add more nodes:- ");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');
	return list;
}

void display(node *list){
	node *ptr;
	for(ptr = list; ptr != NULL; ptr = ptr->next)
		printf("%d ", ptr->data);
	printf("\n");
}

void concat(node *list1, node *list2){
	node *ptr;
	for(ptr = list1; ptr->next != NULL; ptr = ptr->next);
	ptr->next = list2;
}

void main(){
	node *list1 = NULL, *list2 = NULL;
	printf("Creating first linked list:- \n");
	list1 = create(list1);
	printf("Creating second linked list:- \n");
	list2 = create(list2);
	printf("Your 1st linked list is:- ");
	display(list1);
	printf("Your 2nd linked list is:- ");
	display(list2);
	printf("concatinated linked list:- ");
	concat(list1, list2);
	display(list1);
}




