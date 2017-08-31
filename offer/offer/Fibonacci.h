#pragma once

#include<iostream>
using namespace std;

int Fibonacci(int n)
{
	int a = 0, b = 1;
	while (n--) {
		b += a;
		a = b - a;
	}
	return a;
}

int Fibonacci1(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci1(n - 1) + Fibonacci1(n-2);
}

int Fibonacci2(int n)
{
	int a = 0;
	int b = 1;
	int sum = 0;
	if (n == 0)
		return a;
	if (n == 1)
		return b;
	for (int i = 2; i <= n; i++)
	{
		sum = a + b;
		a = b;
		b = sum;
	}
	return sum;
}


void Test_fib()
{
	int ret = Fibonacci2(5);
}