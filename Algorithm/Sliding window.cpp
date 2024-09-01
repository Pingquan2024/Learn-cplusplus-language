#include <iostream>
#include <vector>

class Solution01
{
	int minSubArrayLen(int target, std::vector<int>& nums)
	{
		int n = nums.size();
		int sum = 0, left = 0, right = 0;
		int len = INT_MAX;
		while (right < n)
		{
			sum += nums[right];
			while (sum >= target)
			{
				len = std::min(right - left + 1, len);
				sum -= nums[left++];
			}
			right++;
		}

		return len == INT_MAX ? 0 : len;
	}

};