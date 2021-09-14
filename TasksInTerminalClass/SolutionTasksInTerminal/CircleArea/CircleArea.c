#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main() {
	//input 
	int R;
	printf("Hi ! <(^_^)>\nYou are searching for the area of the circle!\n");
	printf("Input the radius of the circle:\nR = ");
	scanf_s("%d", &R);

	//actions
	double S;
	S = M_PI * R;

	//output
	printf("Area of your circle is %4lf\n", S);
	return 0;
}