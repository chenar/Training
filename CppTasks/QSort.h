#pragma once
#include <vector>

class QSort
{
public:
	QSort();
	~QSort();

	void sort(std::vector<int>& array);
	void sortRecursive(std::vector<int>& array, int l, int r, int n);
};

