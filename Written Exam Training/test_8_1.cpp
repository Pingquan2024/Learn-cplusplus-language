//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int n, m;
//const int N = 10000;
//// int arr1[N], arr2[N];
//int ret[N];
//vector<int> v, v1;
//
//int main()
//{
//    cin >> n >> m;
//    // 归并
//    int x = 0;
//    for (int i = 0; i < n; i++)
//    {
//        // cin >> arr1[i];
//        // v.push_back(arr1[i]);
//        cin >> x;
//        v.push_back(x);
//        x = 0;
//    }
//
//    for (int i = 0; i < m; i++)
//    {
//        // cin >> arr2[i];
//        // v1.push_back(arr2[i]);
//        cin >> x;
//        v1.push_back(x);
//        x = 0;
//    }
//
//    sort(v.begin(), v.end());
//    sort(v1.begin(), v1.end());
//
//    int cur1 = 0, cur2 = 0, index = 0;
//    while (cur1 < n && cur2 < m)
//    {
//        if (v[cur1] < v1[cur2])
//        {
//            ret[index++] = v[cur1++];
//        }
//        else if (v[cur1] > v1[cur2])
//        {
//            ret[index++] = v1[cur2++];
//        }
//        else
//        {
//            if ((index - 1) >= 0)
//            {
//                // ret里边有元素，需要判断该元素是否和前一个相等
//                if (ret[index - 1] != v[cur1])
//                {
//                    ret[index++] = v[cur1++];
//                    cur2++;
//                }
//                else
//                {
//                    cur1++;
//                    cur2++;
//                }
//            }
//            else
//            {
//                ret[index++] = v[cur1++];
//                cur2++;
//            }
//        }
//    }
//
//    while (cur1 < n)
//    {
//        ret[index++] = v[cur1++];
//    }
//
//    while (cur2 < m)
//    {
//        ret[index++] = v1[cur2++];
//    }
//    // 升序输出
//
//    for (int i = 0; i < index; i++)
//    {
//        cout << ret[i] << " ";
//    }
//    cout << endl;
//
//    // // 取小的尾插
//    // int cur1 = 0, cur2 = 0, index = 0;
//    // while (cur1 < n && cur2 < m)
//    // {
//    //     if (arr1[cur1] < arr2[cur2])
//    //     {
//    //         ret[index++] = arr1[cur1++];
//    //     }
//    //     else if (arr1[cur1] > arr2[cur2])
//    //     {
//    //         ret[index++] = arr2[cur2++];
//    //     }
//    //     else
//    //     {
//    //         if ((index - 1) >= 0)
//    //         {
//    //             // ret里边有元素，需要判断该元素是否和前一个相等
//    //             if (ret[index - 1] != arr1[cur1])
//    //             {
//    //                 ret[index++] = arr1[cur1++];
//    //                 cur2++;
//    //             }
//    //             else
//    //             {
//    //                 cur1++;
//    //                 cur2++;
//    //             }
//    //         }
//    //         else
//    //         {
//    //             ret[index++] = arr1[cur1++];
//    //             cur2++;
//    //         }
//    //     }
//    // }
//
//    // while (cur1 < n)
//    // {
//    //     ret[index++] = arr1[cur1++];
//    // }
//
//    // while (cur2 < m)
//    // {
//    //     ret[index++] = arr2[cur2++];
//    // }
//    // // 升序输出
//
//    // for (int i = 0; i < index; i++)
//    // {
//    //     cout << ret[i] << " ";
//    // }
//    // cout << endl;
//
//    return 0;
//}
