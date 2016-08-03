#include "stdafx.h"
#include "QSort.h"


QSort::QSort()
{
}


QSort::~QSort()
{
}

void QSort::sort(std::vector<int>& array)
{
	sortRecursive(array, 0, array.size() - 1, array.size());
}

void QSort::sortRecursive(std::vector<int>& array, int l, int r, int n)
{
	if (l >= r)
	{
		return;
	}
	int refR = r;
	int refL = l;
	int m = (l + r) / 2;
	int mVal = array[m];
	while (l <= r)
	{
		while (l < n && array[l] < mVal)
			++l;
		while (r >= 0 && array[r] > mVal)
			--r;
		if (l <= r)
		{
			int swap = array[l];
			array[l] = array[r];
			array[r] = swap;
			r--;
			l++;
		}
	}
	sortRecursive(array, l, refR, n);
	sortRecursive(array, refL, r, n);

}
