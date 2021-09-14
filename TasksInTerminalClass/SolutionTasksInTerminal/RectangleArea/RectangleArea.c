#include <stdio.h>

int main() {
	//input 
	int a, b;
	printf("Hi ! <(^_^)>\nYou're searching for the area of the rectangle!\n");
	printf("Input parameters of the rectangle : a = ");
	scanf_s("%d", &a);
	printf("\t\t\t\t    b = ");
	scanf_s("%d", &b);

	//actions
	int S;
	S = a * b;

	//output
	printf("Area of your rectangle is %d\n", S);
	return 0;
}