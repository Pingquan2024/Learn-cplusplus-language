/* ƽ���� */
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

/* ƽ���� */
//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//typedef long long LL;
//
//LL x;
//
//int main()
//{
//    cin >> x;
//    LL a = sqrt(x);
//    LL y1 = a * a, y2 = (a + 1) * (a + 1);
//    if (x - y1 < y2 - x) cout << y1 << endl;
//    else cout << y2 << endl;
//}


/* ���� */
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


/* ���� */
//#include <iostream>
//#include <unordered_map>
//
//using namespace std;
//
//int n, m;
//unordered_map<int, int> myMap;
//
//bool check(int i)
//{
//    int g = 0; // �ֳܷɶ�����
//    for (auto& [a, b] : myMap)
//    {
//        g += b / i + (b % i == 0 ? 0 : 1);
//    }
//
//    return g <= m;
//}
//
//int main()
//{
//    cin >> n >> m;
//    int hmax = 0; // ����������������
//    for (int i = 0; i < n; i++)
//    {
//        int x = 0;
//        cin >> x;
//        hmax = max(hmax, ++myMap[x]);
//    }
//
//    int sz = myMap.size();
//    if (sz > m)
//    {
//        cout << -1 << endl;
//    }
//    else
//    {
//        // ö�����Ľ���У���������
//        for (int i = 1; i < hmax; i++)
//        {
//            if (check(i))
//            {
//                cout << i << endl;
//                break;
//            }
//        }
//    }
//    return 0;
//}

