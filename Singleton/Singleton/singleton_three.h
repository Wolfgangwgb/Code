#pragma once
#include<iostream>
using namespace std;

//const_cast:强制类型转换，去除const属性

class Singleton_three
{
public:
	static Singleton_three* GetInstance()
	{
		return const_cast<Singleton_three*>(_singleton);
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

protected:
	Singleton_three(int data =1) :m_data(data)
	{}
	Singleton_three(const Singleton_three&);
	Singleton_three& operator=(const Singleton_three&);
private:
	int m_data;
	static const Singleton_three* _singleton;
};

const Singleton_three* Singleton_three::_singleton = new Singleton_three();
//因为静态初始化在程序开始时，也就是进入主函数之前，
//由主线程以单线程方式完成了初始化，所以静态初始化实例保证了线程安全性。
//在性能要求比较高时，就可以使用这种方式，从而避免频繁的加锁和解锁造成的资源浪费。

void Test_singleton_three()
{
	Singleton_three* singleton = Singleton_three::GetInstance();
	cout << singleton->Getdata() << endl;
	Singleton_three::DestoryInstance();
}