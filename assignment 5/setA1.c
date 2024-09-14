#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct STACK{
    int stk[MAX];
    int top;
};

typedef struct STACK stack;

void initstack(stack *s){
    int i;
    for (i = 0; i < MAX; i++)
    {
        s->stk[i] = 0;
    }
    s->top = -1;
}

int isempty(stack *s){
    if (s->top == -1)
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

void push(stack *s){
    int data;
    printf("\nEnter data:");
    scanf("%d", &data);
    s->top++;
    s->stk[s->top] = data;
}

int pop(stack *s){
    int val;
    val = s->stk[s->top];
    s->top--;
    return val;
}

void display(stack *s){
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("%d\t", s->stk[i]);
    }
}

void peek(stack *s)
{
    printf("\n Top element is: %d.", s->stk[s->top]);
}

void main(){
    stack s;
    int ch;

    initstack(&s);

    while (1)
    {
        printf("\n\n Stack Operations\n");
        printf(" 1. Push\n");
        printf(" 2. Pop\n");
        printf(" 3. Display\n");
        printf(" 4. Peek\n");
        printf(" 5. Exit\n");

        printf("\n Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (isfull(&s))
                printf("\n Stack is FULL!");
            else
                push(&s);
            break;

        case 2:
            if (isempty(&s))
                printf("\n Stack is EMPTY!");
            else
                printf("\n The deleted element is %d",pop(&s));
            break;

        case 3:
            if (isempty(&s))
                printf("\n Stack is EMPTY!");
            else
                display(&s);
            break;
        case 4:
            if (isempty(&s))
                printf("\n Stack is EMPTY!");
            else
                peek(&s);
                break;

        case 5:
            exit(0);

        default:
            printf("\n Invalid choice!\n");
            break;
        }
    }
}