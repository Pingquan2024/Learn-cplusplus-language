	/* ƹ����� */
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//string s, t;
//int arr[27] = { 0 };
//
//
//int main()
//{
//    cin >> s >> t;
//    int count = t.size();
//    for (auto e : t)
//    {
//        arr[e - 65] += 1;    // ��hash1������eλ�ñ��
//    }
//
//    string ret;
//    for (int i = 0; i < s.size(); i++)
//    {
//        int j = i;
//        while (j < s.size())
//        {
//            if (!arr[(s[j] - 65)])
//            {
//                // ������
//                j++;
//            }
//            else
//            {
//                // ����
//                arr[(s[j] - 65)] -= 1;
//                j++;
//                count--;
//            }
//        }
//        i = j;
//    }
//
//    if (count == 0)
//    {
//        cout << "Yes";
//    }
//    else
//    {
//        cout << "No";
//    }
//
//    return 0;
//}


	/* ƹ����� */
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//string str, s;
//
//int main()
//{
//	while (cin >> str >> s)	// w
//	{
//		int hash[26] = { 0 };
//		for (auto ch : str)
//		{
//			hash[ch - 'A']++;
//		}
//		bool ret = true;
//
//		for (auto ch : s)
//		{
//			if (--hash[ch - 'A'] < 0)
//			{
//				ret = false;
//				break;
//			}
//		}
//
//		cout << (ret ? "Yes" : "No") << endl;
//	}
//	return 0;
//}

	/* ��Ӿ��� */
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int n, n1, ret;
//const int N = 1e5 + 10;
//vector<int> v;
//
//// ������
//// ��һ�飺 �����ڶ��� ���ֵ
//// �ڶ��飺 �������Ĵ� ����������
//// ...
//
//int main()
//{
//    cin >> n;       // n������
//    for (int i = 0; i < 3 * n; i++)
//    {
//        n1 = 0;
//        cin >> n1;
//        v.push_back(n1);
//    }
//
//    sort(v.begin(), v.end());   // �Ӵ�С
//    sort(v.begin(), v.end());   // ��С����
//
//    while (n--)
//    {
//        v.pop_back();
//        ret += v.back();
//        v.pop_back();
//    }
//
//    cout << ret << endl;
//}

	/* ��Ӿ��� */
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long LL;
//const int N = 1e5 + 10;
//int n;
//LL arr[N * 3];
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < 3 * n; i++)
//	{
//		cin >> arr[i];
//	}
//
//	sort(arr, arr + 3 * n);
//
//	int pos = 3 * n - 2, count = 1;
//	LL ret = 0;
//	while (count++ <= n)
//	{
//		ret += arr[pos];
//		pos -= 2;
//	}
//
//	cout << ret << endl;
//
//	return 0;
//}

	/* ɾ���������ֵ������� */
//#include <cstdio>
//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int n, ret = 1;
//const int N = 1e5 + 10;
//bool vis[N] = { 0 };
//string s;
//
//int main()
//{
//    cin >> n;
//    getline(cin, s);
//
//    sort(s.begin(), s.end());   // �Ӵ�С
//
//    for (int i = 1; i < n; i++)
//    {
//        if (s[i] != ' ')
//        {
//            if (s[i - 1] + 1 == s[i] && s[i] + 1 == s[i + 1])
//            {
//                if (!vis[s[i]])
//                {
//                    ret += s[i];
//                    vis[s[i]] = vis[s[i - 1]] = vis[s[i + 1]] == true;
//                }
//
//            }
//        }
//
//    }
//
//		// err 
//    cout << ret << endl;
//}


	/* ɾ���������ֵ������� */
//#include <iostream>
//
//using namespace std;
//
//const int N = 1e4 + 10;
//int sum[N];	// sum[i] ��ʾ i ���ֵ��ܺ�
//int n;
//int f[N], g[N];
//
//int main()
//{
//	cin >> n;
//	int x;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> x;
//		sum[x] += x;
//	}
//
//	for (int i = 1; i < N; i++)
//	{
//		f[i] = g[i - 1] + sum[i];
//		g[i] = max(f[i - 1], g[i - 1]);
//	}
//
//	cout << max(f[N - 1], g[N - 1]) << endl;
//
//	return 0;
//}