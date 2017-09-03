#pragma once
#include<iostream>

using namespace std;




class Product
{
public:
	virtual void Show() = 0;
};

class ProductA :public Product
{
public:
	void Show()
	{
		cout << "A show" << endl;
	}
};
class ProductB :public Product
{
public:
	void Show()
	{
		cout << "B show" << endl;
	}
};
class ProductC :public Product
{
public:
	void Show()
	{
		cout << "C show" << endl;
	}
};



class Factory
{
public:
	virtual Product* CreateProduct() = 0;
};

class FactoryA :public Factory
{
	Product* CreateProduct()
	{
		return new ProductA();
	}
};

class FactoryB :public Factory
{
	Product* CreateProduct()
	{
		return new ProductB();
	}
};
class FactoryC :public Factory
{
	Product* CreateProduct()
	{
		return new ProductC();
	}
};



void Test_factory_method()
{
	Factory* fa = new FactoryA();
	Product* pa = fa->CreateProduct();
	pa->Show();
	Factory* fb = new FactoryB();
	Product* pb = fb->CreateProduct();
	pb->Show();
	Factory* fc = new FactoryC();
	Product* pc = fc->CreateProduct();
	pc->Show();


	if (fa)
		delete fa; fa = NULL;
	if (pa)
		delete pa; pa = NULL;
	if (fb)
		delete fb; fb = NULL;
	if (pb)
		delete pb; pb = NULL;
	if (fc)
		delete fc; fc = NULL;
	if (pc)
		delete pc; pc = NULL;

}
