#include <stdio.h>

#include "asm.h"

short currentSalary = 0;
short code = 0;

int main() {
	int result = new_salary();
	printf("%d\n", result);

	code = 20;
	currentSalary = 0;	
	result = new_salary();
	printf("%d\n", result);

	code = 21;
	currentSalary = 0;	
	result = new_salary();
	printf("%d\n", result);

	code = 22;
	currentSalary = 0;	
	result = new_salary();
	printf("%d\n", result);

	code = 25;
	currentSalary = 1000;
	result = new_salary();
	printf("%d\n", result);

	code = 22;
	currentSalary = 1000;
	result = new_salary();
	printf("%d\n", result);

	code = 21;
	currentSalary = 1000;
	result = new_salary();
	printf("%d\n", result);

	code = 20;
	currentSalary = 1000;
	result = new_salary();
	printf("%d\n", result);
	return 0;
}
