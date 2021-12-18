/* Вариант 1 (1 балл)
Заполнить массив размера N случайными значениями в диапозоне от - A до A и выполнить циклический сдвиг вправо на K элементов и развернуть.
Замечание.Измениться должен именно исходный массив.Печатать на экране в указанном порядке не считается решением.
Пример
Вход: 12 12 4
Например, случайно сгенерировался массив 4 -5 3 10 -4 -6 8 -10 1 0 5 7
Выход: -10 8 -6 -4 10 3 -5 4 7 5 0 1 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

int main() {
	int tmp;
	int i, k;
	int* a;
	int l, r, step_shift; 
	//l- massive's length, massive's range (from -A to A), step of cycle shift

	//init
	scanf_s("%d %d %d", &l, &r, &step_shift);
	a = (int*)malloc(l * sizeof(int));
	srand((unsigned)time(NULL));

	//initialization of massive with random numbers
	for (int i = 0; i < l; i++) {
		a[i] = (rand() % (r*2+1)) - r;
		printf(" %d ", a[i]);	
	}
	printf("\n");

	//cycle shift
	for (k = 0; k < l; k++) {
		tmp = a[l - step_shift];
		for (i = l - step_shift; i > 0; i--) 
			a[i] = a[i - step_shift];
		a[0] = tmp;
		printf(" %d ", a[i]);
	}
	printf("\n");

	//reverse
	for (i = 0; i < l / 2; i++) {
		tmp = a[i];
		a[i] = a[l - 1 - i];
		a[l - 1 - i] = tmp;
	}

	//output of massive
	for (i = 0; i < l; i++)
		printf(" %d ", a[i]);
	printf("\n");
	free(a);

	return 0;
}