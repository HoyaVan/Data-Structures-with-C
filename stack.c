#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct StackType {
    int arr[SIZE]; // 100 of int data
    int top;
} StackType;

// arr starts from index 0,
// therefore -1 means arr is empty
void init(StackType *s)
{
    s->top = -1;
}

// empty : return 1
// !empty : return 0
int is_empty(StackType *s)
{
    if(s->top == -1)
        return 1;
    return 0;
}

// full : return 1
// !full : return 0
int is_full(StackType *s)
{
    if(s->top == SIZE - 1)
        return 1;
    return 0;
}

void push(StackType *s, int value)
{
    // prevent stack overflow
    if(is_full(s))
    {
        printf("Stack is full\n");
        exit(1);
    }
    printf("\npushed: %d\n", value);
    // [], array indexing is being performed
    // the location of ++, increase the size first then process
    s->arr[++(s->top)] = value;
}

int pop(StackType *s)
{
    if(is_empty(s))
    {
        printf("Stack is empty\n");
        exit(1);
    }
    // the location of --, reduce the size after process
    return s->arr[(s->top)--];
}

int peek(StackType *s)
{
    if(is_empty(s))
    {
        printf("Stack is empty\n");
    }
    return s->arr[s->top];
}

int main(void)
{
    StackType s;
    init(&s); // reset stack

    push(&s, 3);
    push(&s, 2);
    push(&s, 1);

    printf("\npeek: %d\n", peek(&s));
    printf("\npop: %d\n", pop(&s));
    printf("\npop: %d\n", pop(&s));
    printf("\npop: %d\n", pop(&s));

    printf("\npop: %d\n", pop(&s));
    return 0;
}
