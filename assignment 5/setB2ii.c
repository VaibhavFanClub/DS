#include<stdio.h>
#include<stdlib.h>

struct NODE
{
    int data;
    struct NODE *next;
};

typedef struct NODE node;
node *top = NULL;

node * getnodeint(int c){
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = c;
    temp->next = NULL;
    return temp;
}

int isempty(){
    if(top == NULL)
        return 1;
    else
        return 0;
}

void push(int c){
    node *temp;
    temp = getnodeint(c);
    if(top == NULL){
        top = temp;
    }else{
        temp->next = top;
        top = temp;
    }
}

int pop(){
    node *ptr;
    ptr = top;
    int c;
    if(isempty()){
        printf("Stack is empty\n");
    }else{
        c = ptr->data;
        top = top->next;
        free(ptr);
    }
    return c;
}

void display(){
    node *ptr;
    ptr = top;
    if(isempty()){
        printf("Stack is empty\n");
    }else{
        while(ptr != NULL){
            printf("%c", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void main(){
    int num, temp;
    printf("Enter the number:- ");
    scanf("%d", &num);
    temp = num;
    while(num != 0)
    {
        int rem = num % 10;
        push(rem);
        num /= 10;
    }
    printf("The number:- %d\n", temp);
    printf("The reverse number is:- ");
    display();
}