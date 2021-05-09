#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 100

/*
Implementation of QUEUE using Array.

Queue is a linear structure which follows First In First Out (FIFO) order.

The four main operations performed on queue:
(i) Enqueue: Adds an item to the queue. 
(ii) Dequeue: Removes an item from the queue.
(iii) Front: Get the front item from the queue.
(iv) Rear: Get the last item from the queue.

Note: In the program, 
isEmpty() checks if the stack is empty (i.e Queue Underflow).
isFull() checks if the stack is full (i.e Queue Overflow)
*/
struct QUEUE
{
    int MAX_SIZE;
    int front;
    int rear;
    int *array;
};

struct QUEUE *createQueue(int size)
{
    struct QUEUE *queue = (struct QUEUE *)malloc(sizeof(struct QUEUE));
    queue->MAX_SIZE = size;
    queue->front = queue->rear = -1;
    queue->array = (int *)malloc(queue->MAX_SIZE * sizeof(int));

    return queue;
}

bool isEmpty(struct QUEUE *ptr)
{
    if (ptr->front == -1 || ptr->front > ptr->rear)
    {
        printf("\nQueue Underflow!");
        return true;
    }
    else
        return false;
}

bool isFull(struct QUEUE *ptr)
{
    if (ptr->rear == ptr->MAX_SIZE - 1)
    {
        printf("\nQueue Overflow!");
        return true;
    }
    else
        return false;
}

void enqueue(struct QUEUE *ptr, int element)
{
    if (!isFull(ptr))
    {
        if (ptr->front == -1 && ptr->rear == -1)
            ptr->front = ptr->rear = 0;
        else
            ptr->rear++;
    }
    ptr->array[ptr->rear] = element;
    printf("\nItem: %d successfully inserted!", ptr->array[ptr->rear]);
}

void dequeue(struct QUEUE *ptr)
{
    if (!isEmpty(ptr))
    {
        printf("\nItem: %d successfully deleted!", ptr->array[ptr->front]);
        ptr->front++;
    }
}

void display(struct QUEUE *ptr)
{
    if (!isEmpty(ptr))
    {
        printf("\nThe elements in the queue are: ");
        for (int i = ptr->front; i <= ptr->rear; i++)
        {
            printf("%d ", ptr->array[i]);
        }
    }
}
int main()
{
    struct QUEUE *queue = createQueue(SIZE);
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
            if (!isFull(queue))
            {
                printf("\nEnter the element you want to insert: ");
                scanf("%d", &element);
                enqueue(queue, element);
            }
            break;
        case 2:
            //delete element
            dequeue(queue);
            break;
        case 3:
            //display element
            display(queue);
            break;

        default:
            printf("\nPlease enter a valid choice!\n");
            break;
        }
    } while (choice);
    free(queue);
    return 0;
}
