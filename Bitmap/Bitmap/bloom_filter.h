#pragma once
#include"hash.h"
#include"bitmap.h"

template <class T>
struct _HashFunk1
{
	size_t operator()(const T& key)
	{
		return BKDRHash<T>(key.c_str());
	}
};

template <class T>
struct _HashFunk2
{
	size_t operator()(const T& key)
	{
		return SDBMHash<T>(key.c_str());
	}
};

template <class T>
struct _HashFunk3
{
	size_t operator()(const T& key)
	{
		return RSHash<T>(key.c_str());
	}
};

template <class T>
struct _HashFunk4
{
	size_t operator()(const T& key)
	{
		return APHash<T>(key.c_str());
	}
};

template <class T>
struct _HashFunk5
{
	size_t operator()(const T& key)
	{
		return JSHash<T>(key.c_str());
	}
};

template <class T,
class HashFunk1 = _HashFunk1<T>,
class HashFunk2=_HashFunk2<T>,
class HashFunk3 =_HashFunk3<T>,
class HashFunk4 = _HashFunk4<T>,
class HashFunk5 = _HashFunk5<T>>
class Bloom_Filter
{
public:
	Bloom_Filter(size_t n)
		:_bp(10*n)
		, _range(10*n)
	{}

	void Set(const T& key)
	{
		_bp.Set(HashFunk1()(key) % _range);
		_bp.Set(HashFunk2()(key) % _range);
		_bp.Set(HashFunk3()(key) % _range);
		_bp.Set(HashFunk4()(key) % _range);
		_bp.Set(HashFunk5()(key) %	 _range);
	}

	bool Exist_bloom(const T& key)
	{
		if (!_bp.Exist(HashFunk1()(key) % _range))
			return false;
		if (!_bp.Exist(HashFunk2()(key) % _range))
			return false;
		if (!_bp.Exist(HashFunk3()(key) % _range))
			return false;
		if (!_bp.Exist(HashFunk4()(key) % _range))
			return false;
		if (!_bp.Exist(HashFunk5()(key) % _range))
			return false;
		return true;
	}
protected:
	Bitmap _bp;
	size_t _range;
};

