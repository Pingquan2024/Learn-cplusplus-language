//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int T, a, b;
//
//int main()
//{
//    cin >> T;
//    while (T--)
//    {
//        cin >> a >> b;
//        int flag = 0;
//        int ret = a * b;
//        if (ret <= 3)
//        {
//            cout << "YES" << endl;
//            continue;
//        }
//
//        for (int i = 3; i < sqrt(ret); i++)
//        {
//            if (ret % i == 0)
//            {
//                flag = 1;
//            }
//        }
//
//        if (flag == 1)
//        {
//            cout << "NO" << endl;
//        }
//        else
//        {
//            cout << "YES" << endl;
//        }
//    }
//    return 0;
//}