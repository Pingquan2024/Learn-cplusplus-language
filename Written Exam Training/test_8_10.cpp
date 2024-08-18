//#include <cmath>
//#include <iostream>
//
//using namespace std;
//
//int T, H, ret, tmp;
//int n = 1;
//
//void isZero(int H)
//{
//    if (H == 0)
//    {
//        ret += 1;
//        return;
//    }
//    
//    if (H - n * 2 > 0)
//    {
//        ret++;
//        H -= (n++) * 2;
//        isZero(H);
//    }
//
//    return;
//}
//
//int main()
//{
//    cin >> T;
//    while (T--)
//    {
//        cin >> H;
//        H -= 1;
//        isZero(H);
//
//        if (H > ret)
//            cout << ret << endl;
//        else
//            cout << H << endl;
//    }
//    return 0;
//}


//#include <cmath>
//#include <iostream>
//
//using namespace std;
//
//int T, H, ret = 1, tmp;
//
//void isZero(int H)
//{
//    int n = 1;
//    while (H > 0)
//    {
//        ret++;
//        H -= (n++) * 2;
//    }
//}
//
//int main()
//{
//    cin >> T;
//    while (T--)
//    {
//        cin >> H;
//        H -= 1;
//        isZero(H);
//
//        if (H > ret)
//            cout << ret << endl;
//        else
//            cout << H << endl;
//
//        ret = 1;
//    }
//    return 0;
//}