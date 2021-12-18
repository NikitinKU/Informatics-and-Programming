// Copyright 2021 Nikitin Kirill
// Group: 3821B1PR2

/*
* Постановка задачи:
Разработать программу, реализующую игру «Быки и коровы».
Требования(правила).
	Играют два игрока(человек и компьютер).
	Игрок выбирает длину загадываемого числа – n(от 2 до 5).
	Компьютер «задумывает» n - значное число с неповторяющимися цифрами.
	Игрок делает попытку отгадать число – вводит n - значное число с неповторяющимися цифрами.
	Компьютер сообщает, сколько цифр угадано без совпадения с их позициями в загаданном числе(то есть количество коров)
	и сколько угадано вплоть до позиции в загаданном числе(то есть количество быков).
	Игрок делает попытки, пока не отгадает всю последовательность.
Пример.
	Пусть n = 4.
	Пусть задумано число «3219».
	Игрок ввел число «2310».
	Результат: две «коровы»(две цифры : «2» и «3» — угаданы на неверных позициях) и один «бык»(одна цифра «1» угадана вплоть до позиции).
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int main() {
	int size;
	//int i, j, k, l, n, p;
	int isWork = 1, reInput = 1;
	int userGuess;
	int tmp = 0;
	int toPlay;
	int isPlayed = 1;
	printf("Press: 1 - to start the game\n       0 - to exit\n\n");
	while (isPlayed) {
		printf("Your input is : ");
		scanf_s("%d", &toPlay);
		printf("\n");
		if (toPlay == 0) isPlayed = 0;

		switch (toPlay) {
		case 1:
			printf("Input size of the number that you are going to guess (from 2 to 5) : ");
			reInput = 1;
			while (reInput) {
				scanf_s("%d", &size);
				if (size < 2 || size > 5) printf("Input size from 2 to 5 : ");
				else reInput = 0;
			}

			printf("\n");
			int* A = (int*)malloc(size * sizeof(int));
			int* B = (int*)malloc(size * sizeof(int));

			srand(time(NULL));
			isWork = 1;
			while (isWork) {
				int i, j, k, l, n, p, z, x;
				int checkRepeat = 1;
				int reRand = 1;
				while (reRand) {
					int checkRand = 1;
					for (i = 0; i < size; i++) {
						A[i] = rand() % 9;
					}
					int empty;
					for (i = 0, empty = i + 1; i < empty; i++) {
						if ((i == 0) && (A[i] == 0)) {
							checkRand = 0;
							break;
						}
					}
					if (checkRand == 1) reRand = 0;
					else continue;
				}

				//checking for reapeat of the numbers 
				if (size == 5) {
					for (i = 1, j = i - 1, k = 0, l = size - 1, n = size - 1, p = 0, z = i + 1, x = size - 2; i < size; i++, j++, l--, p++) {
						if ((A[i] == A[j]) || (A[k] == A[l]) || (A[n] == A[p]) || (A[z] == A[x])) {
							checkRepeat = 0;
							break;
						}
					}
					if (checkRepeat == 1) isWork = 0;
					else continue;
				}
				else
					for (i = 1, j = i - 1, k = 0, l = size - 1, n = size - 1, p = 0; i < size; i++, j++, l--, p++) {
						if ((A[i] == A[j]) || (A[k] == A[l]) || (A[n] == A[p])) {
							checkRepeat = 0;
							break;
						}
					}
				if (checkRepeat == 1) isWork = 0;
				else continue;
			}

			/*
			printf("This is the number that computer has guessed: ");
			for (int i = 0; i < size; i++) {
				printf("%d", A[i]);
			}
			printf("\n");
			*/

			printf("Ok, I guessed the number!\n\n");
			isWork = 1;
			while (isWork) {
				int i, j;
				reInput = 1;
				while (reInput) {
					printf("Input your guess : ");
					scanf_s("%d", &userGuess);

					for (i = 0; i < size; i++) {
						B[i] = userGuess % 10;
						userGuess /= 10;
					}
					for (i = 0; i < size / 2; i++) {
						tmp = B[i];
						B[i] = B[size - i - 1];
						B[size - i - 1] = tmp;
					}

					int checkUserGuess = 1;
					int empty;
					for (i = 0, empty = i + 1; i < empty; i++) {
						if ((i == 0) && (A[i] == 0)) {
							checkUserGuess = 0;
							break;
						}
						if (checkUserGuess == 1) reInput = 0;
						else continue;
					}
				}

				//the game
				int cows = 0, bulls = 0;
				for (i = 0; i < size; i++) {
					for (j = 0; j < size; j++) {
						if (A[i] == B[j]) {
							if (i == j) bulls++;
							else cows++;
						}
					}
				}
				printf("Cows : %d\tBulls : %d\n\n", cows, bulls);
				if (bulls == size) isWork = 0;
			}
			free(A);
			free(B);
			printf("The game is over!\nYou guessed my number!\n\n");
			printf("Press: 1 - to play again\n       0 - to exit\n\n");
			break;
		case 0: 
			break;
		default:
			printf("You entered the wrong key! Try again please!\n\n");
			break;
		}
	}
	printf("Goodbye!\n\n");
	return 0;
}