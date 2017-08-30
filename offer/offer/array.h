#pragma once
#include<iostream>
#include<vector>
using namespace std;

bool Find(int target, vector<vector<int> > array)
{
	if (array.empty())
		return false;
	int row = array.size();
	int col = array[0].size();
	int i = 0;
	int j = 0;
	while (j<col && i<row &&col>0&&row>0)
	{
		if (target < array[i][col - 1])
			col--;
		else if (target > array[i][col - 1])
			i++;
		else
			return true;

		if (target < array[row - 1][j])
			row--;
		else if (target > array[row - 1][j])
			j++;
		else
			return true;
	}
	return false;
}

void Test_array()
{
	vector<vector<int> > array(3);
	for (int i = 0; i<3; i++) {
		array[i].resize(3);
	}
	array[0][0] = 2;
	array[0][1] = 5;
	array[0][2] = 6;
	array[1][0] = 4;
	array[1][1] = 7;
	array[1][2] = 8;
	array[2][0] = 9;
	array[2][1] = 11;
	array[2][2] = 15;
	if (Find(2, array))
		cout << "yes" << endl;
	else
		cout << "NO" << endl;

}