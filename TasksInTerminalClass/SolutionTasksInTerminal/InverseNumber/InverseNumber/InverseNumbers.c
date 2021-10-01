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

int main () {
	long int num1;
	long int num2;
	int modeofthetask = 0;
	int isWork = 1;
	printf("Please, choose the method you want to do with the number:\n\n");
	printf("1-st method: Invert the entered number\n");
	printf("2-nd method: Accumulate the sum of numbers of the entered number\n");
	scanf_s("%d", &modeofthetask);

	switch (modeofthetask) {
	case 1:
		printf("Hello! Let's inverse the number!\n");
		printf("For exit - enter 0\n");
		
		while (isWork) {
			int isError = 0; //ошибки нет
			do {
				if (isError) printf("You entered the wrong number! Number must be positive! Try again, please.\n");
				printf("input positive number: ");
				scanf_s("%d", &num1);

				if (num1 == 0) {
					isWork = 0;
					break; //прерывание цикла, выход из него
				}
				isError = (num1 < 0); //меняем статус ошибки
			} while (isError);
			if (!isWork) continue; //не завершаем остаток итерации, переходим к следующей итерации
			//можно через break, но должно быть (выше) while (1) {
			//continue с флагом 

			//algorythm
			long int c = 0; //c is an inverted number in result

			while (num1) {
				c *= 10;
				c += num1 % 10;
				num1 /= 10;
			}
			//result
			printf("Result is %d\n", c);
		}
		printf("Goodbye!\n");
			break;

	case 2:
		printf("Hello! Let's accumulate the sum of numbers of the entered number\n");
		printf("For exit - enter 0\n");
		
		while (isWork) {
			int isError = 0; //ошибки нет
			do {
				if (isError) printf("You entered the wrong number! Number must be positive! Try again, please.\n");
				printf("input positive number: ");
				scanf_s("%d", &num2);

				if (num2 == 0) {
					isWork = 0;
					break; //прерывание цикла, выход из него
				}
				isError = (num2 < 0); //меняем статус ошибки
			} while (isError);
			if (!isWork) continue;

			//algorythm
			long int d = 0;
			while (num2) {
				d += num2 % 10;
				num2 /= 10;
			}
			//result
			printf("Result is %d\n", d);
		}
		printf("Goodbye!\n");
		break;

	default:
		printf("You entered the variant that doesn't exist! Try again, please.\n");
		break;
	} 
	return 0;
}