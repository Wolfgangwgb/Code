#include"blank.h"
#include"array.h"
#include"two_stack_queue.h"
#include"min_stack.h"
#include"one_count.h"
#include"Fibonacci.h"
#include"pop_stack.h"
#include"odd_even_number.h"
#include"arra_half.h"
#include"array_repeat.h"
#include"ugly_number.h"
#include"subarray_sum.h"
#include"int_one_count.h"
#include"mid_number.h"
#include"first_char.h"
#include"array_inverse_pair.h"
//#include"min_k.h"
#include"array_one_number.h"

class A
{
public:
	virtual char f()
	{
		return'f';
	}
	char g(int n)
	{
		return 'g';
	}
};

class B : public A
{
public:
	char f(){ return 'F'; }
protected:
	virtual char g(unsigned int n)
	{
		return (char)('g' + n);
	}
};
int main()
{
	//Test_blank();
	//Test_array();
	//Test_stack();
	//Test_min_stack();
	//Test_one();
	//Test_fib();
	//Test_popstack();
//	Test_odd_even();
	//Test_array_min();
	//Test_array_repeat();
	//Test_ugly_number();
	//Test_subarray();
	//Test_int_one_count();
	//Test_mid_number();
	//Test_first_char();
	//Test_array_inverse();
	//Test_min_k();
	Test_arr_two_first();
	//A* pA = new B;
	//A& rA = *(B*)pA;
	//A oA = *(B*)pA;
	//printf("%c,%c,%c,%c,%c,%c\n", pA->f(), pA->g(1u), rA.f(), rA.g(1), oA.f(), oA.g(1));
	return 0;
}
