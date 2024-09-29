#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


void call_func ( void (*f)(void) );  
short * ptrvec;  
unsigned short num; 

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(short * vec, unsigned short in_num, short * exp_vec)
{
    short vec1[100];


    // setup 
        memset(vec1, 0x55, sizeof vec1);
     
        ptrvec=vec1+1; 	
	memcpy(vec1+1,vec,in_num*sizeof(short));  //   
        num = in_num; 
	call_func(keep_positives);
    
    TEST_ASSERT_EQUAL_INT16(0x5555, vec1[in_num+1]);    // check sentinel 
    TEST_ASSERT_EQUAL_INT16(0x5555, vec1[0]);    // check sentinel  
    TEST_ASSERT_EQUAL_UINT16(in_num, num);    // check num  
    if ( num != 0 ) 
    TEST_ASSERT_EQUAL_INT16_ARRAY(exp_vec, vec1+1, num);    // check vec 
    
}


void test_NullVector()
{ 
    run_test((short[]){0},0,(short[]){0}); 
}
void test_One()
{ 
    run_test((short[]){0},1,(short[]){0}); 
}
void test_Zero()
{ 
    run_test((short[]){-1,0,1},3,(short[]){0,0,1}); 
}
void test_Three()
{ 
    run_test((short[]){-1,-1,-1},3,(short[]){0,1,2}); 
}
void test_Five()
{ 
    run_test((short[]){1000,10000,20000,-1000,-5000},5,(short[]){1000,10000,20000,3,4}); 
}

int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_NullVector);
    RUN_TEST(test_One);
    RUN_TEST(test_Zero);
    RUN_TEST(test_Three);
    RUN_TEST(test_Five);
    return UNITY_END();  

  } 






