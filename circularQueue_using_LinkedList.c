#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 5 //to keep the size of the Queue fixed
/*
Implementation of QUEUE using Linked List.

A circular queue is similar to a linear queue which follows First In First Out (FIFO) order except that the last position is connected to the first posititon in a circular queue that forms a circle. (Also, known as a Ring Buffer).

The four main operations performed on queue:
(i) Enqueue: Adds an item to the queue. 
(ii) Dequeue: Removes an item from the queue.
(iii) Front: Get the front item from the queue.
(iv) Rear: Get the last item from the queue.

Note: In the program, 
isEmpty() checks if the stack is empty (i.e Queue Underflow).
*/
struct NODE
{
    int data;
    struct NODE *nextNode;
};

struct NODE *front = NULL;
struct NODE *rear = NULL;

struct NODE *createNode() //function to create node
{
    struct NODE *queue = (struct NODE *)malloc(sizeof(struct NODE));
    queue->nextNode = NULL;

    return queue;
}

bool isEmpty()
{
    if (front == NULL)
        return true;
    else
        return false;
}

void enqueue()
{
    struct NODE *tempNode = createNode();
    printf("\nEnter the element: ");
    scanf("%d", &tempNode->data);

    if (isEmpty(front))
    {
        front = rear = tempNode;
        rear->nextNode = front;
    }
    else
    {
        rear->nextNode = tempNode;
        rear = tempNode;
        rear->nextNode = front;
    }
    printf("\nElement: %d inserted successfully!", rear->data);
}

void dequeue()
{
    struct NODE *tempPtr = front;
    if (front == rear)
        front = rear = NULL;
    else
    {
        front = front->nextNode;
        rear->nextNode = front;
    }
    printf("\nElement: %d deleted successfully!", tempPtr->data);
    free(tempPtr);
}

void display()
{
    struct NODE *ptr = front;
    printf("\nThe elements in the queue are: ");
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->nextNode;
    } while (ptr != front);
}

int main()
{
    int choice = 0;

    do
    {
        printf("\nSelect the operation you want to perform. Press '0' to exit!\n\n1)Insert element\n2)Delete element\n3)Display elements\n\nEnter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            int element;

        case 0:
            //to exit the program
            printf("Quitting the program....!");
            break;

        case 1:
            //insert element
            enqueue();
            break;

        case 2:
            //delete element
            if (isEmpty())
                printf("\nQueue Underflow!");
            else
                dequeue();
            break;

        case 3:
            //display element
            if (isEmpty())
                printf("\nQueue Underflow!");
            else
                display();
            break;

        default:
            printf("\nPlease enter a valid choice!\n");
            break;
        }
    } while (choice);
    free(front);
    free(rear);
    return 0;
}