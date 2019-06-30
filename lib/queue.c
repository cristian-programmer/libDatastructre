#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

bool isEmpty(Queue *top){
	if(top == NULL) return true;
	return false;
}

void push(Queue **queue,int value){
	Queue *newqueue = malloc(sizeof(Queue*));
	newqueue->value = value;
	newqueue->next = (*queue);
	(*queue) = newqueue;
}

Queue *extract(Queue *queue){
	Queue *temp;
	
	while (queue != NULL) queue = queue->next;
    temp = queue;
    temp->next = NULL;
    free(queue);
    return temp;	
}

int main(){
	printf("\n all good");
	bool res;
	Queue *lqueue = NULL;
	Queue *ex;
	push(&lqueue, 120);
	push(&lqueue, 10);
	ex = extract(lqueue);
	printf("%i\n", ex->value);
	res = isEmpty(lqueue);
	if (res) {
		printf(" Cola vacia\n");
	}else{
		printf(" Cola llena\n");
	}
	return 0;
}