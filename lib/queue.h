#ifndef QUEUE_SIMPLE_H
#define QUEUE_SIMPLE_H

#include <stdbool.h>

typedef struct queue Queue;

struct queue {
	int value;
	Queue *next;
};
/*get the firts node of the queue*/
Queue *extract(Queue *);

/*add to queue a node in last position*/
void push(Queue** ,int);

bool isEmpty(Queue *);

int sizeQueue(Queue*);

#endif