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
//        // ����ǰ
//        while (h > 0 && H > 0)
//        {
//            H -= a;
//            // �ҹ�����
//            if (H > 0)   // ë��ֻ������Ǿͼ���
//            {
//                h -= A;
//                if (h < 0)
//                {
//                    break;
//                }
//            }
//            else    // ë�������
//            {
//                ret++;
//                // ����һֻë���
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
