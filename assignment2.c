/**
* @author Yuho Lim
 * @purpose Create a program that can validate if parentheses matches from user-input
 * @date 12.17.2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 50

typedef struct match_parentheses{
    int top;
    char arr[SIZE];
} match_parentheses;

int init_assignment2(match_parentheses *m)
{
    m->top = -1;
    for (int i = 0; i < SIZE; i++)
    {
        m->arr[i] = 0;
    }
    return 0;
}

int isEmpty_assignment2(match_parentheses *m)
{
    if (m->top == -1)
        return 1;
    return 0;
}

int isFull_assignment2(match_parentheses *m)
{
    if (m->top == SIZE - 1)
        return 1;
    return 0;

}

int push_assignment2(match_parentheses *m, char value)
{
    if(isFull_assignment2(m))
    {
        printf("not enough space\n");
        exit(1);
    }
    return m->arr[++(m->top)] = value;
}

int pop_assignment2(match_parentheses *m)
{
    if(isEmpty_assignment2(m))
    {
        printf("no values inside\n");
        exit(1);
    }
    return m->arr[(m->top)--];
}

// Check if two brackets match
bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

// Function to verify if parentheses match
bool verifyParentheses(const char *input, match_parentheses *m) {
    init_assignment2(m);

    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];

        if (c == '(' || c == '{' || c == '[') {
            push_assignment2(m, c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty_assignment2(m)) {
                return false; // Unmatched closing bracket
            }

            char top = pop_assignment2(m);
            if (!isMatchingPair(top, c)) {
                return false; // Mismatched pair
            }
        }
    }
    return isEmpty_assignment2(m);
}

int main_other2(void) {
    match_parentheses m;

    init_assignment2(&m);

    char input[SIZE];

    printf("Enter a sequence of parentheses: \n");
    fgets(input, SIZE, stdin);

    // Remove the newline character
    input[strcspn(input, "\n")] = '\0';

    // Display the full input sentence
    printf("You entered: %s\n", input);

    if (verifyParentheses(input, &m)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are NOT balanced.\n");
    }

    return 0;
}
