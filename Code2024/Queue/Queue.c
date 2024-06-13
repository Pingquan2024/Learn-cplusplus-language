#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);

	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* del = cur;
		cur = cur->next;

		free(del);
	}
}

void QueuePush(Queue* pq, QDataType x)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}

	newnode->data = x;
	newnode->next = NULL;

	if (pq->ptail == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}

	pq->size++;
}

void QueuePop(Queue* pq) 
{}

QDataType QueueFront(Queue* pq)
{}

QDataType QueueBack(Queue* pq)
{}

bool QueueEmpty(Queue* pq)
{}

int QueueSize(Queue* pq)
{}