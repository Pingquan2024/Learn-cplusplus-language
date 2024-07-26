	/* 乒乓球筐 */
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//string s, t;
//int arr[27] = { 0 };
//
//
//int main()
//{
//    cin >> s >> t;
//    int count = t.size();
//    for (auto e : t)
//    {
//        arr[e - 65] += 1;    // 在hash1数组中e位置标记
//    }
//
//    string ret;
//    for (int i = 0; i < s.size(); i++)
//    {
//        int j = i;
//        while (j < s.size())
//        {
//            if (!arr[(s[j] - 65)])
//            {
//                // 不存在
//                j++;
//            }
//            else
//            {
//                // 存在
//                arr[(s[j] - 65)] -= 1;
//                j++;
//                count--;
//            }
//        }
//        i = j;
//    }
//
//    if (count == 0)
//    {
//        cout << "Yes";
//    }
//    else
//    {
//        cout << "No";
//    }
//
//    return 0;
//}


	/* 乒乓球筐 */
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//string str, s;
//
//int main()
//{
//	while (cin >> str >> s)	// w
//	{
//		int hash[26] = { 0 };
//		for (auto ch : str)
//		{
//			hash[ch - 'A']++;
//		}
//		bool ret = true;
//
//		for (auto ch : s)
//		{
//			if (--hash[ch - 'A'] < 0)
//			{
//				ret = false;
//				break;
//			}
//		}
//
//		cout << (ret ? "Yes" : "No") << endl;
//	}
//	return 0;
//}

	/* 组队竞赛 */
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int n, n1, ret;
//const int N = 1e5 + 10;
//vector<int> v;
//
//// 排完序
//// 第一组： 倒数第二大 最大值
//// 第二组： 倒数第四大 倒数第三大
//// ...
//
//int main()
//{
//    cin >> n;       // n个队伍
//    for (int i = 0; i < 3 * n; i++)
//    {
//        n1 = 0;
//        cin >> n1;
//        v.push_back(n1);
//    }
//
//    sort(v.begin(), v.end());   // 从大到小
//    sort(v.begin(), v.end());   // 从小到大
//
//    while (n--)
//    {
//        v.pop_back();
//        ret += v.back();
//        v.pop_back();
//    }
//
//    cout << ret << endl;
//}

	/* 组队竞赛 */
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long LL;
//const int N = 1e5 + 10;
//int n;
//LL arr[N * 3];
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < 3 * n; i++)
//	{
//		cin >> arr[i];
//	}
//
//	sort(arr, arr + 3 * n);
//
//	int pos = 3 * n - 2, count = 1;
//	LL ret = 0;
//	while (count++ <= n)
//	{
//		ret += arr[pos];
//		pos -= 2;
//	}
//
//	cout << ret << endl;
//
//	return 0;
//}

	/* 删除相邻数字的最大分数 */
//#include <cstdio>
//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int n, ret = 1;
//const int N = 1e5 + 10;
//bool vis[N] = { 0 };
//string s;
//
//int main()
//{
//    cin >> n;
//    getline(cin, s);
//
//    sort(s.begin(), s.end());   // 从大到小
//
//    for (int i = 1; i < n; i++)
//    {
//        if (s[i] != ' ')
//        {
//            if (s[i - 1] + 1 == s[i] && s[i] + 1 == s[i + 1])
//            {
//                if (!vis[s[i]])
//                {
//                    ret += s[i];
//                    vis[s[i]] = vis[s[i - 1]] = vis[s[i + 1]] == true;
//                }
//
//            }
//        }
//
//    }
//
//		// err 
//    cout << ret << endl;
//}


	/* 删除相邻数字的最大分数 */
//#include <iostream>
//
//using namespace std;
//
//const int N = 1e4 + 10;
//int sum[N];	// sum[i] 表示 i 出现的总和
//int n;
//int f[N], g[N];
//
//int main()
//{
//	cin >> n;
//	int x;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> x;
//		sum[x] += x;
//	}
//
//	for (int i = 1; i < N; i++)
//	{
//		f[i] = g[i - 1] + sum[i];
//		g[i] = max(f[i - 1], g[i - 1]);
//	}
//
//	cout << max(f[N - 1], g[N - 1]) << endl;
//
//	return 0;
//}