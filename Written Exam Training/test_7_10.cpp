//#include <iostream>
//
//using namespace std;
//
//int n;
//int a = 0, b = 1, c = 1;
//
//int main()
//{
//    cin >> n;
//    while (n > c)
//    {
//        a = b;
//        b = c;
//        c = a + b;
//    }
//
//    cout << min(n - b, c - n) << endl;
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//class Solution
//{
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param board string字符串vector
//     * @param word string字符串
//     * @return bool布尔型
//     */
//
//    bool vis[101][101] = { 0 };
//    int dx[4] = { 0, 0, 1, -1 };
//    int dy[4] = { 1, -1, 0, 0 };
//
//    size_t n, m;
//
//    bool exist(vector<string>& board, string word)
//    {
//        m = board.size(), n = board[0].size();
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (board[i][j] == word[0])
//                {
//                    if (dfs(board, i, j, word, 0)) return true;
//                }
//            }
//        }
//        return false;
//    }
//
//    bool dfs(vector<string>& board, int i, int j, string word, int pos)
//    {
//        // 处理边界
//        if (pos == word.size() - 1)
//        {
//            return true;
//        }
//
//        vis[i][j] = true;
//        for (int k = 0; k < 4; k++)
//        {
//            int a = i + dx[k], b = j + dy[k];
//            if (a >= 0 && a < m && b >= 0 && b < n && !vis[a][b] && board[a][b] == word[pos + 1])
//            {
//                if (dfs(board, a, b, word, pos + 1))  return true;
//            }
//        }
//
//        vis[i][j] = false;  // 恢复现场
//        return false;
//    }
//};


//
//#include <iostream>
//
//using namespace std;
//
//int n;
//int dp[31][31];
//
//int main()
//{
//    cin >> n;
//    dp[1][1] = 1;
//
//    for (int i = 2; i <= n; i++)
//    {
//        for (int j = 1; j <= i; j++)
//        {
//            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
//        }
//    }
//
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= i; j++)
//        {
//            printf("%5d", dp[i][j]);
//        }
//        printf("\n");
//    }
//
//    return 0;
//
//}