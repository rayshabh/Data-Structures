#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Implementation of STACK ADT using arrays.

Stack is a linear data structure which follows a particular order in which the operations are performed.
The order may be LIFO(Last In First Out) or FILO(First In Last Out).

The three basic operations are performed in stack:
(i) Push: Adds an item in the stack.
(ii) Pop: Removes/delete an item from the stack.
(iii) Peek: Returns top element of stack.

However, in this program I have changed the functionality of 'Peek operation' to 'Peek the element at particular location' and 'Peek the whole elements of the stack'.

isEmpty() checks if the stack is empty (i.e Stack Underflow).
isFull() checks if the stack is full (i.e Stack Overflow).
*/
struct STACK
{
    int MAX_SIZE;
    int TOP;
    int *array;
};

bool isEmpty(struct STACK *ptr)
{
    if (ptr->TOP == -1)
    {
        printf("\nStack is empty!\n");
        return true;
    }
    else
        return false;
}
bool isFull(struct STACK *ptr)
{
    if (ptr->TOP == ptr->MAX_SIZE - 1)
    {
        printf("\nStack is full!\n");
        return true;
    }
    else
        return false;
}
void push(struct STACK *ptr, int element)
{
    ptr->array[++ptr->TOP] = element; //increments the 'TOP' and then insert the element at 'array[TOP]'
    printf("Element %d pushed successfully!\n", element);
}
void pop(struct STACK *ptr)
{
    int temp;
    temp = ptr->array[ptr->TOP--]; //stores the element in temp and then decrements the 'TOP'
    printf("Element %d popped successfully!\n", temp);
}
void peekAtLoc(struct STACK *ptr, int location)
{
    printf("\nThe element at location %d: %d\n", location, ptr->array[(ptr->TOP) - location + 1]);
}

int main()
{
    printf("\n\t\tSTACK ADT OPERATION....!\n");
    int choice = 0;
    struct STACK *stk = (struct STACK *)malloc(sizeof(struct STACK));
    if (stk == NULL)
    {
        printf("\nMemory allocation unsuccessful!\n");
    }
    else
    {
        printf("\nEnter the maximum size of the array: ");
        scanf("%d", &stk->MAX_SIZE);
        stk->TOP = -1;
        stk->array = (int *)malloc(stk->MAX_SIZE * sizeof(int));
    }
    do
    {
        printf("\nSelect the operation you want to perform on stack. Press '0' to exit!\n\n1)Push element\n2)Pop element\n3)Peek at location\n4)Peek all elements\n\nEnter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            int element;
            int location;
        case 0: //to exit the program
            printf("Quitting the program....!");
            break;
        case 1: //to push an element in the stack
            if (!isFull(stk))
            {
                printf("\nEnter the element you want to push into the stack: ");
                scanf("%d", &element);
                push(stk, element);
            };
            break;
        case 2: //to pop an element from the stack
            if (!isEmpty(stk))
            {
                pop(stk);
            }
            break;
        case 3: //peek element at particular location
            if (!isEmpty(stk))
            {
                printf("\nEnter the location of the element you want to peek: ");
                scanf("%d", &location);
                peekAtLoc(stk, location);
            };
            break;
        case 4: //peek all the elements of the stack
            if (!isEmpty(stk))
            {
                int i = 0;
                printf("\nThe elements in the stack are: \n");
                while (i <= stk->TOP)
                {
                    printf("The element at location %d: %d\n", i + 1, stk->array[(stk->TOP) - i]);
                    i++;
                }
            }
            break;
        default:
            printf("\nPlease enter a valid choice!\n");
            break;
        }
    } while (choice);
    free(stk->array);
    free(stk);
    return 0;
}