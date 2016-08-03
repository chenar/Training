#include "stdafx.h"
#include "CombinationSumIV377.h"
#include <vector>


int CombinationSumIV377::combinationSum4(std::vector<int>& nums, int target) {
	return combinationSumRecursive(nums, target, 0);
}

int CombinationSumIV377::combinationSumRecursive(std::vector<int>& nums, int target, int current)
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
