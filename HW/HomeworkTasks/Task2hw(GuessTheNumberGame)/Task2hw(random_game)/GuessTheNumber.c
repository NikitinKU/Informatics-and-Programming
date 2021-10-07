#define _CRT_RAND_S
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>

//Task2:
/*Разработать программу «Угадай число».
В программе должно быть предусмотрено два режима. 
Режим 1. Программа «загадывает» случайное число из диапазона от 1 до 1000. 
Пользователь должен вводить отгадки, на которые программа сообщает: «загаданное число больше», «загаданное число меньше», «угадали». 
Работа завершается, когда пользователь угадает число. Также программа должна подсчитывать число попыток и выводить его в конце работы. 
Режим 2. Пользователь загадывает число из диапазона от 1 до 1000 и вводит его. 
Программа пытается «угадать» число, выводя на экран отгадки, на которые пользователь вводит >, < или =. 
Работа завершается, когда программа угадает число. Также программа должна подсчитывать число попыток и выводить его в конце работы.*/

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
			count_of_tries = 0; //Обнуление счетчика попыток игрока отгадать число
			c = 1 + rand() % 1000; //Я беру остаток от деления диапозона функции rand() на 1000 и прибавляю 1, чтобы установить нужный диапозон, т.е. от 1 до 1000.
			//printf("%d\n", c); //Число, загаданное компьютером
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
			count_of_tries = 0; //Обнуление счетчика попыток игрока отгадать число
			while () 
			{
				srand(time(NULL));
			}
			
		}
	return 0;
	}