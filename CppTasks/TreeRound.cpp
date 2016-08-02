#include "stdafx.h"
#include "TreeRound.h"
#include <vector>
#include <iostream>

using namespace std;

TreeRound::TreeRound()
{
	vector<shared_ptr<Node>> nodes;
	for (int i = 0; i < 10; i++)
	{
		nodes.push_back(make_shared<Node>());
	}

	this->head = nodes[0];
	nodes[0]->value = 5;

	nodes[0]->right = nodes[1];
	nodes[1]->value = 4;

	nodes[0]->left = nodes[2];
	nodes[2]->value = 3;

	nodes[1]->right = nodes[3];
	nodes[3]->value = 2;

	nodes[1]->left = nodes[4];
	nodes[4]->value = 9;

	nodes[2]->right = nodes[5];
	nodes[5]->value = 7;

	nodes[2]->left = nodes[6];
	nodes[6]->value = 1;

	vector<pair<int, int>> queue;
	queue.push_back(pair<int, int>(0, head->value));
	RoundTree(this->head, 1, queue);
	int currentDepth = 0;
	for (auto it = queue.begin(); it != queue.end(); ++it)
	{
		if(currentDepth != it->first)
		{
			currentDepth = it->first;
			cout << endl;
		}
		cout << it->second << " ";
	}
}


TreeRound::~TreeRound()
{
}


void TreeRound::RoundTree(shared_ptr<Node> head, int depth, vector<pair<int, int>>& queue)
{
	if(head == nullptr)
	{
		return;
	}
	
	if(head->left != nullptr)
	{
		queue.push_back(pair<int, int>(depth, head->left->value));		
	}
	if (head->right != nullptr)
	{
		queue.push_back(pair<int, int>(depth, head->right->value));		
	}

	RoundTree(head->left, depth + 1, queue);
	RoundTree(head->right, depth + 1, queue);
}
