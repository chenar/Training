#pragma once
#include <memory>

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
};

