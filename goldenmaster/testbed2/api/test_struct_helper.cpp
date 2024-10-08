#include "test_struct_helper.h"

void testbed2::fillTestStruct1(testbed2::Struct1& test_struct1)
{
	test_struct1.m_field1 = 1;
}

void testbed2::fillTestStruct2(testbed2::Struct2& test_struct2)
{
	test_struct2.m_field1 = 1;
	test_struct2.m_field2 = 1;
}

void testbed2::fillTestStruct3(testbed2::Struct3& test_struct3)
{
	test_struct3.m_field1 = 1;
	test_struct3.m_field2 = 1;
	test_struct3.m_field3 = 1;
}

void testbed2::fillTestStruct4(testbed2::Struct4& test_struct4)
{
	test_struct4.m_field1 = 1;
	test_struct4.m_field2 = 1;
	test_struct4.m_field3 = 1;
	test_struct4.m_field4 = 1;
}

void testbed2::fillTestNestedStruct1(testbed2::NestedStruct1& test_nested_struct1)
{
	fillTestStruct1(test_nested_struct1.m_field1);
}

void testbed2::fillTestNestedStruct2(testbed2::NestedStruct2& test_nested_struct2)
{
	fillTestStruct1(test_nested_struct2.m_field1);
	fillTestStruct2(test_nested_struct2.m_field2);
}

void testbed2::fillTestNestedStruct3(testbed2::NestedStruct3& test_nested_struct3)
{
	fillTestStruct1(test_nested_struct3.m_field1);
	fillTestStruct2(test_nested_struct3.m_field2);
	fillTestStruct3(test_nested_struct3.m_field3);
}
