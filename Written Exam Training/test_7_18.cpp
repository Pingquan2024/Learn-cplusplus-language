/* ���ε�ˮ������� */
//#include <iostream>
//
//using namespace std;
//
//long long n, m, a, b, ret;
//
//int main()
//{
//	cin >> n >> m >> a >> b;
//
//	for (long long x = 0; x <= min(n / 2, m); x++)
//	{
//		long long  y = min(n - 2 * x, (m - x) / 2);
//		ret = max(ret, a * x + b * y);	// ÿ�����ֵ��ret�������
//	}
//
//	cout << ret << endl;
//
//	return 0;
//}

	/* ������Ʊ���������2 */
//#include <iostream>
//
//using namespace std;
//
//const int N = 1e5 + 10;
//
//int n, arr[N], ret;
//
//int main()
//{
//    cin >> n;
//    for (int i = 0; i < n; i++)  cin >> arr[i];
//
//    // ̰��
//    for (int i = 1; i < n; i++)
//    {
//        if (arr[i] > arr[i - 1])
//        {
//            ret += arr[i] - arr[i - 1];     // retͳ�Ƶ�������
//        }
//    }
//
//    cout << ret << endl;
//
//    return 0;
//}

	/* OR62 �����ַ��� */
//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//string s;
//
//int main()
//{
//    getline(cin, s);
//
//    reverse(s.begin(), s.end());
//
//    int n = s.size(), left = 0;
//    while (left < n)
//    {
//        int right = left;
//        while (right < n && s[right] != ' ')   // �ҵ���
//        {
//            right++;
//        }
//
//        // ����˵���Ѿ������ո��ˣ�����һ��������
//        reverse(s.begin() + left, s.begin() + right);
//
//        // ���ܵ��ʼ���ж���ո������ÿո�
//        while (right < n && s[right] == ' ')
//        {
//            right++;
//        }
//
//        // Ȼ���right��left����������һ������
//        left = right;
//    }
//
//    cout << s << endl;
//
//    return 0;
//}
