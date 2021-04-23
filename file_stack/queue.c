#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "queue.txt"
#include <limits.h>


// A structure to represent a queue
typedef struct Queue {
	int front, rear, size;
	unsigned capacity;
	int* array;
} Queue;

// function to create a queue
// of given capacity.
// It initializes size of queue as 0
Queue* createQueue(unsigned capacity){
	Queue* queue = (Queue*)malloc(
		sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;

	// This is important, see the enqueue
	queue->rear = capacity - 1;
	queue->array = (int*)malloc(
		queue->capacity * sizeof(int));
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
void enqueue(Queue* queue, int item)
{
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1)
				% queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	printf("%d enqueued to queue\n", item);
}

// Function to remove an item from queue.
// It changes front and size
int dequeue(Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1)
				% queue->capacity;
	queue->size = queue->size - 1;
	return item;
}

// Function to get front of queue
int front(Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}

// Function to get rear of queue
int rear(Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}

Queue* command_file(Queue* queue){
    FILE* fp;
    char cmd[1024];
    int data = 0;

    fp = fopen(FILE_NAME, "r");

    while(1) {
        fscanf(fp, "%s", cmd);

        if(!strcmp(cmd, "ENQUEUE")){
            fscanf(fp, "%d", &data);
            enqueue(queue, data);
        } 
        else if(!strcmp(cmd, "DEQUEUE"))
            dequeue(queue);
        else if(!strcmp(cmd, "FRONT"))
            printf("Front item is %d\n", front(queue));
        else if(!strcmp(cmd, "REAR"))
            printf("Rear item is %d\n", rear(queue));
        else if(!strcmp(cmd, "END"))
            break;
    }

    fclose(fp);

}

int main(){
	Queue* queue = createQueue(100);
    command_file(queue);

	return 0;
}
