#pragma once
#include"Stlalloc.h"


template <class T,class Alloc = alloc>
class simple_alloc
{
public:
	static T* Allocate(size_t n)
	{
		return 0 == n ? 0 : (T*)Alloc::Allocate(n*sizeof(T));
	}

	static T* Allocate()
	{
		return (T*)Alloc::Allocate(sizeof(T));
	}

	static void Deallocate(T* _p, size_t n)
	{
		if (0 != n)
			Alloc::Deallocate(_p,n*sizeof(T));
	}

	static void Deallocate(T* _p)
	{
		Alloc::Deallocate(_p,sizeof(T));
	}
};

void test()
{
	simple_alloc<char> s;
	s.Allocate();
	s.Allocate(10);
}