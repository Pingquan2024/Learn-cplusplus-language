//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int n, k, mini = 1e9 + 10, ret = -1;
//const int N = 1e5 + 10;
//int arr[N];
//
//int main()
//{
//    cin >> n >> k;
//    // 口罩总数 不舒适度总和
//    for (int i = 0; i < n; i++)
//    {
//        cin >> arr[i];
//        if (arr[i] < mini)
//        {
//            mini = arr[i];
//        }
//    }
//
//    sort(arr, arr + n);
//
//    int tmp = 0, i = 0;
//    while (tmp < k && i < n)
//    {
//        // 舒适度小于k
//        if (mini > k)
//        {
//            // 使用任何一个口罩都会使不舒适度超过k
//            ret = 0;
//            break;
//        }
//        else
//        {
//            tmp += arr[i++];
//            arr[i] *= 2;
//            ret += 1;
//        }
//
//        // 再加几轮
//        if (i == n && tmp < k)
//        {
//            i = 0;
//        }
//    }
//
//    cout << ret << endl;
//
//    return 0;
//}


//#include <iostream>
//
//using namespace std;
//
//int T, n, a, b;
//int ret = 1e9;
//
//int main()
//{
//    cin >> T;
//    while (T--)
//    {
//        cin >> n >> a >> b;
//
//        for (int i = 0; i <= n/2; i++)    // i 是船数
//        {
//
//            ret = min(ret, a * i + b * (n - 2 * i));
//        }
//
//        if (n % 2 != 0)
//        {
//            ret += a;
//        }
//
//        cout << ret << endl;
//    }
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int T, n, a, b;
//int ret = 0;
//
//int main()
//{
//    cin >> T;
//    while (T--)
//    {
//        cin >> n >> a >> b;
//
//        // a < b, a == b
//        // 1.   a  < b, 2a > b 
//        // 2.   a == b
//
//        bool flag1 = a < b;
//        bool flag2 = 2 * a > b;
//
//        // 20,30 flag == 1, flag2 == 1, 如果是一(两)个人那就坐a双人船，如果是三个人那就坐三人船
//        // 10,30 flag == 1, flag2 == 0, 如果是一(两)个人那就坐a双人船，如果是三个人那就坐两人船
//        // 20,10 flag == 0, flag2 == 1,  不考虑
//
//
//        while (n > 0)
//        {
//            if (flag1 && n > 3)
//            {
//                ret += n / 2;
//                n = n - n / 2;
//            }
//
//            if (!flag1 && n > 3)
//            {
//                ret += n / 3;
//                n = n - n / 3;
//            }
//
//            if (flag1 && flag2)
//            {
//                if (n == 1 || n == 2)
//                {
//                    ret += a;
//                    n -= 2;
//                }
//
//                if (n == 3)
//                {
//                    ret += b;
//                    n -= 3;
//                }
//            }
//
//            if (flag1 && !flag2)
//            {
//                if (n == 1 || n == 2)
//                {
//                    ret += a;
//                    n -= 2;
//                }
//
//                if (n == 3)
//                {
//                    ret += a;
//                    n -= 3;
//                }
//            }
//
//            if (!flag1 && flag2)
//            {
//                if (n == 1 || n == 2)
//                {
//                    ret += a;
//                    n -= 2;
//                }
//
//                if (n == 3)
//                {
//                    ret += b;
//                    n -= 3;
//                }
//            }
//        }
//        cout << ret << endl;
//        ret = 0;
//    }
//    return 0;
//}