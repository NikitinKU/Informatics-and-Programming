#include <stdio.h>
#include <math.h>

int main() {
	//input 
	int a, b, c, d, e, f;
	printf("Hi ! <(>_<)>\nYou are counting up the average value of squares of 3 numbers!\n");
	printf("Input 3 numbers: a = ");
	scanf_s("%d", &a);
	printf(" \t\t b = ");
	scanf_s("%d", &b);
	printf(" \t\t c = ");
	scanf_s("%d", &c);

	

	//actions
	float Avg_of_squares_of_3_numbers;
	d = a * a;
	e = b * b;
	f = c * c;
	Avg_of_squares_of_3_numbers = (d + e + f) / 3;

	//output
	printf("The average value of squares of the 3 numbers = %f\n", Avg_of_squares_of_3_numbers);
	return 0;
}