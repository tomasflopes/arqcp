#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


void call_func ( void (*f)(void) );  
char * ptr1;  
char * ptr2; 

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(char * str, char * expected )
{
    char vec1[100];
    char vec2[100];

    

    // setup 
        memset(vec1, 0xaa, sizeof vec1);
        memset(vec2, 0xaa, sizeof vec2);
     
        ptr1=vec1+1; 	
        ptr2=vec2+1; 	
	strcpy(vec1+1,str);  // bad practice  
	call_func(str_copy_porto2);
    
    TEST_ASSERT_EQUAL_CHAR(0xaa, vec1[strlen(str)+2]);    // check sentinel 
    TEST_ASSERT_EQUAL_CHAR(0xaa, vec1[0]);    // check sentinel 
    TEST_ASSERT_EQUAL_PTR(vec1+1,ptr1);  
    TEST_ASSERT_EQUAL_CHAR(0xaa, vec2[strlen(str)+2]);    // check sentinel 
    TEST_ASSERT_EQUAL_CHAR(0xaa, vec2[0]);    // check sentinel 
    TEST_ASSERT_EQUAL_PTR(vec2+1,ptr2);  
    TEST_ASSERT_EQUAL_STRING(expected,ptr2); 
    
}


void test_hey()
{ 
    run_test("hey","hey"); 
}
void test_hello()
{ 
    run_test("Hello world!\n","Hellu wurld!\n"); 
}
void test_One_o()
{ 
    run_test("One o","Une u"); 
}
void test_One_u()
{ 
    run_test("One u","Une u"); 
}
void test_Two_o()
{ 
    run_test("Two oO","Twu uU"); 
}
void test_Two_U()
{ 
    run_test("Two UU","Twu UU"); 
}
void test_Three_o()
{ 
    run_test("Three oOo","Three uUu"); 
}
void test_NullString()
{ 
    run_test("",""); 
}



int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_hey);
    RUN_TEST(test_hello);
    RUN_TEST(test_One_o);
    RUN_TEST(test_One_u);
    RUN_TEST(test_Two_o);
    RUN_TEST(test_Two_U);
    RUN_TEST(test_Three_o);
    RUN_TEST(test_NullString);
    return UNITY_END();  

  } 






