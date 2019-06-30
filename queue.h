#ifndef QUEUE_FILE_H
#define QUEUE_FILE_H

	#define EXIT 0;

	struct queue {
		int data;
		struct queue *next;
	};
	typedef struct queue Queue;
	
	void enqueue(Queue **queue, char);
	void dequeue(Queue **queue);
	void printQ(Queue *queue);
	void menu(void);


#endif 