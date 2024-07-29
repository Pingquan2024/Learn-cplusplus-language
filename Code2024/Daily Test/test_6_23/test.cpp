#include "iostream"
#include "stdio.h"
#include "vector"

using namespace std;

//int target;
//vector<vector<int>> array1(5, vector<int>(5));
//
//class Solution
//{
//public:
//    bool Find(int target, vector<vector<int>> array)
//    {
//        int i = 0;
//        int j = array[0].size() - 1;
//
//        while (i < array.size() && j >= 0)
//        {
//            if (target > array[i][j])
//            {
//                i++;
//            }
//            else if (target < array[i][j])
//            {
//                j--;
//            }
//            else
//            {
//                return true;
//            }
//        }
//
//        return false;
//    }
//};

//int main()
//{
//    cin >> target;
//    for (int i = 0; i < 5; i++)
//    {
//        for (int j = 0; j < 5; j++)
//        {
//            cin >> array1[i][j];
//        }
//    }
//
//    Solution s;
//    bool ret = s.Find(target, array1);
//    cout << ret << endl;
//}



//class Solution
//{
//public:
//    int minNumberInRotateArray(vector<int> array)
//    {
//        if (array.empty())      // 如果容器大小为0，则为 true，否则为 false。
//        {
//            return 0;
//        }
//
//        int left = 0, right = array.size() - 1;
//        int mid = 0;
//
//        while (array[left] >= array[right])
//        {
//            if (right - left == 1)
//            {
//                mid = right;
//                break;
//            }
//
//            mid = (right + left) >> 1;
//
//            if (array[left] == array[right] && array[right] == array[mid])
//            {
//                int result = array[left];
//                for (int i = left + 1; i < right; i++)
//                {
//                    if (result > array[left])
//                    {
//                        result = array[left];
//                    }
//                }
//                return result;
//            }
//
//            if (array[mid] >= array[left])
//            {
//                left = mid;
//            }
//            else
//            {
//                right = mid;
//            }
//        }
//
//        return array[mid];
//    }
//};
//
//int main()
//{
//    vector<int> array;
//    int n;
//    while (cin >> n)
//    {
//        array.push_back(n);
//    }
//
//    Solution s;
//    int ret = s.minNumberInRotateArray(array);
//    cout << ret << endl;
//    return 0;
//}

// 实现一个类，计算程序中创建出了多少个类对象。
//class A
//{
//public:
//	A(int a = 0)
//	{
//		++count;
//	}
//
//	A(const A& aa)
//	{
//		++count;
//	}
//
//	// 静态成员函数 -- 没有this指针
//	static int GetCount()
//	{
//		// _a++; // 不能直接访问非静态成员
//		return count;
//	}
//
//private:
//	// 不属于某个对象，所于所有对象，属于整个类
//	static int count; // 声明
//
//	int _a = 0;
//};
//
//int A::count = 0; // 定义初始化

//void func()
//{
//	A aa1;
//	A aa2(aa1);
//	A aa3 = 1;
//
//	A aa4[10];
//}

//int main()
//{
//	func();
//
//	//cout << A::count << endl;
//	//cout << aa2.count << endl;
//	//cout << aa3.count << endl;
//	//A* ptr = nullptr;
//	//cout << ptr->count << endl;
//
//	//A aa;
//	//cout << aa.GetCount()-1 << endl;
//	cout << A::GetCount()<< endl;
//
//	return 0;
//}

class Solution
{
public:
	vector<int> reOrderArrayTwo(vector<int>& array)
	{
		// if(array.empty())
		// {
		//     return nullptr;
		// }

		int k = 0;
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i] & 1)
			{
				// 奇数
				int temp = array[i];
				int j = i;
				while (j > k)
				{
					// 偶数后移
					array[j] = array[j - 1];
					j--;
				}
				array[k++] = temp;     // 插入奇数
			}
		}

		return array;
	}
};

int main()
{
	vector<int> array = { 11,22,33,44,55,66 };
	vector<int> ret = Solution().reOrderArrayTwo(array);
	for (auto e : array)
	{
		cout << e << " ";
	}
	return 0;
}