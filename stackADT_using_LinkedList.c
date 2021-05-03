#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Implementation of STACK ADT using Linked Lists.

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
    int data;
    struct STACK *nextNode;
} * TOP;
int MAX_SIZE = 0, counter = 0;

struct STACK *createNode() //function to create nodes dynamically using malloc and returns the node
{
    struct STACK *node = (struct STACK *)malloc(sizeof(struct STACK));
    if (node == NULL)
    {
        printf("\nMemory cannot be allocated!");
    }
    else
        return node;
}

bool isEmpty()
{
    if (TOP == NULL)
    {
        printf("\nStack is Empty!");
        return true;
    }
    else
        return false;
}

bool isFull()
{
    if (counter == MAX_SIZE - 1)
    {
        printf("\nStack is Full!");
        return true;
    }
    else
        return false;
}

void push()
{
    int element;
    struct STACK *temp = createNode();
    printf("\nEnter the element you want to push into the stack: ");
    scanf("%d", &element);
    temp->data = element;
    temp->nextNode = NULL;
    if (TOP == NULL) //checking if TOP points to any existing node or not
    {
        TOP = temp; //if not, point the TOP to 'temp'
        printf("\nThe element %d successfully pushed!\n", TOP->data);
    }
    else //if yes, then make TOP point to new temp.
    {
        temp->nextNode = TOP;
        TOP = temp;
        counter++; //counter to keep track of the elements added
        printf("\nThe element %d successfully pushed!\n", TOP->data);
    }
}

void pop()
{
    struct STACK *pop = TOP; //to store the node that is pointed by TOP
    TOP = TOP->nextNode;     //TOP points the previous node
    counter--;               //decrement counter
    printf("\nThe element %d successfully popped!\n", pop->data);
    free(pop); //free the pop node
}

void peekAtLoc()
{
    struct STACK *ptr = TOP;
    int location = 0, i = 1;
    printf("\nEnter the location of the element you want to peek: ");
    scanf("%d", &location);
    while (ptr != NULL)
    {
        if (i == location)
        {
            printf("\nThe element at location %d: %d\n", location, ptr->data);
            return;
        }
        ptr = ptr->nextNode;
        i++;
    }
}

void traverseELements()
{
    struct STACK *ptr = TOP;
    int i = 0;
    while (ptr != NULL)
    {
        printf("\nThe element at location %d: %d\n", ++i, ptr->data);
        ptr = ptr->nextNode;
    }
    free(ptr);
}

int main()
{
    printf("\n\t\tSTACK ADT OPERATION....!\n");
    int choice = 0;
    TOP = NULL;
    printf("\nEnter the maximum size of the Stack: ");
    scanf("%d", &MAX_SIZE);
    do
    {
        printf("\nSelect the operation you want to perform on stack. Press '0' to exit!\n\n1)Push element\n2)Pop element\n3)Peek at location\n4)Peek all elements\n\nEnter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0: //to exit the program
            printf("Quitting the program....!");
            break;
        case 1: //to push an element in the stack
            if (!isFull())
                push();
            break;
        case 2: //to pop an element from the stack
            if (!isEmpty())
                pop();
            break;
        case 3: //peek element at particular location
            if (!isEmpty())
                peekAtLoc();
            break;
        case 4: //peek all the elements of the stack
            if (!isEmpty())
                traverseELements();
            break;
        default:
            printf("\nPlease enter a valid choice!\n");
            break;
        }
    } while (choice);
    free(TOP);
    return 0;
}