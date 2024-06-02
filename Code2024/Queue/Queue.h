#pragma once

#include <stdio.h>

typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
}Queue;
