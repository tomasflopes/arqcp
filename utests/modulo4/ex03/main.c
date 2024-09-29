#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


int call_func ( int (*f)(int x, int y, int z, int w), int x, int y, int z,  int w);  

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int x, int y, int z, int w, int expected )
{
    int  res; 

    

    // setup 
	res = call_func(greatest,x,y,z,w);
    
    TEST_ASSERT_EQUAL_INT(expected,res); 
    
}


void test_Zero()
{ 
    run_test(0,0,0,0,0); 
}
void test_One()
{ 
    run_test(0,1,-1,-3,1); 
}
void test_MinusOne()
{ 
    run_test(-1,-2,-4,-3,-1); 
}
void test_MinusOneB()
{ 
    run_test(-4,-3,-2,-1,-1); 
}
void test_Two()
{ 
    run_test(-3,0,2,1,2); 
}

void test_Three()
{ 
    run_test(-500,2,3,2,3); 
}
void test_Five()
{ 
    run_test(-200,3000,5,5,3000); 
}



int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_One);
    RUN_TEST(test_MinusOne);
    RUN_TEST(test_MinusOneB);
    RUN_TEST(test_Two);
    RUN_TEST(test_Three);
    RUN_TEST(test_Five);
    return UNITY_END();  

  } 






