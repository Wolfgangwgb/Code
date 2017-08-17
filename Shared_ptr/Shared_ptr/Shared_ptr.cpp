#pragma once
using namespace std;

template <class T,class Del>
class Shared_ptr
{
public:
	Shared_ptr()
		:_ptr(NULL)
		, _refcount(new int(0))
	{}
	Shared_ptr(T* ptr)
		:_ptr(ptr)
		, _refcount(new int(1))
	{}

	Shared_ptr(const Shared_ptr<T,Del>& sp)
		:_ptr(sp._ptr)
		, _refcount(sp._refcount)
	{
		(*_refcount)++;
	}

	Shared_ptr<T, Del>& operator=(const Shared_ptr<T, Del>& sp)
	{
		if (this != &sp)
		{
			Realease();//释放
			_ptr = sp._ptr;
			_refcount = sp._refcount;
			(*_refcount)++;
		}
		return *this;	
	}

	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}

	~Shared_ptr()
	{
		Realease();
	}
	inline void Realease()
	{
		if (--(*_refcount) == 0)
		{
			delete _refcount;
			_del(_ptr);
		}
	}
private:
	T* _ptr;
	int* _refcount;//引用计数
	Del _del;//定制删除器
};

//仿函数
template <class T>
struct Delete
{
	void operator()(T* ptr)
	{
		delete ptr;
	}
}; 
template <class T>
struct Deletearray
{
	void operator()(T* ptr)
	{
		delete[] ptr;
	}
};

template <class T>
struct Free
{
	void operator()(T* ptr)
	{
		free(ptr);
	}
};

template <class T>
struct Fclose
{
	void operator()(T* ptr)
	{
		fclose(ptr);
	}
};



int main()
{
	int *p = new int;
	Shared_ptr<int, Delete<int>> sp(p);
	Shared_ptr<int, Delete<int>> sp1(sp);
	Shared_ptr<int, Delete<int>> sp2(new int);
	sp1 = sp2;

	return 0;
}