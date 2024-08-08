#include "SeqList.h"

void SLCheckCapacity(SL* ps1)
{
	if (ps1->size == ps1->capacity)
	{
		SLDataType* tmp = (SLDataType*)realloc(ps1->arr, ps1->capacity * sizeof(SLDataType) * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps1->arr = tmp;
		ps1->capacity *= 2;
	}

}
void SLInit(SL* ps1)
{
	assert(ps1);
	ps1->arr = (SLDataType*)malloc(sizeof(SLDataType) * 4);	// 一次性开4个
	if (ps1->arr == NULL)
	{
		perror("malloc fail");
		return;
	}

	ps1->size = 0;
	ps1->capacity = 4;
}

void SLDestroy(SL* ps1)
{

	free(ps1->arr);
	ps1->arr = NULL;
	ps1->size = 0;
	ps1->capacity = 0;
}

void SLPushBack(SL* ps1, SLDataType x)
{
	assert(ps1);
	SLCheckCapacity(ps1);
	ps1->arr[ps1->size] = x;

	ps1->size++;
}

void SLPushFront(SL* ps1, SLDataType x)
{
	assert(ps1);
	SLCheckCapacity(ps1);

	int tmp = ps1->size + 1;
	while (tmp--)
	{
		ps1->arr[tmp + 1] = ps1->arr[tmp];
	}

	ps1->arr[0] = x;
	ps1->size++;
}

void SLPopBack(SL* ps1)
{
	assert(ps1);
	assert(ps1->size != 0);
	ps1->arr[ps1->size] = 0;
	ps1->size--;
}

void SLPopFront(SL* ps1)
{
	assert(ps1);

	int tmp = ps1->size;
	for (int i = 0; i < tmp; i++)
	{
		ps1->arr[i] = ps1->arr[i + 1];
	}

	ps1->size--;
}

void SLPrint(SL* ps1)
{
	assert(ps1);

	for (int i = 0; i < ps1->size; i++)
	{
		printf("%d ", ps1->arr[i]);
	}
	printf("\n");
}


void SLInsert(SL* ps1, int pos, SLDataType x)
{
	assert(ps1);
	assert(pos >= 0 && pos <= ps1->size);

	SLCheckCapacity(ps1);
	int end = ps1->size - 1;
	while (end >= pos)	// 把pos后边的都挪开
	{
		ps1->arr[end + 1] = ps1->arr[end];
		--end;
	}
	ps1->size++;

	ps1->arr[pos] = x;
}

void SLErase(SL* ps1, int pos)
{
	assert(ps1);
	assert(pos < ps1->size);

	int start = pos + 1;
	while (start < ps1->size)
	{
		ps1->arr[start - 1] = ps1->arr[start];
		++start;
	}

	ps1->size--;
}

int SLFind(SL* ps1, SLDataType x)
{
	assert(ps1);

	for (int i = 0; i < ps1->size; i++)
	{
		if (ps1->arr[i] == x)
		{
			printf("%s[%d]\n", "您要找的数据下标为: ", i);
			return i;
		}
	}

	return -1;
}

void SLModify(SL* ps1, int pos, SLDataType x)
{
	assert(ps1);

	assert(pos >= 0 && pos < ps1->size);

	ps1->arr[pos] = x;
}