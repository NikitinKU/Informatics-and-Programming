#include <stdio.h>
#include <math.h>

int Avg_of_3_numbers() {
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
	Avg_of_3_numbers = (a + b + c) / 3;

	//output
	printf("The average value of the 3 numbers = %f\n", Avg_of_3_numbers);
	return 0;
}

int Avg_of_squares_of_3_numbers() {
	//input 
	int a, b, c;
	printf("\nHi ! <(>_<)>\nYou are counting up the average value of squares of 3 numbers!\n");
	printf("Input 3 numbers: a = ");
	scanf_s("%d", &a);
	printf(" \t\t b = ");
	scanf_s("%d", &b);
	printf(" \t\t c = ");
	scanf_s("%d", &c);

	//actions
	float Avg_of_squares_of_3_numbers;
	Avg_of_squares_of_3_numbers = ((pow(a, 2)) + (pow(b, 2)) + (pow(c, 2))) / 3;

	//output
	printf("The average value of squares of the 3 numbers = %f\n", Avg_of_squares_of_3_numbers);
	return 0;
}

int Avg_of_modules_of_3_numbers() {
	//input 
	int a, b, c;
	printf("\nHi ! <(>_<)>\nYou are counting up the average value of the modules of 3 numbers!\n");
	printf("Input 3 numbers: a = ");
	scanf_s("%d", &a);
	printf(" \t\t b = ");
	scanf_s("%d", &b);
	printf(" \t\t c = ");
	scanf_s("%d", &c);

	//actions
	float Avg_of_modules_of_3_numbers;
	Avg_of_modules_of_3_numbers = (abs(a) + abs(b) + abs(c)) / 3;

	//output
	printf("The average value of modules of the 3 numbers = %f\n", Avg_of_modules_of_3_numbers);
	return 0;
}

int Avg_of_mathroots_of_3_numbers() {
	//input 
	int a, b, c;
	printf("\nHi ! <(>_<)>\nYou are counting up the average value of the math. roots of the 3 numbers!\n");
	printf("Input 3 numbers: a = ");
	scanf_s("%d", &a);
	printf(" \t\t b = ");
	scanf_s("%d", &b);
	printf(" \t\t c = ");
	scanf_s("%d", &c);

	//actions
	float Avg_of_mathroots_of_3_numbers;
	Avg_of_mathroots_of_3_numbers = (sqrt(a) + sqrt(b) + sqrt(c)) / 3;

	//output
	printf("The average value of the math. roots of the 3 numbers = %f\n", Avg_of_mathroots_of_3_numbers);
	return 0;
}

int main()
{
	Avg_of_3_numbers();
	Avg_of_squares_of_3_numbers();
	Avg_of_modules_of_3_numbers();
	Avg_of_mathroots_of_3_numbers();
	return 0;
}