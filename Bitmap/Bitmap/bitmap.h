#pragma once

#include<vector>
#include<iostream>

class Bitmap
{
public:
	Bitmap(size_t size = 1024)
	{
		_vt.resize((size>>5)+1);
	}

	//设置某个数的位置1
	void Set(size_t num)
	{
		size_t index = num >> 5;
		size_t pos = num % 32;
		_vt[index] |= (1<<pos);
	}

	//设置某个数的位置为0
	void Reset(size_t num)
	{
		size_t index = num >> 5;
		size_t pos = num % 32;
		_vt[index] &= (~(1 << pos));
	}

	//判断一个数是否存在

	bool Exist(size_t num)
	{
		size_t index = num >> 5;
		size_t pos = num % 32;
		return _vt[index] & (1 << pos);
	}

private:
	std::vector<size_t> _vt;
};


