#include <stdio.h>
#include <math.h>
#include <locale.h>

/* ���� ��������, ��� ������� �������� ������� ����� �������, ������ ��� ������ ��������� ��������, � ���� �� ������� �� ��������� ������, �� ��������� ������ �������� ������.
� ���� �������� ���������� ������ � ���������� 1, 5, 10, 25.
�������� ���������, ������� ���������� ����� ����������� ���������� �������� ����� ����� ��������� ��������.
������ ������� ������ �� ���� ��������� �������� ���� ����������� �����, ���� �� ������ ��������.
������ �������� ������ ��������� ������ ������� ���������� ��������� ���������� �������� ����� ��� ������.*/

int main()
{
	//input
	printf("Task about the Witcher\n");
	int price; //price that the Witcher
	int c; //number of coins

	//actions
	printf("Input the value to pay the Witcher: ");
    scanf_s("%d", &price);

	c = 0;
	while (price > 0)
	{
		if (price >= 25)
		{
			price = price - 25;
			c = c + 1;
		}

		if (price >= 10)
		{
			price = price - 10;
			c = c + 1;
		}

		if (price >= 5)
		{
			price = price - 5;
			c = c + 1;
		}

		if (price >= 1)
		{
			price = price - 1;
			c = c + 1;
		}

	}

	//output
	printf("The number of coins the Witcher gets is %d", c);
	return 0;
}