#pragma once
#include<vector>
#include<iostream>
using namespace std;

enum State
{
	EMPTY,EXIST,DELETE
};
template <class K,class V>
struct HashNode
{
	pair<K, V> _hn;
	State _s;
	HashNode()
		:_s(EMPTY)
	{}
};

template <class K, class V>
class Hashtable
{
	typedef pair<HashNode<K, V>*, bool> Pair;
public:
	Hashtable()
		:_size(0)
	{}
	bool Insert(const K& key,const V& value)
	{
		Checkcapacity();
		//计算存储位置 ----> 哈希函数
		size_t Hashaddress = Hash_function(key);
		size_t index = Hashaddress;
		//找插入位置
		while (_ht[index]._s == EXIST)
		{
			HashNode<K, V>& elem = _ht[index];
			if (elem._hn.first == key)
				return false;
			++index;
			if (index == _ht.size())//查找到最后一个位置后回到打一个位置，没有用取模，？？？
				index = 0;
			if (index == Hashaddress)
				return false;
		}
		//出了循环两种状态 EMPTY DELETE
		_ht[index]._hn.first = key;
		_ht[index]._hn.second = value;
		_ht[index]._s = EXIST;
		++_size;
	}

	Pair Find(const K& key)
	{
		size_t Hashaddress = Hash_function(key);
		size_t index = Hashaddress;
		while (_ht[index]._s != EMPTY)
		{
			HashNode<K, V>& elem = _ht[index];
			if (elem._hn.first == key)
			{
				if (elem._s == EXIST)
					return Pair(&elem, true);
				else if (elem._s == DELETE)
					return Pair(NULL, false);
			}
			++index;
			if (index == _ht.size())//查找到最后一个位置后回到打一个位置，没有用取模，？？？
				index = 0;
			if (index == Hashaddress)
				return Pair(NULL, false);
		}
		return Pair(NULL, false);
	}

	bool Remove(const K& key)
	{
		Pair hn = Find(key);
		if (hn.second)
		{
			hn.first->_s = DELETE;
			--_size;
			return true;
		}
		return false;
	}
private:
	size_t Hash_function(K key)
	{
		return key%_ht.size();
	}

	void Checkcapacity()
	{
		if (_size == _ht.size())
			_ht.resize(P);
	}
private:
	vector<HashNode<K,V>> _ht;
	size_t _size;
};



















void Test()
{
	int a[] = {37,25,14,36,49,68,57,11};
	Hashtable<int, int> ht();
	for (size_t index = 0; index < sizeof(a) / sizeof(a[0]); ++index)
	{
		ht.Insert(a[index],index);
	}
	ht.Insert(24,8);
	ht.Insert(42, 9);
	ht.Insert(66, 10);
	ht.Insert(78, 11);
	pair<HashNode<int,int>*, bool> h = ht.Find(14);
	pair<HashNode<int, int>*, bool> h1 = ht.Find(15);

	if (ht.Remove(14))
		cout << "True" << endl;
	else
		cout << "False" << endl;

}