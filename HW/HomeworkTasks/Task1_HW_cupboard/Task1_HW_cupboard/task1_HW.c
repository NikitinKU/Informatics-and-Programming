// Copyright 2021 Nikitin Kirill
// Group: 3821B1PR2


/*
Task 1 (Homework):
����� ������� ����� ��������� ����������� ������� �����.

������ ����� :
1. ��������� ������ ������ �� ��� ������� h �� 180 �� 220 ��, ������� w �� 80 �� 120 �� � �������� 5 ��,
2. ��� �������� �� ��� ������� h, �������� d �� 50 �� 90 �� � �������� 15 ��,
3. ��������� ������� � ������ ������ �� ��� ������� w, �������� d � �������� 15 ��,
4. ��� ��������� ����� �� ������ ������� h, ����� ������� w � �������� 1 ��,
5. ���������� ����� � ����� ����� ������ 40 �� �� ���.
������, ��� �������� ��������� ���, ��� � ������, ����� ����� �����.
*/

#include <stdio.h>
#include <math.h>

int main() {
	float h, w, d;
	float dvp, dsp, wood;
	float stenka, bokovini, krishki, dveri, polki, shkaf;
	int iswork = 1;

	printf("Input the height (from 1.8 to 2.2 meters), width (from 0.8 to 1.2 meters), deepness (from 0.5 to 0.9 meters) (using spacebar)\n");
	while (iswork) {
		scanf_s("%f %f %f", &h, &w, &d);
		if ((h >= 1.8) && (h <= 2.2) && (w >= 0.8) && (w <= 1.2) && (d >= 0.5) && (d <= 0.9)) {
			iswork = 0;
			break;
		}
		else 
			printf("You entered the wrong parameters, try again, please.\n");
	}

	printf("Input the density of DVP, DSP, wood\n");
	printf("(In real life) The density of DVP is 700 - 800 kg/m^3\n");
	printf("\t       The density of DSP is 550 - 750 kg/m^3\n");
	printf("\t       The density of wood is 850 kg/m^3\n");
	printf("Parameters: ");
	scanf_s("%f %f %f", &dvp, &dsp, &wood);

	stenka = (h * w * 0.005) * dvp;
	bokovini = ((h * d * 0.015) * dsp) * 2;
	krishki = ((w * d * 0.015) * dsp) * 2;
	dveri = ((h * w * 0.01) * wood) * 2;
	polki = (h / 0.4 - 1) * (((w - 0.03) * d * 0.015) * dsp);
	shkaf = stenka + bokovini + krishki + dveri + polki;
	printf("The weight of the cupboard is: %f kg.", shkaf);
	return 0;
}