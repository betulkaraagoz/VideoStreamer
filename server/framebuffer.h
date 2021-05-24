// C program for array implementation of queue
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
 
typedef struct 
{
    int rate;
    char rate_str[70];
    char frame[13*70];
} Frame;

// A structure to represent a queue
typedef struct {
    int front, rear, size;
    unsigned capacity;
    Frame *array;
} Queue;
 

Frame EMPTY_FRAME;
// function to create a queue
// of given capacity.
// It initializes size of queue as 0
Queue* createQueue(unsigned capacity)
{
    Queue* queue = (Queue*)malloc(
        sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
 
    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->array = (Frame *)malloc(
        queue->capacity * sizeof(Frame));
    return queue;
}
 
// Queue is full when size becomes
// equal to the capacity
int isFull(Queue* queue)
{
    return (queue->size == queue->capacity);
}
 
// Queue is empty when size is 0
int isEmpty(Queue* queue)
{
    return (queue->size == 0);
}
 
// Function to add an item to the queue.
// It changes rear and size
void enqueue(Queue* queue, Frame item)
{
    if (isFull(queue)){
        return;
    }
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}
 
// Function to remove an item from queue.
// It changes front and size
Frame dequeue(Queue* queue)
{
    if (isEmpty(queue))
        return EMPTY_FRAME;
    Frame item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
 
// Function to get front of queue
Frame front(Queue* queue)
{
    if (isEmpty(queue))
        return EMPTY_FRAME;
    return queue->array[queue->front];
}
 
// Function to get rear of queue
Frame rear(Queue* queue)
{
    if (isEmpty(queue))
        return EMPTY_FRAME;
    return queue->array[queue->rear];
}