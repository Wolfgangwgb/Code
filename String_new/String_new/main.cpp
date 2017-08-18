#include"string_shallow_copy.h"
#include"string_ref_int.h"
#include"string_ref_static.h"
#include"string_ref_pointer.h"
#include"string_copy_on_write.h"
#include"string_deep_copy_one.h"

int main()
{
	Test_shallow_copy();
	Test_int_count();
	Test_static_count();
	Test_pointer_count();
	Test_copy();
	Test_d1();
	return 0;
}