#include<stdio.h>
#include<stdlib.h>

struct NODE
{
    char data;
    struct NODE *next;
};

typedef struct NODE node;
node *top = NULL;

node * getnodechar(char c){
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

void push(char c){
    node *temp;
    temp = getnodechar(c);
    if(top == NULL){
        top = temp;
    }else{
        temp->next = top;
        top = temp;
    }
}

char pop(){
    node *ptr;
    ptr = top;
    char c;
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
    char string[100];
    printf("Enter the string:- ");
    gets(string);
    printf("Entered string is %s\n", string);
    for (int i = 0; string[i] != '\0'; i++)
    {
        push(string[i]);
    }
    printf("Reverse of string is :- ");
    display();
}