#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


int   call_func ( int  (*f)(void) );  
long * ptrvec;  
int num; 

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(long * vec, int in_num, int expected )
{
    long vec1[100];

    int  res; 

    // setup 
        memset(vec1, 0x55, sizeof vec1);
     
        ptrvec=vec1+1; 	
	memcpy(vec1+1,vec,in_num*sizeof(long));  //   
        num = in_num; 
	res = call_func(sum_first_byte);
    
    TEST_ASSERT_EQUAL_INT64(0x5555555555555555, vec1[in_num+1]);    // check sentinel 
    TEST_ASSERT_EQUAL_INT64(0x5555555555555555, vec1[0]);    // check sentinel  
    TEST_ASSERT_EQUAL_INT(expected,res);  
    TEST_ASSERT_EQUAL_INT(in_num, num);    // check num 
    TEST_ASSERT_EQUAL_PTR(vec1+1, ptrvec);    // check ptrvec  
    if ( num !=0 ) 
	    TEST_ASSERT_EQUAL_INT64_ARRAY(vec,vec1+1,in_num); // check if vector has changed 
    
}


void test_NullVector()
{ 
    run_test((long[]){0},0,0); 
}
void test_One()
{ 
    run_test((long[]){257},1,1); 
}
void test_Zero()
{ 
    run_test((long[]){256,0,512},3,0); 
}
void test_Minus3()
{ 
    run_test((long[]){-1,255,-1},3,-3); 
}
void test_Four()
{ 
    run_test((long[]){127,127,127,127},4,508); 
}
void test_Nine()
{ 
    run_test((long[]){1,1,1,1,1,1,1,1,2002},9,-38); 
}

int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_NullVector);
    RUN_TEST(test_One);
    RUN_TEST(test_Zero);
    RUN_TEST(test_Minus3);
    RUN_TEST(test_Four);
    RUN_TEST(test_Nine);
    return UNITY_END();  

  } 






