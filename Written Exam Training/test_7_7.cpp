//#include <iostream>
//
//using namespace std;
// 
//	��L,R�����ֵĴ���
// 
//int main()
//{
//    int L, R;
//    int count = 0;
//    cin >> L >> R;
//
//    while (L <= R)
//    {
//        int tmp = L;
//        while (tmp != 0)
//        {
//            if (tmp % 10 == 2)
//            {
//                tmp /= 10;
//                count++;
//            }
//            else
//            {
//                tmp /= 10;
//            }
//        }
//
//        L++;
//    }
//
//    cout << count << endl;
//
//    return 0;
//}


#include <vector>

using namespace std;

// ��������Ľ���

//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param nums1 int����vector
//     * @param nums2 int����vector
//     * @return int����vector
//     */
//
//    vector<int> inse(vector<int>& nums)
//    {
//        for (int i = 0; i < nums.size() - 1; i++)
//        {
//            for (int j = 0; j < nums.size() - i - 1; j++)
//            {
//                if (nums[j] > nums[j + 1])
//                {
//                    int tmp = nums[j];
//                    nums[j] = nums[j + 1];
//                    nums[j + 1] = tmp;
//                }
//            }
//        }
//        return nums;
//    }
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
//    {
//        vector<int> ret;
//
//        inse(nums1);
//        inse(nums2);
//
//        int i = 0;
//        int j = 0;
//        while (i < nums1.size() && j < nums2.size())
//        {
//            if (nums1[i] == nums2[j])
//            {
//                ret.push_back(nums1[i]);
//                i++;
//                j++;
//            }
//            else if(nums1[i] < nums2[j])
//            {
//                i++;
//            }
//            else if (nums1[i] > nums2[j])
//            {
//                j++;
//            }
//        }
//
//        //ret.push_back(0);
//        return ret;
//
//    }
//};

//class Solution
//{
//    bool hash[1010] = { 0 };
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
//    {
//        vector<int> ret;
//        for (auto x : nums1)
//        {
//            hash[x] = true;
//        }
//
//        for (auto x : nums2)
//        {
//            if (hash[x])
//            {
//                ret.push_back(x);
//                hash[x] = false;
//            }
//        }
//        return ret;
//    }
//};
//
//
//int main()
//{
//    vector<int> nums1;
//    vector<int> nums2;
//
//    nums1.push_back(1);
//    nums1.push_back(2);
//
//    nums2.push_back(2);
//    nums2.push_back(2);
//    nums2.push_back(2);
//    nums2.push_back(2);
//
//    vector<int> ret = Solution().intersection(nums1, nums2);
//
//    for (auto e : ret)
//    {
//        printf("%d ", e);
//    }
//
//    return 0;
//}


//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//    string s;
//    cin >> s;
//    char array[300001];
//
//    int s_len = 0;
//    for (auto e : s)
//        if (s_len && e == array[s_len - 1])
//        {
//            s_len--;
//        }
//        else
//        {
//            array[s_len++] = e;
//        }
//
//    array[s_len] = '\0';
//
//    s_len ? cout << s : cout << 0;
//
//}


//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	string s, st;		// st ģ��ջ�ṹ
//	cin >> s;
//
//	for (auto e : s)
//	{
//		if (!st.empty() && st.back() == e)
//		{
//			st.pop_back();
//		}
//		else
//		{
//			st += e;	// string ׷��
//		}
//	}
//
//	cout << (st.size() == 0 ? "0" : st) << endl; //�ж��Ƿ�Ϊ��
//
//	return 0;
//}