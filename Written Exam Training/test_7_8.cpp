//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//double a;
//char b;
//int ret;
//
//int main()
//{
//    cin >> a >> b;
//
//    if (a <= 1)
//    {
//        ret += 20;
//    }
//    else
//    {
//        ret = 20 + ceil(a - 1);
//    }
//
//    if (b == 'y') ret += 5;
//
//    cout << ret << endl;
//
//    return 0;
//}


//#include <iostream>
//
//using namespace std;
//
//const int N = 1e5 + 10;
//
//int n;
//int cost[N];
//int dp[N];
//int ret;
//
//int main()
//{
//    cin >> n;
//    for (int i = 0; i < n; i++)  cin >> cost[i];
//
//    for (int i = 2; i <= n; i++)
//    {
//        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//    }
//
//    cout << dp[n] << endl;
//
//    return 0;
//}


//#include <iostream>
//#include <cstring>
//using namespace std;
//
//string s1, s2;
//string s;
//int n;
//int ret = 0xfffffff;
//
//int main()
//{
//    cin >> n;
//    cin >> s1 >> s2;
//    int prev1 = -1;
//    int prev2 = -1;
//
//    for (int i = 0; i < n; i++)
//    {
//        cin >> s;
//
//        if (s == s1)
//        {
//            if (prev2 != -1)
//            {
//                ret = min(ret, i - prev2);
//            }
//            prev1 = i;
//        }
//
//        if (s == s2)
//        {
//            if (prev1 != -1)
//            {
//                ret = min(ret, i - prev1);
//            }
//            prev2 = i;
//        }
//    }
//
//    if (prev1 == -1 || prev2 == -1)
//    {
//        cout << -1 << endl;
//    }
//    else
//    {
//        cout << ret << endl;
//    }
//
//    return 0;
//}