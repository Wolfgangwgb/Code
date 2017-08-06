//#include "stdafx.h"   VS2013 中不需要此句，详见第6条
#include "gtest/gtest.h"  
#include  "fun.h"
#include <tchar.h>   //若不包含，main中参数会报错
/*
TEST(fun, case1)
{
	EXPECT_LT(-2, fun(1, 2));
	EXPECT_EQ(-1, fun(1, 2));
	ASSERT_LT(-2, fun(1, 2));
	ASSERT_EQ(-1, fun(1, 2));
}

TEST(test, case1)
{
	//ASSERT_TRUE(true);
	ASSERT_FALSE(false) << "assert";//
	//EXPECT_TRUE(true);
	EXPECT_FALSE(false)<<"expect";

}
TEST(DATA,TEST1)
{
	ASSERT_EQ(1,1)<<"1 == 2";
	ASSERT_NE(2,3)<<"2 != 3";
	ASSERT_LT(2,3)<<"2<3";
	ASSERT_LE(2,2)<<"2<=2";
	ASSERT_GT(3,2)<<"3>2";
	ASSERT_GE(5,5)<<"5>=5";
}

TEST(DATA, TEST2)
{
	EXPECT_EQ(1,1)<<"1 == 1";
	EXPECT_NE(1,4)<<"1!=4";
	EXPECT_LT(1,2)<<"1<2";
	EXPECT_LE(2,2)<<"2<=2";
	EXPECT_GT(10,9)<<"10>9";
	EXPECT_GE(4,4)<<"4>=4";
}
TEST(DATA, TEST3)
{
	EXPECT_EQ(1, 1) << "1 == 2";
	EXPECT_NE(1, 32) << "1!=32";
	EXPECT_LT(1, 2) << "1<2";
	EXPECT_LE(2, 3) << "2<=3";

	ASSERT_LE(2, 2) << "2<=2";
	ASSERT_GT(3, 2) << "3>2";
	ASSERT_GE(5, 5) << "5>=5";

	EXPECT_GT(10, 9) << "10>9";
	EXPECT_GE(8, 4) << "8>=4";
}


TEST(STR,STR1)
{
	ASSERT_STREQ("ABC", "ABC");
	ASSERT_STRNE("ABC","DES")<<"ABC"<<"DES";
	ASSERT_STRCASEEQ("ABC", "abc");
	ASSERT_STRCASENE("ABC", "abcC");
}
TEST(STR, STR2)
{
	EXPECT_STREQ("QWED","QWE");
	ADD_FAILURE();//显示返回失败
	EXPECT_STRNE("DDDD","DDDD");
	EXPECT_STRCASEEQ("SDSD","sdsd")<<"HELO";
	EXPECT_STRCASENE("DDD","dddd");
}

bool MutuallyPrime(int m, int n)
{
	return Foo(m, n) > 1;
}

TEST(PredicateAssertionTest, Demo)
{
	int m = 5, n = 6;
	EXPECT_PRED2(MutuallyPrime, m, n);
}
*/
template <class T>
class type
{
public:
	void bar()
	{
		testing::StaticAssertTypeEq<int, T>();
	}
};

TEST(TypeAssertionTest, Demo)
{
	type<bool> fooType;
	fooType.bar();
}
int _tmain(int argc, _TCHAR* argv[])
{
	//多个测试用例时使用，如果不写，运行RUN_ALL_TESTS()时会全部测试，加上则只返回对应的测试结果  
	//testing::GTEST_FLAG(filter) = "test_case_name.test_name";
	//测试初始化
	testing::InitGoogleTest(&argc, argv);
	//return RUN_ALL_TESTS();
	RUN_ALL_TESTS();
	//暂停，方便观看结果,结果窗口将会一闪而过  
	system("PAUSE");
	return 0;
}