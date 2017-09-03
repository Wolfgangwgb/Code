#pragma once
#include<iostream>
using namespace std;

class Singleton_five
{
public:
	static Singleton_five* Getinstance()
	{
		return _singleton;
	}
	int Getdata()
	{
		return m_data;
	}
protected:
	Singleton_five() :m_data(2)
	{}
	Singleton_five(const Singleton_five&);
	Singleton_five& operator=(const Singleton_five&);
private:
	static Singleton_five* _singleton;
	int m_data;
	class GC
	{
	public://зЂвт
		~GC()
		{
			if (_singleton)
			{
				delete _singleton;
				_singleton = NULL;
			}
		}
	};
	static GC _gc;
};

Singleton_five* Singleton_five::_singleton = new Singleton_five();
Singleton_five::GC Singleton_five::_gc;


void Test_singleton_five()
{
	Singleton_five* singleton = Singleton_five::Getinstance();
	cout << singleton->Getdata() << endl;
}