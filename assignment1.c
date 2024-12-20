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

int isPalindrome(const char *input) {
    PalindromeValidation stack;
    init_assignment(&stack);

    // Push all characters onto the stack
    for (int i = 0; input[i] != '\0'; i++) {
        push_assignment(&stack, input[i]);
    }

    // Compare characters by popping from the stack
    for (int i = 0; input[i] != '\0'; i++) {
        char reversedChar = pop_assignment(&stack);
        if (input[i] != reversedChar) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
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

int main(void) {
    char input[SIZE];

    printf("Please enter a sentence: ");
    fgets(input, SIZE, stdin);

    // Remove the newline character added by fgets
    input[strcspn(input, "\n")] = '\0';

    printf("You entered: %s\n", input);

    // Check if it's a palindrome
    if (isPalindrome(input)) {
        printf("The input is a palindrome.\n");
    } else {
        printf("The input is NOT a palindrome.\n");
    }

    return 0;
}