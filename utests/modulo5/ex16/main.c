#include <string.h> 
#include <stdlib.h> 
#include "../../unity.h"
#include "asm.h" 
#include "dmt2.h" 


int call_func(int  (*f)(group * ),  group * p1 ); 

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(short n, unsigned short  * p1 , int expected  )
{
    // setup 
	int result; 
	group g; 
 	g.individual_grades=(unsigned short *)p1;
        g.n_students=n; 

	result=call_func(approved_semester,&g); 
	TEST_ASSERT_EQUAL_INT(expected,result);
	result=call_func(approved_semester,&g); 
	TEST_ASSERT_EQUAL_INT(expected,result);
        /*  twice to see if the data changes */ 

	/* could be a lot better... */ 

}


void test_Zero()
{ 
    run_test(0,(unsigned short[]){0},0);  
}
void test_One()
{ 
    run_test(1,(unsigned short[]){0xff11},1);  
}
void test_Two()
{ 
    run_test(4,(unsigned short[]){0x21ff,0b10000000,0x7771,0},2); 
}
void test_Three()
{ 
    run_test(6,(unsigned short[]){0x7777,0x8888,0xeeee,0x1f1f,00,15},3); 
}


int main()
  { 
    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_One);
    RUN_TEST(test_Two);
    RUN_TEST(test_Three);
    return UNITY_END();  

  } 






