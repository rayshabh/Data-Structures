#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 100

/*
Program to convert infix expression to postfix expression using STACK.

Algorithm:
1. Scan the infix expression from left to right. 
2. If the scanned character is an operand, output it. 
3. Else, 
      1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty or the stack contains a ‘(‘ ), push it. 
      2 Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
4. If the scanned character is an ‘(‘, push it to the stack. 
5. If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
6. Repeat steps 2-6 until infix expression is scanned. 
7. Print the output 
8. Pop and output from the stack until it is not empty.
*/
struct STACK //Stack Declaration
{
    int MAX_SIZE;
    int TOP;
    char *operatorStack;
};

struct STACK *createSTACK(int size)
{
    struct STACK *stack = (struct STACK *)malloc(sizeof(struct STACK));
    stack->MAX_SIZE = size;
    stack->TOP = -1;
    stack->operatorStack = (char *)malloc(stack->MAX_SIZE * sizeof(char));

    return stack;
}

bool isEmpty(struct STACK *ptr) //checks if Stack is empty or not
{
    if (ptr->TOP == -1)
        return true;
    else
        return false;
}

bool isFull(struct STACK *ptr) //checks if Stack is empty or not
{
    if (ptr->TOP == ptr->MAX_SIZE)
        return true;
    else
        return false;
}

void push(struct STACK *ptr, char operator) //push operation
{
    ptr->operatorStack[++ptr->TOP] = operator;
}

char pop(struct STACK *ptr) //pop operation
{
    return ptr->operatorStack[(ptr->TOP--)];
}

int isOperand(char operand) //checks if the upcoming element is a operand or not
{
    return (operand >= 'A' && operand <= 'Z') || (operand >= 'a' && operand <= 'z');
}

int isOperator(char operator) //checks if the upcoming element is a operator or not
{
    return (operator== '+' || operator== '-' || operator== '*' || operator== '/' || operator== '^');
}

int checkPrecedence(char operator) //function to check the precedence of the operator
{
    switch (operator)
    {
    case '+':
    case '-':
        return 2;

    case '*':
    case '/':
        return 3;

    case '^':
        return 4;
    }
    return 0;
}

void infixToPostfix(char *expression, int MAX_SIZE) //converts infix expression to postfix expression
{
    struct STACK *stack = createSTACK(SIZE);

    int i = 0, j = 0;
    bool flagParenthesis = false, flagOperand = false; //flag variables to check if the expression is valid or not

    while (expression[i] != '\0')
    {
        if (isOperand(expression[i])) //checks if scanned element is operand
        {
            expression[j++] = expression[i]; //if the scanned element is an operand, append it to the
            flagOperand = true;              //expression. Set true, if the first scanned element
                                             //is an operand
        }

        else if (expression[i] == '(') //checks if scanned element is '('
        {
            push(stack, expression[i]); //if yes, push it to the stack
            flagParenthesis = true;     //set true, if the first scanned element is '('
        }

        else if (expression[i] == ')') //if ')' parenthesis is encountered
        {
            if (isEmpty(stack)) //checks if stack is empty or not
            {                   //if the expression starts with ')', then the expression is not valid.
                printf("\nThe parenthesis in the expression is unbalanced!");
                return;
            }

            else if (!isEmpty(stack) && flagParenthesis == false) //checks if the stack contains '('
                                                                  //or not
            {
                printf("\nThe parenthesis in the expression is unbalanced!");
                return;
            }

            while (stack->operatorStack[stack->TOP] != '(') //scans the stack till '(' and pops every operator out of the stack and append it to the expression
                expression[j++] = pop(stack);
            stack->TOP--;
            flagParenthesis = false; //set false, if popping completes.
        }

        else if (isOperator(expression[i])) //checks scanned element is an operator

        {
            if (!flagOperand) //checks if the first element of the expression starts with an operator
            {                 //if yes, then Expression is invalid
                printf("\nInvalid Expression!");
                return;
            }

            if (!isEmpty(stack) && checkPrecedence(expression[i]) <= checkPrecedence(stack->operatorStack[stack->TOP])) //checks the scanned operator with the operator in Stack TOP and compares the precedence
            {
                while (checkPrecedence(expression[i]) <= checkPrecedence(stack->operatorStack[stack->TOP]))
                    expression[j++] = pop(stack);
                push(stack, expression[i]);
            }

            else
                push(stack, expression[i]); //push the scanned operator into stack if the precedence is higher
        }
        i++;
    }

    while (!isEmpty(stack)) //popp out operators from the stack
    {
        char temp = pop(stack);
        if (temp == '(') //check if '(' is present in the stack, if yes, the expression is unbalanced
        {
            printf("\nThe parenthesis in the expression is unbalanced!");
            return;
        }
        expression[j++] = temp; //append the popped operator to the expression
    }
    expression[j] = '\0';
    printf("\nThe postifix expression: %s", expression);
    free(stack);
}
int main()
{
    char expression[SIZE];
    printf("\nEnter your expression: ");
    fgets(expression, SIZE, stdin);
    infixToPostfix(expression, strlen(expression));
    return 0;
}