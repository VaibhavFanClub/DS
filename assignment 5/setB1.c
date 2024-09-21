#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct STACK{
    char stk[MAX];
    int top;
};
typedef struct STACK stack;
void initstack(stack *s){
    for (int i = 0; i < MAX; i++)
    {
        s->stk[i] = '\0';
    }
    s->top = -1;
}

int isempty(stack *s){
    if(s->top == -1)
        return 1;
    else
        return 0;
}

int isfull(stack *s){
    if(s->top == MAX - 1)
        return 1;
    else    
        return 0;
}

void push(stack *s, char c){
    s->top++;
    s->stk[s->top] = c;
}

char pop(stack *s){
    return s->stk[s->top--];
}

void display(stack *s){
    for (int i = 0; s->stk[i] != '\0'; i++)
    {
        printf("%c", s->stk[i]);
    }
    printf("\n");
}

void main(){
    char string[100];
    printf("Enter the string of length less than or equal to %d :- ", MAX);
    gets(string);
    stack s;
    initstack(&s);
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (!isfull(&s))
        {
            push(&s, string[i]);
        }else{
            printf("Stack is full\n");
        }
    }
    printf("The elements of stack are:- ");
    display(&s);
    printf("The reverse elements of stack are:- ");
    while (!isempty(&s))
    {
        printf("%c", pop(&s));
    }
    printf("%c\n", pop(&s));    
}