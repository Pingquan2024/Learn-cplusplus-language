//#include <iterator>
//class Solution
//{
//public:
//    int m, n;
//
//    string solve(string s, string t)
//    {
//        m = s.size() - 1, n = t.size() - 1;
//        int tmp = 0;
//        string ret;
//        while (m >= 0 || n >= 0 || tmp)
//        {
//            if (m >= 0)  tmp += s[m--] - '0';
//            if (n >= 0)  tmp += t[n--] - '0';
//            ret += (tmp % 10) + '0';
//            tmp /= 10;
//        }
//
//        reverse(ret.begin(), ret.end());
//
//        return ret;
//    }
//};



//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//	ListNode(int x)
//		: val(x)
//		,next(nullptr)
//	{}
//};
//
//class Solution
//{
//public:
//    ListNode* reverse(ListNode* head)
//    {
//        ListNode* newhead = new ListNode(0);
//        ListNode* cur = head;
//
//        while (cur)
//        {
//            ListNode* next = cur->next;
//            cur->next = newhead->next;
//            newhead->next = cur;
//            cur = next;
//        }
//        cur = newhead->next;
//        return newhead;
//    }
//
//    ListNode* addInList(ListNode* head1, ListNode* head2)
//    {
//        head1 = reverse(head1);
//        head2 = reverse(head2);
//
//        int tmp = 0;
//
//        ListNode* cur1 = head1, * cur2 = head2;
//        ListNode* ret = new ListNode(0);
//        ListNode* prev = ret;
//
//        while (cur1 || cur2 || tmp)
//        {
//            if (cur1)
//            {
//                tmp += cur1->val;
//                cur1 = cur1->next;
//            }
//
//            if (cur2)
//            {
//                tmp += cur2->val;
//                cur2 = cur2->next;
//            }
//            prev = prev->next = new ListNode(tmp % 10);
//            tmp /= 10;
//        }
//
//        cur1 = ret->next;
//        ret->next = nullptr;
//        delete ret;
//
//        return reverse(cur1);
//    }
//};
//
//
//
//
//
//int main()
//{
//	ListNode* nhead = new ListNode(9);
//	ListNode* next1 = new ListNode(3);
//	ListNode* next2 = new ListNode(7);
//	nhead->next = next1;
//	next1->next = next2;
//
//	ListNode* nhead1 = new ListNode(6);
//	ListNode* next11 = new ListNode(3);
//	nhead1->next = next11;
//
//	Solution().addInList(nhead,nhead1);
//
//	return 0;
//}




//class Solution
//{
//public:
//
//    string solve(string s, string t)
//    {
//        reverse(s.begin(), s.end());
//        reverse(t.begin(), t.end());
//
//        int m = s.size(), n = t.size();
//        vector<int> tmp(m + n);
//
//        // 1. 无进位相乘
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                tmp[i + j] += ((s[i] - '0') * (t[j] - '0'));
//            }
//        }
//
//        // 2. 处理进位
//        int c = 0;
//        string ret;
//        for (auto x : tmp)
//        {
//            c += x;
//            ret += c % 10 + '0';
//            c /= 10;
//        }
//
//        while (c)
//        {
//            ret += (c % 10) + '0';
//            c /= 10;
//        }
//
//        // 3. 处理前导零
//        while (ret.size() > 1 && ret.back() == '0')
//        {
//            ret.pop_back();
//        }
//
//        reverse(ret.begin(), ret.end());
//
//        return ret;
//    }
//};