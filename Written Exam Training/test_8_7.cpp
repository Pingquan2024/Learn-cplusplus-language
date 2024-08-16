//#include <iostream>
//
//using namespace std;
//
//// const int N = 1e5 + 10;
//int n, arr[100000];
//int sum1, sum2, sum3, sum4;
//
//int main()
//{
//    cin >> n;
//
//    for (int i = 0; i < n; i++)
//    {
//        cin >> arr[i];
//        if (i % 2 == 0)
//        {
//            sum1 += arr[i];
//        }
//
//        if (i % 2 != 0)
//        {
//            sum2 += arr[i];
//        }
//
//        if (i % 3 == 0)
//        {
//            sum3 += arr[i];
//        }
//    }
//
//    // for(int i = 1; i < n; i+=3)
//    // {
//    //     sum4 += arr[i];
//    // }
//
//    auto ret1 = sum1 > sum2 ? sum1 : sum2;
//    auto ret2 = sum2 > sum3 ? sum2 : sum3;
//    auto ret = ret1 > ret2 ? ret1 : ret2;
//    // cout << max(max(sum1, sum2), max(sum3, sum4)) << endl;
//    cout << ret << endl;
//}
