#pragma once

template<class T1,class T2>
inline void construct(T1* p, const T2& value)
{
	new((void*)p)T1(value);
}

template<class T1>
inline void construct(T1* p)
{
	new((void*)p)T1();
}

template<class T1>
inline void construct(T1* p)
{
	p->~T1();
}