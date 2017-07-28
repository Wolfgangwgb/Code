#pragma once



template <class T,class Alloc>
class simple_alloc
{
public:
	static T* allocate(size_t n)
	{
		return 0 == n ? 0 : (T*)Alloc::allocate(n*sizeof(T));
	}

	static T* allocate()
	{
		return (T*)Alloc::allocate(sizeof(T));
	}

	static void deallocate(T* _p, size_t n)
	{
		if (0 != n)
			Alloc::deallocate(_p,n*sizeof(T));
	}

	static void deallocate(T* _p)
	{
		Alloc::deallocate(_p,sizeof(T));
	}
};