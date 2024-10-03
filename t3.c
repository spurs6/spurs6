#define MAX_SIZE 5//
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int array[MAX_SIZE];//先定义后使用，即先定义一个结构类型的队列queue
	int front;          //然后定义了一个结构体的别名queue
	int rear;
}queue;

void initqueue(queue* q);
void enqueue(int value,queue* q);
int dequeue(queue* q);

void initqueue(queue* q) {
	q->front = -1;
	q->rear = -1;
}
int isempty(queue* q) {
	return q->rear == q->front;
}
int isfull(queue* q) {
	return (q->rear+1)%MAX_SIZE==q->front;//或者将这个条件改成(q->rear+1)%MAX_SIZE==0
	//或者将这个条件改成（q->rear+1）%MAX_SIZE==q->front
}
void enqueue(int value, queue* q) {
	if (isfull(q)) {
		printf("The queue is already full!\n");
	}
	else {
		q->rear = (q->rear + 1) % MAX_SIZE;
		q->array[q->rear] = value;
	}
}
int dequeue(queue* q) {
	if (isempty(q)) {
		printf("The queue is already empty!\n");
		return -1;
	}
	else {
		int sector = q->array[q->front];
		q->front++;
		return sector;
	}

}


int main() {
	queue* q=(queue*) malloc(sizeof(queue)*MAX_SIZE);
	if (q == NULL) {
		return -1;
	}
	initqueue(q);
	enqueue(1, q);
	enqueue(2, q);
	enqueue(3, q);
	enqueue(4, q);
	enqueue(5, q);
	for (int i = 0; i < MAX_SIZE;i++ ) {
		printf("%d\n",q->array[i]);
	}
	dequeue(q);
	for (int i = 1; i < MAX_SIZE; i++) {
		printf("%d\n", q->array[i]);
	}
	free(q);
	q = NULL;
	return 0;
}

