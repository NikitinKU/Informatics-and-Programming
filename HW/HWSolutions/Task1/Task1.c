// Copyright 2021 Nikitin Kirill
// Group: 3821B1PR2


/*
Task 1 (Homework):
Фирма «Умелые ручки» выпускает двухдверные одежные шкафы.

Состав шкафа :
1. накладная задняя стенка из ДВП высотой h от 180 до 220 см, шириной w от 80 до 120 см и толщиной 5 мм,
2. две боковины из ДСП высотой h, глубиной d от 50 до 90 см и толщиной 15 мм,
3. накладные верхняя и нижняя крышки из ДСП шириной w, глубиной d и толщиной 15 мм,
4. две накладные двери из дерева высотой h, общей шириной w и толщиной 1 см,
5. внутренние полки в шкафу через каждый 40 см из ДСП.
Считая, что известны плотности ДСП, ДВП и дерева, найти массу шкафа.
*/

#include <stdio.h>
#include <math.h>

int main() {
	float h, w, d;
	float dvp, dsp, wood;
	float stenka, bokovini, krishki, dveri, polki, shkaf;
	int iswork = 1;
	float eps = 0.001;

	//t - thickness 
	float t_of_stenka = 0.005;
	float t_of_bokovini = 0.015;
	float t_of_krishki = 0.015;
	float t_of_dveri = 0.01;
	float t_of_polki = 0.015;
	float shelf_space = 0.4;
	int quantity_of_component = 2;

	printf("Input the height (from 1.8 to 2.2 meters), width (from 0.8 to 1.2 meters), deepness (from 0.5 to 0.9 meters) (using spacebar)\n");
	while (iswork) {
		scanf_s("%f %f %f", &h, &w, &d);
		if (((h - eps >= 1.8) || (h + eps >= 1.8)) && 
			((h - eps <= 2.2) || (h + eps <= 2.2)) && 
			((w - eps >= 0.8) || (w + eps >= 0.8)) && 
			((w - eps <= 1.2) || (w + eps <= 1.2)) && 
			((d - eps >= 0.5) || (d + eps >= 0.5)) &&
			((d - eps <= 0.9) || (d + eps <= 0.9))) {
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

	stenka = (h * w * t_of_stenka) * dvp;
	bokovini = ((h * d * t_of_bokovini) * dsp) * quantity_of_component;
	krishki = ((w * d * t_of_krishki) * dsp) * quantity_of_component;
	dveri = ((h * w * t_of_dveri) * wood) * quantity_of_component;
	polki = (h / shelf_space - 1) * (((w - (t_of_bokovini * 2)) * d * t_of_polki) * dsp);
	shkaf = stenka + bokovini + krishki + dveri + polki;
	printf("The weight of the cupboard is: %f kg.", shkaf);

	return 0;
}