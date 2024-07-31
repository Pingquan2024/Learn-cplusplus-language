#include <iostream>
#include <vector>
#include <algorithm>


class Solution
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
    Solution().moveZeroes(nums);

    for (int e : nums)
    {
        std::cout << e << ",";
    }
    std::cout << std::endl;
}

int main()
{
    TestMovezeroes();

    return 0;
}
