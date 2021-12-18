// Copyright 2021 Nikitin Kirill
// Group: 3821B1PR2

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
	 
	//for all
		int ModeOfTheGame = 0;
		int count_of_tries = 0;

	//for 1-st mode
		int attempt = 0;
		int rand_num; 
	
	//for 2-nd mode
		int num_for_guess = 0; //number that the computer will guess
		char compare;
		char equel = '=';
		char greater = '>';
		char lower = '<';
		int left = 1;
		int right = 1000;
		int current = 0;
		int notGuessed = 1;

	printf("Choose the mode of the game: 1-st mode: You got to guess the number\n");
	printf("\t\t\t     2-nd mode: The computer got to guess the number\n");
	scanf_s("%d", &ModeOfTheGame);

	switch (ModeOfTheGame) {
		case 1:
			printf("Welcome!\nYou gotta guess the number that the computer picked in range between 1 to 1000\n");
			srand((unsigned)time(NULL));
			rand_num = 1 + rand() % 1000;
			printf("The computer has picked the number in range of 1 to 1000!\nTry to guess it! Good luck!\nEnter the number You think the computer has picked: ");	
			while (notGuessed) {
				scanf_s("%d", &attempt);
				if ((attempt >= 1) && (attempt <= 1000)) {
					if (attempt == rand_num) {
						printf("\nCongratulations! You guessed the number!\nThe number for guessing was: %d\n", rand_num);
						count_of_tries++;
						notGuessed = 0;
						break;
					}
					else if (attempt > rand_num) {
						printf("The number < %d, try again: ", attempt);
						count_of_tries++;
					}
					else {
						printf("The number > %d, try again: ", attempt);
						count_of_tries++;
					}
				}
				else {
					printf("You entered the wrong number! The range is 1 to 1000.\nEnter the number again, please: ");
				}
			}
		break;

		case 2:
			printf("\nWelcome!\nThe computer will try to guess the number that you'd pick for guessing\n");
			printf("Choose the number from 1 to 1000 and I will guess it!\n");
			while (notGuessed) {
				current = (left + right) / 2;
				printf("\nI'm thinking... Your number is %d... Is it right?\n", current);
				getchar();
				scanf_s("%c", &compare);
				if (compare == equel) {
					printf("Yahoo! I guessed the number! It was %d\n", current);
					count_of_tries++;
					notGuessed = 0;
					break;
				}
				else
					if (compare == greater) {
						left = current + 1;
						count_of_tries++;
					}
					else (compare == lower); {
					right = current - 1;
					count_of_tries++;
					}
			}
			break;

		default:
				printf("You entered the variant that doesn't exist! Try again, please.\n");
				break;
	}
	printf("The quantity of tries is: %d\n", count_of_tries);
	printf("Goodbye!\n");
	return 0;
}