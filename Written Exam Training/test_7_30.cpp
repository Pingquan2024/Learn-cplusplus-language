//#include <iostream>
//#include <algorithm>
////#include <numeric.h>
////#include <bits/stdc++.h>
//
//using namespace std;
//
//int n, x;
//const int N = 1e5 + 10;
//long long arr[N];
//
//long long gcd(long long a, long long b)
//{
//    long long tmp;
//    while (b > 0)
//    {
//        tmp = a % b;
//        a = b;
//        b = tmp;
//    }
//    return a;
//}
//
//int main()
//{
//    cin >> n >> x;
//    for (int i = 0; i < n; i++)  cin >> arr[i];
//
//    long long tmp = 0;
//    long long ret = x;
//    for (tmp = 0; tmp < n; tmp++)
//    {
//        if (x >= arr[tmp])
//        {
//            ret += arr[tmp];
//        }
//        else
//        {
//            ret += (ret + gcd(ret, arr[tmp]));
//        }
//    }
//
//    cout << ret << endl;
//
//    return 0;
//}

//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//class Solution
//{
//public:
//
//    int dx[2] = { 0 ,1 };
//    int dy[2] = { 1 ,0 };
//    int m, n, ret;
//    bool hash[200][200] = { 0 };
//
//    void bfs(vector<vector<int> >& grid, int i, int j)
//    {
//        hash[i][j] = true;
//        // 
//        for (int k = 0; k < 2; k++)
//        {
//            int a = i + dx[k], b = j + dy[k];
//            if (a >= 0 && a < m && b >= 0 && b < n && !hash[a][b])
//            {
//                //bfs(grid, a, b);
//            }
//            //ret = max(ret, grid[a][b]);
//        }
//    }
//
//    int maxValue(vector<vector<int> >& grid)
//    {
//        m = grid.size(), n = grid[0].size();
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                bfs(grid, i, j);
//            }
//        }
//
//        return ret;
//    }
//};
//
//int main()
//{
//    vector<vector<int>> v{ {1,3,1},{1,5,1},{4,2,1} };
//    int ret = Solution().maxValue(v);
//    cout << ret << endl;
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int t, n;
//int arr[100];
//string str;
//
//int main()
//{
//    cin >> t;   // 代表数组的组数
//    while (t--)
//    {
//        cin >> n;
//        {
//            for (int i = 0; i < n; i++)  cin >> arr[i];
//        }
//
//        // 判断arr中按规则是否可以取出回文字符串
//        for (int i = 0; i < n; i++)
//        {
//
//        }
//    }
//}
