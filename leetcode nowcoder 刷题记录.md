# leetcode 刷题记录

##（1）[27.移除元素](https://leetcode.cn/problems/remove-element/description/)

给你一个数组 `nums` 和一个值 `val`，你需要 **[原地](https://baike.baidu.com/item/原地算法)** 移除所有数值等于 `val` 的元素。元素的顺序可能发生改变。然后返回 `nums` 中与 `val` 不同的元素的数量。

假设 `nums` 中不等于 `val` 的元素数量为 `k`，要通过此题，您需要执行以下操作：

- 更改 `nums` 数组，使 `nums` 的前 `k` 个元素包含不等于 `val` 的元素。`nums` 的其余元素和 `nums` 的大小并不重要。
- 返回 `k`。

**示例 1：**

```c
输入：nums = [3,2,2,3], val = 3
输出：2, nums = [2,2,_,_]
解释：你的函数函数应该返回 k = 2, 并且 nums 中的前两个元素均为 2。
你在返回的 k 个元素之外留下了什么并不重要（因此它们并不计入评测）。
```

**示例 2：**

```c
输入：nums = [0,1,2,2,3,0,4,2], val = 2
输出：5, nums = [0,1,4,0,3,_,_,_]
解释：你的函数应该返回 k = 5，并且 nums 中的前五个元素为 0,0,1,3,4。
注意这五个元素可以任意顺序返回。
你在返回的 k 个元素之外留下了什么并不重要（因此它们并不计入评测）。
```

**答案**

```c
//移除元素
int removeElement(int* nums, int numsSize, int val)
{
	int src = 0;
	int dst = 0;
	while (src < numsSize)
	{
		if (nums[src] != val)
		{
			nums[dst++] = nums[src++];
		}
		else
		{
			src++;
		}
	}

	return dst;
}
```



## （2）[2129.将标题首字母大写](https://leetcode.cn/problems/capitalize-the-title/description/)

给你一个字符串 `title` ，它由单个空格连接一个或多个单词组成，每个单词都只包含英文字母。请你按以下规则将每个单词的首字母 **大写** ：

- 如果单词的长度为 `1` 或者 `2` ，所有字母变成小写。
- 否则，将单词首字母大写，剩余字母变成小写。

请你返回 **大写后** 的 `title` 。

**示例 1：**

```c
输入：title = "capiTalIze tHe titLe"
输出："Capitalize The Title"
解释：
由于所有单词的长度都至少为 3 ，将每个单词首字母大写，剩余字母变为小写。
```

**示例 2：**

```c
输入：title = "First leTTeR of EACH Word"
输出："First Letter of Each Word"
解释：
单词 "of" 长度为 2 ，所以它保持完全小写。
其他单词长度都至少为 3 ，所以其他单词首字母大写，剩余字母小写。
```

**示例 3：**

```c
输入：title = "i lOve leetcode"
输出："i Love Leetcode"
解释：
单词 "i" 长度为 1 ，所以它保留小写。
其他单词长度都至少为 3 ，所以其他单词首字母大写，剩余字母小写。
```

**答案**

```c
char* capitalizeTitle(char* title) 
{
    int n = strlen(title);
    int l = 0, r = 0;   // 单词左右边界（左闭右开）
    while (r < n) 
    {
        while (r < n && title[r] != ' ') 
        {
            ++r;
        }
        // 对于每个单词按要求处理
        if (r - l > 2) 
        {
            title[l++] = toupper(title[l]);
        }
        while (l < r) {
            title[l++] = tolower(title[l]);
        }
        l = ++r;
    }
    return title;
}

```

##（3）[349. 两个数组的交集](https://leetcode.cn/problems/intersection-of-two-arrays/)

给定两个数组 `nums1` 和 `nums2` ，返回 *它们的* *交集*输出结果中的每个元素一定是 **唯一** 的。我们可以 **不考虑输出结果的顺序** 

**示例 1：**

```
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
```

**示例 2：**

```
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
解释：[4,9] 也是可通过的
```

**代码**

```c
class Solution 
{
    bool hash[1010] ={ 0 } ;
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ret;
        for(auto x : nums1)
        {
            hash[x]=true;
        }

        for(auto x : nums2)
        {
           if(hash[x])
           {
                ret.push_back(x);
                hash[x]=false;
           }
        }
        return ret;
    }
};
```



## （4）[26. 删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/)

给你一个 **非严格递增排列** 的数组 `nums` ，请你**[ 原地](http://baike.baidu.com/item/原地算法)** 删除重复出现的元素，使每个元素 **只出现一次** ，返回删除后数组的新长度。元素的 **相对顺序** 应该保持 **一致** 。然后返回 `nums` 中唯一元素的个数。

考虑 `nums` 的唯一元素的数量为 `k` ，你需要做以下事情确保你的题解可以被通过：

- 更改数组 `nums` ，使 `nums` 的前 `k` 个元素包含唯一元素，并按照它们最初在 `nums` 中出现的顺序排列。`nums` 的其余元素与 `nums` 的大小不重要。
- 返回 `k` 。

**判题标准:**

系统会用下面的代码来测试你的题解:

```c
int[] nums = [...]; // 输入数组
int[] expectedNums = [...]; // 长度正确的期望答案

int k = removeDuplicates(nums); // 调用

assert k == expectedNums.length;
for (int i = 0; i < k; i++) 
{
    assert nums[i] == expectedNums[i];
}
```

如果所有断言都通过，那么您的题解将被 **通过**。

 

**示例 1：**

```
输入：nums = [1,1,2]
输出：2, nums = [1,2,_]
解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。
```

**示例 2：**

```
输入：nums = [0,0,1,1,1,2,2,3,3,4]
输出：5, nums = [0,1,2,3,4]
解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。
```

**代码**

```c
//删除有序数组中的重复项
int removeDuplicates(int* nums, int numsSize) 
{
	int src = 0;
	int dst = 0;
	while (src < numsSize)
	{
		if (nums[src] != nums[dst])
		{
			nums[++dst] = nums[src++];
		}
		else
		{
			src++;
		}
	}
	return dst+1;
}
```



##（5）[215. 数组中的第K个最大元素](https://leetcode.cn/problems/kth-largest-element-in-an-array/)

给定整数数组 `nums` 和整数 `k`，请返回数组中第 `**k**` 个最大的元素。

请注意，你需要找的是数组排序后的第 `k` 个最大的元素，而不是第 `k` 个不同的元素。

你必须设计并实现时间复杂度为 `O(n)` 的算法解决此问题。

 

**示例 1:**

```
输入: [3,2,1,5,6,4], k = 2
输出: 5
```

**示例 2:**

```
输入: [3,2,3,1,2,4,5,5,6], k = 4
输出: 4
```

**代码**

```c
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.begin()+k); 
        for(size_t i = k; i < nums.size(); ++i)
        {
        if(nums[i] > pq.top())
        {
            pq.pop();
            pq.push(nums[i]);
        }
        }

        return pq.top();
    }
};
```

##（6）[374. 猜数字大小](https://leetcode.cn/problems/guess-number-higher-or-lower/)

我们正在玩猜数字游戏。猜数字游戏的规则如下：

我会从 `1` 到 `n` 随机选择一个数字。 请你猜选出的是哪个数字。

如果你猜错了，我会告诉你，我选出的数字比你猜测的数字大了还是小了。

你可以通过调用一个预先定义好的接口 `int guess(int num)` 来获取猜测结果，返回值一共有三种可能的情况：

- `-1`：你猜的数字比我选出的数字大 （即 `num > pick`）。
- `1`：你猜的数字比我选出的数字小 （即 `num < pick`）。
- `0`：你猜的数字与我选出的数字相等。（即 `num == pick`）。

返回我选出的数字。

 

**示例 1：**

```
输入：n = 10, pick = 6
输出：6
```

**示例 2：**

```
输入：n = 1, pick = 1
输出：1
```

**示例 3：**

```c
输入：n = 2, pick = 1
输出：1
```

**代码**

```c
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

//二分的思想
class Solution 
{
public:
    int guessNumber(int n) 
    {
        int left = 1, right = n;
        while (left < right)        // 循环直至区间左右端点相同
        { 
            int mid = left + (right - left) / 2; 
            if (guess(mid) <= 0) 
            {
                right = mid; // 答案在区间 [left, mid] 中
            } 
            else 
            {
                left = mid + 1; // 答案在区间 [mid+1, right] 中
            }
        }
        // 此时有 left == right，区间缩为一个点，即为答案
        return right;
    }
};

```



##（7）[20. 有效的括号](https://leetcode.cn/problems/valid-parentheses/)

给定一个只包括 `'('`，`')'`，`'{'`，`'}'`，`'['`，`']'` 的字符串 `s` ，判断字符串是否有效。

有效字符串需满足：

1. 左括号必须用相同类型的右括号闭合。
2. 左括号必须以正确的顺序闭合。
3. 每个右括号都有一个对应的相同类型的左括号。

 

**示例 1：**

```
输入：s = "()"
输出：true
```

**示例 2：**

```
输入：s = "()[]{}"
输出：true
```

**示例 3：**

```
输入：s = "(]"
输出：false
```

**代码**

```c
class Solution {
public:
    bool isValid(string s) 
    {
        unordered_map<char,int> m{{'(',1},{'[',2},{'{',3},
                                {')',4},{']',5},{'}',6}};
        stack<char> st;
        bool istrue = true;
        for(char c : s)
        {
            int flag=m[c];
            if(flag >= 1 && flag <= 3) 
            	st.push(c);
            else if(!st.empty() && m[st.top()] == flag - 3) 
            	st.pop();
            else 
            {
                istrue=false;break;
            }
        }
        if(!st.empty()) 
        	istrue=false;
        
        return istrue;
    }
};

```



##（8）[746. 使用最小花费爬楼梯](https://leetcode.cn/problems/min-cost-climbing-stairs/)

给你一个整数数组 `cost` ，其中 `cost[i]` 是从楼梯第 `i` 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。

你可以选择从下标为 `0` 或下标为 `1` 的台阶开始爬楼梯。

请你计算并返回达到楼梯顶部的最低花费。

 

**示例 1：**

```
输入：cost = [10,15,20]
输出：15
解释：你将从下标为 1 的台阶开始。
- 支付 15 ，向上爬两个台阶，到达楼梯顶部。
总花费为 15 。
```

**示例 2：**

```
输入：cost = [1,100,1,1,1,100,1,1,100,1]
输出：6
解释：你将从下标为 0 的台阶开始。
- 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
- 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
- 支付 1 ，向上爬一个台阶，到达楼梯顶部。
总花费为 6 。
```

**代码**

```c
class Solution 
{
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        vector<int> dp(n + 1);
        dp[1] = dp[0] = 0;    

        for(int i = 2; i <= n; i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1] , dp[i - 2] + cost[i - 2]);
        }

        return dp[n];
    }
};
```



##（9）[LCR 088. 使用最小花费爬楼梯](https://leetcode.cn/problems/GzCJIP/)

数组的每个下标作为一个阶梯，第 `i` 个阶梯对应着一个非负数的体力花费值 `cost[i]`（下标从 `0` 开始）。

每当爬上一个阶梯都要花费对应的体力值，一旦支付了相应的体力值，就可以选择向上爬一个阶梯或者爬两个阶梯。

请找出达到楼层顶部的最低花费。在开始时，你可以选择从下标为 0 或 1 的元素作为初始阶梯。

 

**示例 1：**

```
输入：cost = [10, 15, 20]
输出：15
解释：最低花费是从 cost[1] 开始，然后走两步即可到阶梯顶，一共花费 15 。
```

 **示例 2：**

```
输入：cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
输出：6
解释：最低花费方式是从 cost[0] 开始，逐个经过那些 1 ，跳过 cost[3] ，一共花费 6 。
```

**代码**

```c
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        vector<int> dp(n + 1);
        dp[1] = dp[0] = 0;    

        for(int i = 2; i <= n; i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1] , dp[i - 2] + cost[i - 2]);
        }

        return dp[n];
    }
};
```



##（10）[415. 字符串相加](https://leetcode.cn/problems/add-strings/)

给定两个字符串形式的非负整数 `num1` 和`num2` ，计算它们的和并同样以字符串形式返回。

你不能使用任何內建的用于处理大整数的库（比如 `BigInteger`）， 也不能直接将输入的字符串转换为整数形式。

 

**示例 1：**

```
输入：num1 = "11", num2 = "123"
输出："134"
```

**示例 2：**

```
输入：num1 = "456", num2 = "77"
输出："533"
```

**示例 3：**

```
输入：num1 = "0", num2 = "0"
输出："0"
```

**代码**

```c
class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        int end1=num1.size()-1, end2=num2.size()-1;
        int carry_bit=0;  //进位
        
        string strRet;

        //提前计算出大小
        strRet.reserve(num1.size()>num2.size()?num1.size()+1:num2.size()+1);

        while(end1 >= 0 || end2 >= 0)
        {
            int val1 = end1 >= 0 ? num1[end1]-'0'  :0;
            int val2 = end2 >= 0 ? num2[end2]-'0' : 0;
            int ret = val1 + val2 + carry_bit;
            carry_bit = ret / 10;
            ret = ret % 10;

            strRet+=('0' + ret);

            --end1;
            --end2;
        }
        
        if(carry_bit == 1)
        {
            strRet += '1';
        }

        reverse(strRet.begin(),strRet.end());

        return strRet;
    }
};
```



##（11）[69。 x 的平方根 ](https://leetcode.cn/problems/sqrtx/)

给你一个非负整数 `x` ，计算并返回 `x` 的 **算术平方根** 。

由于返回类型是整数，结果只保留 **整数部分** ，小数部分将被 **舍去 。**

**注意：**不允许使用任何内置指数函数和算符，例如 `pow(x, 0.5)` 或者 `x ** 0.5` 。

 

**示例 1：**

```
输入：x = 4
输出：2
```

**示例 2：**

```
输入：x = 8
输出：2
解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
```

**代码**

```c
class Solution 
{
public:
    int mySqrt(int x) 
    {
        return sqrt(x);
    }
};
```

##（12）[162. 寻找峰值](https://leetcode.cn/problems/find-peak-element/)

峰值元素是指其值严格大于左右相邻值的元素。

给你一个整数数组 `nums`，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 **任何一个峰值** 所在位置即可。

你可以假设 `nums[-1] = nums[n] = -∞` 。

你必须实现时间复杂度为 `O(log n)` 的算法来解决此问题。

 

**示例 1：**

```
输入：nums = [1,2,3,1]
输出：2
解释：3 是峰值元素，你的函数应该返回其索引 2。
```

**示例 2：**

```
输入：nums = [1,2,1,3,5,6,4]
输出：1 或 5 
解释：你的函数可以返回索引 1，其峰值元素为 2；
     或者返回索引 5， 其峰值元素为 6。
```

**代码**

```c
class Solution 
{
public:
    int findPeakElement(vector<int>& nums) 
    {
        int i = 0;
        int left = 0,right = nums.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[mid + 1])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
```



##（13）[2660. 保龄球游戏的获胜者](https://leetcode.cn/problems/determine-the-winner-of-a-bowling-game/)

给你两个下标从 **0** 开始的整数数组 `player1` 和 `player2` ，分别表示玩家 1 和玩家 2 击中的瓶数。

保龄球比赛由 `n` 轮组成，每轮的瓶数恰好为 `10` 。

假设玩家在第 `i` 轮中击中 `xi` 个瓶子。玩家第 `i` 轮的价值为：

- 如果玩家在该轮的前两轮的任何一轮中击中了 `10` 个瓶子，则为 `2xi` 。
- 否则，为 `xi` 。

玩家的得分是其 `n` 轮价值的总和。

返回

- 如果玩家 1 的得分高于玩家 2 的得分，则为 `1` ；
- 如果玩家 2 的得分高于玩家 1 的得分，则为 `2` ；
- 如果平局，则为 `0` 。

**示例 1：**

```
输入：player1 = [4,10,7,9], player2 = [6,5,2,3]
输出：1
解释：player1 的得分是 4 + 10 + 2*7 + 2*9 = 46 。
player2 的得分是 6 + 5 + 2 + 3 = 16 。
player1 的得分高于 player2 的得分，所以 play1 在比赛中获胜，答案为 1 。
```

**示例 2：**

```
输入：player1 = [3,5,7,6], player2 = [8,10,10,2]
输出：2
解释：player1 的得分是 3 + 5 + 7 + 6 = 21 。
player2 的得分是 8 + 10 + 2*10 + 2*2 = 42 。
player2 的得分高于 player1 的得分，所以 play2 在比赛中获胜，答案为 2 。
```

**示例 3：**

```
输入：player1 = [2,3], player2 = [4,1]
输出：0
解释：player1 的得分是 2 + 3 = 5 。
player2 的得分是 4 + 1 = 5 。
player1 的得分等于 player2 的得分，所以这一场比赛平局，答案为 0 。
```

**代码**

```c
class Solution 
{
public:
    int score(const vector<int> &player) 
    {
        int res = 0;
        for (int i = 0; i < player.size(); i++) 
        {
            if ((i > 0 && player[i - 1] == 10) 
                 || (i > 1 && player[i - 2] >= 10)) 
            {
                res += 2 * player[i];
            } 
            else 
            {
                res += player[i];
            }
        }
        return res;
    }

    int isWinner(vector<int>& player1, vector<int>& player2) 
    {
        int s1 = score(player1);
        int s2 = score(player2);
        int ret = 0;
        if(s1 > s2)
        {
            ret =1;
        }
        else if(s1 < s2)
        {
            ret = 2;
        }
        else
        {
            ret = 0;
        }

        return ret;
    }
};

```



##（14）[2706. 购买两块巧克力](https://leetcode.cn/problems/buy-two-chocolates/)

给你一个整数数组 `prices` ，它表示一个商店里若干巧克力的价格。同时给你一个整数 `money` ，表示你一开始拥有的钱数。

你必须购买 **恰好** 两块巧克力，而且剩余的钱数必须是 **非负数** 。同时你想最小化购买两块巧克力的总花费。

请你返回在购买两块巧克力后，最多能剩下多少钱。如果购买任意两块巧克力都超过了你拥有的钱，请你返回 `money` 。注意剩余钱数必须是非负数。

 

**示例 1：**

```
输入：prices = [1,2,2], money = 3
输出：0
解释：分别购买价格为 1 和 2 的巧克力。你剩下 3 - 3 = 0 块钱。所以我们返回 0 。
```

**示例 2：**

```
输入：prices = [3,2,3], money = 3
输出：3
解释：购买任意 2 块巧克力都会超过你拥有的钱数，所以我们返回 3 。
```

**代码**

```cpp
class Solution 
{
public:
    int buyChoco(vector<int>& prices, int money) 
    {
        sort(prices.begin(),prices.end());
        return money-prices[0]-prices[1] >= 0 ? money-prices[0]-prices[1] : money;
    }
};

```



##（15）[104. 二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)

给定一个二叉树 `root` ，返回其最大深度。

二叉树的 **最大深度** 是指从根节点到最远叶子节点的最长路径上的节点数。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg)

 

```txt
输入：root = [3,9,20,null,null,15,7]
输出：3
```

**示例 2：**

```
输入：root = [1,null,2]
输出：2
```

**代码**

```cpp
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
class Solution 
{
public:
    int maxDepth(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return 0;
        }

        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
};
```



##（16）[125. 验证回文串](https://leetcode.cn/problems/valid-palindrome/)

如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 **回文串** 。

字母和数字都属于字母数字字符。

给你一个字符串 `s`，如果它是 **回文串** ，返回 `true` ；否则，返回 `false` 。

 

**示例 1：**

```
输入: s = "A man, a plan, a canal: Panama"
输出：true
解释："amanaplanacanalpanama" 是回文串。
```

**示例 2：**

```
输入：s = "race a car"
输出：false
解释："raceacar" 不是回文串。
```

**示例 3：**

```
输入：s = " "
输出：true
解释：在移除非字母数字字符之后，s 是一个空字符串 "" 。
由于空字符串正着反着读都一样，所以是回文串。
```

**代码**

```cpp
class Solution {
public:
    bool isLetterOrNumber(char ch) 
    {
        return (ch >= '0' && ch <= '9') 
                || (ch >= 'a' && ch <= 'z') 
                || (ch >= 'A' && ch <= 'Z');
    }

    bool isPalindrome(string s) 
    { // 先小写字母转换成大写，再进行判断
        for(auto& ch : s) 
        {
            if (ch >= 'a' && ch <= 'z')
                ch -= 32;
        }

        int begin = 0,end = s.size()-1;
        while(begin < end)
        {
         while (begin < end && !isLetterOrNumber(s[begin]))
                ++begin;
            while (begin < end && !isLetterOrNumber(s[end]))
                --end;
            if (s[begin] != s[end]) 
            {
                return false;
            } 
            else 
            {
                ++begin;
                --end;
            }
        }
        return true;
    }
};
```

##（17）[520. 检测大写字母](https://leetcode.cn/problems/detect-capital/)

我们定义，在以下情况时，单词的大写用法是正确的：

- 全部字母都是大写，比如 `"USA"` 。
- 单词中所有字母都不是大写，比如 `"leetcode"` 。
- 如果单词不只含有一个字母，只有首字母大写， 比如 `"Google"` 。

给你一个字符串 `word` 。如果大写用法正确，返回 `true` ；否则，返回 `false` 。

 

**示例 1：**

```
输入：word = "USA"
输出：true
```

**示例 2：**

```
输入：word = "FlaG"
输出：false
```

**代码**

```cpp
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

```

##（18）[面试题 17.04. 消失的数字](https://leetcode.cn/problems/missing-number-lcci/)

数组`nums`包含从`0`到`n`的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？

**注意：**本题相对书上原题稍作改动

**示例 1：**

```
输入：[3,0,1]
输出：2
```

 

**示例 2：**

```
输入：[9,6,4,2,3,5,7,0,1]
输出：8
```

**代码**

```cpp
class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int ret = 0;
        for(int i = 1;i <= nums.size(); i++)
        {
            ret ^= i;
        }

        for(auto i : nums)
        {
            ret ^= i;
        }
        return ret;
    }
};
```

##（19）[189. 轮转数组](https://leetcode.cn/problems/rotate-array/)

给定一个整数数组 `nums`，将数组中的元素向右轮转 `k` 个位置，其中 `k` 是非负数。

 

**示例 1:**

```cpp
输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]
```

**示例 2:**

```
输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释: 
向右轮转 1 步: [99,-1,-100,3]
向右轮转 2 步: [3,99,-1,-100]
```

**代码**

```cpp
class Solution 
{
public:
    void reverse(vector<int>& nums, int left, int right)
    {
        while (left < right)
        {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            ++left;
            --right;
        }
	}


    void rotate(vector<int>& nums, int k) 
    {
        if(k > nums.size())
        {
            k %= nums.size();
        }

        reverse(nums, 0, nums.size() - k -1);
        reverse(nums, nums.size() - k,nums.size() - 1);
        reverse(nums, 0,nums.size()- 1);
    }
};
```

##（20）[203. 移除链表元素](https://leetcode.cn/problems/remove-linked-list-elements/)

给你一个链表的头节点 `head` 和一个整数 `val` ，请你删除链表中所有满足 `Node.val == val` 的节点，并返回 **新的头节点** 。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/03/06/removelinked-list.jpg)

```
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]
```

**示例 2：**

```
输入：head = [], val = 1
输出：[]
```

**示例 3：**

```
输入：head = [7,7,7,7], val = 7
输出：[]
```

**代码**

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* cur = head;
        ListNode *newhead = nullptr, *tail = nullptr;
        while (cur) 
        {
            if (cur->val != val) 
            {
                if (tail == NULL) 
                {
                    newhead = tail = cur;
                } 
                else 
                {
                    tail->next = cur;
                    tail = tail->next;
                }
                cur = cur->next;
                tail->next = NULL;
            } 
            else 
            {
                ListNode* del = cur;
                cur = cur->next;
                delete del;
            }
        }
        return newhead;
    }
};

// struct ListNode* removeElements(struct ListNode* head, int val)
// {
// 	struct ListNode* cur = head;
// 	struct ListNode* newhead = NULL, * tail = NULL;
// 	while (cur)
// 	{
// 		if (cur->val!= val)
// 		{
// 			if (tail==NULL)
// 			{
// 				newhead = tail = cur;
// 			}
// 			else
// 			{
// 				tail->next = cur;
// 				tail = tail->next;
// 			}
// 			cur = cur->next;
// 			tail->next = NULL;
// 		}
// 		else
// 		{
// 			struct ListNode* del = cur;
// 			cur = cur->next;
// 			free(del);
// 		}
// 	}
// 	return newhead;
// }
```



##（21）[9. 回文数](https://leetcode.cn/problems/palindrome-number/)

给你一个整数 `x` ，如果 `x` 是一个回文整数，返回 `true` ；否则，返回 `false` 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

- 例如，`121` 是回文，而 `123` 不是。

 

**示例 1：**

```
输入：x = 121
输出：true
```

**示例 2：**

```
输入：x = -121
输出：false
解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
```

**示例 3：**

```
输入：x = 10
输出：false
解释：从右向左读, 为 01 。因此它不是一个回文数。
```

**代码**

```cpp
class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if(x <= 0) 
        {
            return x == 0;
        }
        if(x % 10 == 0)
        {
            return false;
        }

        int reverseX = 0;
        while(x > reverseX)
        {
            reverseX *= 10;
            reverseX += x % 10;
            x /= 10;
        }
    return reverseX == x || reverseX / 10 == x;
    }
};
```

##（22）[28. 找出字符串中第一个匹配项的下标](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/)

给你两个字符串 `haystack` 和 `needle` ，请你在 `haystack` 字符串中找出 `needle` 字符串的第一个匹配项的下标（下标从 0 开始）。如果 `needle` 不是 `haystack` 的一部分，则返回 `-1` 。

 

**示例 1：**

```
输入：haystack = "sadbutsad", needle = "sad"
输出：0
解释："sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0 。
```

**示例 2：**

```
输入：haystack = "leetcode", needle = "leeto"
输出：-1
解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
```

**代码**

```cpp
class Solution
{
public:
    int strStr(string haystack, string needle) 
    {
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i + m <= n; i++) 
        {
            bool flag = true;
            for (int j = 0; j < m; j++) 
            {
                if (haystack[i + j] != needle[j]) 
                {
                    flag = false;
                    break;
                }
            }
            
            if (flag) 
            {
                return i;
            }
        }
        return -1;
    }
};
```

##（23）[88. 合并两个有序数组](https://leetcode.cn/problems/merge-sorted-array/)

给你两个按 **非递减顺序** 排列的整数数组 `nums1` 和 `nums2`，另有两个整数 `m` 和 `n` ，分别表示 `nums1` 和 `nums2` 中的元素数目。

请你 **合并** `nums2` 到 `nums1` 中，使合并后的数组同样按 **非递减顺序** 排列。

**注意：**最终，合并后数组不应由函数返回，而是存储在数组 `nums1` 中。为了应对这种情况，`nums1` 的初始长度为 `m + n`，其中前 `m` 个元素表示应合并的元素，后 `n` 个元素为 `0` ，应忽略。`nums2` 的长度为 `n` 。

 

**示例 1：**

```
输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]
解释：需要合并 [1,2,3] 和 [2,5,6] 。
合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。
```

**示例 2：**

```
输入：nums1 = [1], m = 1, nums2 = [], n = 0
输出：[1]
解释：需要合并 [1] 和 [] 。
合并结果是 [1] 。
```

**代码**

```cpp
class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int end1 = m-1;
        int end2 = n-1;
        int i = m+n-1;
        while(end1 >= 0 && end2 >= 0)
        {
            if(nums1[end1] > nums2[end2])
            {
                nums1[i--] = nums1[end1--];
            }
            else
            {
                nums1[i--] = nums2[end2--];
            }
        }

        while(end2 >= 0)
        {
            nums1[i--] = nums2[end2--];
        }
    }
};
```

##（24）[1512. 好数对的数目](https://leetcode.cn/problems/number-of-good-pairs/)

给你一个整数数组 `nums` 。

如果一组数字 `(i,j)` 满足 `nums[i]` == `nums[j]` 且 `i` < `j` ，就可以认为这是一组 **好数对** 。

返回好数对的数目。

 

**示例 1：**

```
输入：nums = [1,2,3,1,1,3]
输出：4
解释：有 4 组好数对，分别是 (0,3), (0,4), (3,4), (2,5) ，下标从 0 开始
```

**示例 2：**

```
输入：nums = [1,1,1,1]
输出：6
解释：数组中的每组数字都是好数对
```

**示例 3：**

```
输入：nums = [1,2,3]
输出：0
```

**代码**

```c
int numIdenticalPairs(int* nums, int numsSize) 
{
    int count=0;
    for(int i=0;i<numsSize;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[i]==nums[j])
            {
                count++;
            }
        }

    }
    return count;
}
```

##（25）[258. 各位相加](https://leetcode.cn/problems/add-digits/)

给定一个非负整数 `num`，反复将各个位上的数字相加，直到结果为一位数。返回这个结果。

 

**示例 1:**

```
输入: num = 38
输出: 2 
解释: 各位相加的过程为：
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2
由于 2 是一位数，所以返回 2。
```

**示例 2:**

```
输入: num = 0
输出: 0
```

**代码**

```c
int addDigits(int num)
{
    while (num >= 10) 
    {
        int sum = 0;
        while (num > 0) 
        {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}

```

##（26）[709. 转换成小写字母](https://leetcode.cn/problems/to-lower-case/)

给你一个字符串 `s` ，将该字符串中的大写字母转换成相同的小写字母，返回新的字符串。

 

**示例 1：**

```
输入：s = "Hello"
输出："hello"
```

**示例 2：**

```
输入：s = "here"
输出："here"
```

**示例 3：**

```
输入：s = "LOVELY"
输出："lovely"
```

**代码**

```c
char * toLowerCase(char * s)
{
    int len = strlen(s);
    for (int i = 0; i < len; ++i) 
    {
        s[i] = tolower(s[i]);
    }
    return s;
}


```

##（27）[1281. 整数的各位积和之差](https://leetcode.cn/problems/subtract-the-product-and-sum-of-digits-of-an-integer/)

给你一个整数 `n`，请你帮忙计算并返回该整数「各位数字之积」与「各位数字之和」的差。

 

**示例 1：**

```
输入：n = 234
输出：15 
解释：
各位数之积 = 2 * 3 * 4 = 24 
各位数之和 = 2 + 3 + 4 = 9 
结果 = 24 - 9 = 15
```

**示例 2：**

```
输入：n = 4421
输出：21
解释： 
各位数之积 = 4 * 4 * 2 * 1 = 32 
各位数之和 = 4 + 4 + 2 + 1 = 11 
结果 = 32 - 11 = 21
```

**代码**

```c

int subtractProductAndSum(int n) 
{
    int res1 = 1, res2 = 0;
    while (n) 
    {
        int x = n % 10;
        n /= 10;
        res1 *= x;
        res2 += x;
    }
    return res1 - res2;
}

```

##（28）[231. 2 的幂](https://leetcode.cn/problems/power-of-two/)

给你一个整数 `n`，请你判断该整数是否是 2 的幂次方。如果是，返回 `true` ；否则，返回 `false` 。

如果存在一个整数 `x` 使得 `n == 2x` ，则认为 `n` 是 2 的幂次方。

 

**示例 1：**

```
输入：n = 1
输出：true
解释：20 = 1
```

**示例 2：**

```
输入：n = 16
输出：true
解释：24 = 16
```

**示例 3：**

```
输入：n = 3
输出：false
```

**代码**

```c
bool isPowerOfTwo(int n) 
{
    return n > 0 && (n & (n - 1)) == 0;
}
```

##（29）[326. 3 的幂](https://leetcode.cn/problems/power-of-three/)

给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 `true` ；否则，返回 `false` 。

整数 `n` 是 3 的幂次方需满足：存在整数 `x` 使得 `n == 3x`

 

**示例 1：**

```
输入：n = 27
输出：true
```

**示例 2：**

```
输入：n = 0
输出：false
```

**示例 3：**

```
输入：n = 9
输出：true
```

**示例 4：**

```c
输入：n = 45
输出：false
```

**代码**

```c
//统计输入数字3进制形式下1的个数，若换算成的3进制串只有1个1，则为3的幂，否则不是

bool isPowerOfThree(int n)
{
    int count=0;
    while(n)
    {
        count+=n%3;
        n/=3;
    }
    
    return count==1?true:false;
}

```

##（30）[263. 丑数](https://leetcode.cn/problems/ugly-number/)



**丑数** 就是只包含质因数 `2`、`3` 和 `5` 的正整数。

给你一个整数 `n` ，请你判断 `n` 是否为 **丑数** 。如果是，返回 `true` ；否则，返回 `false` 。

 

**示例 1：**

```
输入：n = 6
输出：true
解释：6 = 2 × 3
```

**示例 2：**

```
输入：n = 1
输出：true
解释：1 没有质因数，因此它的全部质因数是 {2, 3, 5} 的空集。习惯上将其视作第一个丑数。
```

**示例 3：**

```
输入：n = 14
输出：false
解释：14 不是丑数，因为它包含了另外一个质因数 7 。
```

**代码**

```c
bool isUgly(int n) 
{
    if (n <= 0) 
    {
        return false;
    }

    int number[3]={2,3,5};
    for(int i=0;i<3;i++)
    {
        while(n%number[i]==0)
        {
            n/=number[i];
        }    
    }
    return n==1;
}
```



##（31）[1534. 统计好三元组](https://leetcode.cn/problems/count-good-triplets/)

给你一个整数数组 `arr` ，以及 `a`、`b` 、`c` 三个整数。请你统计其中好三元组的数量。

如果三元组 `(arr[i], arr[j], arr[k])` 满足下列全部条件，则认为它是一个 **好三元组** 。

- `0 <= i < j < k < arr.length`
- `|arr[i] - arr[j]| <= a`
- `|arr[j] - arr[k]| <= b`
- `|arr[i] - arr[k]| <= c`

其中 `|x|` 表示 `x` 的绝对值。

返回 **好三元组的数量** 。

 

**示例 1：**

```
输入：arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
输出：4
解释：一共有 4 个好三元组：[(3,0,1), (3,0,1), (3,1,1), (0,1,1)] 。
```

**示例 2：**

```
输入：arr = [1,1,2,2,3], a = 0, b = 0, c = 1
输出：0
解释：不存在满足所有条件的三元组。
```

**代码**

```c
int countGoodTriplets(int* arr, int arrSize, int a, int b, int c)
{
    int num=0;
    for(int i=0;i<arrSize-2;i++)
    {
        for(int j=i+1;j<arrSize-1;j++)
        {
            if(abs(arr[i]-arr[j])<=a)
            {
                for(int k=j+1;k<arrSize;k++)
                {
                    if(abs(arr[j]-arr[k])<=b
                        &&abs(arr[i]-arr[k])<=c)
                    {
                        num++;
                    }
                }
            }
        }
    }
    return num;
}


```

##（32）[1422. 分割字符串的最大得分](https://leetcode.cn/problems/maximum-score-after-splitting-a-string/)

给你一个由若干 0 和 1 组成的字符串 `s` ，请你计算并返回将该字符串分割成两个 **非空** 子字符串（即 **左** 子字符串和 **右** 子字符串）所能获得的最大得分。

「分割字符串的得分」为 **左** 子字符串中 **0** 的数量加上 **右** 子字符串中 **1** 的数量。

 

**示例 1：**

```
输入：s = "011101"
输出：5 
解释：
将字符串 s 划分为两个非空子字符串的可行方案有：
左子字符串 = "0" 且 右子字符串 = "11101"，得分 = 1 + 4 = 5 
左子字符串 = "01" 且 右子字符串 = "1101"，得分 = 1 + 3 = 4 
左子字符串 = "011" 且 右子字符串 = "101"，得分 = 1 + 2 = 3 
左子字符串 = "0111" 且 右子字符串 = "01"，得分 = 1 + 1 = 2 
左子字符串 = "01110" 且 右子字符串 = "1"，得分 = 2 + 1 = 3
```

**示例 2：**

```
输入：s = "00111"
输出：5
解释：当 左子字符串 = "00" 且 右子字符串 = "111" 时，我们得到最大得分 = 2 + 3 = 5
```

**示例 3：**

```
输入：s = "1111"
输出：3
```

**代码**

```c
int maxScore(char * s)
{
    int n = strlen(s);
    int presum = 0, ans = -1 - n;
    for (int i = 0; i < n; i++) 
    {
        if (i > 0 && presum * 2 - i > ans)
        {
            ans = presum * 2 - i;
        }
        if (s[i] == '0') 
        {
            presum++;
        }
    }
    return ans + n - presum;
}


```

##（33）[2586. 统计范围内的元音字符串数](https://leetcode.cn/problems/count-the-number-of-vowel-strings-in-range/)



给你一个下标从 **0** 开始的字符串数组 `words` 和两个整数：`left` 和 `right` 。

如果字符串以元音字母开头并以元音字母结尾，那么该字符串就是一个 **元音字符串** ，其中元音字母是 `'a'`、`'e'`、`'i'`、`'o'`、`'u'` 。

返回 `words[i]` 是元音字符串的数目，其中 `i` 在闭区间 `[left, right]` 内。

 

**示例 1：**

```
输入：words = ["are","amy","u"], left = 0, right = 2
输出：2
解释：
- "are" 是一个元音字符串，因为它以 'a' 开头并以 'e' 结尾。
- "amy" 不是元音字符串，因为它没有以元音字母结尾。
- "u" 是一个元音字符串，因为它以 'u' 开头并以 'u' 结尾。
在上述范围中的元音字符串数目为 2 。
```

**示例 2：**

```
输入：words = ["hey","aeo","mu","ooo","artro"], left = 1, right = 4
输出：3
解释：
- "aeo" 是一个元音字符串，因为它以 'a' 开头并以 'o' 结尾。
- "mu" 不是元音字符串，因为它没有以元音字母开头。
- "ooo" 是一个元音字符串，因为它以 'o' 开头并以 'o' 结尾。
- "artro" 是一个元音字符串，因为它以 'a' 开头并以 'o' 结尾。
在上述范围中的元音字符串数目为 3 。
```

**代码**

```c

bool cmpp(char a) 
{
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') 
    {
        return true;
    }
    return false;
}

int vowelStrings(char** words, int wordsSize, int left, int right) 
{
    int i, j;
    int len;
    int output = 0;

    for (i = left; i <= right; ++i) 
    {
        len = strlen(words[i]);
        if (cmpp(words[i][0]) && cmpp(words[i][len - 1])) 
        {
            output++;
        }
    }

    return output;
}

```

##（34）[LCR 133. 位 1 的个数](https://leetcode.cn/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/)

编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为 [汉明重量](http://en.wikipedia.org/wiki/Hamming_weight)).）。

 

**提示：**

- 请注意，在某些语言（如 Java）中，没有无符号整数类型。在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的还是无符号的，其内部的二进制表示形式都是相同的。
- 在 Java 中，编译器使用 [二进制补码](https://baike.baidu.com/item/二进制补码/5295284) 记法来表示有符号整数。因此，在上面的 **示例 3** 中，输入表示有符号整数 `-3`。

 

**示例 1：**

```
输入：n = 11 (控制台输入 00000000000000000000000000001011)
输出：3
解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
```

**示例 2：**

```
输入：n = 128 (控制台输入 00000000000000000000000010000000)
输出：1
解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。
```

**示例 3：**

```
输入：n = 4294967293 (控制台输入 11111111111111111111111111111101，部分语言中 n = -3）
输出：31
解释：输入的二进制串 11111111111111111111111111111101 中，共有 31 位为 '1'。
```

**代码**

```c
int hammingWeight(uint32_t n) 
{
    int ret = 0;
    while (n) 
    {
        n &= n - 1;
        ret++;
    }
    return ret;
}

```

##（35）[917. 仅仅反转字母](https://leetcode.cn/problems/reverse-only-letters/)

给你一个字符串 `s` ，根据下述规则反转字符串：

- 所有非英文字母保留在原有位置。
- 所有英文字母（小写或大写）位置反转。

返回反转后的 `s` *。*

 

**示例 1：**

```
输入：s = "ab-cd"
输出："dc-ba"
```

**示例 2：**

```
输入：s = "a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"
```

**示例 3：**

```
输入：s = "Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-T!"
```

**代码**

```c
class Solution 
{
public:

    bool isLetter(char ch)
    {
        if(ch >='a' && ch <= 'z')
            return true;
        if(ch >='A' && ch <= 'Z')
            return true;

        return false;
    }

    string reverseOnlyLetters(string s) 
    {
        size_t begin =0,end=s.size()-1;
        while(begin < end)
        {
            while(begin < end &&  !isLetter(s[begin]))
            ++begin;

            while(begin < end &&  !isLetter(s[end]))
            --end;

            swap(s[begin],s[end]);
            ++begin;
            --end;
        }
        return s;
    }
};
```

##（36）[118. 杨辉三角](https://leetcode.cn/problems/pascals-triangle/)

给定一个非负整数 *`numRows`，*生成「杨辉三角」的前 *`numRows`* 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。

![img](https://pic.leetcode-cn.com/1626927345-DZmfxB-PascalTriangleAnimated2.gif)

 

**示例 1:**

```
输入: numRows = 5
输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
```

**示例 2:**

```
输入: numRows = 1
输出: [[1]]
```

**代码**

```c
class Solution 
{
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv;

        //numRows行，每行vector<int>()
        vv.resize(numRows,vector<int>());
        for(size_t i=0;i<vv.size();i++)
        {
            vv[i].resize(i+1,0);
            vv[i][0]=vv[i][vv[i].size()-1]=1;
        }

        for(size_t i =0;i<vv.size();i++)
        {
            for(size_t j =0;j<vv[i].size();j++)
            {
                if(vv[i][j]==0)
                {
                    vv[i][j]=vv[i-1][j]+vv[i-1][j-1];
                }
            }
        }    
        return vv;
    }
};
```



## （37）[852. 山脉数组的峰顶索引](https://leetcode.cn/problems/peak-index-in-a-mountain-array/)

符合下列属性的数组 `arr` 称为 **山脉数组** ：

- `arr.length >= 3`
- 存在i（0 < i < arr.length - 1）使得：
  - `arr[0] < arr[1] < ... arr[i-1] < arr[i] `
  - `arr[i] > arr[i+1] > ... > arr[arr.length - 1]`

给你由整数组成的山脉数组 `arr` ，返回满足 `arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1]` 的下标 `i` 。

你必须设计并实现时间复杂度为 `O(log(n))` 的解决方案。

**示例 1：**

```
输入：arr = [0,1,0]
输出：1
```

**示例 2：**

```
输入：arr = [0,2,1,0]
输出：1
```

**示例 3：**

```
输入：arr = [0,10,5,2]
输出：1
```

**代码**

```c
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0,right = arr.size()-1;

        while(left < right)
        {
            int mid = (right-left+1)/2+left;
            if(arr[mid] > arr[mid-1]) 
            {
                left = mid;
            }
            else right = mid-1;
        }

        return left;
    }
};


```

##（38）[1470. 重新排列数组](https://leetcode.cn/problems/shuffle-the-array/)

给你一个数组 `nums` ，数组中有 `2n` 个元素，按 `[x1,x2,...,xn,y1,y2,...,yn]` 的格式排列。

请你将数组按 `[x1,y1,x2,y2,...,xn,yn]` 格式重新排列，返回重排后的数组。

 

**示例 1：**

```
输入：nums = [2,5,1,3,4,7], n = 3
输出：[2,3,5,4,1,7] 
解释：由于 x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 ，所以答案为 [2,3,5,4,1,7]
```

**示例 2：**

```
输入：nums = [1,2,3,4,4,3,2,1], n = 4
输出：[1,4,2,3,3,2,4,1]
```

**示例 3：**

```
输入：nums = [1,1,2,2], n = 2
输出：[1,2,1,2]
```

**代码**

```cpp
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) 
    {

        for(int i = 0; i < 2 * n; i ++)
        {
            int j = i < n ? 2 * i : 2 * (i - n) + 1;
            nums[j] |= (nums[i] & 1023) << 10;
        }
        for(int& e: nums) e >>= 10;
        return nums;
    }
};


```

##（39）[867. 转置矩阵](https://leetcode.cn/problems/transpose-matrix/)

给你一个二维整数数组 `matrix`， 返回 `matrix` 的 **转置矩阵** 。

矩阵的 **转置** 是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。

![img](https://assets.leetcode.com/uploads/2021/02/10/hint_transpose.png)

 

**示例 1：**

```
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[1,4,7],[2,5,8],[3,6,9]]
```

**示例 2：**

```
输入：matrix = [[1,2,3],[4,5,6]]
输出：[[1,4],[2,5],[3,6]]
```

**代码**

```cpp
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();  //m为有几行，n为一行有几个
        vector<vector<int>> transposed(n, vector<int>(m));
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                transposed[j][i] = matrix[i][j];
            }
        }
        return transposed;
    }
};
```

##（40）[283. 移动零](https://leetcode.cn/problems/move-zeroes/)



给定一个数组 `nums`，编写一个函数将所有 `0` 移动到数组的末尾，同时保持非零元素的相对顺序。

**请注意** ，必须在不复制数组的情况下原地对数组进行操作。

 

**示例 1:**

```
输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
```

**示例 2:**

```
输入: nums = [0]
输出: [0]
```

**代码**

```cpp
class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) 
        {
            if (nums[right]) 
            {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};

```

##（41）[606. 根据二叉树创建字符串](https://leetcode.cn/problems/construct-string-from-binary-tree/)



给你二叉树的根节点 `root` ，请你采用前序遍历的方式，将二叉树转化为一个由括号和整数组成的字符串，返回构造出的字符串。

空节点使用一对空括号对 `"()"` 表示，转化后需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/05/03/cons1-tree.jpg)

```
输入：root = [1,2,3,4]
输出："1(2(4))(3)"
解释：初步转化后得到 "1(2(4)())(3()())" ，但省略所有不必要的空括号对后，字符串应该是"1(2(4))(3)" 。
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2021/05/03/cons2-tree.jpg)

```
输入：root = [1,2,3,null,4]
输出："1(2()(4))(3)"
解释：和第一个示例类似，但是无法省略第一个空括号对，否则会破坏输入与输出一一映射的关系。
```

**代码**

```cpp
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
class Solution 
{
public:
    string tree2str(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return "";
        }

        string str=to_string(root->val);
        if(root->left || root->right)
        {
            str+='(';
            str+=tree2str(root->left);
            str+=')';
        }

        if(root->right)
        {
            str+='(';
            str+=tree2str(root->right);
            str+=')';
        }

        return str;
    }
};
```

##（42）[236. 二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/)



给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

[百度百科](https://baike.baidu.com/item/最近公共祖先/8918834?fr=aladdin)中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（**一个节点也可以是它自己的祖先**）。”

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

```
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出：3
解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

```
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出：5
解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
```

**示例 3：**

```
输入：root = [1,2], p = 1, q = 2
输出：1
```

**代码**

```cpp
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
    if(root == nullptr)
        return false;

    path.push(root);
    if(root == x)
        return true;

    if(GetPath(root->left, x, path))
        return true;

    if(GetPath(root->right, x, path))
        return true;

    path.pop();
    return false;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pPath,qPath;
        GetPath(root, p, pPath);
        GetPath(root, q, qPath);

        while(pPath.size() != qPath.size())
        {
            if(pPath.size() > qPath.size())
            {
                pPath.pop();
            }
            else
            {
                qPath.pop();
            }
        }

        while(pPath.top() != qPath.top())
        {
            pPath.pop();
            qPath.pop();
        }

        return pPath.top();
    }
};
```

##（43）[94. 二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/)



给定一个二叉树的根节点 `root` ，返回 *它的 **中序** 遍历* 。

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg)

```
输入：root = [1,null,2,3]
输出：[1,3,2]
```

**示例 2：**

```
输入：root = []
输出：[]
```

**示例 3：**

```
输入：root = [1]
输出：[1]
```

**代码**

```cpp
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

class Solution 
{
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*> st;
        TreeNode* cur=root;
        vector<int> v;

        while(cur || !st.empty())
        {
            //1.左路节点
            while(cur)
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
```

##（44）[26. 删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/)

给你一个 **非严格递增排列** 的数组 `nums` ，请你**[ 原地](http://baike.baidu.com/item/原地算法)** 删除重复出现的元素，使每个元素 **只出现一次** ，返回删除后数组的新长度。元素的 **相对顺序** 应该保持 **一致** 。然后返回 `nums` 中唯一元素的个数。

考虑 `nums` 的唯一元素的数量为 `k` ，你需要做以下事情确保你的题解可以被通过：

- 更改数组 `nums` ，使 `nums` 的前 `k` 个元素包含唯一元素，并按照它们最初在 `nums` 中出现的顺序排列。`nums` 的其余元素与 `nums` 的大小不重要。
- 返回 `k` 。

**判题标准:**

系统会用下面的代码来测试你的题解:

```
int[] nums = [...]; // 输入数组
int[] expectedNums = [...]; // 长度正确的期望答案

int k = removeDuplicates(nums); // 调用

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
```

**代码**

```cpp
//删除有序数组中的重复项
int removeDuplicates(int* nums, int numsSize) 
{
	int src = 0;
	int dst = 0;
	while (src < numsSize)
	{
		if (nums[src] != nums[dst])
		{
			nums[++dst] = nums[src++];
		}
		else
		{
			src++;
		}
	}
	return dst+1;
}
```

##（45）[876. 链表的中间结点](https://leetcode.cn/problems/middle-of-the-linked-list/)



给你单链表的头结点 `head` ，请你找出并返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/07/23/lc-midlist1.jpg)

```
输入：head = [1,2,3,4,5]
输出：[3,4,5]
解释：链表只有一个中间结点，值为 3 。
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2021/07/23/lc-midlist2.jpg)

```
输入：head = [1,2,3,4,5,6]
输出：[4,5,6]
解释：该链表有两个中间结点，值分别为 3 和 4 ，返回第二个结点。
```

**代码**

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head)
{
	struct ListNode* slow = head, * fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
```

##（46）[21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)



将两个升序链表合并为一个新的 **升序** 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg)

```
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
```

**示例 2：**

```
输入：l1 = [], l2 = []
输出：[]
```

**示例 3：**

```
输入：l1 = [], l2 = [0]
输出：[0]
```



**代码**

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    
    struct ListNode* mergedList;
    
    if (list1->val <= list2->val) {
        mergedList = list1;
        mergedList->next = mergeTwoLists(list1->next, list2);
    } else {
        mergedList = list2;
        mergedList->next = mergeTwoLists(list1, list2->next);
    }
    
    return mergedList;
}
```

##（47）[面试题 02.02. 返回倒数第 k 个节点](https://leetcode.cn/problems/kth-node-from-end-of-list-lcci/)



实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。

**注意：**本题相对原题稍作改动

**示例：**

```
输入： 1->2->3->4->5 和 k = 2
输出： 4
```

**说明：**

给定的 *k* 保证是有效的。

**代码**

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int kthToLast(struct ListNode* head, int k)
{
	struct ListNode* fast = head, * slow = head;
	while (k--)
	{
		if (fast == NULL)
			return NULL;

		fast = fast->next;
	}

	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow->val;
}

```

##（48）[LCR 024. 反转链表](https://leetcode.cn/problems/UHnkqh/)



给定单链表的头节点 `head` ，请反转链表，并返回反转后的链表的头节点。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)

```
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg)

```
输入：head = [1,2]
输出：[2,1]
```

**示例 3：**

```
输入：head = []
输出：[]
```



**代码**

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL)
	{
		return NULL;
	}

	struct ListNode* n1 = NULL;
	struct ListNode* n2 = head;
	struct ListNode* n3 = n2->next;

	while (n2)
	{
		n2->next = n1;

		//迭代
		n1 = n2;
		n2 = n3;
		if (n3)
			n3 = n3->next;
	}

	return n1;
}
```

##（49）[面试题 02.04. 分割链表](https://leetcode.cn/problems/partition-list-lcci/)



给你一个链表的头节点 `head` 和一个特定值 `x` ，请你对链表进行分隔，使得所有 **小于** `x` 的节点都出现在 **大于或等于** `x` 的节点之前。

你不需要 **保留** 每个分区中各节点的初始相对位置。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/01/04/partition.jpg)

```
输入：head = [1,4,3,2,5,2], x = 3
输出：[1,2,2,4,3,5]
```

**示例 2：**

```
输入：head = [2,1], x = 2
输出：[1,2]
```

**代码**

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x) 
{
    struct ListNode* small = malloc(sizeof(struct ListNode));
    struct ListNode* smallHead = small;
    struct ListNode* large = malloc(sizeof(struct ListNode));
    struct ListNode* largeHead = large;
    
    while (head != NULL) 
    {
        if (head->val < x) 
        {
            small->next = head;
            small = small->next;
        } 
        else 
        {
            large->next = head;
            large = large->next;
        }
        head = head->next;
    }
    
    large->next = NULL;
    small->next = largeHead->next;
    return smallHead->next;
}


```

##（50）[234. 回文链表](https://leetcode.cn/problems/palindrome-linked-list/)

给你一个单链表的头节点 `head` ，请你判断该链表是否为回文链表。如果是，返回 `true` ；否则，返回 `false` 。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg)

```
输入：head = [1,2,2,1]
输出：true
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg)

```
输入：head = [1,2]
输出：false
```

**代码**

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) 
{
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) 
    {
        struct ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

struct ListNode* endOfFirstHalf(struct ListNode* head) 
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast->next != NULL && fast->next->next != NULL) 
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

bool isPalindrome(struct ListNode* head) 
{
    if (head == NULL) 
    {
        return true;
    }

    // 找到前半部分链表的尾节点并反转后半部分链表
    struct ListNode* firstHalfEnd = endOfFirstHalf(head);
    struct ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

    // 判断是否回文
    struct ListNode* p1 = head;
    struct ListNode* p2 = secondHalfStart;
    bool result = true;
    while (result && p2 != NULL) 
    {
        if (p1->val != p2->val) 
        {
            result = false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    // 还原链表并返回结果
    firstHalfEnd->next = reverseList(secondHalfStart);
    return result;
}

```

##（51）[35. 搜索插入位置](https://leetcode.cn/problems/search-insert-position/)

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 `O(log n)` 的算法。

 

**示例 1:**

```
输入: nums = [1,3,5,6], target = 5
输出: 2
```

**示例 2:**

```
输入: nums = [1,3,5,6], target = 2
输出: 1
```

**示例 3:**

```
输入: nums = [1,3,5,6], target = 7
输出: 4
```

**代码**

```c
int searchInsert(int* nums, int numsSize, int target) 
{
    int left = 0;
    int right = numsSize - 1;
    int ans = numsSize;
    while (left <= right) 
    {
        int mid = left + ((right - left) / 2);
        if(nums[mid]>=target)
        {
            ans = mid;
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    return ans;
}
```



##（52）[141. 环形链表](https://leetcode.cn/problems/linked-list-cycle/)



给你一个链表的头节点 `head` ，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 `next` 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 `pos` 来表示链表尾连接到链表中的位置（索引从 0 开始）。**注意：`pos` 不作为参数进行传递** 。仅仅是为了标识链表的实际情况。

*如果链表中存在环* ，则返回 `true` 。 否则，返回 `false` 。

 

**示例 1：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist.png)

```
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。
```

**示例 2：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test2.png)

```
输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。
```

**示例 3：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test3.png)

```
输入：head = [1], pos = -1
输出：false
解释：链表中没有环。
```

**代码**

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) 
{
    struct ListNode*slow=head,*fast=head;
    while(fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
        {
            return true;
        }
    }

    return false;
}
```

##（53）[142. 环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/)



给定一个链表的头节点  `head` ，返回链表开始入环的第一个节点。 *如果链表无环，则返回 `null`。*

如果链表中有某个节点，可以通过连续跟踪 `next` 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 `pos` 来表示链表尾连接到链表中的位置（**索引从 0 开始**）。如果 `pos` 是 `-1`，则在该链表中没有环。**注意：`pos` 不作为参数进行传递**，仅仅是为了标识链表的实际情况。

**不允许修改** 链表。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png)

```
输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。
```

**示例 2：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test2.png)

```
输入：head = [1,2], pos = 0
输出：返回索引为 0 的链表节点
解释：链表中有一个环，其尾部连接到第一个节点。
```

**示例 3：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test3.png)

```c
输入：head = [1], pos = -1
输出：返回 null
解释：链表中没有环。
```

**代码**

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) 
{
    struct ListNode*slow=head,*fast=head;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;

        //带环
        if(slow==fast)
        {
            //求入点
            struct ListNode *meet=slow;
            while(head !=meet)
            {
                head=head->next;
                meet=meet->next;
            }
            return meet;
        }
    }

    return NULL;
}
```

##（54）[136. 只出现一次的数字](https://leetcode.cn/problems/single-number/)



给你一个 **非空** 整数数组 `nums` ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

 

**示例 1 ：**

```
输入：nums = [2,2,1]
输出：1
```

**示例 2 ：**

```
输入：nums = [4,1,2,1,2]
输出：4
```

**示例 3 ：**

```
输入：nums = [1]
输出：1
```

**代码**

```c
int singleNumber(int* nums, int numsSize) 
{
	int n = 0;
	for (int i = 0; i < numsSize; i++) 
    {
		n ^= nums[i];
	}
	return n;
}

```

##（55）[66. 加一](https://leetcode.cn/problems/plus-one/)



给定一个由 **整数** 组成的 **非空** 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储**单个**数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

 

**示例 1：**

```
输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。
```

**示例 2：**

```
输入：digits = [4,3,2,1]
输出：[4,3,2,2]
解释：输入数组表示数字 4321。
```

**示例 3：**

```
输入：digits = [0]
输出：[1]
```

**代码**

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    for(int i = digitsSize - 1; i >= 0; --i)
    {
        digits[i] = digits[i] + 1;//最后元素+1判断是不是10
        //如果当前元素不为10，直接返回数组
        if(digits[i] != 10)
        {
            *returnSize = digitsSize;
            return digits;
        }
        //第一个元素不为10，后面元素均为10的情况
        if(digits[i] == 10)
            digits[i] = 0;
    }
    
    //元素全为9开辟新数组
    int* ans = malloc(sizeof(int) * (digitsSize + 1));
    memset(ans, 0, sizeof(int) * (digitsSize + 1));//全部置0
    ans[0] = 1;
    *returnSize = digitsSize + 1;
    
    return ans;
}

```

##（56）[217. 存在重复元素](https://leetcode.cn/problems/contains-duplicate/)



给你一个整数数组 `nums` 。如果任一值在数组中出现 **至少两次** ，返回 `true` ；如果数组中每个元素互不相同，返回 `false` 。

 

**示例 1：**

```
输入：nums = [1,2,3,1]
输出：true
```

**示例 2：**

```
输入：nums = [1,2,3,4]
输出：false
```

**示例 3：**

```
输入：nums = [1,1,1,3,3,4,3,2,4,2]
输出：true
```

**代码**

```c
int cmp(const void* _a, const void* _b) 
{
    int a = *(int*)_a, b = *(int*)_b;
    return a - b;
}

bool containsDuplicate(int* nums, int numsSize) 
{
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize - 1; i++) 
    {
        if (nums[i] == nums[i + 1]) 
        {
            return true;
        }
    }
    return false;
}

```

##（57）[1. 两数之和](https://leetcode.cn/problems/two-sum/)



给定一个整数数组 `nums` 和一个整数目标值 `target`，请你在该数组中找出 **和为目标值** *`target`* 的那 **两个** 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

 

**示例 1：**

```
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
```

**示例 2：**

```
输入：nums = [3,2,4], target = 6
输出：[1,2]
```

**示例 3：**

```
输入：nums = [3,3], target = 6
输出：[0,1]
```

**代码**

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    int i = 0;
    for (i = 0; i < numsSize; i++) 
    {
        int j = 0;
        for (j = i+1; j < numsSize; j++) 
        {
            if (nums[i] + nums[j] == target) 
            {
                int* ret =(int*)malloc(sizeof(int) * 2);
                ret[0] = i;
                ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    
    *returnSize = 0;
    return NULL;
}
```



##（58）[67. 二进制求和](https://leetcode.cn/problems/add-binary/)

给你两个二进制字符串 `a` 和 `b` ，以二进制字符串的形式返回它们的和。

 

**示例 1：**

```
输入:a = "11", b = "1"
输出："100"
```

**示例 2：**

```
输入：a = "1010", b = "1011"
输出："10101"
```

**代码**

```c
void reserve(char* s) 
{
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) 
    {
        char t = s[i];
        s[i] = s[len - i - 1], s[len - i - 1] = t;
    }
}

char* addBinary(char* a, char* b) 
{
    reserve(a);
    reserve(b);

    int len_a = strlen(a), len_b = strlen(b);
    int n = fmax(len_a, len_b), carry = 0, len = 0;
    char* ans = (char*)malloc(sizeof(char) * (n + 2));
    for (int i = 0; i < n; ++i) 
    {
        carry += i < len_a ? (a[i] == '1') : 0;
        carry += i < len_b ? (b[i] == '1') : 0;
        ans[len++] = carry % 2 + '0';
        carry /= 2;
    }

    if (carry) 
    {
        ans[len++] = '1';
    }
    ans[len] = '\0';
    reserve(ans);

    return ans;
}

```

##（59）[2235. 两整数相加](https://leetcode.cn/problems/add-two-integers/)

给你两个整数 `num1` 和 `num2`，返回这两个整数的和。

 

**示例 1：**

```
输入：num1 = 12, num2 = 5
输出：17
解释：num1 是 12，num2 是 5 ，它们的和是 12 + 5 = 17 ，因此返回 17 。
```

**示例 2：**

```
输入：num1 = -10, num2 = 4
输出：-6
解释：num1 + num2 = -6 ，因此返回 -6 。
```



**代码**

```c
class Solution 
{
public:
    int sum(int num1, int num2) 
    {
        return num1 + num2;
    }
};
```

##（60）[2469. 温度转换](https://leetcode.cn/problems/convert-the-temperature/)

给你一个四舍五入到两位小数的非负浮点数 `celsius` 来表示温度，以 **摄氏度**（**Celsius**）为单位。

你需要将摄氏度转换为 **开氏度**（**Kelvin**）和 **华氏度**（**Fahrenheit**），并以数组 `ans = [kelvin, fahrenheit]` 的形式返回结果。

返回数组 *`ans`* 。与实际答案误差不超过 `10-5` 的会视为正确答案**。**

**注意：**

- `开氏度 = 摄氏度 + 273.15`
- `华氏度 = 摄氏度 * 1.80 + 32.00`

 

**示例 1 ：**

```
输入：celsius = 36.50
输出：[309.65000,97.70000]
解释：36.50 摄氏度：转换为开氏度是 309.65 ，转换为华氏度是 97.70 。
```

**示例 2 ：**

```
输入：celsius = 122.11
输出：[395.26000,251.79800]
解释：122.11 摄氏度：转换为开氏度是 395.26 ，转换为华氏度是 251.798 。
```

**代码**

```c
class Solution 
{
public:
    vector<double> convertTemperature(double celsius) 
    {
        return {celsius + 273.15, celsius * 1.80 + 32.00};
    }
};
```

##（61）[2413. 最小偶倍数](https://leetcode.cn/problems/smallest-even-multiple/)

给你一个正整数 `n` ，返回 `2` 和 `n` 的最小公倍数（正整数）。

 

**示例 1：**

```
输入：n = 5
输出：10
解释：5 和 2 的最小公倍数是 10 。
```

**示例 2：**

```
输入：n = 6
输出：6
解释：6 和 2 的最小公倍数是 6 。注意数字会是它自身的倍数。
```

**代码**

```c
class Solution 
{
public:
    int smallestEvenMultiple(int n) 
    {
        //最小公倍数
        if(n%2==0)
        {
            //偶数
            if(n>=2)
            {
                return n;
            }
        }
        return 2*n;
    }
};
```

##（62）[2236. 判断根结点是否等于子结点之和](https://leetcode.cn/problems/root-equals-sum-of-children/)

给你一个 **二叉树** 的根结点 `root`，该二叉树由恰好 `3` 个结点组成：根结点、左子结点和右子结点。

如果根结点值等于两个子结点值之和，返回 `true` ，否则返回 `false` 。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2022/04/08/graph3drawio.png)

```
输入：root = [10,4,6]
输出：true
解释：根结点、左子结点和右子结点的值分别是 10 、4 和 6 。
由于 10 等于 4 + 6 ，因此返回 true 。
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2022/04/08/graph3drawio-1.png)

```
输入：root = [5,3,1]
输出：false
解释：根结点、左子结点和右子结点的值分别是 5 、3 和 1 。
由于 5 不等于 3 + 1 ，因此返回 false 。
```

**代码**

```c
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
class Solution 
{
public:
    bool checkTree(TreeNode* root) 
    {
        if((root->left->val)+(root->right->val)==root->val)
        {
            return true;
        }
        else
            return false;
    }
};
```

##（63）[1486. 数组异或操作](https://leetcode.cn/problems/xor-operation-in-an-array/)



给你两个整数，`n` 和 `start` 。

数组 `nums` 定义为：`nums[i] = start + 2*i`（下标从 0 开始）且 `n == nums.length` 。

请返回 `nums` 中所有元素按位异或（**XOR**）后得到的结果。

 

**示例 1：**

```
输入：n = 5, start = 0
输出：8
解释：数组 nums 为 [0, 2, 4, 6, 8]，其中 (0 ^ 2 ^ 4 ^ 6 ^ 8) = 8 。
     "^" 为按位异或 XOR 运算符。
```

**示例 2：**

```
输入：n = 4, start = 3
输出：8
解释：数组 nums 为 [3, 5, 7, 9]，其中 (3 ^ 5 ^ 7 ^ 9) = 8.
```

**示例 3：**

```
输入：n = 1, start = 7
输出：7
```

**示例 4：**

```
输入：n = 10, start = 5
输出：2
```

**代码**

```c
class Solution 
{
public:
    int xorOperation(int n, int start) 
    {
        int i=0;
        int q=0;
    	for(i=0;i<n;i++)
    	{
        	q^=start + 2*i;
    	}
        
    return q;
    }
};
```

##（64）[509. 斐波那契数](https://leetcode.cn/problems/fibonacci-number/)

**斐波那契数** （通常用 `F(n)` 表示）形成的序列称为 **斐波那契数列** 。该数列由 `0` 和 `1` 开始，后面的每一项数字都是前面两项数字的和。也就是：

```
F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1
```

给定 `n` ，请计算 `F(n)` 。

 

**示例 1：**

```
输入：n = 2
输出：1
解释：F(2) = F(1) + F(0) = 1 + 0 = 1
```

**示例 2：**

```
输入：n = 3
输出：2
解释：F(3) = F(2) + F(1) = 1 + 1 = 2
```

**示例 3：**

```
输入：n = 4
输出：3
解释：F(4) = F(3) + F(2) = 2 + 1 = 3
```

**代码**

```c
class Solution 
{
public:
    int fib(int n) 
    {
        if(n == 0)
        {
            return 0;
        }

        if(n == 1)
        {
            return 1;
        }

        return  fib(n - 1) + fib(n - 2);
    }
};
```



## （65）[557. 反转字符串中的单词 III](https://leetcode.cn/problems/reverse-words-in-a-string-iii/)

给定一个字符串 `s` ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

 

**示例 1：**

```
输入：s = "Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"
```

**示例 2:**

```
输入： s = "Mr Ding"
输出："rM gniD"
```

**代码**

```cpp
class Solution 
{
public:
    string reverseWords(string s) 
    {
        size_t start = 0;
        size_t end = s.find(" ");
        while(end != string::npos)
        {
            reverse(s.begin()+start, s.begin()+end);
            start = end + 1;
            end = s.find(" ",start);
        }

        end = s.size();
        reverse(s.begin() + start,s.begin() + end);
        return s;
    }
};
```



##（66）[17. 电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/)



给定一个仅包含数字 `2-9` 的字符串，返回所有它能表示的字母组合。答案可以按 **任意顺序** 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/11/09/200px-telephone-keypad2svg.png)

 

**示例 1：**

```
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

**示例 2：**

```
输入：digits = ""
输出：[]
```

**示例 3：**

```
输入：digits = "2"
输出：["a","b","c"]
```

 

**提示：**

- `0 <= digits.length <= 4`
- `digits[i]` 是范围 `['2', '9']` 的一个数字。

**代码**

```cpp
const string str_num[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> ret;
        if(digits.empty())  
            return ret;

        string str;
        int i = 0;
        _letterCombinations(digits,i,str,ret);
        return ret;
    }

    void _letterCombinations(const string& digits ,int i, string str, vector<string>& ret)
    {
        if (i == digits.size()) 
		{
			ret.push_back(str); 
		}
		else 
		{
			int num = digits[i] - '0'; 
			const string& letters = str_num[num]; 
			for (auto ch : letters)
			{
				_letterCombinations(digits, i + 1, str + ch, ret);
			}
		}
    }
};
```



##（67）[541. 反转字符串 II](https://leetcode.cn/problems/reverse-string-ii/)

给定一个字符串 `s` 和一个整数 `k`，从字符串开头算起，每计数至 `2k` 个字符，就反转这 `2k` 字符中的前 `k` 个字符。

- 如果剩余字符少于 `k` 个，则将剩余字符全部反转。
- 如果剩余字符小于 `2k` 但大于或等于 `k` 个，则反转前 `k` 个字符，其余字符保持原样。



**示例 1：**

```
输入：s = "abcdefg", k = 2
输出："bacdfeg"
```

**示例 2：**

```
输入：s = "abcd", k = 2
输出："bacd"
```

 

**提示：**

- `1 <= s.length <= 104`
- `s` 仅由小写英文组成
- `1 <= k <= 104`

**代码**

```cpp
class Solution
{
public:
	string reverseStr(string s, int k) 
    {
		int sz = s.size();
		//以2k为一个单位对字符串进行遍历
		for (int left = 0; left < sz; left += 2 * k)
		{
			int right = left + k; //标记最后一个需要被反转的字符的下一个字符
			if (right > sz)
				right = sz; //若越界，则让right标记字符串末尾
			reverse(s.begin() + left, s.begin() + right); //反转left和right所标记的k个字符
		}
		return s; //返回目标字符串
	}
};

```



##（68）[79. 单词搜索](https://leetcode.cn/problems/word-search/)

给定一个 `m x n` 二维字符网格 `board` 和一个字符串单词 `word` 。如果 `word` 存在于网格中，返回 `true` ；否则，返回 `false` 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/11/04/word2.jpg)

```
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2020/11/04/word-1.jpg)

```
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
输出：true
```

**示例 3：**

![img](https://assets.leetcode.com/uploads/2020/10/15/word3.jpg)

```
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
输出：false
```



**提示：**

- `m == board.length`
- `n = board[i].length`
- `1 <= m, n <= 6`
- `1 <= word.length <= 15`
- `board` 和 `word` 仅由大小写英文字母组成



**进阶：**你可以使用搜索剪枝的技术来优化解决方案，使其在 `board` 更大的情况下可以更快解决问题？

**代码**

```cpp
class Solution 
{
    int n, m;
    bool vis[16][16] = { 0 };
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };

public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == word[0])
                {
                    if(dfs(board, i, j, word, 0)) return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int pos)
    {
        if(pos == word.size() - 1)
        {
            return true;
        }

        vis[i][j] = true;
        for(int k = 0; k < 4; k++)
        {
            int a = i + dx[k], b = j + dy[k];
            if(a >= 0 && a < m && b >= 0 && b < n && !vis[a][b] && board[a][b] == word[pos + 1])
            {
                if(dfs(board, a, b, word, pos + 1)) return true;
            }
        }

        vis[i][j] = false;
        return false;
    }
};
```



##（69）[169. 多数元素](https://leetcode.cn/problems/majority-element/)

给定一个大小为 `n` 的数组 `nums` ，返回其中的多数元素。多数元素是指在数组中出现次数 **大于** `⌊ n/2 ⌋` 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

**示例 1：**

```
输入：nums = [3,2,3]
输出：3
```

**示例 2：**

```
输入：nums = [2,2,1,1,1,2,2]
输出：2
```

 

**提示：**

- `n == nums.length`
- `1 <= n <= 5 * 104`
- `-109 <= nums[i] <= 109`

 

**进阶：**尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。

**代码**

```cpp
class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int candidate = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); ++i) 
        {
            if (nums[i] == candidate) 
            {
                count++;
            } 
            else if (count == 1) 
            {
                candidate = nums[i];
            } 
            else 
            {
                count--;
            }
        }

        return candidate;
    }
};
```



# nowcoder 刷题记录

## （1）[BC121有序序列合并](https://www.nowcoder.com/practice/a9e943b0dab142759807d0cfb6863897?tpId=290&tqId=39909&ru=/exam/oj)



**描述**

输入两个升序排列的序列，将两个序列合并为一个有序序列并输出。

数据范围： 1≤n,m≤1000 1≤*n*,*m*≤1000 ， 序列中的值满足 0≤*v**a**l*≤30000 

**输入描述：**

输入包含三行，

第一行包含两个正整数n, m，用空格分隔。n表示第二行第一个升序序列中数字的个数，m表示第三行第二个升序序列中数字的个数。

第二行包含n个整数，用空格分隔。

第三行包含m个整数，用空格分隔。

**输出描述：**

输出为一行，输出长度为n+m的升序序列，即长度为n的升序序列和长度为m的升序序列中的元素重新进行升序序列排列合并。

**示例1**

输入：

```
5 6
1 3 7 9 22
2 8 10 17 33 44
```

输出：

```
1 2 3 7 8 9 10 17 22 33 44
```

**代码**

```cpp
#include<stdio.h>
int main()
{
    int n, m;
    scanf("%d %d\n", &n, &m);
    int i, j,arr[2000];
    int tmp;
    for(i=0; i<n; i++)
    {
        scanf("%d ", &arr[i]);
    }
    
    for(i=n; i<n+m; i++)
    {
        scanf("%d ", &arr[i]);
    }
    
    for(i=0; i<n+m; i++)
    {
        for(j=0; j<n+m-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    
    for(i=0; i<n+m; i++)
    {
        printf("%d ", arr[i]);
    }

}

```

##（2）[NOIP2010数字统计](https://ac.nowcoder.com/acm/contest/19859/A)



**题目描述**

  请统计某个给定范围[L, R]的所有整数中，数字2出现的次数。  

  比如给定范围[2, 22]，数字2在数2中出现了1次，在数12中出现1次，在数20中出现1次，在数21中出现1次，在数22中出现2次，所以数字2在该范围内一共出现了6次。



**输入描述:**

```
输入共1行，为两个正整数L和R，之间用一个空格隔开。
```

 **输出描述:**

```
输出共1行，表示数字2出现的次数。
```

示例1

**输入**

```
2 22
```

**输出**

```
6
```

**代码**

```cpp
#include <iostream>

using namespace std;
int main()
{
    int l,r;
    cin>>l>>r;
    int ret=0;
    for(int i = l;i <= r;i++)
    {
        int tmp = i;
        while(tmp)
        {
            if(tmp%10 == 2)
            {
                ret++;
            }
            tmp /= 10;
        }
    }
    cout << ret << endl;

    return 0;
}
```

##（3）[NC313两个数组的交集](https://www.nowcoder.com/practice/56ea71d1f4e94de2aaec10e985874cce?tpId=196&tqId=40269&ru=/exam/oj)

**描述**

给定两个整数数组分别为![nums1](https://www.nowcoder.com/equation?tex=nums1), ![nums2](https://www.nowcoder.com/equation?tex=nums2)，找到它们的公共元素并按返回。

数据范围：

![img](https://www.nowcoder.com/equation?tex=1%5Cleq%20nums1.length%2C%20nums2.length%20%5Cleq%201000)
![img](https://www.nowcoder.com/equation?tex=1%5Cleq%20%20nums1%5Bi%5D%2C%20nums2%5Bi%5D%20%5Cleq%201000)

**示例1**

输入：

```
[1,2 ],[2,2,2,2]
```

返回值：

```
[2]
```

说明：

```
两个数组的公共元素只有2 
```

**示例2**

输入：

```
[1,2,3],[8,2,2,3,8]
```

返回值：

```
[2,3]
```

说明：

```
两个数组的公共元素为2和3，返回[3,2]也是一个正确的答案 
```

**代码**

```cpp
class Solution 
{
    bool hash[1010] ={ 0 } ;
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ret;
        for(auto x : nums1)
        {
            hash[x]=true;
        }

        for(auto x : nums2)
        {
           if(hash[x])
           {
                ret.push_back(x);
                hash[x]=false;
           }
        }
        return ret;
    }
};
```

##（4）[AB5点击消除](https://www.nowcoder.com/practice/8d3643ec29654cf8908b5cf3a0479fd5?tpId=308&tqId=40462&ru=/exam/oj)

**描述**

牛牛拿到了一个字符串。
他每次“点击”，可以把字符串中相邻两个相同字母消除，例如，字符串"abbc"点击后可以生成"ac"。
但相同而不相邻、不相同的相邻字母都是不可以被消除的。
牛牛想把字符串变得尽可能短。他想知道，当他点击了足够多次之后，字符串的最终形态是什么？

**输入描述：**

一个字符串，仅由小写字母组成。（字符串长度不大于300000）

 **输出描述：**

一个字符串，为“点击消除”后的最终形态。若最终的字符串为空串，则输出0。

**示例1**

输入：

```
abbc
```

输出：

```
ac
```

**示例2**

输入：

```
abba
```

输出：

```
0
```

**示例3**

输入：

```
bbbbb
```

输出：

```
b
```

**代码**

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    //本次用string模拟栈
    string s,st;

    cin >> s;
    for(auto ch : s)
    {
        if(st.size() && st.back() == ch)    //栈里有元素 且 ch和栈里元素相同
        {
            st.pop_back();                  //pop_back 相当于出栈操作
        }
        else 
        {
            st+=ch;                         //否则就入栈
        }
    }

    cout<< (st.size()==0 ? "0" : st) << endl; //判断是否为空
    return 0;
}
```

##（5）[BC64牛牛的快递](https://www.nowcoder.com/practice/41b42e7b3c3547e3acf8e90c41d98270?tpId=290&tqId=39852&ru=/exam/oj)

**描述**

牛牛正在寄快递，他了解到快递在 1kg 以内的按起步价 20 元计算，超出部分按每 kg 1元计算，不足 1kg 部分按 1kg计算。如果加急的话要额外付五元，请问牛牛总共要支付多少快递费

**输入描述：**

第一行输入一个单精度浮点数 a 和一个字符 b ，a 表示牛牛要寄的快递的重量，b表示牛牛是否选择加急，'y' 表示加急 ，'n' 表示不加急。

**输出描述：**

输出牛牛总共要支付的快递费用

**示例1**

输入：

```
1.5 y
```

输出：

```
26
```

**示例2**

输入：

```
0.7 n
```

输出：

```
20
```

**代码**

```cpp
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a;
    char b;
    cin >> a >> b;
    int ret = 0;
    if(a < 1)
    {
        ret += 20;
    }
    else
    {
        // ret += ceil(a-1) + 20;
        ret += 20;
        double c = a-1;
        if(c - int(c) > 0)
        {
            ret += (int)c +1;
        }
        else 
        {
            ret += (int)c;
        }
    }

    if(b == 'y')
    {
        ret += 5;
    }

    cout << ret;

    return 0;
}
```

##（6）[DP4最小花费爬楼梯](https://www.nowcoder.com/practice/9b969a3ec20149e3b870b256ad40844e?tpId=230&tqId=39751&ru=/exam/oj)

**描述**

给定一个整数数组 ![img](https://www.nowcoder.com/equation?tex=cost%20%5C) ，其中 ![img](https://www.nowcoder.com/equation?tex=cost%5Bi%5D%5C) 是从楼梯第![img](https://www.nowcoder.com/equation?tex=i%20%5C)个台阶向上爬需要支付的费用，下标从0开始。一旦你支付此费用，即可选择向上爬一个或者两个台阶。

你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。



请你计算并返回达到楼梯顶部的最低花费。

数据范围：数组长度满足 ![img](https://www.nowcoder.com/equation?tex=1%20%5Cle%20n%20%5Cle%2010%5E5%20%5C) ，数组中的值满足 ![img](https://www.nowcoder.com/equation?tex=1%20%5Cle%20cost_i%20%5Cle%2010%5E4%20%20%5C)

 **输入描述：**

第一行输入一个正整数 n ，表示数组 cost 的长度。

第二行输入 n 个正整数，表示数组 cost 的值。

**输出描述：**

输出最低花费

**示例1**

输入：

```
3
2 5 20
```

输出：

```
5
```

说明：

```
你将从下标为1的台阶开始，支付5 ，向上爬两个台阶，到达楼梯顶部。总花费为5 
```

**示例2**

输入：

```
10
1 100 1 1 1 90 1 1 80 1
```

输出：

```
6
```

说明：

```
你将从下标为 0 的台阶开始。
1.支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
2.支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
3.支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
4.支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
5.支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
6.支付 1 ，向上爬一个台阶，到达楼梯顶部。
总花费为 6 。  
```

**代码**

```cpp
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n;
int cost[N];
int dp[N];

int main()
{
    cin >> n;
    for(int i= 0; i<n; i++)
    {
        cin >> cost[i];
    }

    for(int i = 2; i <= n; i++)
    {
        dp[i] = min(dp[i - 1] + cost[i - 1] , dp[i - 2] + cost[i - 2]);
    }

    cout << dp[n] << endl;

    return 0;
}
```

##（7）[**数组中两个字符串的最小距离**](https://www.nowcoder.com/practice/2c6a0a8e1d20492f92941400036e0890)

**描述**

给定一个字符串数组strs，再给定两个字符串str1和str2，返回在strs中str1和str2的最小距离，如果str1或str2为null，或不在strs中，返回-1。

**输入描述：**

输入包含有多行，第一输入一个整数n（1≤n≤105）（1≤*n*≤105），代表数组strs的长度，第二行有两个字符串分别代表str1和str2，接下来n行，每行一个字符串，代表数组strs (保证题目中出现的所有字符串长度均小于等于10)。

**输出描述：**

输出一行，包含一个整数，代表返回的值。

**示例1**

输入：

```
1
CD AB
CD
```

输出：

```
-1
```

**示例2**

输入：

```
5
QWER 666
QWER
1234
qwe
666
QWER
```

**输出**

```
1
```

**备注：**

```
时间复杂度O(n)，额外空间复杂度O(1)
```

**代码**

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string str1,str2;
    string s;
    cin >> n;
    cin >> str1 >>str2;

    int prev1 = -1, prev2 = -1, ret = 0x3f3f3f3f;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        if(s == str1)         //去找最近的s2
        {
            if(prev2 != -1)
            {
                ret = min(ret,i-prev2); 
            }
            prev1 =i;
        }
        else if(s == str2)   //去找最近的s1
        {
            if(prev1 != -1)
            {
                ret = min(ret,i-prev1);
            }
            prev2 =i;
        }
    }

    if(ret == 0x3f3f3f3f)
    {
        cout << -1 <<endl;
    }
    else
    {
        cout << ret << endl;
    }

    return 0;
}
```

##（8）[**BC149** **简写单词**](https://www.nowcoder.com/practice/0cfa856bf0d649b88f6260d878f35bb4?tpId=290&tqId=39937&ru=/exam/oj)

**描述**

规定一种对于复合词的简写方式为只保留每个组成单词的首字母，并将首字母大写后再连接在一起

比如 “College English Test”可以简写成“CET”，“Computer Science”可以简写为“CS”，“I am Bob”简写为“IAB”

输入一个长复合词（组成单词数 ![img](https://www.nowcoder.com/equation?tex=sum%2Csum%5Cgeq1%E4%B8%94sum%5Cleq100),每个单词长度![img](https://www.nowcoder.com/equation?tex=len%2Clen%5Cgeq1%E4%B8%94len%5Cleq50))，请你输出它的简写

**输入描述：**

输入一个复合词

**输出描述：**

输出一行，表示复合词的简写

**示例1**

输入：

```
College English Test
```

输出：

```
CET
```

**代码**

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    while(cin >> s)
    {
        if(s[0] <= 'z' && s[0] >= 'a')
        {
            cout << (char)(s[0] - 32);
        }
        else
        {
            cout << s[0] ;
        }
    }
    return 0;
}
```



##（9）[求1+2+3+...+n](https://www.nowcoder.com/questionTerminal/7a0da8fc483247ff8800059e12d7caf1?)

**描述**

求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

数据范围： ![img](https://www.nowcoder.com/equation?tex=0%20%3C%20n%20%5Cle%20200%20)
进阶： 空间复杂度 ![img](https://www.nowcoder.com/equation?tex=O(1)) ，时间复杂度 ![img](https://www.nowcoder.com/equation?tex=O(n))

示例1

**输入**

```
5
```

 **输出**

```
15
```

**代码**

```cpp
class Sum
{
public:
    Sum()
    {
        _sum += _n;
        ++_n;
    }

    static int getSum()
    {
        return _sum;
    }

private:
    static int _n;
    static int _sum;
};

int Sum::_n=1;
int Sum::_sum=0;

class Solution 
{
public:
    int Sum_Solution(int n) 
    {
        Sum arr[n];
        return Sum::getSum();
    }
};
```

## （10）[Fibonacci数列](https://www.nowcoder.com/practice/18ecd0ecf5ef4fe9ba3f17f8d00d2d66?tpId=122&tqId=33668&ru=/exam/oj)

**描述**

Fibonacci数列是这样定义的：
F[0] = 0
F[1] = 1
for each i ≥ 2: F[i] = F[i-1] + F[i-2]
因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。

 **输入描述：**

输入为一个正整数N(1 ≤ N ≤ 1,000,000)

**输出描述：**

输出一个最小的步数变为Fibonacci数"

**示例1**

输入：

```
15
```

输出：

```
2
```

**代码**

```cpp
#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;

    int a = 0, b = 1, c = 1;
    while(n > c)
    {
        a = b;
        b = c;
        c = a + b;
    }
  
    cout << min(c - n, n - b) << endl;

    return 0;
}
```



##（11）[单词搜索](https://www.nowcoder.com/practice/987f2981769048abaf6180ed63266bb2?tpId=196&tqId=39583&ru=/exam/oj)

**描述**

给出一个二维字符数组和一个单词，判断单词是否在数组中出现，

单词由相邻单元格的字母连接而成，相邻单元指的是上下左右相邻。同一单元格的字母不能多次使用。

数据范围：

0 < 行长度 <= 100

0 < 列长度 <= 100

0 < 单词长度 <= 1000

例如：

给出的数组为["XYZE","SFZS","XDEE"]时，

对应的二维字符数组为：

![img](https://uploadfiles.nowcoder.com/images/20211126/301499_1637896596011/20B541D503C0E83922E04940EF9A339B)

若单词为"XYZZED"时，应该返回 true，

也即：

![img](https://uploadfiles.nowcoder.com/images/20211126/301499_1637896362359/1404105FB1E8B94984AC4B24ECC014A2)
若单词为"SEE"时，应该返回 true，

也即：

![img](https://uploadfiles.nowcoder.com/images/20211126/301499_1637896663211/4BC6A403DA23D72F1A8B0F7BF2CE481F)
若单词为"XYZY"时，应该返回 false。

**示例1**

输入：

```
["XYZE","SFZS","XDEE"],"XYZZED"
```

返回值：

```
true
```

**示例2**

输入：

```
["XYZE","SFZS","XDEE"],"SEE"
```

返回值：

```
true
```

**示例3**

输入：

```
["XYZE","SFZS","XDEE"],"XYZY"
```

返回值：

```
false
```

**代码**

```cpp
class Solution 
{
    int n , m;
    bool vis[101][101] = { 0 };
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };

public:

    bool exist(vector<string>& board, string word) 
    {
        m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == word[0])
                {
                    if(dfs(board, i, j, word, 0)) return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<string>& board, int i, int j, string& word, int pos)
    {
        if(pos == word.size() - 1)
        {
            return true;
        }

        vis[i][j] = true;
        for( int k = 0; k < 4; k++)
        {
            int a = i + dx[k], b = j + dy[k];
            if(a >= 0 && a < m && b >= 0 && b < n && !vis[a][b] && board[a][b] == word[pos +1])
            {
                if(dfs(board, a, b, word, pos + 1)) return true;
            }
        }

        vis[i][j] = false;
        return false;
    }
};
```



##（12）[游游的you](https://www.nowcoder.com/questionTerminal/cd117803b3364b218a8b3dcc498dee25)

游游现在有a个'y'，b个'o'，c个'u'，他想用这些字母拼成一个字符串。

三个相邻的字母是"you"可以获得2分，两个相邻的字母是"oo"，可以获得1分。

问最多可以获得多少分？

 **输入描述:**

```
第一行一个整数qqq，代表询问次数。
接下来qqq行，每行三个正整数a,b,ca,b,ca,b,c，用空格隔开。
1≤q≤1051\leq q \leq 10^51≤q≤105
1≤a,b,c≤1091\leq a,b,c \leq 10^91≤a,b,c≤109
```

 **输出描述**

```
输出q行，代表每次询问的答案。
```

示例1

 **输入**

```
3
1 1 1
2 3 2
1 5 2
```

**输出**

```
2
4
5
```

**说明**

```
第一次询问，可以拼出"you"，获得2分。
第二次询问，可以拼出"oyouyou"，获得4分。
第三次询问，可以拼出"uooooyou"，获得5分。
```

**代码**

```cpp
#include <iostream>

using namespace std;

int main()
{
    int q;
    int a, b, c;

    cin >> q;
    while(q--)
    {
        cin >> a >> b >> c;
        int x = min(a, min(b, c));
        cout << (2 * x + max(b - x -1, 0)) << endl;
    }

    return 0;
}
```

##（13）[杨辉三角](https://www.nowcoder.com/questionTerminal/e671c6a913d448318a49be87850adbcc)

KiKi知道什么叫杨辉三角之后对杨辉三角产生了浓厚的兴趣，他想知道杨辉三角的前n行，请编程帮他解答。杨辉三角，本质上是二项式(a+b)的n次方展开后各项的系数排成的三角形。其性质包括：每行的端点数为1， 一个数也为1；每个数等于它左上方和上方的两数之和。 

 **输入描述:**

```
第一行包含一个整数数n。 (1≤n≤30)
```

 **输出描述:**

```
包含n行，为杨辉三角的前n行，每个数输出域宽为5。
```

示例1

**输入**

```
6
```

**输出**

```
    1
    1    1
    1    2    1
    1    3    3    1
    1    4    6    4    1
    1    5   10   10    5    1
```

**代码**

```cpp
#include <iostream>

using namespace std;

int dp[31][31];

int main()
{
    int n;
    cin >> n;

    dp[1][1] = 1;
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            printf("%5d",dp[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```



##（14）[NC398 腐烂的苹果](https://www.nowcoder.com/practice/54ab9865ce7a45968b126d6968a77f34?tpId=196&tqId=40529&ru=/exam/oj)

**描述**

给定一个 n*×*m* 的网格，其中每个单元格中可能有三种值中的一个 0 , 1 , 2。

其中 0 表示这个格子为空、1 表示这个格子有一个完好的苹果，2 表示这个格子有一个腐烂的苹果。

腐烂的苹果每分钟会向上下左右四个方向的苹果传播一次病菌，并导致相邻的苹果腐烂。请问经过多少分钟，网格中不存在完好的苹果。如果有苹果永远不会腐烂则返回 -1

数据范围：1≤*n*,*m*≤1000 ，网格中的值满足 0≤*v**a**l*≤2 

 **示例1**

输入：

```
[[2,1,1],[1,0,1],[1,1,1]]
```

返回值：

```
4
```

 **示例2**

输入：

```
[[2,1,0],[1,0,1],[0,0,0]]
```

返回值：

```
-1
```

**代码**

```cpp
class Solution 
{
    int n, m;
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    bool vis[1001][1001] = { 0 };

public:
    int rotApple(vector<vector<int> >& grid) 
    {
        m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 2)
                    q.push({i,j});

        int ret = 0;
        while(q.size())
        {
            ret++;
            int sz = q.size();
            while(sz--)
            {
                auto [a, b] = q.front();
                q.pop();
                for(int i = 0; i < 4; i++)
                {
                    int x = a + dx[i], y = b + dy[i];
                    if(x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] == 1)
                    {
                        vis[x][y] = true;
                        q.push({x, y});
                    }
                }
            }
        }

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1 && !vis[i][j])
                    return -1;

        return ret - 1;
    }
};

```

