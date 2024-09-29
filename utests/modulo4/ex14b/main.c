#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


int call_func ( int (*f)(int *p, int x), int *p, int x );  

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int x, int bitpos, int expected, int exp_res)
{
    int  res; 
    int  v[3]={0x55555555,0x55555555,0x55555555}; 

    v[1]=x;     

	res = call_func(reset_bit,&v[1],bitpos);
    
    TEST_ASSERT_EQUAL_INT(exp_res,res); 
    TEST_ASSERT_EQUAL_INT(expected,v[1]); 
    TEST_ASSERT_EQUAL_INT(0x55555555,v[0]); 
    TEST_ASSERT_EQUAL_INT(0x55555555,v[2]); 
    
}


void test_Zero()
{ 
    run_test(-1,0,-2,1); 
}
void test_One()
{ 
    run_test(-2,0,-2,0); 
}
void test_Four()
{ 
    run_test(0xffff,15,0x7fff,1); 
}
void test_FourA()
{ 
    run_test(0x7fff,15,0x7fff,0); 
}
void test_Thirty()
{ 
    run_test(0x7fffffff,30,0x3fffffff,1); 
}
void test_ThirtyA()
{ 
    run_test(0x3fffffff,30,0x3fffffff,0); 
}



int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_One);
    RUN_TEST(test_Four);
    RUN_TEST(test_FourA);
    RUN_TEST(test_Thirty);
    RUN_TEST(test_ThirtyA);
    return UNITY_END();  

  } 






