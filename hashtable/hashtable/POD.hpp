
#pragma once


struct __TrueType
{
	bool Get()
	{
		return true;
	}
};

struct __FalseType
{
	bool Get()
	{
		return false;
	}
};


template <class T>
struct TypeTraits
{
	typedef __FalseType __IsPODType;
};

template<>
struct TypeTraits<int>
{
	typedef __TrueType __IsPODType;
};
template<>
struct TypeTraits<char>
{
	typedef __TrueType __ISPODType;
};