//#include <iostream>
//#include <string>
//
//using namespace std;
//
//string str, ret;
//
//int main()
//{
//    cin >> str;
//
//    string str2;
//    // 先去除‘-’
//    for (auto e : str)
//    {
//        if (e != '-')
//        {
//            str2 += e;
//        }
//    }
//
//    // 计算识别码
//    int tmp = 0, i = 0, j = 1;
//    while (i < str2.size() - 1)
//    {
//        tmp += (str2[i++] - '0') * j;
//        j++;
//    }
//
//    int modAfter = tmp % 11;
//
//    if (modAfter == str[str.size() - 1] - '0')
//    {
//        cout << "Right" << endl;
//    }
//    else
//    {
//        for (int i = 0; i < str.size() - 1; i++)
//        {
//            cout << str[i];
//        }
//
//        if (modAfter == 10)
//        {
//            cout << "X" << endl;
//        }
//        else
//        {
//            cout << modAfter + '0' << endl;
//        }
//    }
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//int n, m;
//string str;
//vector<string> ve;
//int dx[4] = { 0, 0, 1, -1 };
//int dy[4] = { 1, -1, 0, 0 };
//bool kotori[31][31];
//char word[4] = { 'k','.','*','e' };
//
//int dfs(vector<string> grid, int i, int j)
//{
//    kotori[i][j] = true;
//    // 处理一下边界
//    if (i == n && j == m)
//    {
//        return -1;
//    }
//
//    for (int k = 0; k < 4; k++)
//    {
//        int a = i + dx[k], b = j + dy[k];
//        if (a >= 0 && a < n && b >= 0 && b < m && !kotori[a][b] && grid[a][b] == '.')
//        {
//
//        }
//    }
//}
//
//int main()
//{
//    cin >> n >> m;
//
//    for (int i = 0; i < n; i++)
//    {
//        cin >> str;
//        ve.push_back(str);
//        str.clear();
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            if (ve[i][j] == 'k')
//            {
//                // 开始探索
//                if (!dfs(ve, i, j))
//                {
//                    // 返回的为假，证明没有出口
//
//                }
//            }
//        }
//    }
//
//    return 0;
//}
//
//
//#include <vector>
//
//using namespace std;
//
//class Solution
//{
//public:
//    int m = 0, n = 0, ret = 1;
//    int dx[4] = { 0, 0, 1, -1 };
//    int dy[4] = { 1, -1, 0, 0 };
//    bool vis[1001][1001];
//
//    void dfs(vector<vector<int>> matrix, int &i, int &j)
//    {
//        vis[i][j] = true;
//        if (i == m && j == n)
//        {
//            return;
//        }
//
//        int a = 0, b = 0, k = 0;
//        for (k = 0; k < 4; k++)
//        {
//            a = i + dx[k], b = j + dy[k];
//            if (a >= 0 && a < m && b >= 0 && b < n && !vis[a][b] && (matrix[a][b] > matrix[i][j]))
//            {
//                ret++;
//                break;
//            }
//        }
//
//        i = a, j = b;
//        if (k == 4)
//        {
//            vis[i][j] = false;
//        }
//    }
//
//    int solve(vector<vector<int> >& matrix)
//    {
//        m = matrix.size(), n = matrix[0].size();
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                dfs(matrix, i, j);
//            }
//        }
//
//        return ret;
//    }
//};
//
//int main()
//{
//    vector<vector<int>> ve{ {1,2,3},{4,5,6},{7,8,9} };
//
//    Solution().solve(ve);
//
//    return 0;
//}