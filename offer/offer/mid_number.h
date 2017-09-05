#pragma once
#include<iostream>
#include<list>
using namespace std;



/*class Solution11 {
public:
	void Insert(int num)
	{
		l.push_back(num);
		l.sort();
	}

	double GetMedian()
	{
		list<int>::iterator it = l.begin();
		if (l.size() % 2 != 0)
		{
			for (int i = 0; i < l.size() / 2; i++)
				it++;
			return *it;
		}
		else
		{
			for (int i = 0; i <l.size() / 2-1; i++)
				it++;
			return (*it +*(it++))>>1;
		}
	}
private:
	list<int> lmin;
	list<int> lmax;

};
//5,2,3,4,1,6,7,0,8
void Test_mid_number()
{
	Solution11 s;
	s.Insert(5);
	s.Insert(2);
	s.Insert(3);
	s.Insert(4);
	s.Insert(1);
	s.Insert(6);
	s.Insert(7);
	s.Insert(0);
	s.Insert(8);

	double ret = s.GetMedian();
	s.Insert(11);
	ret = s.GetMedian();
}*/