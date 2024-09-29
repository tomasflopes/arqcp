#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


void call_func ( void (*f)(void) );  
int * ptrvec;  
int num; 

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int * vec, int in_num, int * expected )
{
    int  vec1[100];

    

    // setup 
        memset(vec1, 0x55, sizeof vec1);
     
        ptrvec=vec1+1; 	
	memcpy(vec1+1,vec,in_num*sizeof(int));  //   
        num = in_num; 
	call_func(vec_add_two);
    
    TEST_ASSERT_EQUAL_INT(0x55555555, vec1[in_num+1]);    // check sentinel 
    TEST_ASSERT_EQUAL_INT(0x55555555, vec1[0]);    // check sentinel  
    if (num !=0) 
	    TEST_ASSERT_EQUAL_INT_ARRAY(expected, vec1+1, in_num);  
    TEST_ASSERT_EQUAL_INT(in_num, num);    // check num 
    TEST_ASSERT_EQUAL_PTR(vec1+1, ptrvec);    // check ptrvec 
    
}


void test_NullVector()
{ 
    run_test((int[]){0},0,(int[]){0}); 
}
void test_One()
{ 
    run_test((int[]){1},1,(int[]){3}); 
}
void test_Zero()
{ 
    run_test((int[]){1,0,-1},3,(int[]){3,2,1}); 
}
void test_Minus()
{ 
    run_test((int[]){-2,-2,-2},3,(int[]){0,0,0}); 
}
void test_Five()
{ 
    run_test((int[]){1,2,3,4,255},5,(int[]){3,4,5,6,257}); 
}

int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_NullVector);
    RUN_TEST(test_One);
    RUN_TEST(test_Zero);
    RUN_TEST(test_Minus);
    RUN_TEST(test_Five);
    return UNITY_END();  

  } 






