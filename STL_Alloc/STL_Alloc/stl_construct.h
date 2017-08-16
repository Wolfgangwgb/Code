#pragma once
#include"IteratorTraits.h"
#include "TypeTraits.h"

template<class T1, class T2>
inline void Construct(T1* p, const T2& value)
{
	new((void*)p)T1(value);
}

template<class T>
inline void Construct(T* p)
{
	new((void*)p)T();
}

template<class T>
inline void Destroy(T* p)
{
	p->~T();
}

template<class Iterator>
void _Destroy(Iterator first, Iterator last, TrueType){}

template<class Iterator>
void _Destroy(Iterator first, Iterator last, FalseType)
{
	while (first != last)
	{
		Destroy(&(*first));
		first++;
	}
}

template<class Iterator>
void Destroy(Iterator first, Iterator last)
{
	TypeTraits<IteratorTraits<Iterator>::ValueType>::hasTrivialDestructor del;
	_Destroy(first, last, del);
}

