#include <stdio.h>

int main() {
	//input 
	int a, h;
	printf("Hi ! <(^_^)>\nYou're searching for the area of the rectangle!\n");
	printf("Input parameters of the triangle: a = ");
	scanf_s("%d", &a);
	printf("\t\t\t\t  h = ");
	scanf_s("%d", &h);

	//actions
	float S;
	S = 0.5 * a * h;

	//output
	printf("The area of your triangle is %2f\n", S);
	return 0;
}