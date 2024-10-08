#include "test_struct_helper.h"

void testbed1::fillTestStructBool(testbed1::StructBool& test_struct_bool)
{
	test_struct_bool.m_fieldBool = true;
}

void testbed1::fillTestStructInt(testbed1::StructInt& test_struct_int)
{
	test_struct_int.m_fieldInt = 1;
}

void testbed1::fillTestStructFloat(testbed1::StructFloat& test_struct_float)
{
	test_struct_float.m_fieldFloat = 1.1f;
}

void testbed1::fillTestStructString(testbed1::StructString& test_struct_string)
{
	test_struct_string.m_fieldString = QString("xyz");
}
