#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


int call_func ( int (*f)(char *p, int num), char *p, int num);  

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(char  *p, int num, int expected)
{
    int  res; 

	res = call_func(count_odd,p,num);
    
    TEST_ASSERT_EQUAL_INT(expected,res); 
    
}


void test_Zero()
{ 
    run_test((char[]){},0,0); 
}
void test_One()
{ 
    run_test((char[]){1},1,1); 
}
void test_OneA()
{ 
    run_test((char[]){0},1,0); 
}
void test_OneB()
{ 
    run_test((char[]){-1},1,1); 
}
void test_Three()
{ 
    run_test((char[]){1,2,3},3,2); 
}
void test_Five()
{ 
    run_test((char[]){1,2,3,4,5},5,3); 
}



int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_One);
    RUN_TEST(test_OneA);
    RUN_TEST(test_OneB);
    RUN_TEST(test_Three);
    RUN_TEST(test_Five);
    return UNITY_END();  

  } 






