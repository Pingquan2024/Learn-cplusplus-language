	/* 最长回文子串 */
//class Solution
//{
//public:
//
//    int getLongestPalindrome(string A)
//    {
//        int n = A.size(), ret1 = 0, ret2 = 0;
//
//        for (int i = 0; i < n; i++)
//        {
//            int left = i - 1, right = i + 1;
//            while (left >= 0 && right < n && A[left] == A[right])
//            {
//                left--;
//                right++;
//            }
//
//            ret1 = max(ret1, right - left - 1);
//
//            left = i, right = i + 1;
//            while (left >= 0 && right < n && A[left] == A[right])
//            {
//                left--;
//                right++;
//            }
//
//            ret2 = max(ret2, right - left - 1);
//        }
//
//        return max(ret1, ret2);
//    }
//};


	/* 买卖股票的最好时机(一) */
//#include <iostream>
//
//using namespace std;
//
//int n;
//const int N = 1e5 + 10;
//int prices[N];
//
//int main()
//{
//    cin >> n;
//    for (int i = 0; i < n; i++)  cin >> prices[i];
//
//    int ret = 0, PrevMin = prices[0];
//
//    for (int i = 1; i < n; i++)
//    {
//        PrevMin = min(prices[i], PrevMin);
//        ret = max(ret, prices[i] - PrevMin);
//    }
//
//    cout << ret << endl;
//
//    return 0;
//}

	/* 过河卒 */
//#include <iostream>
//
//using namespace std;
//
//int n, m, x, y;
//long long dp[25][25];
//
//int main()
//{
//    cin >> n >> m >> x >> y;
//
//    x += 1; y += 1;
//    dp[0][1] = 1;
//
//    for (int i = 1; i <= n + 1; i++)
//    {
//        for (int j = 1; j <= m + 1; j++)
//        {
//            if (i != x && j != y && abs(i - x) + abs(j - y) == 3 || (i == x && j == y))
//            {
//                dp[i][j] = 0;
//            }
//            else
//            {
//                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//            }
//        }
//    }
//
//    cout << dp[n + 1][m + 1] << endl;
//
//    return 0;
//}