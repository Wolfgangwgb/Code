#pragma once

#include<malloc.h>
#include<stdlib.h>
#include<iostream>




//http://blog.csdn.net/boydfd/article/details/44900331
//空间配置器
//一级空间配置器

template <int inst>
class _malloc_alloc_template
{
private:

	//
	static void* _oom_malloc(size_t);
	static void* _oom_realloc(void*,size_t);
	static void(*_malloc_alloc_oom_handler)();


public:
	static void* allocate(size_t s)
	{
		void* _result = malloc(s);
		if (0 == _result)
			_result = _oom_malloc(s);
		return _result;
	}

	static void deallocate(void* _p, size_t)
	{
		free(_p);
	}

	static void* reallocate(void*_p,size_t,size_t new_size)
	{
		void* _result = realloc(_p,new_size);
		if (0 == _result)
			_result = _oom_realloc(_p,new_size);
		return _result;
	}
	//?????
	static void(*_set_malloc_handler(void(*_f)()))()
	{
		void(*old)() = _malloc_alloc_oom_handler;
		_malloc_alloc_oom_handler = _f;
		return (old);
	}

};

template <int inst>
void(*_malloc_alloc_template<inst>::_malloc_alloc_oom_handler)() = 0;

template <int inst>
void* _malloc_alloc_template<inst>::_oom_malloc(size_t s)
{
	void(* _my_malloc_handler)();
	void* _result;
	//for(;;)和while(1)的区别
	for (;;)
	{
		_my_malloc_handler = _malloc_alloc_oom_handler;
		if (_my_malloc_handler == 0)
		{
			//抛出异常
			cout << "out of merrory" << endl;
		}
		(*_my_malloc_handler)();
		_result = malloc(s);
		if (_result)
			return _result;
	}
}

template <int inst>
void* _malloc_alloc_template<inst>::_oom_realloc(void* _p,size_t s)
{
	void(*_my_malloc_handler)();
	void* _result;
	//for(;;)和while(1)的区别
	for (;;)
	{
		_my_malloc_handler = _malloc_alloc_oom_handler;
		if (_my_malloc_handler == 0)
		{
			//抛出异常
			std::cout << "out of merrory" << std:: endl;
		}
		(*_my_malloc_handler)();
		_result = realloc(_p,s);
		if (_result)
			return _result;
}




