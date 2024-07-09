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
            sum -= arr[left];
        }
        right++;
    }

    cout << left << " " << right << endl;

}