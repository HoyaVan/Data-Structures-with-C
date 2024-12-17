#include <stdio.h>
#include <stdlib.h>>
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
    //prevent stack overflow
    if(is_full(s))
    {
        printf("Stack is full\n");
        exit(1);
    }
    s->

}

int main(void) {

    return 0;
}
