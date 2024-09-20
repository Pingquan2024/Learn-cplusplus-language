/* ×Ö·û´®Ìæ»» */

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Solution
//{
//public:
//    string formatString(string str, vector<char>& arg)
//    {
//        int i = 0;
//        string ret;
//        for (i = 0; i < str.size() - 1; i++)
//        {
//            if (str[i] == '%' && str[i + 1] == 's')
//            {
//                str[i] = arg.front();
//                arg.back();
//                if (str.size())
//                {
//                    str.erase(str.begin() + i + 1);
//                }
//                if (arg.size())
//                {
//                    arg.erase(arg.begin());
//                }
//            }
//        }
//
//        for (auto x : str)
//        {
//            ret += x;
//        }
//
//        if (arg.size())
//        {
//            for (auto e : arg)
//            {
//                ret += e;
//            }
//        }
//
//        return ret;
//    }
//};
//int main()
//{
//    string str("A%sC%sE");
//    vector<char> v;
//    v.push_back('B');
//    v.push_back('D');
//    v.push_back('F');
//    Solution().formatString(str, v);
//
//    return 0;
//}


/* ×Ö·û´®Ìæ»» */
//class StringFormat
//{
//public:
//    string formatString(string A, int n, vector<char> arg, int m)
//    {
//        int j = 0;
//        string ret;
//
//        for (int i = 0; i < n; i++)
//        {
//            if (A[i] == '%')
//            {
//                if (i + 1 < n && A[i + 1] == 's')
//                {
//                    ret += arg[j++];
//                    i++;
//                }
//                else
//                {
//                    ret += A[i];
//                }
//            }
//            else
//            {
//                ret += A[i];
//            }
//        }
//
//        while (j < m)
//        {
//            ret += arg[j++];
//        }
//
//        return ret;
//    }
//};

//#include <iostream>
//#include <string>
//#include <set>
//
//using namespace std;
//
//string str, s, ret;
//int n;
//double retq, dst;
//
//
//int main()
//{
//    cin >> str >> n;
//
//    int sz = str.size();
//
//    int i = 0;
//    int Rounds = sz / n;
//    set<pair<int, double>> m;
//    while (i < sz && Rounds--)
//    {
//        for (i = 0; i < n; i++)
//        {
//            retq = 0;
//            if (str[i] == 'C' || str[i] == 'G')
//            {
//                retq++;
//                dst = retq;
//            }
//        }
//        if (retq > dst)
//        {
//            for (i = i - n; i < n; i++)
//            {
//                s += str[i];
//            }
//            ret.assign(s);
//        }
//        // m.insert({i, ret});
//        i += n;
//        n += n;
//    }
//
//    cout << ret;
//
//    return 0;
//}

