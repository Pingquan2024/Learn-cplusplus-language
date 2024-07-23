    /* 删除公共字符 */
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//string s, t;
//
//int main()
//{
//    getline(cin, s);
//    getline(cin, t);
//
//    bool hash[300] = { 0 };
//    for (char ch : t)    hash[ch] = true;
//
//    for (auto ch : s)
//    {
//        if (!hash[ch])
//        {
//            cout << ch;
//        }
//    }
//    return 0;
//}

    /* 两个链表的第一个公共节点 */
///*
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//			val(x), next(NULL) {
//	}
//};*/
//class Solution {
//public:
//	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
//	{
//		ListNode* cur1 = pHead1, * cur2 = pHead2;
//		while (cur1 != cur2)
//		{
//			cur1 = cur1 != nullptr ? cur1->next : pHead2;
//			cur2 = cur2 != nullptr ? cur2->next : pHead1;
//		}
//
//		return cur1;
//	}
//};

    /* mari和shiny */
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int n;
//string str;
//
//int main()
//{
//    cin >> n >> str;
//
//    int s = 0, h = 0, y = 0;
//    for (int i = 0; i < n; i++)
//    {
//        char ch = str[i];
//        if (ch == 's')   s++;
//        else if (ch == 'h')  h += s;
//        else if (ch == 'y')  y += h;
//    }
//
//    cout << y << endl;
//
//    return 0;
//}
