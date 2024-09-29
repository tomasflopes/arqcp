#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


int call_func( int (*f)(short w), short w);  

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void run_test( short input, int expected )
{
    int  res; 
    // setup 
	res = call_func(call_incr, input);
    
    TEST_ASSERT_EQUAL_INT(expected,res); 
}

void test_Zero()                  /*  LOTS of things to improve !!!! */ 
{ 
    run_test(0,-55); 
}
void test_One()                  /*  LOTS of things to improve !!!! */ 
{ 
    run_test(1,-53); 
}
void test_MinusOne()                  /*  LOTS of things to improve !!!! */ 
{ 
    run_test(0,-55); 
}
void test_FF()                  /*  LOTS of things to improve !!!! */ 
{ 
    run_test(0xff,455); 
}
void test_FF00()                  /*  LOTS of things to improve !!!! */ 
{ 
    run_test(0xff00,-567); 
}
void test_FFFF()                  /*  LOTS of things to improve !!!! */ 
{ 
    run_test(0xffff,-57); 
}
void test_Three()                  /*  LOTS of things to improve !!!! */ 
{ 
    run_test(3,-49); 
}
void test_Five()                  /*  LOTS of things to improve !!!! */ 
{ 
    run_test(5,-45); 
}
void test_MinusTwo()                  /*  LOTS of things to improve !!!! */ 
{ 
    run_test(-2,-59); 
}

int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_One);
    RUN_TEST(test_MinusOne);
    RUN_TEST(test_FF);
    RUN_TEST(test_FF00);
    RUN_TEST(test_FFFF);
    RUN_TEST(test_Three);
    RUN_TEST(test_Five);
    RUN_TEST(test_MinusTwo);
    return UNITY_END();  

  } 






