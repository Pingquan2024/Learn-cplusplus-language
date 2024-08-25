//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <string>
//#include <cstdlib>
//
//using namespace std;
//
//// vector<int> v;
//string t;
//
//int main()
//{
//    // 每个数只出现一次
//    // 递减或递增
//    // 判断这个素数的回文数是否为素数？
//    cin >> t;
//    //int tmp = t;
//    //while (tmp)
//    //{
//    //    int c = tmp % 10;
//    //    v.insert(v.begin(), c);
//    //    tmp /= 10;
//    //}
//
//    int right = t.size();
//    // t的回文数是
//    while (right >= 2)
//    {
//        t.insert(t.end(), t[right - 2]);
//        right--;
//    }
//
//    int flag = -1;
//    long long ret = sqrt(stoll(t));
//    for (int i = 2; i < ret; i++)
//    {
//        if (ret % i == 0)
//        {
//            flag = 1;
//            break;
//        }
//    }
//
//    if (flag == 1)
//    {
//        cout << "noprime" << endl;
//    }
//    else
//    {
//        cout << "prime" << endl;
//    }
//    return 0;
//}
//


//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int n, a, b;
//
//int main()
//{
//    cin >> n;
//    vector<int> v;
//
//    while (n--)
//    {
//        cin >> a >> b;
//        v.push_back(a);
//        v.push_back(b);
//    }
//
//    int ret = 1;
//    for (int i = 1; i < v.size(); i += 2)
//    {
//        if (v[i] <= v[i + 1])
//        {
//            ret += 1;
//        }
//    }
//
//    cout << ret << endl;
//
//    return 0;
//}
