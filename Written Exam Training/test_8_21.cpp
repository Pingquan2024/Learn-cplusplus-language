#include <iostream>
#include <vector>

using namespace std;

int n, q, x;
vector<vector<int>> arr;
vector<int> v;

void change1(vector<vector<int>>& nums)
{
    // 做行与行之间的交换
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        swap(nums[left++], nums[right--]);
    }
}

void change2(vector<int>& nums)
{
    // 先做一行之间的交换
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        swap(nums[left++], nums[right--]);

    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //cin >> arr[i][j];
            int m = 0;
            cin >> m;
            v.push_back(m);
        }
        arr.push_back(v);
        v.clear();
    }

    cin >> q;
    while (q--)
    {
        cin >> x;
        vector<vector<int>> ve = arr;
        if (x == 1)
        {
            change1(ve);
            int i = 0;
            while (i < ve.size())
            {
                change2(ve[i++]);
            }
        }
        else
        {
            change1(ve);
        }

        for (auto e : ve)
        {
            for (auto x : e)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
