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