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