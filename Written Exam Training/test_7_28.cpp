//#include <cctype>
//class Solution
//{
//public:
//    string str;
//
//    string compressString(string param)
//    {
//        int n = param.size();
//        // int hash[53] = { 0 };
//        // for(int i = 0; i < n; i++)
//        // {
//        //     if(param[i] >= 'a' && param[i] <= 'z')
//        //     {
//        //         hash[param[i] - 'a']++;
//        //     }
//        //     // 'a' 97   'A' 65
//        //     hash[param[i] - 39]++;  // 统计每个字母出现的次数
//        // }
//
//        int count = 1;
//        for (int i = 0; i < n; i++)
//        {
//            char tmp = param[i];
//            if (param[i + 1] != tmp)
//            {
//                str += tmp;
//                if (count != 1)
//                {
//                    str += count + '0';
//                    count = 1;
//                }
//            }
//            else
//            {
//                count++;
//            }
//        }
//        return str;
//    }
//};

//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//class Solution
//{
//public:
//    int knapsack(int V, int n, vector<vector<int>>& vw)
//    {
//        // 能装V个体积，现有n个物品
//
//        int actualV = 0, ret = 0;
//        vector<int> v;
//        for (int i = 0; i < n; i++)
//        {
//            v.push_back(vw[i][i]);
//        }
//        sort(v.begin(), v.end());
//
//
//        for (int i = 0; i < n; i++)
//        {
//            while (actualV < V)
//            {
//                actualV += v[i];
//            }
//        }
//    }
//};
