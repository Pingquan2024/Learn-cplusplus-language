//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//string str;
//int i = 0;
//
//int main()
//{
//    cin >> str;
//    while (i < str.size())
//    {
//        if (str[i] % 2 == 0)
//        {
//            str[i] = '0';
//        }
//        else
//        {
//            str[i] = '1';
//        }
//        i++;
//    }
//
//    cout << atoi(str.c_str()) << endl;
//
//    return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <cstdio>
//
//using namespace std;
//
//const int N = 1e2 + 10;
//int n, m;
//long long arr[N][N];
//long long ret[N][N];
//long long sum1[N];
//long long sum;
//
//int main()
//{
//    cin >> n >> m;
//    for (long long i = 1; i <= n; i++)
//    {
//        for (long long j = 1; j <= m; j++)
//        {
//            scanf("%lld", &arr[i][j]);
//            sum += arr[i][j];
//        }
//        sum1[i] = sum;
//        sum = 0;
//    }
//
//    // for(long long i = 1; i <= n; i++)  // ��
//    // {
//    //     for(long long j = 1; j <= m; j++)  // ��
//    //     {
//    //         ret[i][j] = sum1[i] - arr[i][j];
//    //         int k = 1;
//    //         while(k <= m)
//    //         {
//    //             ret[i][j] += arr[k++][j]; 
//    //         }
//    //     }
//    // }
//    for (long long i = 1; i <= n; i++)  // ��
//    {
//        for (long long j = 1; j <= m; j++)  // ��
//        {
//            int k = 0, t = 0;
//            for (long long k = 1; k <= n; k++)  // ���� i ���ڵ���
//            {
//                ret[i][j] += arr[k][j];
//            }
//
//            for (long long k = 1; k <= m; k++)  // ���� j ���ڵ���
//            {
//                ret[i][j] += arr[i][k];
//            }
//
//            ret[i][j] -= arr[i][j];
//        }
//    }
//
//    for (long long i = 1; i <= n; i++)  // ��
//    {
//        for (long long j = 1; j <= m; j++)  // ��
//        {
//            printf("%lld ", ret[i][j]);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}