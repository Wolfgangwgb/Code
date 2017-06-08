#pragma once
#include<string>
#include<string.h>

template <class K>
struct Hash
{};

inline size_t Hash_string(const char* s)
{
	unsigned long h = 0;
	for (; *s; ++s)
	{
		h = h * 5 + *s;
	}
	return size_t(h);
}
template <>
struct Hash<string>
{
	size_t operator()(string x)const
	{
		return Hash_string(x.c_str());
	}
};
template <>
struct Hash<char*>
{
	size_t operator()(const char *s)const
	{
		return Hash_string(s);
	}
};
template <>
struct Hash<const char*>
{
	size_t operator()(const char *s)const
	{
		return Hash_string(s);
	}
};
template <>
struct Hash<char>
{
	size_t operator()(char x)const
	{
		return x;
	}
};
template <>
struct Hash<int>
{
	size_t operator()(int x)const
	{
		return x;
	}
};


template <>
struct Hash<short>
{
	size_t operator()(short x)const
	{
		return x;
	}
};
template <>
struct Hash<long>
{
	size_t operator()(long x)const
	{
		return x;
	}
};



//////////////////////////////////
////±È½ÏÆ÷//////

