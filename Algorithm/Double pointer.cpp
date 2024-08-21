#include <iostream>
#include <string>
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
	std::vector<int> nums { 0,1,0,3,12 };
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

void TestDuplicateZeros()
{
	std::vector<int> arr{ 0,1,2,3,12 };
	Solution02().duplicateZeros(arr);
	for (auto e : arr)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

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

void TestIsHappy()
{
	int ret = Solution03().isHappy(10);
	std::cout << ret << std::endl;
}

/* 04.盛最多水的容器*/
class Solution04
{
public:
	int maxArea(std::vector<int>& height)
	{
		int left = 0, right = height.size() - 1, ret = 0;

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

void TestMaxArea()
{
	std::vector<int> height{ 1,8,6,2,5,4,8,3,7 };
	int ret = Solution04().maxArea(height);
	std::cout << ret << std::endl;
}

/* 05. 和为s的两个数 ---> 查找总价格为目标值的两个商品 */
class Solution05
{
public:
	std::vector<int> twoSum(std::vector<int>& price, int target)
	{
		int left = 0, right = price.size() - 1;
		while (left < right)
		{
			if (price[left] + price[right] < target)
			{
				left++;
			}
			else if (price[left] + price[right] > target)
			{
				right--;
			}
			else
			{
				return { price[left],price[right] };
			}
		}
		return { -1,-1 };
	}
};

void TestTwoSum()
{
	std::vector<int> price{ 8, 21, 27, 34, 52, 66 };
	int target = 61;
	std::vector<int> ret = Solution05().twoSum(price, target);
	for (auto e : ret)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

class Solution06
{
public:
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
	{
		std::vector<std::vector<int>> ve;
		// 排序
		sort(nums.begin(), nums.end());

		// 固定一个数
		for (int i = 0; i < nums.size();)
		{
			int left = i + 1, right = nums.size() - 1;
			int target = -nums[i];
			if (nums[i] > 0) break;
			// 二个数字和的思路
			while (left < right)
			{
				int sum = nums[left] + nums[right];
				if (sum > target) right--;
				else if (sum < target) left++;
				else
				{
					ve.push_back({ nums[i], nums[left++], nums[right--] });
					while (left < right && nums[left] == nums[left - 1])
					{
						left++;
					}

					while (left < right && nums[right] == nums[right + 1])
					{
						right--;
					}
				}
			}
			i++;
			while (i < nums.size() && nums[i] == nums[i - 1])
			{
				i++;
			}
		}
		return ve;
	}
};

void TestThreeSum()
{
	//std::vector<int> v{ 1,1,4,5,4,6,-4,-4,0,0,-1,0 };
	std::vector<int> v{ -1,0,1,2,-1,-4 };
	//std::vector<int> v{ 0, 1, 1 };
	std::vector<std::vector<int>> ret = Solution06().threeSum(v);
	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[0].size(); j++)
		{
			std::cout << ret[i][j] << " ";
		}
		std::cout << std::endl;
	}

}

class Solution07
{
public:
	std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
	{
		sort(nums.begin(), nums.end());

		std::vector<std::vector<int>> ve;
		for (int i = 0; i < nums.size(); )
		{
			// 固定了a
			for (int j = i + 1; j < nums.size();)
			{
				// 固定了b
				int left = j + 1, right = nums.size() - 1;
				long long targetTmp = (long long)target - nums[i] - nums[j];
				while (left < right)
				{
					int sum = nums[left] + nums[right];
					if (sum > targetTmp)
					{
						right--;
					}
					else if (sum < targetTmp)
					{
						left++;
					}
					else
					{
						// 相等,然后去重
						ve.push_back({ nums[i], nums[j], nums[left++], nums[right--] });
						while (left < right && nums[left] == nums[left - 1]) left++;
						while (left < right && nums[right] == nums[right + 1]) right--;
					}
				}
				j++;
				while (j < nums.size() && nums[j] == nums[j - 1]) j++;
			}
			i++;
			while (i < nums.size() && nums[i] == nums[i - 1]) i++;
		}
		return ve;
	}
};


void TestFourSum()
{
	std::vector<int> arr{ 1,0,-1,0,-2,2 };
	int target = 0;
	std::vector<std::vector<int>> ret = Solution07().fourSum(arr, target);

		for (auto e : ret)
		{
			for (auto number : e)
			{
				std::cout << number << " ";
			}
			std::cout << std::endl;
		}

}


#if 0
int main()
{
	// TestMovezeroes();

	// TestDuplicateZeros();

	// TestIsHappy();

	// TestMaxArea();

	// TestTwoSum();

	// TestThreeSum();

	TestFourSum();

	return 0;
}
#endif
