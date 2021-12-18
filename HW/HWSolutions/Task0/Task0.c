#include <stdio.h>;
#include <math.h>;

int main()
{
	printf("Task: Distance between 2 circles\n");

	//input
	float x1, x2, y1, y2, r1, r2;
	float d;

	printf("Input parameters of the 1st circle (in form: x1 y1 r1):");
	scanf_s("%f %f %f", &x1, &y1, &r1);

	printf("Input parameters of the 2nd circle (in form: x2 y2 r2):");
	scanf_s("%f %f %f", &x2, &y2, &r2);


	//actions
	d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

	//output
	if (d == r1 + r2) 
	{
		printf("Okrujnosti kasautsya drug druga\n");
	}
	else
		if (d < r1 + r2) {
			if ((r1 == r2) && (x1 == x2) && (y1 == y2)) 
			{
				printf("Okrujnosti sovpadaut\n");
			}
			else
				if (d + r1 < r2 || d + r2 < r1) 
				{
					printf("Odna okrujnost vnutri drugoy\n");
				}
				else (d + r1 == r2 || d + r2 == r1); 
				{
					printf("Kasautsya vnutrenne\n");
				}
		}
		else
			if (d > r1 + r2) 
			{
				printf("Okrujnosti ne svyazani mejdu soboy\n");
			}
			else ((d < r1 + r2) && (d + r1 > r2 || d + r2 > r1)); 
			{
				printf("Okrujnosti peresekautsya\n");
			}
	return 0;
} 
