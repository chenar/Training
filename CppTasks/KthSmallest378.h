#pragma once
#include <vector>

class KthSmallest378
{
public:
	KthSmallest378() {};
	int combinationSum4(std::vector<int>& nums, int target);

private:
	int combinationSumRecursive(std::vector<int>& nums, int target, int current);
};

