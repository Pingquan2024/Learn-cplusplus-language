//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int q, x, ret;
//vector<int> v;
//
//int main()
//{
//    cin >> q;
//    while (q--)
//    {
//        cin >> x;
//        if (x % 2 == 0)
//        {
//            cout << (x == 0 ? -1 : x) << endl;
//        }
//        else
//        {
//            // ÆæÊý
//            int tmp = x;
//            int signal = -1;
//            while (tmp)
//            {
//                int c = tmp % 10;
//                v.insert(v.begin(), c);
//                tmp /= 10;
//                //if (tmp % 2 != 0)
//                //{
//                //    ret = -1;
//                //    signal = 1;
//                //    break;
//                //}
//                if (c % 2 == 0)
//                {
//                    signal = 1;
//                }
//            }
//
//            int flag = 0;
//            for (int i = 0; (i < v.size() && signal == 1); i++)
//            {
//                if (v[i] % 2 == 0 && flag != 1)
//                {
//                    flag = 1;
//                    ret = v[i];
//                    continue;
//                }
//
//                cout << v[i];
//            }
//            if (signal != -1)
//                cout << ret << endl;
//            else
//                cout << -1 << endl;
//        }
//        v.clear();
//    }
//
//    return 0;
//}
