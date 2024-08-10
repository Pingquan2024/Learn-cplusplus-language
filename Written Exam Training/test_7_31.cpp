//#include <iostream>
//
//using namespace std;
//
//int a, h, b, k;
//int ret;
//
//int main()
//{
//    cin >> a >> h >> b >> k;
//    //      2   3    1   3
//    // 模拟
//    while (h && k)
//    {
//        // 对立攻击
//        ret += a;
//        // 光攻击
//        ret += b;
//        // 小红使用幻术，对立和光互相攻击
//        k -= a; h -= b;
//        //  1       2
//        //  -1      1
//    }
//
//    // 其中一人死亡
//    (h <= 0) ? (ret += 10 * b) : (ret += 10 * a);
//
//    cout << ret << endl;
//    //          6
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//const int N = 1e5 + 10;
//int arr[N];
//int n;
//
//int main()
//{
//    cin >> n;
//    for (int i = 0; i < n; i++)  cin >> arr[i];
//    int hash[N] = { 0 };
//
//    //滑动窗口
//    long long left = 0, right = 0, retLen = 0;
//
//    while (right < n)
//    {
//        // 进窗口
//        hash[arr[right]]++;    // 表示出现过该字符
//        while (hash[arr[right]] > 1)
//        {
//            hash[arr[left]]--;
//            left++;
//        }
//
//        retLen = max(retLen, right - left + 1);
//        right++;
//    }
//
//    cout << retLen << endl;
//    return 0;
//}



//#include <iostream>
//#include <string>
//
//using namespace std;
//
//string str;
//const int N = 1e7 + 10;
//
//int main()
//{
//    cin >> str;
//    int hash[N] = { 0 };
//
//    long long left = 0, right = 0, retLen = 0;
//
//    while (right < str.size())
//    {
//        // 进窗口
//        hash[str[right]]++;    // 表示出现过该字符
//        while (hash[str[right]] > 1)
//        {
//            hash[str[left]]--;
//            left++;
//        }
//
//        retLen = max(retLen, right - left + 1);
//        right++;
//    }
//
//    cout << retLen << endl;
//
//    return 0;
//}



