#pragma once
#include <vector>

class CombinationSumIV377
{
public:
	CombinationSumIV377(){}

	int combinationSum4(std::vector<int>& nums, int target);
private:
	int combinationSumRecursive(std::vector<int>& nums, int target, int current);;
};

