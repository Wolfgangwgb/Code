#pragma once
#include<iostream>
using namespace std;

class ProductA
{
public:
	virtual void show() = 0;
};

class ProductA1 :public ProductA
{
public:
	void show()
	{
		cout << "ProductA1" << endl;
	}
};

class ProductA2 :public ProductA
{
public:
	void show()
	{
		cout << "ProductA2" << endl;
	}
};


class ProductB
{
public:
	virtual void show() = 0;
};

class ProductB1 :public ProductB
{
public:
	void show()
	{
		cout << "ProductB1" << endl;
	}
};

class ProductB2 :public ProductB
{
public:
	void show()
	{
		cout << "ProductB2" << endl;
	}
};



class Factory
{
public:
	virtual ProductA* CreateProductA() = 0;
	virtual ProductB* CreateProductB() = 0;
};

class Factory1 :public Factory
{
public:
	ProductA* CreateProductA()
	{
		return new ProductA1();
	}
	ProductB* CreateProductB()
	{
		return new ProductB1();
	}
};


class Factory2 :public Factory
{
public:
	ProductA* CreateProductA()
	{
		return new ProductA2();
	}
	ProductB* CreateProductB()
	{
		return new ProductB2();
	}
};

void Test_abstract_factory()
{
	Factory* f1 = new Factory1();
	ProductA* pa1 = f1->CreateProductA();
	pa1->show();
	ProductB* pb1 = f1->CreateProductB();
	pb1->show();
	Factory* f2 = new Factory2();
	ProductA* pa2 = f2->CreateProductA();
	pa2->show();
	ProductB* pb2 = f2->CreateProductB();
	pb2->show();
	if (f1)
		delete f1; f1 = NULL;
	if (pa1)
		delete pa1; pa1 = NULL;
	if (pb1)
		delete pb1; pb1 = NULL;
	if (f2)
		delete f2; f2 = NULL;
	if (pa2)
		delete pa2; pa2 = NULL;
	if (pb2)
		delete pb2; pb2 = NULL;

}