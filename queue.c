#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue_t* create_queue()   // return a newly created empty queue
{
	// DO NOT MODIFY!!!
	queue_t* Q = (queue_t*) malloc(sizeof(queue_t));
	Q->list = create_list();
	Q->front = Q->list->head;
	Q->rear = Q->list->tail;
	Q->size = Q->list->size;
	return Q;
}

void enqueue(queue_t* q, int data) // TODO: insert data at the end of a queue
{
   node_t* temporary=(node_t*)malloc(sizeof(node_t));
   temporary->data=data;
   temporary->prev=temporary->next=NULL;
   if (q->list->head==NULL)
   {
	   q->list->head=temporary;
	   q->list->size++;
   }
   else
   {
	   node_t* current=q->list->head;
	   node_t* prev=NULL;
	   while(current!=NULL)
	   {
	   prev=current;
	   current=current->next;
       }
       q->list->tail=prev;
	   q->list->tail->next=temporary;
	   temporary->prev=q->list->tail;
	   q->list->tail=temporary;
	   q->list->size++;
   }
    q->front= q->list->head;
	q->rear = q->list->tail;
	q->size = q->list->size;
}

int dequeue(queue_t* q) 	// TODO: return the data at the front of a queue and remove it. Return -1 if queue is empty
{
	int x;
	if (q->list->size==0)
	{
		return -1;
	}
	else
	{
		node_t* current=q->list->head;
		node_t* second=current->next;
		if (second==NULL)
		{
			q->list->head=NULL;
			x=current->data;
			free(current);
			current=NULL;
		}
		else
		{
			q->list->head=second;
			second->prev=NULL;
			x=current->data;
			free(current);
			current=NULL;
		}
	}
	q->list->size--; 
    q->front= q->list->head;
	q->rear = q->list->tail;
	q->size = q->list->size;
    return x;	
}

int front(queue_t* q) // TODO: return the data at the front of a queue. Return -1 if queue is empty
{
	if (q->list->size==0){return -1;}
	else{
		int x;
		x=q->front->data;
		return x;
	}
}

int empty(queue_t* q) // return if the queue is empty
{
	// DO NOT MODIFY!!!
	return is_empty(q->list);
}

int queue_size(queue_t* q) // returns the number of elements in the queue
{
	// DO NOT MODIFY!!!
	return q->size;
}

void delete_queue(queue_t* q) // empty the contents of the queue
{
	// DO NOT MODIFY!!!
	delete_list(q->list);
	free(q);
}
