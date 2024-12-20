/**
 * @author Yuho Lim
 * @purpose Create a program that can validate Palindrome
 * @date 12.17.2024
 */
#include "assignment1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int init_assignment(PalindromeValidation *p)
{
    p->top = -1;
    for (int i = 0; i < SIZE; i++)
    {
        p->arr[i] = 0;
    }
    return 0;
}

int isEmpty_assignment(PalindromeValidation *p)
{
    if(p->top == -1)
        return 1;
    return 0;
}

int isFull_assignment(PalindromeValidation *p)
{
    if(p->top == SIZE - 1)
        return 1;
    return 0;
}

int push_assignment(PalindromeValidation *p, int value) {
    if(isFull_assignment(p)) {
        printf("Stack is full\n");
        exit(1);
    }
    return p->arr[++p->top] = value;
}

int pop_assignment(PalindromeValidation *p) {
    if(isEmpty_assignment(p)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return p->arr[p->top--];
}

int peek_assignment(PalindromeValidation *p) {
    if(isEmpty_assignment(p)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return p->arr[p->top];
}

void scan_assignment(PalindromeValidation *p) {
    if (p->top < 0) {
        printf("No letters in the array.\n");
        exit(1);
    }

    // Compare the first and last letters
    if (p->arr[0] == p->arr[p->top]) {
        printf("The first and the last letter are the same.\n");
    } else {
        printf("The first and the last letter are NOT the same.\n");
    }
    printf("\n");
}

void display_assignment(PalindromeValidation *p) {
    if (isEmpty_assignment(p)) {
        printf("Stack is empty\n");
        exit(1);
    }

    for (int i = 0; p->arr[i] != '\0'; i++) { // Iterate until the null terminator
        printf("%c", p->arr[i]); // Print each character
    }
}

int main_other2(void) {
    PalindromeValidation s;

    init_assignment(&s);

    printf("Please enter an Sentence: ");
    fgets(s.arr, SIZE, stdin);

    // Remove the newline character added by fgets
    s.arr[strcspn(s.arr, "\n")] = '\0';

    // Update the `top` variable to reflect the last character index
    s.top = strlen(s.arr) - 1;

    scan_assignment(&s);

    display_assignment(&s);

    return 0;
}