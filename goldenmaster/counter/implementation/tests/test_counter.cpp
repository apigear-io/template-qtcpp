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
#include "test_counter.h"
#include "implementation/counter.h"

/**
 *  will be called before the first test function is executed.
*/
void TestCounterCounter::initTestCase(){

}

/**
 *  will be called to create a global test data table.
*/
void TestCounterCounter::initTestCase_data(){

}

/**
 *  will be called after the last test function was executed.
*/
void TestCounterCounter::cleanupTestCase(){

}

/**
 *  will be called before each test function is executed.
*/
void TestCounterCounter::init(){

}

/**
 *  will be called after every test function.
*/
void TestCounterCounter::cleanup(){

}
/**
 *  Test operation increment
*/
void TestCounterCounter::increment(){
    counter::Counter testCountercounter;
    // Do implement test here
}
/**
 *  Test operation decrement
*/
void TestCounterCounter::decrement(){
    counter::Counter testCountercounter;
    // Do implement test here
}
/**
 *  Test proptery vector
*/
void TestCounterCounter::vector(){
    counter::Counter testCountercounter;
    // Do implement test here
}
/**
 *  Test proptery extern_vector
*/
void TestCounterCounter::extern_vector(){
    counter::Counter testCountercounter;
    // Do implement test here
}

QTEST_MAIN(TestCounterCounter);


