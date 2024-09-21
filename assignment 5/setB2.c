#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct STACK{
    char stk[MAX];
    int top;
};
typedef struct STACK stack;
void initstack(stack *s){
    for (int i = 0; i < MAX; i++)
    {
        s->stk[i] = 0;
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

void push(stack *s, int n){
    s->top++;
    s->stk[s->top] = n;
}

int pop(stack *s){
    return s->stk[s->top--];
}

void display(stack *s){
    for (int i = 0; i < MAX; i++)
    {
        printf("%d", s->stk[i]);
    }
    printf("\n");
}

void main(){
    int num, temp;
    printf("Enter the number of length less than or equal to %d :- ", MAX);
    scanf("%d", &num);
    temp = num;
    stack s;
    initstack(&s);
    while(num != 0)
    {
        int rem = num % 10;
        if (!isfull(&s))
        {
            push(&s, rem);
        }else{
            printf("Stack is full\n");
        }
        num /= 10;
    }
    printf("The number:- %d\n", temp);
    printf("The reverse number is:- ");
    display(&s);
}