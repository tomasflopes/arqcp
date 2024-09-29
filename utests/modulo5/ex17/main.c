#include <string.h> 
#include <stdlib.h> 
#include "../../unity.h"
#include "asm.h" 
#include "zxc_func.h"
#include "dmt2.h" 


char call_func(char (*f)(structA **, int, int ),  structA ** p1 , int p2, int p3 );


void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int rows, int columns  )
{
    // setup 

	structA **m;
        char result;
	m=zxc_new_matrix(rows,columns);
	int pok=dmt_has(m);
	int psize=dmt_size(m);
	TEST_ASSERT_MESSAGE(pok,"Pointer not in Dynamic Memory");
        TEST_ASSERT_EQUAL_INT(rows*sizeof(int*), psize);  
	/* up to here testing the test auxiliary functions */ 

	
	   int i,j; 
	   for (i=0;i<rows;i++) 
		for (j=0;j<columns;j++) 
			m[i][j].ub.b=1+i*columns+j; 
	   for (i=0;i<rows;i++) 
		for (j=0;j<columns;j++) 
		{  
		   result=call_func(return_unionB_b,m,i,j);
		   TEST_ASSERT_EQUAL_INT8(1+i*columns+j,result); 

		} 	
   	
	
	   for(j = 0; j < rows ; j++)
		   free(m[j]);
	   free(m);

    


}


void test_One()
{ 
    run_test(1,1);  
}
void test_Two()
{ 
    run_test(2,2); 
}
void test_Three()
{ 
    run_test(3,3); 
}
void test_Ten()
{ 
    run_test(10,10); 
}


int main()
  { 
    UNITY_BEGIN();
    RUN_TEST(test_One);
    RUN_TEST(test_Two);
    RUN_TEST(test_Three);
    RUN_TEST(test_Ten);
    return UNITY_END();  

  } 






