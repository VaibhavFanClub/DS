#include<stdio.h>
#include<stdlib.h>

struct NODE{
	int data;
	struct NODE *next, *prev;
};
typedef struct NODE node;

node *getnode(){
	node *temp;
	temp = (node *)malloc(sizeof(node));
	printf("Enter data:- ");
	scanf("%d",&temp->data);
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

node *create(node *list){
	node *temp, *last;
	char ch;
	do{
		temp = getnode();
		if(list == NULL){
			list = temp;
			temp->next = list;
			temp->prev = list;
		}
		else{
			for(last = list; last->next != list; last = last->next);
			last->next = temp;
			temp->prev = last;
			temp->next = list;
			list->prev = temp;
		}
		printf("Do you want to add more nodes:- ");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');
	return list;
}

void display(node *list){
	node *ptr;
	for(ptr = list; ptr->next != list; ptr = ptr->next)
		printf("%d ", ptr->data);
	printf("%d ", ptr->data);
}

void main(){
	node *list = NULL;
	list = create(list);
	printf("Your linked list is:- ");
	display(list);
	printf("\n");
}




