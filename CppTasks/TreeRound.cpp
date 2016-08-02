#include "stdafx.h"
#include "TreeRound.h"
#include <vector>

using namespace std;

TreeRound::TreeRound()
{
	vector<shared_ptr<Node>> nodes(10, make_shared<Node>());

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
}


TreeRound::~TreeRound()
{
}
