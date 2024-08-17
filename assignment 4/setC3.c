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

node *igetnode(int data){
	node *temp;
	temp = (node *)malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

node * intersect(node *list1, node *list2, node *ilist){
	node *ptr1, *ptr2, *temp, *last;
	for(ptr1 = list1; ptr1 != NULL; ptr1 = ptr1->next){
		for(ptr2 = list2; ptr2 != NULL; ptr2 = ptr2->next){
			if(ptr1->data == ptr2->data){
				if(ilist == NULL){
					temp = igetnode(ptr1->data);
					ilist = temp;
				} else{
					temp = igetnode(ptr1->data);
					for(last = ilist; last->next != NULL; last = last->next);
					last->next = temp;
				}
			}
		}
	}
	return ilist;
}

void main(){
	node *list1 = NULL, *list2 = NULL, *ilist = NULL;
	printf("Creating first linked list:- \n");
	list1 = create(list1);
	printf("Creating second linked list:- \n");
	list2 = create(list2);
	printf("Your 1st linked list is:- ");
	display(list1);
	printf("Your 2nd linked list is:- ");
	display(list2);
	printf("Intersection of two linked list:- ");
	ilist = intersect(list1, list2, ilist);
	display(ilist);
}




