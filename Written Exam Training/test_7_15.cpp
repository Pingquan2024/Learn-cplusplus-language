/* 最小公倍数*/
//#include <iostream>
//
//using namespace std;
//
//size_t a, b;
//
//size_t gcd(size_t a, size_t b)
//{
//    if (b == 0)
//    {
//        return a;
//    }
//
//    return gcd(b, a % b);
//}
//
//int main()
//{
//    cin >> a >> b;
//
//    cout << (a * b / gcd(a, b)) << endl;
//
//    return 0;
//}


//class Solution
//{
//public:
//    int MLS(vector<int>& arr)
//    {
//        sort(arr.begin(), arr.end());
//        int ret = 0, n = arr.size();
//
//        for (int i = 0; i < n;)
//        {
//            int j = i + 1, count = 1;
//            while (j < n)
//            {
//                if (arr[j] - arr[j - 1] == 1)
//                {
//                    count++;
//                    j++;
//                }
//                else if (arr[j] - arr[j - 1] == 0)
//                {
//                    j++;
//                }
//                else
//                {
//                    break;
//                }
//            }
//            ret = max(ret, count);
//            i = j;
//        }
//
//        return ret;
//    }
//};


//#include <iostream>
//
//using namespace std;
//
//int m, n;
//const int N = 510;
//char arr[N][N];
//int dp[N][N];
//
//int main()
//{
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            cin >> arr[i][j];
//        }
//    }
//
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            int t = 0;
//            if (arr[i][j] == 'l')    t = 4;
//            else if (arr[i][j] == 'o')   t = 3;
//            else if (arr[i][j] == 'v')   t = 2;
//            else if (arr[i][j] == 'e')   t = 1;
//            dp[i][j] = max(dp[i][j - 1] + t, dp[i - 1][j] + t);
//        }
//    }
//
//    cout << dp[n][m] << endl;
//
//    return 0;
//}