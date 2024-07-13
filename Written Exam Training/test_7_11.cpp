//#include <iostream>
//
//using namespace std;
//
///**
// * Definition for singly-linked list.*/
//struct ListNode
//{
//	int val;
//	ListNode* next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//
//class Solution {
//public:
//	ListNode* reverseList(ListNode* head)
//	{
//		if (head == nullptr)   return nullptr;
//		ListNode* cur = head;
//		ListNode* rhead = nullptr;
//
//		while (cur)
//		{
//			ListNode* next = cur->next;	// 先把next保存起来
//			cur->next = rhead;
//			rhead = cur;
//			cur = next;
//		}
//
//		return rhead;
//	}
//};
//
//int main()
//{
//	ListNode* head = new ListNode;
//	ListNode* next1 = new ListNode;
//	ListNode* next2 = new ListNode;
//	ListNode* next3 = new ListNode;
//	ListNode* next4 = new ListNode;
//	ListNode* next5 = new ListNode;
//
//	head->next = next1;
//	next1->next = next2;
//	next2->next = next3;
//	next3->next = next4;
//	next4->next = next5;
//	next5->next = nullptr;
//
//	head->val = 1;
//	next1->val = 2;
//	next2->val = 3;
//	next3->val = 4;
//	next4->val = 5;
//
//	Solution().reverseList(head);
//}


//#include <iostream>
//
//using namespace std;
//
//int q;
//int a, b, c;
//
//int main()
//{
//    cin >> q;
//
//    while (q--)
//    {
//        cin >> a >> b >> c;
//        int x = min(a, min(b, c));
//        cout << (x * 2 + max(b - x - 1, 0)) << endl;
//    }
//
//    return 0;
//}

//#include <queue>
//#include <vector>
//
//using namespace std;
//
//class Solution
//{
//public:
//    size_t n, m;
//    int ret;
//    int dx[4] = { 0, 0, 1, -1 };
//    int dy[4] = { 1, -1, 0, 0 };
//    bool vis[1001][1001] = { 0 };
//
//    queue<pair<int, int>> q; // 保存坏的苹果下标
//
//    int rotApple(vector<vector<int> >& grid)
//    {
//        m = grid.size(), n = grid[0].size();
//        for (int i = 0; i < m; i++)
//            for (int j = 0; j < n; j++)
//                if (grid[i][j] == 2)
//                    q.push({ i, j });
//
//        while (q.size())
//        {
//            size_t sz = q.size();
//            ret++;
//            while (sz--)
//            {
//                auto [a, b] = q.front();
//                q.pop();
//                for (int k = 0; k < 4; k++)
//                {
//                    int x = a + dx[k], y = b + dy[k];
//                    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] == 1)
//                    {
//                        vis[x][y] = true;   // 表示x,y位置的苹果已坏
//                        q.push({ x, y });
//                    }
//                }
//            }
//        }
//
//        for (int i = 0; i < m; i++)
//            for (int j = 0; j < n; j++)
//                if (grid[i][j] == 1 && !vis[i][j])
//                {
//                    ret = -1;
//                    break;
//                }
//
//        if (ret != -1)
//        {
//            ret -= 1;
//        }
//
//        return ret;
//    }
//};


//class Solution
//{
//public:
//    int LastRemaining_Solution(int n, int m) {
//        int f = 0;
//        for (int i = 2; i <= n; i++)
//        {
//            f = (f + m) % i;
//        }
//
//        return f;
//    }
//};