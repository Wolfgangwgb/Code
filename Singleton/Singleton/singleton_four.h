#pragma once
#include<iostream>
using namespace std;

//new和delete需要成对使用，有时候就忘记的delete，造成内存泄漏
//单例模式中获取实例对象和释放实例对象两个函数需要成对存在，也会忘记
//所以以下方式避免忘记释放
class Singleton_four
{
public:
	static Singleton_four* GetInstance()
	{
		static Singleton_four _singleton;//创建静态对象,静态全局共享
		return &_singleton;
	}
	int Getdata()
	{
		return m_data;
	}

protected:
	Singleton_four() :m_data(10)
	{}
	Singleton_four(const Singleton_four&);
	Singleton_four& operator=(const Singleton_four&);
private:
	int m_data;
};


void Test_singleton_four()
{
	Singleton_four* singleton = Singleton_four::GetInstance();
	cout << singleton->Getdata() << endl;
}