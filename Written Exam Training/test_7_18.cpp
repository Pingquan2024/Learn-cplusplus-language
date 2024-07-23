/* 游游的水果大礼包 */
//#include <iostream>
//
//using namespace std;
//
//long long n, m, a, b, ret;
//
//int main()
//{
//	cin >> n >> m >> a >> b;
//
//	for (long long x = 0; x <= min(n / 2, m); x++)
//	{
//		long long  y = min(n - 2 * x, (m - x) / 2);
//		ret = max(ret, a * x + b * y);	// 每次最大值在ret里面放着
//	}
//
//	cout << ret << endl;
//
//	return 0;
//}

	/* 买卖股票的最大利润2 */
//#include <iostream>
//
//using namespace std;
//
//const int N = 1e5 + 10;
//
//int n, arr[N], ret;
//
//int main()
//{
//    cin >> n;
//    for (int i = 0; i < n; i++)  cin >> arr[i];
//
//    // 贪心
//    for (int i = 1; i < n; i++)
//    {
//        if (arr[i] > arr[i - 1])
//        {
//            ret += arr[i] - arr[i - 1];     // ret统计的是利润
//        }
//    }
//
//    cout << ret << endl;
//
//    return 0;
//}

	/* OR62 倒置字符串 */
//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//string s;
//
//int main()
//{
//    getline(cin, s);
//
//    reverse(s.begin(), s.end());
//
//    int n = s.size(), left = 0;
//    while (left < n)
//    {
//        int right = left;
//        while (right < n && s[right] != ' ')   // 找单词
//        {
//            right++;
//        }
//
//        // 到这说明已经遇到空格了，找完一个单词了
//        reverse(s.begin() + left, s.begin() + right);
//
//        // 可能单词间会有多个空格，跳过该空格
//        while (right < n && s[right] == ' ')
//        {
//            right++;
//        }
//
//        // 然后把right给left，继续找下一个单词
//        left = right;
//    }
//
//    cout << s << endl;
//
//    return 0;
//}
