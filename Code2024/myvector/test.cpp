
#include "myvector.h"
using namespace std;

void test_vector()
{
	vector<int> v1;           //����int���͵Ŀ�����
	vector<int> v2(10, 2);    //���캬��10��2��int��������
	vector<int> v3(v2);       //��������int���͵�v2�����ĸ���Ʒ
	vector<int> v4(v2.begin(), v2.end());  //ʹ�õ�������������v2������ĳһ������

	cout << v4.size() << endl;             //10
	cout << v4.capacity() << endl;         //10

	v4.reserve(20);						   //�ı�������capacityΪ20��size����
	cout << "v4��sizeΪ��" << v4.size() <<" "<< "v4��capacityΪ��" << v4.capacity() << endl;
	v4.reserve(10);                        //С��������ǰ��capacityʱ��ʲôҲ������capacity��size����
	cout << "v4��sizeΪ��" << v4.size() <<" "<< "v4��capacityΪ��" << v4.capacity() << endl;

	v4.resize(15);                         //�ı�������sizeΪ15
	cout << "v4��sizeΪ��" << v4.size() <<" "<< "v4��capacityΪ��" << v4.capacity() << endl;
	v4.resize(10);                         //С��������ǰ��sizeʱ����size��С����ֵ���ı�������sizeΪ10
	cout << "v4��sizeΪ��" << v4.size() <<" "<< "v4��capacityΪ��" << v4.capacity() << endl;

	cout << v2.empty() << endl;             //ͨ��empty�������жϵ�ǰ�����Ƿ�Ϊ�գ�����ֵΪbool�� 

	vector<int> v;            
	v.push_back(1);                         //β��Ԫ��1
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vector<int>::iterator it = v.begin();               //���������
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	vector<int>::reverse_iterator rit = v.rbegin();     //���������
	while (rit != v.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

	v.pop_back();                           //βɾԪ��1
	v.pop_back();
	v.pop_back();

	v.insert(v.begin(), 0);                 //��������ͷ����0
	v.insert(v.begin(), 4, -1);             //��������ͷ����3��-1

	v.erase(v.begin() + 1);                 //ɾ����2��λ�õ�Ԫ��
	v.erase(v.begin(), v.begin() + 2);      //ɾ���õ��������Ԫ��
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int>::iterator pos = find(v.begin(), v.end(), 2);  //��ȡֵΪ2��Ԫ�صĵ�����
	v.insert(pos, 10);                                        //��2��λ�ò���10
	pos = find(v.begin(), v.end(), 10);                       //���»�ȡλ�ã���ֹ������ʧЧ
	v.erase(pos);                                             //ɾ��10
	for (auto e : v)
	{
		cout << e << " ";
	}

	v.push_back(3);                         //β��Ԫ��
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.swap(v2);                             //�����������������ݿռ䣬����v,v2�����ݿռ�
	/*���ݸ�����һ��Ҳ����ɽ���*/

	//ʹ�á��±�+[]���ķ�ʽ��������
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	//֧�ֵ�������֧�ַ�Χfor
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////
/*������ʧЧ����һ*/
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
	vector<int>::iterator pos = find(v.begin(), v.end(), 2); //��ȡֵΪ2��Ԫ�صĵ�����
	v.insert(pos, 10);                                       //��ֵΪ2��Ԫ�ص�λ�ò���10
	//v: 1 10 2 3 4 5
	v.erase(pos);                                            //ɾ��Ԫ��2��error��������ʧЧ��
	//v: 1 2 3 4 5
}
#endif

/*������ʧЧʵ����*/
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
		if (*it % 2 == 0) //ɾ���������е�ȫ��ż��
		{
			v.erase(it);
		}
		it++;
	}
}
#endif

//////////////////////////////////////////////////////////////////////////////////////////////
/*ʵ��һ�������*/
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
	vector<int>::iterator pos = find(v.begin(), v.end(), 2); //��ȡֵΪ2��Ԫ�صĵ�����
	v.insert(pos, 10);                                       //��ֵΪ2��Ԫ�ص�λ�ò���10
	//v: 1 10 2 3 4 5
	pos = find(v.begin(), v.end(),10);
	v.erase(pos);                                            //ɾ��Ԫ��
	//v: 1 2 3 4 5
}
#endif 

/*ʵ�����������*/
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
		if (*it % 2 == 0) //ɾ���������е�ȫ��ż��
		{
			it = v.erase(it); //ɾ�����ȡ��һ��Ԫ�صĵ�����
		}
		else
		{
			it++; //��������it++
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