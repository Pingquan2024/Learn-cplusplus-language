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
//    // ģ��
//    while (h && k)
//    {
//        // ��������
//        ret += a;
//        // �⹥��
//        ret += b;
//        // С��ʹ�û����������͹⻥�๥��
//        k -= a; h -= b;
//        //  1       2
//        //  -1      1
//    }
//
//    // ����һ������
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
//    //��������
//    long long left = 0, right = 0, retLen = 0;
//
//    while (right < n)
//    {
//        // ������
//        hash[arr[right]]++;    // ��ʾ���ֹ����ַ�
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
//        // ������
//        hash[str[right]]++;    // ��ʾ���ֹ����ַ�
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



