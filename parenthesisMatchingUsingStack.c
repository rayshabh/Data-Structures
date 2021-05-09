#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 100

/*
Check for balanced parenthesis using Stack.

Algorithm:
Step 1: Define a stack to hold brackets.
Step 2: Traverse the expression from left to right.
    (a) If the character is opening bracket (, or { or [, then push it into stack.
    (b) If the character is closing bracket ), } or ] Then pop from stack, and if the popped character is matched with the starting bracket then it is ok. otherwise they are not balanced.
Step 3: After traversal if the any bracket is present in the stack then it is not balanced.

Example: 
1. Enter your expression: }[])]
Output: Expression is not balanced!

2. Enter your expression: []{}()
Output: Expression is balanced!
*/

struct STACK
{
    int MAX_SIZE;
    char TOP;
    char *array;
};

struct STACK *createSTACK(int size)
{
    struct STACK *stack = (struct STACK *)malloc(sizeof(struct STACK));
    stack->MAX_SIZE = size;
    stack->TOP = -1;
    stack->array = (char *)malloc(stack->MAX_SIZE * sizeof(char));

    return stack;
}

bool isEmpty(struct STACK *ptr)
{
    if (ptr->TOP == -1)
        return true;
    else
        return false;
}

bool isFull(struct STACK *ptr)
{
    if (ptr->TOP == ptr->MAX_SIZE)
        return true;
    else
        return false;
}

void push(struct STACK *ptr, char element)
{
    ptr->array[++ptr->TOP] = element;
}

char pop(struct STACK *ptr)
{
    return ptr->array[(ptr->TOP--)];
}

bool characterMatch(char poppedElement, char element)
{
    if (poppedElement == '[' && element == ']')
        return true;
    if (poppedElement == '{' && element == '}')
        return true;
    if (poppedElement == '(' && element == ')')
        return true;
    return false;
}

void parenthesisMatching(char *exp, int MAX_SIZE)
{
    struct STACK *stack = createSTACK(MAX_SIZE);

    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(stack, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(stack)) //checks if expression starts with closing parenthesis
            {
                printf("\nExpression is not balanced!"); //if 'YES', the expression is not balanced!
                return;
            }
            char poppedElement = pop(stack);
            if (!characterMatch(poppedElement, exp[i])) //Traverse each character and check with the TOP of the stack
            {
                printf("\nExpression is not balanced!"); //if not equal, the expression is not balanced!
                return;
            }
        }
        i++;
    }
    if (isEmpty(stack)) //check if the stack is empty or not
        printf("\nExpression is balanced!");
    else
        printf("\nExpression is unbalanced");
}

int main()
{
    char expression[SIZE];
    printf("\nEnter your expression: ");
    fgets(expression, SIZE, stdin);
    parenthesisMatching(expression, strlen(expression));
    return 0;
}