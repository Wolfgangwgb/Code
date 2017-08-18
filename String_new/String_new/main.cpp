#include"string_shallow_copy.h"
#include"string_ref_int.h"
#include"string_ref_static.h"
#include"string_ref_pointer.h"
#include"string_copy_on_write.h"

int main()
{
	Test_shallow_copy();
	Test_int_count();
	Test_static_count();
	Test_pointer_count();
	Test_copy();
	return 0;
}