//#include <iostream>
//#include <string>
//
//using namespace std;
//
//string s;
//int len = 0;
//size_t begin1 = 0;
//
//int main()
//{
//    cin >> s;
//    for (int i = 0; i < s.size(); i++)
//    {
//        if (s[i] >= '0' && s[i] <= '9')
//        {
//            int j = i;
//            while (j < s.size() && s[j] >= '0' && s[j] <= '9')
//            {
//                j++;
//            }
//
//            if (j - i > len)
//            {
//                begin1 = i;
//                len = j - i;
//            }
//            i = j;
//        }
//    }
//
//    cout << s.substr(begin1, len) << endl;
//
//    return 0;
//}


//#include <vector>
//using namespace std;
//
//class Solution
//{
//public:
//    int m, n;
//    int ret = 0;
//    int dx[4] = { 0, 0, 1, -1 };
//    int dy[4] = { 1, -1, 0, 0 };
//    bool vis[210][210] = { 0 };
//
//    int solve(vector<vector<char> >& grid)
//    {
//        m = grid.size(), n = grid[0].size();
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (grid[i][j] - '0' == 1 && !vis[i][j])
//                {
//                    ret++;
//                    dfs(grid, i, j);
//                }
//            }
//        }
//
//        return ret;
//    }
//
//    void dfs(vector<vector<char>>& grid, int i, int j)
//    {
//        vis[i][j] = true;
//        for (int k = 0; k < 4; k++)
//        {
//            int a = i + dx[k], b = j + dy[k];
//            if (a >= 0 && a < m && b >= 0 && b < n && !vis[a][b] && grid[a][b] - '0' == 1)
//            {
//                dfs(grid, a, b);
//            }
//        }
//
//    }
//};
//
//
//int main()
//{
//    vector<char> a1{ 1,1,0,0,0 };
//    vector<char> a2{ 0,1,0,1,1 };
//    vector<char> a3{ 0,0,0,1,1 };
//    vector<char> a4{ 0,0,0,0,0 };
//    vector<char> a5{ 0,0,1,1,1 };
//    vector<vector<char>> arr{ a1,a2,a3,a4,a5 };
//    Solution().solve(arr);
//
//    return 0;
//}


//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int n;
//int arr[6];
//
//int main()
//{
//    cin >> n;
//    while (n--)
//    {
//        for (int i = 0; i < 6; i++)
//        {
//            cin >> arr[i];
//        }
//
//        sort(arr, arr + 6);
//
//        if (arr[0] + arr[1] > arr[2] && arr[3] + arr[4] > arr[5]
//            || arr[0] + arr[2] > arr[3] && arr[1] + arr[4] > arr[5]
//            || arr[0] + arr[3] > arr[4] && arr[1] + arr[2] > arr[5]
//            || arr[0] + arr[4] > arr[5] && arr[1] + arr[2] > arr[3])
//        {
//            cout << "Yes" << endl;
//        }
//        else
//        {
//            cout << "No" << endl;
//
//        }
//    }
//    return 0;
//}