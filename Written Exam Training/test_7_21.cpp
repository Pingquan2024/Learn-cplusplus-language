	/* ţţ������ */
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int t, n, k;
//string s;
//
//int main()
//{
//    cin >> t;
//
//    // t���Ե�������n����n����k��ʤ����������
//    while (t--)
//    {
//        cin >> n >> k;
//        for (int i = 0; i < n; i++)
//        {
//            cin >> s[i];
//        }
//
//        // ��ʼ����
//        int star = 0;
//        if (n == 1)
//        {
//            (s[0] == 'W') ? (star += 1) : (star -= 1);
//        }
//        else if (n >= 2)
//        {
//            (s[0] == 'W') ? (star += 1) : (star -= 1);
//            (s[1] == 'W') ? (star += 1) : (star -= 1);
//
//            for (int i = 2; i < n; i++)
//            {
//                if (s[i] == 'L')     // ţţʧ��
//                {
//                    star -= 1;
//                }
//                else    // ʤ��
//                {
//                    if (s[i - 1] == 'W' && s[i - 2] == 'W')
//                    {
//                        star += k;
//                    }
//                    else
//                    {
//                        star += 1;
//                    }
//                }
//            }
//        }
//        else
//        {
//            star = 0;
//        }
//        cout << star << endl;
//    }
//    return 0;
//}


	/* ţţ������ */
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int t, n, k;
//string s;
//
//int func()
//{
//    int ret = 0;
//    for (int i = 0; i < n; i++)
//    {
//        char ch = s[i];
//        if (ch == 'L')
//        {
//            ret -= 1;
//        }
//        else
//        {
//            if (i - 1 >= 0 && i - 2 >= 0 && s[i - 1] == 'W' && s[i - 2] == 'W')
//            {
//                ret += k;
//            }
//            else
//            {
//                ret += 1;
//            }
//        }
//    }
//
//    return ret;
//}
//
//int main()
//{
//    cin >> t;
//    while (t--)
//    {
//        cin >> n >> k >> s;
//
//        cout << func() << endl;
//    }
//    return 0;
//}


	/* ����ظ������� */
//class solution
//{
//public:
//    int n = 0, ret = 0;
//
//    int maxlength(vector<int>& arr)
//    {
//        n = arr.size();
//        int left = 0, right = 0;
//        int retlen = 1e5;
//
//        int retleft = -1, retright = -1;
//        while (right < n)
//        {
//            ret += 1;
//            while (arr[right] - arr[left] >= ret)
//            {
//                // ��������
//                if (right - left + 1 < retlen)
//                {
//                    retleft = left;
//                    retright = right;
//                    retlen = right - left + 1;
//                }
//                ret -= 1;
//            }
//            right++;
//        }
//
//        if (retlen == 1e5)
//        {
//            retlen = n;
//        }
//        // ��������ظ�Ԫ��������ĳ���
//        return retlen;
//    }
//};


	/* ����ظ������� */
//class Solution
//{
//public:
//
//    int hash[100010] = { 0 };
//
//    int maxLength(vector<int>& arr)
//    {
//        int left = 0, right = 0, n = arr.size();
//
//        int ret = 0;
//        while (right < n)
//        {
//            // ������
//            hash[arr[right]]++;
//            while (hash[arr[right]] > 1)     // �жϣ�����������ظ�Ԫ��
//            {
//                // ������
//                hash[arr[left]]--;
//                left++;
//            }
//            ret = max(ret, right - left + 1);
//            right++;
//        }
//        return ret;
//    }
//};

	/* �����ַ��� */
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int n;
//const int N = 1e5 + 10;
//int arr[N];
//// bool vis[N] = { 0 };
//
//int main()
//{
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> arr[i];
//        // vis[arr[i]] = true;
//    }
//
//    for (int i = 1; i < n; i++)
//    {
//        while (n)
//        {
//            if (arr[i - 1] == arr[i])
//            {
//                int tmp = arr[n - 1];
//                arr[n - 1] = arr[i];
//                arr[i] = tmp;
//                n--;
//            }
//        }
//
//    }
//
//    cout << "YES" << endl;
//    for (auto e : arr)
//    {
//        cout << e + '0';
//    }
//
//    return 0;
//}

	/* �����ַ��� */
//#include <iostream>
//
//using namespace std;
//
//int n;
//const int N = 1e5 + 10;
//char s[N];
//char ret[N];
//
//int main()
//{
//    cin >> n >> s;
//    int hash1[26] = { 0 };
//    int highChar = 0, maxCount = 0;
//    // �ҳ��ִ��������ַ�,�Լ���Ӧ�Ĵ���
//    for (int i = 0; i < n; i++)
//    {
//        int index = s[i] - 'a';
//        if (++hash1[index] > maxCount)
//        {
//            highChar = s[i];
//            maxCount = hash1[index];
//        }
//    }
//
//    // �ж��ܲ�������
//    if (maxCount > (n + 1) / 2)
//    {
//        cout << "no" << endl;
//    }
//    else
//    {
//        cout << "yes" << endl;
//        int i = 0;
//        while (maxCount--)
//        {
//            ret[i] = highChar;
//            i += 2;
//        }
//
//        // ����ʣ�µ��ַ�
//        for (int j = 0; j < 26; j++)
//        {
//            if (hash1[j] && j + 'a' != highChar)
//            {
//                while (hash1[j]--)
//                {
//                    if (i >= n)
//                    {
//                        i = 1;
//                    }
//                    ret[i] = j + 'a';
//                    i += 2;
//                }
//            }
//        }
//
//        for (int j = 0; j < n; j++)
//        {
//            cout << ret[j];
//        }
//        cout << endl;
//    }
//
//    return 0;
//}


