#include "stdafx.h"
#include "MaximixArrangements336.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>


using namespace std;


MaximixArrangements336::MaximixArrangements336()
{
	ComputeLongestOperationForNumber(11, 2011);
}

void MaximixArrangements336::Test()
{
	cout << "Test 1 result: " << Test1() << endl;
	cout << "Test 2 result: " << Test2() << endl;
}

string MaximixArrangements336::ComputeLongestOperationForNumber(int carriagsCount, int number)
{
	_ASSERT(carriagsCount < 26);
	string allCarriages = GenerateAllCarriages(carriagsCount);
	auto allPermutations = GenerateAllPermutations(allCarriages);
	vector<int> indexes;
	
	int currentCounter;
	for (currentCounter = 0; currentCounter < number; currentCounter++)	
	{}
	cout << "Result: " << allPermutations[currentCounter - 1] << endl;
	return allPermutations[currentCounter - 1];
}
void MaximixArrangements336::Rotate(string& carriageOrder, int pos)
{
	int length = carriageOrder.size();
	int l = pos;
	int r = length - 1;
	while(l < r)
	{
		char tmp = carriageOrder[l];
		carriageOrder[l] = carriageOrder[r];
		carriageOrder[r] = tmp;
		l++;
		r--;
	}
}

int MaximixArrangements336::CountRotations(string carriageOrder, string allCarriage)
{
	int rotationCounter = 0;
	int lenth = allCarriage.size();
	for (int i = 0; i < allCarriage.size(); i++)
	{
		auto pos = carriageOrder.find(allCarriage[i]);
	    if(pos == i)
	    {
			continue;
	    }
		else if( pos == lenth - 1)
		{
			rotationCounter++;
			Rotate(carriageOrder, i);
		}
		else
		{
			rotationCounter += 2;
			Rotate(carriageOrder, pos);
			Rotate(carriageOrder, i);
		}
	}
	return rotationCounter;
}

void MaximixArrangements336::GenerateAllPermutationsRecursive(string& current, string allCarriages, vector<string>& result, int& currentMaximum)
{
	int currentSize = current.size();
	int allCarriagesSize = allCarriages.size();
	if(allCarriagesSize == currentSize)
	{
		int rotations = CountRotations(current, allCarriages);
		if(rotations > currentMaximum)
		{
			currentMaximum = rotations;
			result.clear();
		}
		if (rotations == currentMaximum)
		{
			result.push_back(current);
		}
	}
	else
	{
		int leftChars = allCarriagesSize - currentSize;
		current.push_back(' ');
		for (int i = 0; i < allCarriagesSize; i++)
		{
			if (current.find(allCarriages[i]) == string::npos)
			{
				current[currentSize] = allCarriages[i];
				GenerateAllPermutationsRecursive(current, allCarriages, result, currentMaximum);
			}
		}
		current.pop_back();
	}
}

string MaximixArrangements336::GenerateAllCarriages(int carriagsCount)
{
	string allCarriages;
	for (int i = 0; i < carriagsCount; i++)
	{
		allCarriages += 'A' + i;
	}
	//cout << allCarriages << endl;
	return allCarriages;
}

vector<string> MaximixArrangements336::GenerateAllPermutations(string allCarriages)
{
	vector<string> permutations;

	string current;
	int initialMaximum = 1;
	GenerateAllPermutationsRecursive(current, allCarriages, permutations, initialMaximum);
//	sort(permutations.begin(), permutations.end());
	return permutations;
}


bool MaximixArrangements336::Test1()
{
	return ComputeLongestOperationForNumber(4, 1) == "DACB";
}

bool MaximixArrangements336::Test2()
{
	return ComputeLongestOperationForNumber(6, 10) == "DFAECB";
}

