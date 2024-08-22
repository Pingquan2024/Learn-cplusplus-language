/* 平方数 */
//#include <iostream>
//
//using namespace std;
//
//int x, y, minVal = 10000000;
//
//int main()
//{
//    cin >> x;
//    int a = 0;
//
//    while ((x - a * a) < minVal && minVal >= 0)
//    {
//        minVal = x - a * a;
//        a++;
//    }
//
//
//    cout << a << endl;
//
//    return 0;
//}

/* 平方数 */
//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//typedef long long LL;
//
//LL x;
//
//int main()
//{
//    cin >> x;
//    LL a = sqrt(x);
//    LL y1 = a * a, y2 = (a + 1) * (a + 1);
//    if (x - y1 < y2 - x) cout << y1 << endl;
//    else cout << y2 << endl;
//}


/* 分组 */
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//int n, m, ret, count1;
//const int N = 1e5 + 10;
//int arr[N];
//
//int main()
//{
//    // n 个同学分成 m 组
//    cin >> n >> m;
//
//    int number = n / m;
//    int highVoicer = 0; // 出现最多的声部是什么
//    int maxVoicer = 0;  // 最多的声部有几个人
//    int minVoicer = 100000;
//
//    int hash[N] = { 0 };
//
//    for (int i = 0; i < n; i++)
//    {
//        cin >> arr[i];
//        if (++hash[arr[i]] > maxVoicer)
//        {
//            // 统计出每个声部有多少人
//            highVoicer = arr[i];
//            maxVoicer = hash[arr[i]];
//        }
//
//        if (hash[arr[i]] < minVoicer)
//        {
//            minVoicer = hash[arr[i]];
//        }
//    }
//
//    // 总共有ret个声部
//    for (int i = 0; i < n; i++)
//    {
//        if (hash[i])
//        {
//            count1 += 1;
//        }
//    }
//
//    if (count1 < n / m)
//    {
//        ret = minVoicer;
//    }
//    else if (count1 > n / m)
//    {
//        ret = -1;
//    }
//    else
//    {
//        ret = minVoicer;
//    }
//
//    cout << ret << endl;
//
//    return 0;
//}


/* 分组 */
//#include <iostream>
//#include <unordered_map>
//
//using namespace std;
//
//int n, m;
//unordered_map<int, int> myMap;
//
//bool check(int i)
//{
//    int g = 0; // 能分成多少组
//    for (auto& [a, b] : myMap)
//    {
//        g += b / i + (b % i == 0 ? 0 : 1);
//    }
//
//    return g <= m;
//}
//
//int main()
//{
//    cin >> n >> m;
//    int hmax = 0; // 代表声部最多的人数
//    for (int i = 0; i < n; i++)
//    {
//        int x = 0;
//        cin >> x;
//        hmax = max(hmax, ++myMap[x]);
//    }
//
//    int sz = myMap.size();
//    if (sz > m)
//    {
//        cout << -1 << endl;
//    }
//    else
//    {
//        // 枚举最后的结果中，最多的人数
//        for (int i = 1; i < hmax; i++)
//        {
//            if (check(i))
//            {
//                cout << i << endl;
//                break;
//            }
//        }
//    }
//    return 0;
//}

