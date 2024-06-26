/*代码段集合，该文件不可直接运行*/


//字符串相加

class Solution {
public:
    string addStrings(string num1, string num2)
    {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int carry_bit = 0;  //进位

        string strRet;

        //提前算出大小
        strRet.reserve(num1.size() > num2.size() ? num1.size() + 1 : num2.size() + 1);

        while (end1 >= 0 || end2 >= 0)
        {
            int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
            int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
            int ret = val1 + val2 + carry_bit;
            carry_bit = ret / 10;
            ret = ret % 10;

            strRet += ('0' + ret);

            --end1;
            --end2;
        }
        if (carry_bit == 1)
        {
            strRet += '1';
        }

        reverse(strRet.begin(), strRet.end());

        return strRet;
    }
};

//统计范围内的元音字符串数
class Solution {

public:

    int vowelStrings(vector<string>& words, int left, int right) {

        unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u' };

        int ans = 0;

        for (int i = left; i <= right; ++i) {

            const string& word = words[i];

            if (vowels.count(word[0]) && vowels.count(word.back())) {

                ++ans;

            }

        }
        return ans;
    }
};


//仅仅反转字母
class Solution
{
public:

    bool isLetter(char ch)
    {
        if (ch >= 'a' && ch <= 'z')
            return true;
        if (ch >= 'A' && ch <= 'Z')
            return true;

        return false;
    }

    string reverseOnlyLetters(string s)
    {
        size_t begin = 0, end = s.size() - 1;
        while (begin < end)
        {
            while (begin < end && !isLetter(s[begin]))
                ++begin;

            while (begin < end && !isLetter(s[end]))
                --end;

            swap(s[begin], s[end]);
            ++begin;
            --end;
        }
        return s;
    }
};


//118.杨辉三角
class Solution
{
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv;
        vv.resize(numRows, vector<int>());
        for (size_t i = 0; i < vv.size(); i++)
        {
            vv[i].resize(i + 1, 0);
            vv[i][0] = vv[i][vv[i].size() - 1] = 1;
        }

        for (size_t i = 0; i < vv.size(); i++)
        {
            for (size_t j = 0; j < vv[i].size(); j++)
            {
                if (vv[i][j] == 0)
                {
                    vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
                }
            }
        }
        return vv;
    }
};

//852. 山脉数组的峰顶索引
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;

        while (left < right)
        {
            int mid = (right - left + 1) / 2 + left;
            if (arr[mid] > arr[mid - 1])
            {
                left = mid;
            }
            else right = mid - 1;
        }

        return left;
    }
};

// 数组中的第K个最大元素
// class Solution 
// {
// public:
//     int findKthLargest(vector<int>& nums, int k) 
//     {
//         priority_queue<int> pq(nums.begin(),nums.end());

//     while(--k)
//     {
//         pq.pop();
//     }

//         return pq.top();
//     }
// };

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.begin() + k);
        for (size_t i = k; i < nums.size(); ++i)
        {
            if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
};

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());

//         return nums[nums.size()-k];
//     }
// };

//二叉树的最近公共祖先
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
        {}
 * };
 */

bool GetPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path)
{
    if (root == nullptr)
        return false;

    path.push(root);
    if (root == x)
        return true;

    if (GetPath(root->left, x, path))
        return true;

    if (GetPath(root->right, x, path))
        return true;

    path.pop();
    return false;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pPath, qPath;
        GetPath(root, p, pPath);
        GetPath(root, q, qPath);

        while (pPath.size() != qPath.size())
        {
            if (pPath.size() > qPath.size())
            {
                pPath.pop();
            }
            else
            {
                qPath.pop();
            }
        }

        while (pPath.top() != qPath.top())
        {
            pPath.pop();
            qPath.pop();
        }

        return pPath.top();
    }
};

//二叉树中序遍历
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        vector<int> v;

        while (cur || !st.empty())
        {
            //1.左路节点
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }

            // 栈里面取到左路节点，它左路节点左子树访问完了
            TreeNode* top = st.top();
            st.pop();
            v.push_back(top->val);

            //访问左路节点右子树  --子问题
            cur = top->right;
        }
        return v;
    }
};

//746 使用最小花费爬楼梯
class Solution
{
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1);
        dp[1] = dp[0] = 0;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[n];
    }
};

// 只要记录有多少个大写字母即可，在遍历过程中，如果大写字母的个数小于正在遍历的下标，说明不符合题解，既不是连续的出现大写字母，如 “AaAa” 遍历到第二个 A 时的情况。
// 最终判断是否为全大写或只是首字母大写即可。

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int uc = 0;
        for (int i = 0; i < word.size(); i++)
        {
            if (isupper(word[i]) && uc++ < i)
            {
                return false;
            }
        }

        return uc == word.size() || uc <= 1;
    }
};

// 牛客除2！
#include <iostream>
#include <queue>

using namespace std;

typedef long long LL;

LL n, k;
priority_queue<LL> heap;

int main()
{
    cin >> n >> k;
    LL sum = 0, x;

    while (n--)
    {
        cin >> x;
        sum += x;
        if (x % 2 == 0)
        {
            heap.push(x);
        }
    }

    while (heap.size() && k--)
    {
        LL t = heap.top() / 2;
        heap.pop();
        sum -= t;
        if (t % 2 == 0)
        {
            heap.push(t);
        }
    }

    cout << sum << endl;
    return 0;
}

//日期间差几天
class Solution
{
    bool leap_year(int year)
    {
        return ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0));
    }

    int date_to_int(string date)
    {
        int year, month, day;
        sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
        int month_length[] = { 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
        int ans = 0;
        while (year != 1971 or month != 1 or day != 1)
        {
            ++ans;
            if (--day == 0)
                if (--month == 0)
                    --year;
            if (day == 0)
            {
                day = month_length[month];
                if (month == 2 && leap_year(year))
                    ++day;
            }
            if (month == 0)
                month = 12;
        }
        return ans;
    }

public:
    int daysBetweenDates(string date1, string date2)
    {
        return abs(date_to_int(date1) - date_to_int(date2));
    }
};


//557. 反转字符串中的单词 III
class Solution
{
public:
    string reverseWords(string s)
    {
        size_t start = 0;
        size_t end = s.find(" ");
        while (end != string::npos)
        {
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
            end = s.find(" ", start);
        }

        end = s.size();
        reverse(s.begin() + start, s.begin() + end);
        return s;
    }
};


//二维字符数组和一个单词，判断单词是否在数组中出现，
class Solution
{
    int n, m;
    bool vis[101][101] = { 0 };
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };

public:

    bool exist(vector<string>& board, string word)
    {
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(board, i, j, word, 0)) return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<string>& board, int i, int j, string& word, int pos)
    {
        if (pos == word.size() - 1)
        {
            return true;
        }

        vis[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            int a = i + dx[k], b = j + dy[k];
            if (a >= 0 && a < m && b >= 0 && b < n && !vis[a][b] && board[a][b] == word[pos + 1])
            {
                if (dfs(board, a, b, word, pos + 1)) return true;
            }
        }

        vis[i][j] = false;
        return false;
    }
};

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = (int)prices.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) 
            {
                ans = max(ans, prices[j] - prices[i]);
            }
        }
        return ans;
    }
};


//class Solution
//{
//public:
//    vector<int> twoSum(vector<int>& nums, int target)
//    {
//        for (int i = 0; i < nums.size() - 1; i++)
//        {
//
//        }
//    }
//};
