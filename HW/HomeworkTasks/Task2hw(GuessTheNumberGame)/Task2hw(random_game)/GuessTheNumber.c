#define _CRT_RAND_S
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>

//Task2:
/*����������� ��������� ������� �����.
� ��������� ������ ���� ������������� ��� ������. 
����� 1. ��������� ����������� ��������� ����� �� ��������� �� 1 �� 1000. 
������������ ������ ������� �������, �� ������� ��������� ��������: ����������� ����� ������, ����������� ����� ������, ��������. 
������ �����������, ����� ������������ ������� �����. ����� ��������� ������ ������������ ����� ������� � �������� ��� � ����� ������. 
����� 2. ������������ ���������� ����� �� ��������� �� 1 �� 1000 � ������ ���. 
��������� �������� ��������� �����, ������ �� ����� �������, �� ������� ������������ ������ >, < ��� =. 
������ �����������, ����� ��������� ������� �����. ����� ��������� ������ ������������ ����� ������� � �������� ��� � ����� ������.*/

int main() {
	setlocale(LC_ALL, "Russian");

	//input
	int c, count_of_tries, attempt, ModeOfTheGame; 
	/*
	c - a random number in range of 1 to 1000 that the computer picks and gives you for guessing it 
	count_of_tries - all attempts the player did guessing the number
	attempt - player's attempt that he inputs every time
	ModeOfTheGame is literally the mode of the game
					 1-st mode: You gotta guess the number (case 1)
					 2-nd mode: The computer gotta guess the number (case 2)
	*/

	printf("Choose the mode of the game: 1-st mode: You gotta guess the number\n\t\t\t2-nd mode: The computer gotta guess the number");

	//actions
		switch (ModeOfTheGame)
		{
		case 1:
			printf("Welcome!\nYou gotta guess the number that the computer picked in range between 1 to 1000\n");
			srand(time(NULL));
			count_of_tries = 0; //��������� �������� ������� ������ �������� �����
			c = 1 + rand() % 1000; //� ���� ������� �� ������� ��������� ������� rand() �� 1000 � ��������� 1, ����� ���������� ������ ��������, �.�. �� 1 �� 1000.
			//printf("%d\n", c); //�����, ���������� �����������
			printf("The computer has picked the number in range of 1 to 1000!\nTry to guess it! Good luck!\nEnter the number You think the computer has picked: ");
			again:
			scanf_s("%d", &attempt);
			while (attempt > 0)
			{
				if ((attempt >= 1) && (attempt <= 1000))
				{
					if (attempt == c)
					{
						printf("\nCongratulations! You guessed the number!\nThe number for guessing was: %d\n", c);
						printf("By the way the quantity of tries is: %d\n", count_of_tries);
						count_of_tries += 1;
						break;
					}
					else
						if (attempt > c)
						{
							printf("The number < %d, try again: ", attempt);
							count_of_tries += 1;
							goto again;
							break;
						}
						else
						{
							printf("The number > %d, try again: ", attempt);
							count_of_tries += 1;
							goto again;
							break;
						}
				}
				else
				{
					printf("You entered the wrong number! The range is 1 to 1000.\nEnter the number again, please: ");
					goto again;
				}
		break;
			}
		case 2:
			printf("Welcome!\nThe computer will try to guess the number that you'd pick for guessing\nChoose the number from 1 to 1000: ");
			scanf_s("%d", &c);
			count_of_tries = 0; //��������� �������� ������� ������ �������� �����
			while () 
			{
				srand(time(NULL));
			}
			
		}
	return 0;
	}