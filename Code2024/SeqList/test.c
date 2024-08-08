#include "SeqList.h"

void TestSeqList1()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPushBack(&s, 6);
	SLPushBack(&s, 6);
	SLPushBack(&s, 6);
	SLPrint(&s);

	SLDestroy(&s);
}

void TestSeqList2()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushFront(&s, 5);
	SLPushFront(&s, 6);
	SLPushFront(&s, 6);
	SLPushFront(&s, 7);
	SLPushFront(&s, 6);
	SLPrint(&s);

	SLDestroy(&s);
}

void TestSeqList3()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushFront(&s, 5);
	SLPushFront(&s, 6);
	SLPrint(&s);

	SLPopBack(&s);
	SLPopBack(&s);
	SLPrint(&s);

	SLPopBack(&s);
	SLPopBack(&s);
	SLPrint(&s);

	SLPopBack(&s);
	SLPopBack(&s);
	//SLPopBack(&s);
	SLPrint(&s);

	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPrint(&s);

	SLDestroy(&s);
}

void TestSeqList4()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPrint(&s);

	SLPopFront(&s);
	SLPopFront(&s);
	SLPrint(&s);

	SLPopFront(&s);
	SLPopFront(&s);
	SLPrint(&s);

	//SLPopFront(&s);
	//SLPopFront(&s);
	//SLPrint(&s);

	SLDestroy(&s);
}

void TestSeqList5()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPrint(&s);

	SLInsert(&s, 2, 15);
	SLPrint(&s);

	//SLInsert(&s, 20, 30);
	//SLPrint(&s);

	//SLInsert(&s, -20, 30);
	//SLPrint(&s);

	SLErase(&s, 3);
	SLPrint(&s);

	SLPopFront(&s);
	SLPrint(&s);

	SLPopBack(&s);
	SLPrint(&s);

	SLDestroy(&s);
}

void TestSeqList6()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPrint(&s);

	int pos = SLFind(&s, 6);
	if (pos != -1)
	{
		SLErase(&s, pos);
	}
	SLPrint(&s);

	SLDestroy(&s);
}

void TestSeqList7()
{
	//SL* s = NULL;
	//SLPushBack(s, 1);
	//SLPushBack(s, 2);
	////SLPushBack(s, 3);
	//SLPrint(s);

	//SLDestroy(s);
}

int main()
{
	// TestSeqList1();
	// TestSeqList2();
	// TestSeqList3();
	// TestSeqList4();
	// TestSeqList5();
	// TestSeqList6();
	TestSeqList7();

	return 0;
}





