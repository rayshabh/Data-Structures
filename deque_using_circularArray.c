#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 5

/*
Deque (Double Ended Queue) is a linear data structure in which the insertion and deletion operations are performed from both ends. It is also known as a generalized version of the queue.

The four main operations performed on deque:
(i) Enqueue at Front: Adds an item at the front of Deque.
(ii) Enqueue at Rear: Adds an item at the rear of Deque.
(iii) Dequeue at Front: Deletes an item from front of Deque.
(iv) Dequeue at Front: Deletes an item from rear of Deque.

Note: In the program, 
isEmpty() checks if the stack is empty (i.e Deque Underflow).
isFull() checks if the stack is full (i.e Deque Overflow)
*/
struct DEQUE
{
    int MAX_SIZE;
    int front;
    int rear;
    int *array;
};

struct DEQUE *createQueue(int size)
{
    struct DEQUE *queue = (struct DEQUE *)malloc(sizeof(struct DEQUE));
    queue->MAX_SIZE = size;
    queue->front = queue->rear = -1;
    queue->array = (int *)malloc(queue->MAX_SIZE * (sizeof(int)));

    return queue;
}

bool isEmpty(struct DEQUE *ptr)
{
    if (ptr->front == -1 && ptr->rear == -1)
        return true;
    else
        return false;
}
bool isFull(struct DEQUE *ptr)
{
    if ((ptr->rear + 1) % ptr->MAX_SIZE == ptr->front)
        return true;
    else
        return false;
}

void enqueueRear(struct DEQUE *ptr)
{
    int element;
    printf("\nEnter the element: ");
    scanf("%d", &element);

    if (isEmpty(ptr))
    {
        ptr->front = ptr->rear = 0;
        ptr->array[ptr->rear] = element;
    }
    else
    {
        ptr->rear = (ptr->rear + 1) % ptr->MAX_SIZE;
        ptr->array[ptr->rear] = element;
    }
    printf("\nElement: %d inserted successfully!", ptr->array[ptr->rear]);
}

void dequeueRear(struct DEQUE *ptr)
{
    printf("\nElement: %d deleted successfully!", ptr->array[ptr->rear]);
    if (ptr->front == ptr->rear)
        ptr->front = ptr->rear = -1;
    else
        ptr->rear = (ptr->rear + (ptr->MAX_SIZE - 1)) % ptr->MAX_SIZE;
}

void enqueueFront(struct DEQUE *ptr)
{
    int element;
    printf("\nEnter the element: ");
    scanf("%d", &element);

    if (isEmpty(ptr))
    {
        ptr->front = ptr->rear = 0;
        ptr->array[ptr->front] = element;
    }
    else
    {
        ptr->front = (ptr->front + (ptr->MAX_SIZE - 1)) % ptr->MAX_SIZE;
        ptr->array[ptr->front] = element;
    }
    printf("\nElement: %d inserted successfully!", ptr->array[ptr->front]);
}

void dequeueFront(struct DEQUE *ptr)
{
    printf("\nElement: %d deleted successfully!", ptr->array[ptr->front]);
    if (ptr->front == ptr->rear)
        ptr->front = ptr->rear = -1;
    else
        ptr->front = (ptr->front + 1) % ptr->MAX_SIZE;
}

void display(struct DEQUE *ptr)
{
    printf("\nThe elements in the deque are: Front ----> ");

    int i = ptr->front;
    while (i != ptr->rear)
    {
        printf("%d ", ptr->array[i]);
        i = (i + 1) % ptr->MAX_SIZE;
    }
    printf("%d", ptr->array[i]);
    printf(" <---- Rear");
}

int main()
{
    struct DEQUE *queue = createQueue(SIZE);
    int choice = 0;

    do
    {
        printf("\nSelect the operation you want to perform. Press '0' to exit!\n\n1)Insert element at rear\n2)Insert element at front\n3)Delete element from rear\n4)Delete element from front\n5)Display elements\n\nEnter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            //to exit the program
            printf("Quitting the program....!");
            break;

        case 1:
            //insert element at rear
            if (isFull(queue))
                printf("\nDeque Overflow!");
            else
                enqueueRear(queue);
            break;

        case 2:
            //insert element at front
            if (isFull(queue))
                printf("\nDeque Overflow!");
            else
                enqueueFront(queue);
            break;

        case 3:
            //delete element from rear
            if (isEmpty(queue))
                printf("\nDeque Underflow!");
            else
                dequeueRear(queue);
            break;

        case 4:
            //delete element from front
            if (isEmpty(queue))
                printf("\nDeque Underflow!");
            else
                dequeueFront(queue);
            break;

        case 5:
            //display element
            if (isEmpty(queue))
                printf("\nDeque Underflow!");
            else
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