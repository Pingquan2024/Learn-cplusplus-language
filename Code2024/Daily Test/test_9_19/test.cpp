// ˼·1
//class HeapOnly
//{
//public:
//	void Destroy()
//	{
//		delete this;
//	}
//
//private:
//	~HeapOnly()
//	{
//		cout << "~HeapOnly()" << endl;
//	}
//
//	int _x;
//};
//
//int main()
//{
//	//HeapOnly ho1;
//	//static HeapOnly ho2;
//	HeapOnly* pho3 = new HeapOnly;
//	pho3->Destroy();
//
//	return 0;
//}