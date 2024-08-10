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
		if(list == NULL){
			list = temp;
			temp->next = list;
		}
		else{
			for(last = list; last->next != list; last = last->next);
			last->next = temp;
			temp->next = list;
		}
		printf("Do you want to add more nodes:- ");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');
	return list;
}

void search(node *list, int val){
	node *ptr;
	int pos;
	for(ptr = list, pos=1; ptr->next != list && ptr->data != val; pos++, ptr = ptr->next);
	if(ptr->data == val){
		printf("Value found at pos %d\n",pos);
	}
	else{
		printf("Value not found\n");
	}
}

void length(node *list){
	node *ptr;
	int cnt;
	for(ptr = list, cnt=1; ptr->next != list; cnt++, ptr = ptr->next);
	printf("Length of ll is %d\n",cnt);
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
		printf("3. Search\n");
		printf("4. Length\n");
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
			case 3:	printf("Enter value to search:- ");
						scanf("%d",&val);
						search(list, val);
						printf("\n\n");
						break;
			case 4:	length(list);
						printf("\n\n");
						break;
			case 5: 	exit(0);
		}
	}
}

