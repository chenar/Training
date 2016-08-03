#include "stdafx.h"

#include <vector>

#include "KthSmallest378.h"

int KthSmallest378::combinationSum4(std::vector<int>& nums, int target) {
	return combinationSumRecursive(nums, target, 0);
}

int KthSmallest378::combinationSumRecursive(std::vector<int>& nums, int target, int current)
{
	if (current > target)
	{
		return 0;
	}
	else if (current == target)
	{
		return 1;
	}
	else
	{
		int result = 0;
		for (int num : nums)
		{
			result += combinationSumRecursive(nums, target, current + num);
		}
		return result;
	}
}
