#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


long call_func ( long (*f)(void) );  
long * ptrvec;  
int num; 
long even; 

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(long * vec, int in_num, long  expected )
{
    long vec1[100];

    long res_sum;

    // setup 
        memset(vec1, 0x55, sizeof vec1);
     
        ptrvec=vec1+1; 	
	memcpy(vec1+1,vec,in_num*sizeof(long));  //   
        num = in_num; 
	res_sum=call_func(vec_sum_even);
    
    TEST_ASSERT_EQUAL_INT64(0x5555555555555555, vec1[in_num+1]);    // check sentinel 
    TEST_ASSERT_EQUAL_INT64(0x5555555555555555, vec1[0]);    // check sentinel  
    TEST_ASSERT_EQUAL_INT64(expected,res_sum);  
    TEST_ASSERT_EQUAL_INT(in_num, num);    // check num 
    TEST_ASSERT_EQUAL_PTR(vec1+1, ptrvec);    // check ptrvec 
    
}


void test_NullVector()
{ 
    run_test((long[]){0},0,0); 
}
void test_One()
{ 
    run_test((long[]){2},1,2); 
}
void test_Zero()
{ 
    run_test((long[]){1,0,-1},3,0); 
}
void test_Minus3()
{ 
    run_test((long[]){-1,-1,-1},3,0); 
}
void test_Five()
{ 
    run_test((long[]){10,10,10,10,10},5,50); 
}

int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_NullVector);
    RUN_TEST(test_One);
    RUN_TEST(test_Zero);
    RUN_TEST(test_Minus3);
    RUN_TEST(test_Five);
    return UNITY_END();  

  } 






