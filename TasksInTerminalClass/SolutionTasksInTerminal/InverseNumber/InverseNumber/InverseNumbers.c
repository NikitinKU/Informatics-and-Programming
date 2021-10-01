#include <stdio.h>

/* 
finish the code 
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
	int num;
	int mode1or2;
	printf("Hello! Let's inverse the number!\n");
	printf("For exit - enter 0\n");
	int isWork = 1;
	switch (mode1or2) {

	
	while (isWork) {
		int isError = 0; //ошибки нет
		do {
			if (isError) printf("You entered the wrong number! Number must be positive! Try again, please.\n");
			printf("input positive number: ");
			scanf_s("%d", &num);

			if (num == 0) {
				isWork = 0;
				break; //прерывание цикла, выход из него
			}
			isError = (num < 0); //меняем статус ошибки
		} while (isError);
		if (!isWork) continue; //не завершаем остаток итерации, переходим к следующей итерации
		//можно через break, но while (1) {
		//continue с флагом 

		//algorythm
		//int mode1or2;
		int c = 0; //c is an invert number in result
		switch (mode1or2) 
		
		case 1:
			while (num) {
				c *= 10;
				c += num % 10;
				num /= 10;
				//result
				printf("Result is %d\n", c);
			}

		case 2:
			while (num) {
				c += num % 10;
				num /= 10;
			}
			//result
			printf("Result is %d\n", c);
		
	}

	printf("Goodbye!\n");
	return 0;
}