/* ������� 1 (1 ����)
��������� ������ ������� N ���������� ���������� � ��������� �� - A �� A � ��������� ����������� ����� ������ �� K ��������� � ����������.
���������.���������� ������ ������ �������� ������.�������� �� ������ � ��������� ������� �� ��������� ��������.
������
���� : 12 12 4
��������, �������� �������������� ������ 4 - 5 3 10 - 4 - 6 8 - 10 1 0 5 7
����� : -10 8 - 6 - 4 10 3 - 5 4 7 5 0 1 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <malloc.h>
#define N 10

int main() {
	int i;
	int tmp;
	int a[N] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (i = 0; i < N; i++)
		printf(" %d ", a[i]);
	printf("\n");

	//reverse
	for (i = 0; i < N / 2; i++) {
		tmp = a[i];
		a[i] = a[N - 1 - i];
		a[N - 1 - i] = tmp;
	}
	for (i = 0; i < N; i++)
		printf(" %d ", a[i]);
	printf("\n");

	//sdvig
	int tmp1 = a[N - 1];
	for (i = N - 1; i > 0; --i)
		a[i] = a[i - 1];
	a[0] = tmp1;

	for (i = 0; i < N; i++)
		printf(" %d ", a[i]);
	printf("\n");


	return 0;
}