//#include <iostream>
//
//using namespace std;
//
//int n, m, ret = 1;
//
//int main()
//{
//    cin >> n >> m;
//    // n个气球 一排摆成m个
//
//    while (m)
//    {
//        ret *= m;
//        m--;
//    }
//
//    ret *= n;
//
//    cout << ret << endl;
//    cout << ret % 109 << endl;
//}


//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int n, m, x_s, y_s, x_t, y_t;
//int ret;
//// char arr[1010][1010] ={ '0' };
//string str;
//
//// vector<vector<char>> arr;
//int dx[4] = { 0, 0, 1, -1 };
//int dy[4] = { 1, -1, 0, 0 };
//bool hash1[1010][1010] = { 0 };
//
//bool bfs(string str, int i, int j)
//{
//    hash1[i][j] = true;
//
//    if (i == x_t && j == y_t)
//    {
//        return true;
//    }
//
//    for (int k = 0; k < 4; k++)
//    {
//        int a = i + dx[k], b = j + dy[k];
//        if (a >= 0 && a < n && b >= 0 && b < m && !hash1[a][b] && str[a] + b == '.')
//        {
//            if (bfs(str, a, b)) return true;
//        }
//    }
//
//    hash1[i][j] = false;
//    return false;
//}
//
//bool exist(string& str)
//{
//
//    for (int i = x_s; i <= x_t; i++)
//    {
//        for (int j = y_s; j <= y_t; j++)
//        {
//            if (str[i] + j == '.' && !hash1[i][j])
//            {
//                ret++;
//                if (bfs(str, i, j)) return true;
//            }
//        }
//    }
//    return false;
//}
//
//int main()
//{
//    cin >> n >> m;
//    cin >> x_s >> y_s >> x_t >> y_t;
//
//    for (int i = 0; i <= n; i++)
//    {
//        cin >> str[i];
//    }
//
//    exist(str);
//
//    cout << ret << endl;
//
//    return 0;
//}

