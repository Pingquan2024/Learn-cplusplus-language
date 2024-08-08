#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* arr;
	int size;
	int capacity;
}SL;

void SLInit(SL* ps1);

void SLDestroy(SL* ps1);

void SLPushBack(SL* ps1, SLDataType x);

void SLPushFront(SL* ps1, SLDataType x);

void SLPopBack(SL* ps1);

void SLPopFront(SL* ps1);

void SLPrint(SL* ps1);

void SLInsert(SL* ps1, int pos, SLDataType x);

void SLErase(SL* ps1, int pos);

int SLFind(SL* ps1, SLDataType x);

void SLModify(SL* ps1, int pos, SLDataType x);