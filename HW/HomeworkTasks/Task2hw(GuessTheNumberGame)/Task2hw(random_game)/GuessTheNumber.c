// Copyright 2021 Kirill Nikitin

/*
/Task2:
/*����������� ��������� ������� �����.
� ��������� ������ ���� ������������� ��� ������.
����� 1. ��������� ����������� ��������� ����� �� ��������� �� 1 �� 1000.
������������ ������ ������� �������, �� ������� ��������� ��������: ����������� ����� ������, ����������� ����� ������, ��������.
������ �����������, ����� ������������ ������� �����. ����� ��������� ������ ������������ ����� ������� � �������� ��� � ����� ������.
����� 2. ������������ ���������� ����� �� ��������� �� 1 �� 1000 � ������ ���.
��������� �������� ��������� �����, ������ �� ����� �������, �� ������� ������������ ������ >, < ��� =.
������ �����������, ����� ��������� ������� �����. ����� ��������� ������ ������������ ����� ������� � �������� ��� � ����� ������.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {

	//input
	int c, count_of_tries = 0, attempt = 0, ModeOfTheGame = 0; 
	int num_for_guess = 0; //number that the computer will guess

	char equel = '=';
	char greater = '>';
	char lower = '<';

	printf("Choose the mode of the game: 1-st mode: You got to guess the number\n");
	printf("\t\t\t     2-nd mode: The computer got to guess the number\n");
	scanf_s("%d", &ModeOfTheGame);

	switch (ModeOfTheGame) {
		case 1:
			printf("Welcome!\nYou gotta guess the number that the computer picked in range between 1 to 1000\n");
			srand(time(NULL));
			c = 1 + rand() % 1000; //� ���� ������� �� ������� ��������� ������� rand() �� 1000 � ��������� 1, ����� ���������� ������ ��������, �.�. �� 1 �� 1000.
			//printf("%d\n", c); //�����, ���������� �����������
			printf("The computer has picked the number in range of 1 to 1000!\nTry to guess it! Good luck!\nEnter the number You think the computer has picked: ");
		again:
			scanf_s("%d", &attempt);
			while (attempt > 0) {
				if ((attempt >= 1) && (attempt <= 1000)) {
					if (attempt == c) {
						printf("\nCongratulations! You guessed the number!\nThe number for guessing was: %d\n", c);
						count_of_tries++;
						break;
					}
					else
						if (attempt > c) {
							printf("The number < %d, try again: ", attempt);
							count_of_tries++;
							goto again;
							break;
						}
						else {
							printf("The number > %d, try again: ", attempt);
							count_of_tries++;
							goto again;
							break;
						}
				}
				else {
					printf("You entered the wrong number! The range is 1 to 1000.\nEnter the number again, please: ");
					goto again;
				}
			}
			break;

		case 2:
			printf("Welcome!\nThe computer will try to guess the number that you'd pick for guessing\n");
			printf("Choose the number from 1 to 1000: ");
		again1:
			scanf_s("%d", &num_for_guess);
			srand(time(NULL));
			c = 1 + rand() % 1000;

			printf("Computer thinks this number is %d\n", c);
			printf("Is it right?\n");
			while (num_for_guess > 0) {
				/*if ((num_for_guess >= 1) && (num_for_guess <= 1000)) {
					if (c == num_for_guess) {
						printf("The computer guessed the number! It was %d\n", num_for_guess);
						count_of_tries++;
					}
					else 
						if (c > num_for_guess) {
							printf("");
							count_of_tries++;
						}
						else {
							printf("");
							count_of_tries++;
						}
				}
				else {
					printf("You entered the wrong number! The range is 1 to 1000.\nEnter the number again, please: ");
					goto again1;
				}*/
			}
			break;

		default:
			printf("You entered the variant that doesn't exist! Try again, please.\n");
			break;
	}
	printf("By the way the quantity of tries is: %d\n", count_of_tries);
	printf("Goodbye!\n");
	return 0;
}