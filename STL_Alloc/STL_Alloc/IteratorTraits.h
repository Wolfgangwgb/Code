#pragma once

//五种迭代器类型以及之间的关系
struct Input_iterator{};
struct Output_iterator{};
struct Forward_iterator : public Input_iterator{};
struct Bidirectional_iterator : public Forward_iterator{};
struct RandomAccess_iterator : public Bidirectional_iterator{};



template <class Iterator>
class IteratorTraits
{
	typedef typename Iterator::IteratorCategory IteratorCategory;
	typedef typename Iterator::ValueType ValueType;
	typedef typename Iterator::DifferenceType DifferenceType;
	typedef typename Iterator::Poniter Poniter;
	typedef typename Iterator::Reference Reference;
};

template <class T>
struct IteratorTraits<T*>
{
	typedef RandomAccess_iterator IteratorCategory;
	typedef T ValueType;
	typedef int DifferenceType;//ptrdiff_t
	typedef T* Poniter;
	typedef T& Reference;
};

template <class T>
struct IteratorTraits<const T*>
{
	typedef RandomAccess_iterator IteratorCategory;
	typedef T ValueType;
	typedef int DifferenceType;//ptrdiff_t
	typedef const T* Poniter;
	typedef const T& Reference;
};

template<class Iterator>
int _Distance(Iterator first, Iterator last, RandomAccess_iterator)
{
	return last - first;
}

template<class InputIterator>
int _Distance(InputIterator first, InputIterator last, Input_iterator)
{
	int count = 0;
	while (first != last)
	{
		count++;
		++first;
	}

	return count;
}

template<class InputIterator>
int Distance(InputIterator first, InputIterator last)
{
	return _Distance(first, last, IteratorTraits<InputIterator>::IteratorCategory());
}



//begin /rebegin
template<class Iterator>
class ReverseIterator
{
public:
	typename typedef Iterator::ValueType ValueType;  // 对象的类型
	typename typedef Iterator::DifferenceType DifferenceType; // 迭代器之间的距离
	typename typedef Iterator::Reference Reference;  // 对象引用
	typename typedef Iterator::Pointer Pointer;      // 指针
	typename typedef Iterator::IteratorCategory IteratorCategory;  // 区分迭代器的类型


	typedef ReverseIterator<Iterator> Self;
public:
	ReverseIterator()
	{}

	ReverseIterator(Iterator cur)
		: _cur(cur)
	{}

	ReverseIterator(const Self& s)
		: _cur(s._cur)
	{}

	Reference operator*()
	{
		Iterator it(_cur);
		return *(--it);
	}

	Pointer operator->()
	{
		return _cur.operator->();
	}

	Self& operator++()
	{
		_cur.operator--();
		return *this;
	}

	Self operator++(int)
	{
		Self temp(*this);
		_cur.operator--();
		return temp;
	}

	Self& operator--()
	{
		_cur.operator++();
		return *this;
	}

	Self operator--(int)
	{
		Self temp(*this);
		_cur.operator++();
		return temp;
	}

	bool operator==(const Self& s)
	{
		return _cur == s._cur;
	}

	bool operator!=(const Self& s)
	{
		return _cur != s._cur;
	}

private:
	Iterator _cur;
};