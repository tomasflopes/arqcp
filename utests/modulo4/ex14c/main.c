#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


void call_func ( void (*f)(int *p, int x), int *p, int x );  

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int x, int bitpos, int expected )
{
    int  v[3]={0x55555555,0x55555555,0x55555555}; 

    v[1]=x;     

	call_func(reset_2bits,&v[1],bitpos);
    
    TEST_ASSERT_EQUAL_INT(expected,v[1]); 
    TEST_ASSERT_EQUAL_INT(0x55555555,v[0]); 
    TEST_ASSERT_EQUAL_INT(0x55555555,v[2]); 
    
}


void test_Zero()
{ 
    run_test(-1,0,0x7ffffffe); 
}
void test_One()
{ 
    run_test(0x7ffffffe,0,0x7ffffffe); 
}
void test_Four()
{ 
    run_test(0xffffffff,4,0xf7ffffef); 
}
void test_Eight()
{ 
    run_test(0xffffffff,8,0xff7ffeff); 
}
void test_Twelve()
{ 
    run_test(0xffffffff,12,0xfff7efff); 
}


int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_One);
    RUN_TEST(test_Four);
    RUN_TEST(test_Eight);
    RUN_TEST(test_Twelve);
    return UNITY_END();  

  } 






