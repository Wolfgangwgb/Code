#pragma once
#include<iostream>
using namespace std;

typedef enum ProductType
{
	TypeA,
	TypeB,
	TypeC
}producttype;


class Product
{
public:
	virtual void Show()= 0;
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
	void Show()
	{
		cout << "B show" << endl;
	}
};
class ProductC :public Product
{
	void Show()
	{
		cout << "C show" << endl;
	}
};

class Factory
{
public:
	Product* CreateProduct(producttype type)
	{
		switch (type)
		{
		case TypeA:
			return new ProductA();
		case TypeB:
			return new ProductB();
		case TypeC:
			return new ProductC();
		default:
			return NULL;
		}
	}
};

void Test()
{
	Factory* f = new Factory();
	Product* pa = f->CreateProduct(TypeA);
	if (pa)
		pa->Show();
	Product* pb = f->CreateProduct(TypeA);
	if (pb)
		pb->Show();
	Product* pc = f->CreateProduct(TypeA);
	if (pc)
		pc->Show();
	delete f;
	f = NULL;
	delete pa;
	pa = NULL;
	delete pa;
	pa = NULL;
	delete pa;
	pa = NULL;
}

