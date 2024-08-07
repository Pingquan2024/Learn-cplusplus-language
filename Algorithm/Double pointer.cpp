#include <iostream>
#include <vector>
#include <algorithm>

/* 01. 移动零 */
class Solution01
{
public:
    void moveZeroes(std::vector<int>& nums)
    {
        size_t n = nums.size();

        int cur = 0, dest = -1;
        while (cur < n)
        {
            if (nums[cur] == 0)
            {
                cur++;
            }
            else
            {
                std::swap(nums[dest + 1], nums[cur]);
                dest++;
                cur++;
            }
        }
    }
};

void TestMovezeroes()
{
    std::vector<int> nums{ 0,1,0,3,12 };
    Solution01().moveZeroes(nums);

    for (int e : nums)
    {
        std::cout << e << ",";
    }
    std::cout << std::endl;
}

/* 02.复写零 */
class Solution02
{
public:
    void duplicateZeros(std::vector<int>& arr)
    {
        int n = arr.size(), cur = 0, dest = -1;

        while (cur < n)
        {
            if (arr[cur] != 0)
            {
                dest++;
            }
            else
            {
                dest += 2;
            }
            if (dest >= n - 1)
            {
                break;
            }
            cur++;
        }

        // 处理边界情况
        if (dest == n)
        {
            arr[n - 1] = 0;
            cur--;
            dest -= 2;
        }

        while (cur >= 0)
        {
            if (arr[cur]) arr[dest--] = arr[cur--];
            else
            {
                arr[dest--] = 0;
                arr[dest--] = 0;
                cur--;
            }
        }
    }
};

/* 03.快乐数 */
class Solution03
{
public:
    int bitSum(int n)
    {
        int sum = 0;

        while (n)
        {
            int tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int slow = n, fast = bitSum(n);
        while (slow != fast)
        {
            slow = bitSum(slow);
            fast = bitSum(bitSum(fast));
        }
        return slow == 1;
    }
};

/* 04.盛最多水的容器*/
class Solution04
{
public:
    int maxArea(std::vector<int>& height)
    {
        int left = 0, right = height.size() - 1, ret;

        while (left < right)
        {
            int v = std::min(height[left], height[right]) * (right - left);
            ret = std::max(ret, v);
            if (height[left] > height[right]) right--;
            else left++;
        }

        return ret;
    }
};

int main()
{
    TestMovezeroes();

    return 0;
}
