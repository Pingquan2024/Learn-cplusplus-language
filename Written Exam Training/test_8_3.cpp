//#include <iostream>
//
//using namespace std;
//
//int t, h, a, H, A;
//int ret;
//
//int main()
//{
//    cin >> t;
//    while (t--)
//    {
//        cin >> h >> a >> H >> A;
//        int tmp = H;
//        // 攻击前
//        while (h > 0 && H > 0)
//        {
//            H -= a;
//            // 我攻击完
//            if (H > 0)   // 毛球怪还活着那就继续
//            {
//                h -= A;
//                if (h < 0)
//                {
//                    break;
//                }
//            }
//            else    // 毛球怪下线
//            {
//                ret++;
//                // 上另一只毛球怪
//                H = tmp;
//            }
//        }
//
//        cout << ret << endl;
//    }
//
//
//    return 0;
//}
