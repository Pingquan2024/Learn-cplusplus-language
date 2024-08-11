//#include <iostream>
//#include <string>
//
//using namespace std;
//
//string str1, str2;
//int ret;
//
//int main()
//{
//    cin >> str1 >> str2;
//    int len1 = str1.size(), len2 = str2.size();
//    ret = len1;
//    for (int i = 0; i <= len2 - len1; i++)
//    {
//        int tmp = 0;
//        for (int j = 0; j < len1; j++)
//        {
//            if (str1[j] != str2[i + j])
//            {
//                tmp++;
//            }
//        }
//        ret = min(ret, tmp);
//    }
//
//    cout << ret << endl;
//
//    return 0;
//}


//#include <iostream>
//
//using namespace std;
//
//int n;
//int arr[50];
//long long ret;
//
//int main()
//{
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> arr[i];
//    }
//
//    // long long gcd(long long a, long long b)
//    // {
//    //     gcd(b, a % b);
//    //     if(a == 0)
//    //     {
//    //         return b;
//    //     }
//    // }
//
//    // 最小公倍数是否是2的倍数
//    for (int i = 0; i < n; i++)
//    {
//        ret *= arr[i];  // 累乘
//    }
//
//    if (ret % 2 == 0)
//    {
//        cout << "YES";
//    }
//    else
//    {
//        cout << "NO";
//    }
//
//    return 0;
//}


//#include <functional>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int v, n;
//const int N = 30;
//vector<int> ve;
//
//int main()
//{
//    cin >> v >> n;
//    for (int i = 0; i < n; i++)
//    {
//        int x = 0;
//        cin >> x;
//        ve.push_back(x);
//    }
//
//    sort(ve.begin(), ve.end());
//
//    size_t actv = 0;
//    while (actv < v)
//    {
//        if (actv + ve.front() < v)
//        {
//            actv += ve.front();
//            ve.erase(ve.begin());
//        }
//        else
//        {
//            break;
//        }
//    }
//
//    cout << v - actv << endl;
//
//    return 0;
//}