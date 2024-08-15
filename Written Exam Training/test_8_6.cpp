//#include <iostream>
//#include <string>
//
//using namespace std;
//
//string str;
//
//int main()
//{
//    // Ð¡Ð´×ÖÄ¸
//    cin >> str;
//    int hash[110] = { 0 };
//    int minn = 110, maxn = 0;
//    for (auto e : str)
//    {
//        if (++hash[e - 'a'] > maxn)
//        {
//            maxn = hash[e - 'a'];
//        }
//        else if (hash[e - 'a'] < minn)
//        {
//            minn = hash[e - 'a'];
//        }
//    }
//
//    int ret = maxn - minn;
//    if (ret % 2 == 0 || ret % 3 == 0 || ret % 5 == 0 || ret % 7 == 0)
//    {
//        cout << "No Answer" << endl;
//        cout << "0";
//    }
//    else
//    {
//        cout << "Lucky Word" << endl;
//        cout << ret;
//    }
//
//    return 0;
//}

//class Solution
//{
//public:
//    int arr[100000];
//    bool hostschedule(vector<vector<int> >& schedule)
//    {
//        int m = schedule.size(), n = schedule[0].size();
//        int k = 0;
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                arr[k++] = schedule[i][j];
//            }
//        }
//
//        for (int i = 0; i < m + n; i++)
//        {
//            if (arr[i + 1] < arr[i])
//            {
//                return  false;
//            }
//        }
//        return true;
//    }
//};


//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int nums[510], n, sum, ret;
//
//int main()
//{
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> nums[i];
//        sum += nums[i];
//    }
//
//    sort(nums, nums + n);
//
//    for (int i = 0; i < n; i++)
//    {
//        while ((ret < sum / 2) && i < n)
//        {
//            ret += nums[i++];
//            sum -= nums[i++];
//        }
//
//        if (ret == sum)
//        {
//            cout << "true";
//        }
//        else
//        {
//            cout << "false";
//        }
//
//    }
//
//    return 0;
//}