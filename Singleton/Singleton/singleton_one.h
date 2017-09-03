#pragma once
#include<iostream>
using namespace std;

//不考虑线程安全
//在多线程情况下可能创建多个实例
class Singleton_one
{
public:
	static Singleton_one* GetInstance( int data)//创建实例
	{
		if (_singleton == NULL)
		{
			_singleton = new Singleton_one(data);
		}
		return _singleton;
	}

	static void DestoryInstance()
	{
		if (_singleton)
		{
			delete _singleton;
			_singleton = NULL;
		}
	}
	int Getdata()
	{
		return m_data;
	}

protected://防止类外调用构造函数
	Singleton_one(int data = 10) :m_data(data)
	{}
	Singleton_one(const Singleton_one& s);
	Singleton_one& operator=(const Singleton_one&);
private:
	static Singleton_one* _singleton;//类的静态成员
	int m_data;
};

Singleton_one* Singleton_one::_singleton = NULL;//类的静态成员在类外初始化

void Test_singleton_one()
{
	Singleton_one* singleton = Singleton_one::GetInstance(20);
	cout << singleton->Getdata();
	Singleton_one::DestoryInstance();
}