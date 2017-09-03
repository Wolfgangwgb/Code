#pragma once
#include<iostream>
using namespace std;
#include<mutex>
#include<thread>

//线程安全
// 1.分配空间 2.调用构造函数 3.赋值
// 编译器编译优化可能会把2和3进行指令重排，这样可能会导致
// 高并发场景下，其他线程获取到未调用构造函数初始化的对象
// 以下加入内存栅栏进行处理，防止编译器重排栅栏后面的赋值
// 到内存栅栏之前
class Singleton_two
{
public:
	static Singleton_two* GetInstance(int data = 2)
	{
		//进行了两次m_Instance == NULL的判断，是借鉴了Java的单例模式实现时，
		//使用的所谓的“双检锁”机制。因为进行一次加锁和解锁是需要付出对应的代价的，
		//而进行两次判断，就可以避免多次加锁与解锁操作，同时也保证了线程安全
		if (_singleton == NULL)
		{
			lock_guard<mutex> lock(_mx);
			//_mx.lock();
			if (_singleton == NULL)
			{
				_singleton = new Singleton_two(data);
				
			}
			//_mx.unlock();
		}
		return _singleton;
	}
	
	static void DestoryInstance()
	{
		lock_guard<mutex> lock(_mx);
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
	Singleton_two(int data = 1) :m_data(data)
	{}
	Singleton_two(const Singleton_two& s);
	Singleton_two& operator=(Singleton_two&);
private:
	static Singleton_two* _singleton;
	static mutex _mx;
	int m_data;
};

Singleton_two* Singleton_two::_singleton = NULL;
mutex Singleton_two::_mx;//

void Test_singleton_two()
{
	Singleton_two* singleton = Singleton_two::GetInstance(22);
	cout<<singleton->Getdata() << endl;
	Singleton_two::DestoryInstance();
}