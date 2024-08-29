//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int ret1, ret2;
//string str1, str2;
//
//int main()
//{
//    cin >> str1 >> str2;
//
//    // 目标计算最少编辑次数
//
//    int hash1[60] = { 0 };
//    int hash2[60] = { 0 };
//
//    // 计算一下不同的字符有几个
//    for (int i = 0; i < max(str1.size(), str2.size()); i++)
//    {
//        if (i < str1.size())
//        {
//            hash1[str1[i] - 'A']++;
//        }
//
//        if (i < str2.size())
//        {
//            hash2[str2[i] - 'A']++;
//        }
//    }
//
//    for (int i = 0; i < max(str1.size(), str2.size()); i++)
//    {
//        if (hash1[str1[i] - 'A'] > hash2[str2[i] - 'A'])
//        {
//            ret1 += hash1[str1[i] - 'A'] - hash2[str2[i] - 'A'];
//        }
//
//        if (hash1[str1[i] - 'A'] < hash2[str2[i] - 'A'])
//        {
//            ret2 += hash2[str2[i] - 'A'] - hash1[str1[i] - 'A'];
//        }
//
//    }
//
//    cout << ret1 + ret2 << endl;
//    return 0;
//}



//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int n, m, sum;
//vector<vector<int>> ve;
//vector<int> v;

//int main()
//{
//    cin >> n >> m;
//
//    int left = 1, right = 1, retLen = 100;
//    int retLeft = -1, retRight = -1;
//
//    while (right < n)
//    {
//        sum += right;
//        while (sum >= m)
//        {
//            // if(right - left < retLen)
//            // {
//            //     retLeft = left;
//            //     retRight = right;
//            //     retLen = retRight - retLeft;
//            // }
//
//            if (sum == m)
//            {
//                for (int k = left; k <= right; k++)
//                {
//                    v.push_back(k);
//                }
//            }
//            sum -= left;
//            left++;
//        }
//        right++;
//    }
//    return 0;
//}


//int main()
//{
//    cin >> n >> m;
//
//    int left = 1, right = n, retLen = 100;
//    int retLeft = -1, retRight = -1;
//
//    while (left != right)
//    {
//        sum += left + right;
//        v.push_back(left);
//        v.push_back(right);
//
//        while (sum >= m)
//        {
//            // if(right - left < retLen)
//            // {
//            //     retLeft = left;
//            //     retRight = right;
//            //     retLen = retRight - retLeft;
//            // }
//    
//            sum -= right;
//            v.pop_back();
//            // left++;
//        }
//        right--;
//    }
//
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//int main() 
//{
//    int n;
//    while (cin >> n) 
//    {
//        int times = 1, begin = 0;
//        while (n != 1) 
//        {
//            begin = begin + pow(2, (times - 1));
//            n /= 2;
//            times++;
//        }
//        cout << begin << endl;
//    }
//    return 0;
//}
