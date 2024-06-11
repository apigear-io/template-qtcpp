/**
NO TITLE
Copyright (C) 2020 ApiGear UG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include "test_voidinterface.h"
#include "implementation/voidinterface.h"

/**
 *  will be called before the first test function is executed.
*/
void TestTbSimpleVoidInterface::initTestCase(){

}

/**
 *  will be called to create a global test data table.
*/
void TestTbSimpleVoidInterface::initTestCase_data(){

}

/**
 *  will be called after the last test function was executed.
*/
void TestTbSimpleVoidInterface::cleanupTestCase(){

}

/**
 *  will be called before each test function is executed.
*/
void TestTbSimpleVoidInterface::init(){

}

/**
 *  will be called after every test function.
*/
void TestTbSimpleVoidInterface::cleanup(){

}
/**
 *  Test operation funcVoid
*/
void TestTbSimpleVoidInterface::funcVoid(){
    tb_simple::VoidInterface testTbsimplevoidinterface;
    // Do implement test here
}

QTEST_MAIN(TestTbSimpleVoidInterface);


