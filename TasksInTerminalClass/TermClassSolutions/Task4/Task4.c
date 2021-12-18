/*Научиться создавать массивы (статические и динамические)
Научиться заполнять массивы.
Реализовать несколько простых функций над массивами :
найти произведение нечетных элементов массива;
найти произведение элементов массива с нечётными индесами;
найти произведение элементов массива нечётных по значению; 
поменять местами элементы с заданными индексами;
ДЗ:
	Вариант 1: поменять местами правую и левую половины массива
		Пример: 1 2 3 4 5 6 7 8 -> 5 6 7 8 1 2 3 4
		Указание. Реализовать двумя способами :
		1. без использования дополнительного массива.
		2. с использованием дополнительного массива.

	Вариант 2: развернуть массив
		Пример: 1 2 3 4 5 7 8 9 -> 9 8 7 6 5 4 3 2 1
		Указание. Реализовать двумя способами : 
		1. используя другой массив.
		2. без дополнительных массивов.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int product_odd_elements = 1;
	int product_odd_values = 1;
	int product_odd_index = 1;
	int i, j, k, l;
	int tmp;
	int size;
	int min, max;

	printf("Input size of the array (it'd be better if u input an even number) : ");
	scanf_s("%d", &size);
	int* A = (int*)malloc(size * sizeof(int));
	int* B = (int*)malloc(size * sizeof(int));
	int* C = (int*)malloc(size * sizeof(int));
	int* D = (int*)malloc(size * sizeof(int));
	int* E = (int*)malloc(size * sizeof(int));
	int* F = (int*)malloc(size * sizeof(int));
	int* tmpArr = (int*)malloc(size * sizeof(int));

	printf("Enter minimum and maximum of numbers : ");
	scanf_s("%d %d", &min, &max);
	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++) {
		A[i] = (max - min) * ((float)rand() / RAND_MAX) + min;
	}

	printf("\n");
	for (i = 0; i < size; i++) {
		B[i] = A[i];
		tmpArr[i] = A[i];
		C[i] = A[i];
		D[i] = A[i];
		F[i] = A[i];
	}


	printf("There is a dynamic array with some elements : ");
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");

	for (i = 0; i < size; i++) {
		if (i % 2 == 0) product_odd_elements *= A[i];
		if (A[i] % 2 > 0) product_odd_values *= A[i];
		if (i % 2 > 0) product_odd_index *= A[i];
	}
	printf("\nThere is a product of odd array elements: %d\n", product_odd_elements);
	printf("\nThere is a product of odd in value array elements: %d\n", product_odd_values);
	printf("\nThere is a product of array elements with odd indexes: %d\n", product_odd_index);

	printf("\nInput 2 indexes (from 0 to MAX that u input) of the elements in the massive that u wanna swap : ");
	scanf_s("%d %d", &i, &j);
	tmp = tmpArr[i];
	tmpArr[i] = tmpArr[j];
	tmpArr[j] = tmp;
	for (i = 0; i < size; i++)
		printf("%d ", tmpArr[i]);
	printf("\n");

	int with_or_not, isWork = 1;
	while (isWork) {
		printf("\nEnter the mode of how to reverse the halves of the array (1 or 2):\n\n");
		printf("\tThe 1-st mode: without an additional array\n");
		printf("\tThe 2-nd mode: with an additional array\n");
		printf("\tOr input 0 for exit.\n\n");
		printf("The mode is: ");
		scanf_s("%d", &with_or_not);
			if (with_or_not == 0) {
				isWork = 0;
				break;
			}
		printf("\nWell! Let's reverse the halves of the array!\n\n");
		printf("There it is:\n");
		switch (with_or_not) {
		case 1:
			//without an additional array
			printf("\t( array : ");
			for (i = 0; i < size; i++)
				printf("%d ", A[i]);
			printf(")");
			printf("\n");

			for (i = 0; i < size / 2; i++) {
				tmp = A[i];
				A[i] = A[size / 2 + i];
				A[size / 2 + i] = tmp;
			}

			printf("\tinversed halves of massive : ");
			for (i = 0; i < size; i++)
				printf("%d ", A[i]);

			printf("\n");

			for (i = 0; i < size / 2; i++) {
				tmp = D[i];
				D[i] = D[size - i - 1];
				D[size - i - 1] = tmp;
			}
			printf("\tinversed massive : ");
			for (i = 0; i < size; i++)
				printf("%d ", D[i]);
			break;

		case 2:
			//with an additional array
			printf("\t( array : ");
			for (i = 0; i < size; i++)
				printf("%d ", A[i]);
			printf(")");
			printf("\n");

			for (i = size / 2, j = 0; i < size; i++, j++) {
				tmp = C[i];
				C[i] = C[j];
				C[j] = tmp;
			}

			printf("\tinversed halves of massive : ");
			for (i = 0; i < size / 2; i++) 
				printf("%d ", C[i]);
			for (k = 0; k < size / 2; k++) 
				printf("%d ", B[k]);

			printf("\n");

			for (i = 0; i < size; i++)
				E[i] = F[size - 1 - i];

			printf("\tinversed massive : ");
			for (i = 0; i < size; i++)
				printf("%d ", E[i]);
			break;

		default:
			printf("You entered the wrong number of the mode!");
			break;
		}
		printf("\n");

	}
	printf("\nGoodbye!\n");
	free(A);
	free(B);
	free(C);
	free(D);
	free(E);
	free(F);
	free(tmpArr);

	return 0;
}