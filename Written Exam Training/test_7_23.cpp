//
//#include <iostream>
//
//using namespace std;
//
//int x, y, minVal = 10000000;
//
//int main()
//{
//    cin >> x;
//    int a = 0;
//
//    while ((x - a * a) < minVal && minVal >= 0)
//    {
//        minVal = x - a * a;
//        a++;
//    }
//
//
//    cout << a << endl;
//
//    return 0;
//}


//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//int n, m, ret, count1;
//const int N = 1e5 + 10;
//int arr[N];
//
//int main()
//{
//    // n ��ͬѧ�ֳ� m ��
//    cin >> n >> m;
//
//    int number = n / m;
//    int highVoicer = 0; // ��������������ʲô
//    int maxVoicer = 0;  // ���������м�����
//    int minVoicer = 100000;
//
//    int hash[N] = { 0 };
//
//    for (int i = 0; i < n; i++)
//    {
//        cin >> arr[i];
//        if (++hash[arr[i]] > maxVoicer)
//        {
//            // ͳ�Ƴ�ÿ�������ж�����
//            highVoicer = arr[i];
//            maxVoicer = hash[arr[i]];
//        }
//
//        if (hash[arr[i]] < minVoicer)
//        {
//            minVoicer = hash[arr[i]];
//        }
//    }
//
//    // �ܹ���ret������
//    for (int i = 0; i < n; i++)
//    {
//        if (hash[i])
//        {
//            count1 += 1;
//        }
//    }
//
//    if (count1 < n / m)
//    {
//        ret = minVoicer;
//    }
//    else if (count1 > n / m)
//    {
//        ret = -1;
//    }
//    else
//    {
//        ret = minVoicer;
//    }
//
//    cout << ret << endl;
//
//    return 0;
//}
