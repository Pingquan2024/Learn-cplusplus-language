//#include <iostream>
//#include <string>
//
//using namespace std;
//
//string s;
//
//int main()
//{
//    while (cin >> s)
//    {
//        if (s[0] >= 'a' && s[0] <= 'z')
//        {
//            cout << (char)(s[0] - 32);
//        }
//        else
//        {
//            cout << s[0];
//        }
//    }
//
//    return 0;
//}

#include <iostream>

using namespace  std;

const int N = 1e7 + 10;
int arr[N];

int n, x, sum;

int main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int left = 0, right = 0;
    int retLen = N;
    int retLeft = -1, retRight = -1;
    while (right < n)
    {
        sum += arr[right];
        while (sum >= x)
        {
            // 更新数据
            if (right - left + 1 < retLen)
            {
                retLeft = left;
                retRight = right;
                retLen = right - left + 1;
            }
            sum -= arr[left++];
        }
        right++;
    }

    cout << retLeft << " " << retRight << endl;

}


//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int n, k, x;
//long long sum;
//priority_queue<long long> heap;
//
//int main()
//{
//    cin >> n >> k;
//    while (n--)
//    {
//        cin >> x;
//        sum += x;
//        if (x % 2 == 0)
//        {
//            heap.push(x);
//        }
//    }
//
//    // 这样heap里的就都是偶数
//    while (heap.size() && k--)
//    {
//        long long t = heap.top();
//        heap.pop();
//        sum -= t / 2;
//        if ((t / 2) % 2 == 0)
//        {
//            heap.push(t / 2);
//        }
//    }
//
//    cout << sum << endl;
//
//    return 0;
//}
