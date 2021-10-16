/*Научиться создавать массивы(статические и динамические)
Научиться заполнять массивы.
Реализовать несколько простых функций над массивами :
найти произведение нечетных элементов массива;
найти произведение элементов массива с нечётными индесами;
найти произведение элементов массива нечётных по значению; //?
поменять местами элементы с заданными индексами;
поменять местами правую и левую половины массива(ДЗ)
Пример: 1 2 3 4 5 6 7 8 -> 5 6 7 8 1 2 3 4
Указание.Реализовать двумя способами :
1. с использованием дополнительного массива;
2. без использования дополнительного массива.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 8

/*void printArr(int A[N]) {
	for (int i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n");
}*/

int main() {  // 0 1 2 3 4 5 6 7
	int A[N] = { 1,2,3,4,5,6,7,8 };
	int B[N] = { 0 };
	int product_odd_values = 1;
	int product_odd_index = 1;
	int i, j;

	printf("There is a static array with some elements:\n");
	for (i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n0 1 2 3 4 5 6 7 - indexes of elements\n");

	for (i = 0; i < N; i++) {
		if (A[i] % 2 > 0) {
			product_odd_values *= A[i];
		}

		if (i % 2 > 0) {
			product_odd_index *= A[i];
		}
	}
	printf("\nThere is a product of odd array elements: %d\n", product_odd_values);
	printf("\nThere is a product of array elements with odd indexes: %d\n", product_odd_index);

	//printf("\nInput 2 indexes (from 0 to 7) of the elements in the massive that u wanna swap\n");
	//scanf_s("%d %d", &i, &j);
	int tmp;
	/*for (; i < N; i++) {
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
	}
	for (i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n");*/

	int with_or_not;
	printf("\nEnter the mode of how to reverse the halves of the array (1 or 2):\n\n");
	printf("\tThe 1-st mode: without an additional array\n");
	printf("\tThe 2-nd mode: with an additional array\n\n");
	printf("The mode is: ");
	scanf_s("%d", &with_or_not);
	printf("\nWell! Let's reverse the halves of the array!\n\n");
	printf("There it is: ");
	switch (with_or_not) {
	case 1:
		//without an additional array
		for (i = 0; i < N / 2; i++) {
			tmp = A[i];
			A[i] = A[N / 2 + i];
			A[N / 2 + i] = tmp;
		}
		for (i = 0; i < N; i++)
			printf("%d ", A[i]);
		break;

	case 2:
		//with an additional array
		for (i = 0; i < N; i++) {
			B[i] = A[N / 2 + i];
		}
		for (i = 0; i < N; i++)
			printf("%d ", B[i]);
		printf("\n");
		break;

	default:
		printf("You entered the wrong number of the mode!");
		break;
	}
	printf("\n");

	return 0;
}


/*srand((unsigned)time(NULL));
for (int i = 0; i < N; i++) {
	A[i] = rand()%
}*/