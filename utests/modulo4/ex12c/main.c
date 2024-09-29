#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


int call_func ( int (*f)(short *p, int num), short *p, int num);  

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(short  *p, int num, int expected)
{
    int  res; 

	res = call_func(vec_count_bits_one,p,num);
    
    TEST_ASSERT_EQUAL_INT(expected,res); 
    
}


void test_Zero()
{ 
    run_test((short[]){},0,0); 
}
void test_One()
{ 
    run_test((short[]){1},1,1); 
}
void test_OneA()
{ 
    run_test((short[]){0},1,0); 
}
void test_MinusOne()
{ 
    run_test((short[]){-1},1,16); 
}
void test_Three()
{ 
    run_test((short[]){-1,-2,-4},3,45); 
}
void test_Five()
{ 
    run_test((short[]){-1,-1,0,-1,-1},5,64); 
}



int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_One);
    RUN_TEST(test_OneA);
    RUN_TEST(test_MinusOne);
    RUN_TEST(test_Three);
    RUN_TEST(test_Five);
    return UNITY_END();  

  } 






