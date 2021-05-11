#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 5

/*
Implementation of QUEUE using Array.

A circular queue is similar to a linear queue which follows First In First Out (FIFO) order except that the last position is connected to the first posititon in a circular queue that forms a circle. (Also, known as a Ring Buffer).

The four main operations performed on queue:
(i) Enqueue: Adds an item to the queue. 
(ii) Dequeue: Removes an item from the queue.
(iii) Front: Get the front item from the queue.
(iv) Rear: Get the last item from the queue.

Note: In the program, 
isEmpty() checks if the stack is empty (i.e Queue Underflow).
isFull() checks if the stack is full (i.e Queue Overflow)
*/

struct circularQueue
{
    int MAX_SIZE;
    int front;
    int rear;
    int *array;
};

struct circularQueue *createQueue(int size)
{
    struct circularQueue *Queue = (struct circularQueue *)malloc(sizeof(struct circularQueue));
    Queue->MAX_SIZE = size;
    Queue->front = Queue->rear = -1;
    Queue->array = (int *)malloc(Queue->MAX_SIZE * sizeof(int));

    return Queue;
}

bool isEmpty(struct circularQueue *ptr)
{
    if (ptr->front == -1 && ptr->rear == -1)
    {
        printf("\nQueue Underflow!");
        return true;
    }
    else
        return false;
}

bool isFull(struct circularQueue *ptr)
{
    if ((ptr->rear + 1) % ptr->MAX_SIZE == ptr->front)
    {
        printf("\nQueue Overflow!");
        return true;
    }
    else
        return false;
}

void enqueue(struct circularQueue *ptr, int element)
{
    if (ptr->front == -1 && ptr->rear == -1)
    {
        ptr->front = ptr->rear = 0;
        ptr->array[ptr->rear] = element;
        printf("\nElement: %d inserted successfully!", ptr->array[ptr->rear]);
        printf("\nPosition of Front: %d and Rear: %d\n", ptr->front, ptr->rear);
    }
    else
    {
        ptr->rear = (ptr->rear + 1) % ptr->MAX_SIZE;
        ptr->array[ptr->rear] = element;
        printf("\nElement: %d inserted successfully!", ptr->array[ptr->rear]);
        printf("\nPosition of Front: %d and Rear: %d\n", ptr->front, ptr->rear);
    }
}

void dequeue(struct circularQueue *ptr)
{
    if (ptr->front == ptr->rear)
    {
        printf("\nElement: %d deleted successfully!", ptr->array[ptr->front]);
        ptr->front = ptr->rear = -1;
        printf("\nPosition of Front: %d and Rear: %d\n", ptr->front, ptr->rear);
    }
    else
    {
        printf("\nElement: %d deleted successfully!", ptr->array[ptr->front]);
        ptr->front = (ptr->front + 1) % ptr->MAX_SIZE;
        printf("\nPosition of Front: %d and Rear: %d\n", ptr->front, ptr->rear);
    }
}

void display(struct circularQueue *ptr)
{
    printf("\nThe elements in the queue are: ");

    int i = ptr->front;
    while (i != ptr->rear)
    {
        printf("%d ", ptr->array[i]);
        i = (i + 1) % ptr->MAX_SIZE;
    }
    printf("%d", ptr->array[i]);
}

int main()
{
    struct circularQueue *Queue = createQueue(SIZE);
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
            if (!isFull(Queue))
            {
                printf("\nEnter the element you want to insert: ");
                scanf("%d", &element);
                enqueue(Queue, element);
            }
            break;
        case 2:
            //delete element
            if (!isEmpty(Queue))
            {
                dequeue(Queue);
            }
            break;
        case 3:
            //display element
            if (!isEmpty(Queue))
            {
                display(Queue);
            }
            break;

        default:
            printf("\nPlease enter a valid choice!\n");
            break;
        }
    } while (choice);
    free(Queue);
    return 0;
}