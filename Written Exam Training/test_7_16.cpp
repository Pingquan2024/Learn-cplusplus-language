    /* Ìí¼Ó¶ººÅ */
//#include <iostream>
//#include <cstdlib>
//
//using namespace std;
//
//long long int N = 0;
//string s, ret;
//
//int main()
//{
//    cin >> N;
//
//    s = to_string(N);
//
//    for (int i = 0; i < s.size(); i++)
//    {
//        size_t n = s.size() % 3;
//        if (n == 1)
//        {
//            s.insert(s.begin(), '0');
//            s.insert(s.begin(), '0');
//        }
//
//        if (n == 2)
//        {
//            s.insert(s.begin(), '0');
//        }
//    }
//
//    // cout << s << endl;
//    int k = 3;
//    for (int j = 0; j < s.size(); j++)
//    {
//        cout << s[j];
//        k--;
//
//        if (k == 0 && j < s.size() - 1)
//        {
//            cout << ",";
//            k = 3;
//        }
//    }
//
//    return 0;
//}

/* Ìí¼Ó¶ººÅ */
//#include <iostream>
//
//using namespace std;
//
//string s, ret;
//
//int main()
//{
//    cin >> s;
//
//    int n = s.size();
//    for (int i = 0; i < n; i++)
//    {
//        ret += s[i];
//        if ((n - i - 1) % 3 == 0 && i != n - 1)
//        {
//            ret += ',';
//        }
//    }
//
//    cout << ret << endl;
//
//    return 0;
//}

    /* ÌøÌ¨½× */
//#include <iostream>
//
//using namespace std;
//
//int n;
//int dp[41];
//
//int main()
//{
//    cin >> n;
//    dp[1] = 1, dp[0] = 1;
//    for (int i = 2; i <= n; i++)
//    {
//        dp[i] = max(dp[i - 2], dp[i - 2] + dp[i - 1]);
//    }
//
//    cout << dp[n] << endl;
//
//    return 0;
//}

    /* ÌøÌ¨½× */
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//
//    int a = 1, b = 1, c = 0;
//    for (int i = 2; i <= n; i++)
//    {
//        c = a + b;
//        a = b;
//        b = c;
//    }
//
//    if (n == 0 || n == 1)
//    {
//        cout << n << endl;
//    }
//    else
//    {
//        cout << c << endl;
//    }
//
//    return 0;
//}


    /* ÆË¿ËÅÆË³×Ó */
//class Solution
//{
//public:
//    int zero, two, count;
//    bool hash[14] = { 0 };
//
//    bool IsContinuous(vector<int>& numbers)
//    {
//        for (auto x : numbers)
//        {
//            hash[x] = true;
//            if (x == 0)
//            {
//                zero += 1;
//            }
//        }
//
//        // sort(numbers.begin(),numbers.end());
//
//        for (int i = 0; i < 14; i++)
//        {
//            if (hash[i])
//            {
//                count++;
//            }
//            else
//            {
//                if (hash[i] == false && zero > 0)
//                {
//                    count++;
//                    zero--;
//                }
//            }
//        }
//        if (count >= 5)
//        {
//            return true;
//        }
//        return false;
//
//        // sort(numbers.begin(),numbers.end());
//        // int i = 0;
//        // while(i < numbers.size())
//        // {
//        //     int j = i + 1;
//        //     if((numbers[j - 1] == numbers[ j ]) && (numbers[j] != 0))
//        //     {
//        //         return false;
//        //     }
//
//        //     // if((numbers[0] == 0) || (numbers[j] == 0))
//        //     // {
//        //     //     zero += 1; 
//        //     //     j++;
//        //     // }
//
//        //     // while(j < numbers.size())
//        //     // {
//        //     //     if(numbers[j] != 0)
//        //     //     {
//        //     //         if((numbers[j] - numbers[j - 1] == 2))
//        //     //         {
//        //     //             two += 1;
//        //     //             if(two < zero)
//        //     //             {
//        //     //                 count++;
//        //     //                 two--;
//        //     //                 zero--;
//        //     //             }
//        //     //         }
//        //     //         else if(numbers[j] - numbers[j - 1] == 1)
//        //     //         {
//        //     //             count++;
//        //     //         }
//        //     //     }
//        //     //     j++;
//        //     // }
//        //     // i = j;
//        //     i = j;
//        // }
//    }
//};

    /* ÆË¿ËÅÆË³×Ó */
//class Solution
//{
//public:
//
//    bool hash[14] = { 0 };
//
//    bool IsContinuous(vector<int>& numbers)
//    {
//        int maxVal = 0, minVal = 14;
//        for (auto x : numbers)
//        {
//            if (x)
//            {
//                if (hash[x]) return false;
//                hash[x] = true;
//                maxVal = max(maxVal, x);
//                minVal = min(minVal, x);
//            }
//        }
//
//        return maxVal - minVal <= 4;
//    }
//};