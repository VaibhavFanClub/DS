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

void append(node *list){
	node *temp, *last;
	for(last = list; last->next != list; last = last->next);
	temp = getnode();
	temp->next = last->next;
	temp->prev = last;
	last->next->prev = temp;
	last->next = temp;
}

void deleteVal(node *list, int val){
	node *temp, *ptr, *last;
	for(ptr = list; ptr->next != list && ptr->data != val; ptr = ptr->next);
	if(ptr->data == val){
		if(ptr == list){
			list = ptr->next;
			ptr->next->prev = ptr->prev;
			ptr->prev->next = list;
		}
		else{
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;
		}
		free(ptr);
	}
	else{
		printf("Value not found\n");
	}
}

void display(node *list){
	node *ptr;
	for(ptr = list; ptr->next != list; ptr = ptr->next)
		printf("%d ", ptr->data);
	printf("%d ", ptr->data);
}

void main(){
	node *list = NULL;
	while(1){
		int choice, val;
		printf("!!!! MENU !!!!\n");
		printf("1. Create\n");
		printf("2. Display\n");
		printf("3. Append\n");
		printf("4. Delete\n");
		printf("5. Exit\n\n");
		printf("Enter your choice (1/2/3/4/5):- ");
		scanf("%d",&choice);
		switch(choice){
			case 1:	list = create(list);
						printf("\n\n");
						break;
			case 2:	printf("Linked list = ");
						display(list);
						printf("\n\n");
						break;
			case 3:	append(list);
						printf("\n\n");
						break;
			case 4:	printf("Enter val to delete:- ");
						scanf("%d",&val);
						deleteVal(list, val);
						printf("\n\n");
						break;
			case 5: 	exit(0);
		}
	}
}

