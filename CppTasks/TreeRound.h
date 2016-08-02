#pragma once
#include <memory>
#include <vector>
#include <queue>

class TreeRound
{
	struct Node
	{
		std::shared_ptr<Node> left = nullptr;
		std::shared_ptr<Node> right = nullptr;
		int value;
	};

	std::shared_ptr<Node> head;

public:
	TreeRound();
	~TreeRound();
	void RoundTree(std::shared_ptr<Node> head, int depth, std::vector<std::pair<int, int>>& queue );
};

