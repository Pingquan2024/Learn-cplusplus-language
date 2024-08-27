//#include <iostream>
//#include <string>
//
//using namespace std;
//
//string str;
//int ret = 2;
//
//int main()
//{
//	cin >> str;
//
//	// bool hash[26] = { 0 };
//
//	// int begin = -1, end = 0, len = -1;
//	// for (int i = 0; i < str.size(); i++)
//	// {
//	//     int j = i;
//	//     while (j < str.size() && hash[str[j] - 'a'] == )
//	//     {
//	//         hash[str[j] - 'a'] = true;
//	//         j++;
//	//         if (j - i > len)
//	//         {
//	//             begin = i;
//	//             len = j - i;
//	//         }
//	//     }
//	//     i = j;
//	// }
//	// cout << len << endl;
//
//	if (str.size() >= 2)
//	{
//		for (int i = 2; i < str.size();)
//		{
//			int j = i;
//
//			while (str[j] == str[j - 1] || str[j] == str[j - 2])
//			{
//				j++;
//			}
//
//			// 到这就代表不相等了
//			ret = j - i + 1;
//
//			i = j;
//		}
//	}
//	cout << ret << endl;
//	return 0;
//}


//#include <algorithm>
//
//class Solution
//{
//public:
//    vector<string> Permutation(string str)
//    {
//        int n = str.size();
//        string s;
//        vector<string> ret;
//
//        sort(str.begin(), str.end());
//        reverse(str.begin(), str.end());
//
//        do
//        {
//            for (int i = 0; i < n; i++)
//            {
//                s += str[i];
//            }
//            ret.push_back(s);
//            s.clear();
//
//        } while (prev_permutation(str.begin(), str.end()));
//
//        return ret;
//    }
//};