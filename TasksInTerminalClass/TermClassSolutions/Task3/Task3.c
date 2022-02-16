#include <stdio.h>

/* Task in terminal 01.10.21
2 modes (methods): 1: invert number
				   2: sum of numbers
example:
5372 2nd mode
res:17
5372 1st mode
res:2735
37200 1st mode
res:273
*/

int main()
{
	long int num;
	int modeofthetask = 0;
	int isWork = 1;

	long int c = 0; //c is an inverted number in result
	long int d = 0;

	printf("Hello! This programm will help you to manipulate with the entered number!\n");
	printf("Invert the number or accumulate the sum of numbers!\n\n");

	while (isWork)
	{
		int isError = 0; //ioeaee iao

		do
		{
			if (isError) printf("You entered the wrong number! Number must be positive! Try again, please.\n");
			printf("Input positive number:\n");
			scanf_s("%d", &num);

			if (num == 0)
			{
				isWork = 0;
				break; //i?a?uaaiea oeeea, auoia ec iaai
			}
			isError = (num < 0); //iaiyai noaoon ioeaee


			printf("\nPlease, choose the method you want to do with the number:\n\n");
			printf("1-st method: Invert the entered number\n");
			printf("2-nd method: Accumulate the sum of numbers of the entered number\n\n");
			scanf_s("%d", &modeofthetask);

			switch (modeofthetask)
			{

			case 1:
				printf("\nLet's inverse the number!\n");
				//algorythm
				while (num)
				{
					c *= 10;
					c += num % 10;
					num /= 10;
				}
				//result
				printf("Result is %d\n\n", c);
				printf("For exit - enter 0\n\n");
				break;

			case 2:
				printf("\nLet's accumulate the sum of numbers of the entered number!\n");
				//algorythm
				while (num)
				{
					d += num % 10;
					num /= 10;
				}
				//result
				printf("Result is %d\n\n", d);
				printf("For exit - enter 0\n\n");
				break;

			default:
				printf("You entered the variant that doesn't exist! Try again, please.\n");
				break;

			}
		} while (isError);
		if (!isWork) continue;
		/*ia caaa?oaai inoaoie eoa?aoee, ia?aoiaei e neaao?uae eoa?aoee
		ii?ii ?a?ac break, ii aie?ii auou (auoa) while (1) {
		continue n oeaaii */
	}
	printf("\nGoodbye!\n");
	return 0;
}