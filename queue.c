#include <stdio.h>
#include <stdlib.h>
#include "queue.h"




int main(){
	Queue *head =  malloc(sizeof(Queue)); 

	if(head == NULL) {
		printf("No memory \n");
		return EXIT;
	}
   
    char value;
    int choise;
    menu();
    printf("%s\n", "Escoja una opción");	
    
    scanf("%u",&choise);
    while (choise != 3) {
    	switch(choise) {

    		case 1:
    		 printf("%s\n","Ingrese un caracter");
    		 scanf("\n%c", &value);
    		 enqueue(&head, value);
    		 printQ(head);
    		break;

    		case 2:
    		 dequeue(&head);
    		 printQ(head);	
    		break;
    	}

    	printf("ingresa una opcion\n");
    	scanf("%u", &choise);
    }
	return EXIT;
}


void enqueue(Queue **hqueue, char value){
	Queue *newqueue = malloc(sizeof(Queue));
	Queue *endqueue = *hqueue;
	if(newqueue == NULL){
		printf("%s\n", "no hay memoria");
		return;
	}

	newqueue->data = value;
	newqueue->next = NULL;

	while (endqueue->next != NULL){
		endqueue = endqueue->next;
	}



	endqueue->next = newqueue;

}


void dequeue(Queue **hqueue){
	if(hqueue == NULL || (*hqueue)->next == NULL){
		printf("%s\n", "No hay cola");
		return;
	}

	Queue *first = (*hqueue)->next;
	Queue *second = first->next;
	Queue *now = *hqueue;

	now->next = second;
	free(first);


}

void printQ(Queue *hqueue){
	Queue *q = hqueue;
	if(q == NULL || q->next == NULL) {
		printf("%s\n", "La cola esta vacia");
		return;
	} 

	while(q != NULL){
		printf("%c\n -->", q->data);
		q = q->next;
	}
	printf("NULL\n");


}

void menu(){
	puts("Ingresa un valor \n"
	" .1 Agregar a la cola un valor\n"
	" .2 Sacar de la cola un valor\n"
	" .3 Salir\n");
}