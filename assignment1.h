#ifndef ASSGINEMENT1_H
#define ASSGINEMENT1_H
#define SIZE 50

typedef struct PalindromeValidation
{
    char arr[SIZE];
    int top;
} PalindromeValidation;

// Function declarations
int init_assignment(PalindromeValidation *p);
int isEmpty_assignment(PalindromeValidation *p);
int isFull_assignment(PalindromeValidation *p);
int push_assignment(PalindromeValidation *p, int value);
int pop_assignment(PalindromeValidation *p);
int peek_assignment(PalindromeValidation *p);
void scan(PalindromeValidation *p);
int main_assignment(void);

#endif
