#include <stdio.h>

int main() {
	//input 
	int a, b, c;
	printf("Hi ! <(>_<)>\nYou are counting up the average value of 3 numbers!\n");
	printf("Input 3 numbers: a = ");
	scanf_s("%d", &a);
	printf(" \t\t b = ");
	scanf_s("%d", &b);
	printf(" \t\t c = ");
	scanf_s("%d", &c);


	//actions
	float Avg_of_3_numbers;
	Avg_of_3_numbers = (a + b + c)/3;

	//output
	printf("The average value of the 3 numbers = %f\n", Avg_of_3_numbers);
	return 0;
}