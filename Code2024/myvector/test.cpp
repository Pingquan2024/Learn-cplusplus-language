
#include "myvector.h"
using namespace std;

void test_vector()
{
	vector<int> v1;           //构造int类型的空容器
	vector<int> v2(10, 2);    //构造含有10个2的int类型容器
	vector<int> v3(v2);       //拷贝构造int类型的v2容器的复制品
	vector<int> v4(v2.begin(), v2.end());  //使用迭代器拷贝构造v2容器的某一段内容

	cout << v4.size() << endl;             //10
	cout << v4.capacity() << endl;         //10

	v4.reserve(20);						   //改变容器的capacity为20，size不变
	cout << "v4的size为：" << v4.size() <<" "<< "v4的capacity为：" << v4.capacity() << endl;
	v4.reserve(10);                        //小于容器当前的capacity时，什么也不做。capacity，size不变
	cout << "v4的size为：" << v4.size() <<" "<< "v4的capacity为：" << v4.capacity() << endl;

	v4.resize(15);                         //改变容器的size为15
	cout << "v4的size为：" << v4.size() <<" "<< "v4的capacity为：" << v4.capacity() << endl;
	v4.resize(10);                         //小于容器当前的size时，将size缩小到该值。改变容器的size为10
	cout << "v4的size为：" << v4.size() <<" "<< "v4的capacity为：" << v4.capacity() << endl;

	cout << v2.empty() << endl;             //通过empty函数来判断当前容器是否为空，返回值为bool型 

	vector<int> v;            
	v.push_back(1);                         //尾插元素1
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vector<int>::iterator it = v.begin();               //正向迭代器
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	vector<int>::reverse_iterator rit = v.rbegin();     //反向迭代器
	while (rit != v.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

	v.pop_back();                           //尾删元素1
	v.pop_back();
	v.pop_back();

	v.insert(v.begin(), 0);                 //在容器开头插入0
	v.insert(v.begin(), 4, -1);             //在容器开头插入3个-1

	v.erase(v.begin() + 1);                 //删除第2个位置的元素
	v.erase(v.begin(), v.begin() + 2);      //删除该迭代区间的元素
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int>::iterator pos = find(v.begin(), v.end(), 2);  //获取值为2的元素的迭代器
	v.insert(pos, 10);                                        //在2的位置插入10
	pos = find(v.begin(), v.end(), 10);                       //重新获取位置，防止迭代器失效
	v.erase(pos);                                             //删除10
	for (auto e : v)
	{
		cout << e << " ";
	}

	v.push_back(3);                         //尾插元素
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.swap(v2);                             //交换两个容器的数据空间，交换v,v2的数据空间
	/*数据个数不一样也能完成交换*/

	//使用“下标+[]”的方式遍历容器
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	//支持迭代器就支持范围for
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////
/*迭代器失效案例一*/
#if 0
void test_vector2()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	//v: 1 2 3 4 5
	vector<int>::iterator pos = find(v.begin(), v.end(), 2); //获取值为2的元素的迭代器
	v.insert(pos, 10);                                       //在值为2的元素的位置插入10
	//v: 1 10 2 3 4 5
	v.erase(pos);                                            //删除元素2？error（迭代器失效）
	//v: 1 2 3 4 5
}
#endif

/*迭代器失效实例二*/
#if 0
void test_vector3()
{
	vector<int> v;
	for (int i = 1; i <= 6; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0) //删除容器当中的全部偶数
		{
			v.erase(it);
		}
		it++;
	}
}
#endif

//////////////////////////////////////////////////////////////////////////////////////////////
/*实例一解决方法*/
#if 1
void test_vector2()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	//v: 1 2 3 4 5
	vector<int>::iterator pos = find(v.begin(), v.end(), 2); //获取值为2的元素的迭代器
	v.insert(pos, 10);                                       //在值为2的元素的位置插入10
	//v: 1 10 2 3 4 5
	pos = find(v.begin(), v.end(),10);
	v.erase(pos);                                            //删除元素
	//v: 1 2 3 4 5
}
#endif 

/*实例二解决方法*/
#if 1
void test_vector3()
{
	vector<int> v;
	for (int i = 1; i <= 6; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0) //删除容器当中的全部偶数
		{
			it = v.erase(it); //删除后获取下一个元素的迭代器
		}
		else
		{
			it++; //是奇数则it++
		}
	}
}
#endif

int main()
{
	//test_vector();
	//test_vector2();
	//test_vector3();

	return 0;
}