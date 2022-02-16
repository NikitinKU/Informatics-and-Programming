// Copyright 2021 Nikitin Kirill
// Group: 3821B1PR2

/*Постановка задачи:
Разработать программу «Электронная касса».
Программа должна имитировать работу кассового аппарата по сканированию товаров и формированию чека за покупку.
Каждый товар идентифицируется штрих-кодом. Штрих-код хранится в виде массива из четырех символов.
Каждый символ принимает значение от ‘0’ до ‘9’.
Один и тот же товар может сканироваться несколько раз, но в чек информация о каждом товаре входит в виде
«наименование – стоимость за единицу (для упрощения в рублях без копеек) – количество – общая стоимость за товар».
Чек состоит не менее чем из одной записи указанного вида.
Чек дополнительно включает общую стоимость товаров в покупке, суммарную скидку и итоговую сумму к оплате (все в рублях).
Каждый товар описывается штрих-кодом, наименованием, стоимостью за единицу товара, скидкой в процентах от стоимости.
Скидки устанавливаются на каждый товар независимо (в диапазоне от 1 до 50%). 
	Программа должна предоставлять следующие операции:
		1) «сканировать» очередной товар,
		2) вывести описание отсканированного товара,
		3) добавить данные о товаре в чек,
		4) сформировать чек за покупку,
		5) рассчитать итоговую сумму к оплате.*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#define SIZE 13
#define SYMB 13
#define N 4

int main() {
	srand((unsigned)time(NULL));
	int barcode[SIZE][N], barcodeCheck[SIZE], discount[SIZE];
	char products[SIZE][SYMB] = { {"Milk"}, {"Banana"}, {"Apple"}, {"Nutella"}, {"Eggs"}, {"Bread"}, {"Chicken"}, {"Juice"}, {"Tomato"}, {"Potato"}, {"Cheese"}, {"Oil"}, {"Fish"} };
	int price[SIZE] = { 63, 15, 10, 360, 99, 46, 370, 100, 17, 8, 160, 130, 890 };
	int receipt[SIZE] = { 0 };
	int usersBarcode;
	int MenuChooser = 0;
	int isWork = 1;
	int scanProduct, check, lastScannedProduct = 0, k = 0, priceWithDiscount = 0, amountToPay = 0, totalPrice = 0;

	//barcode generation && discount generation (0% - 50%)
	int checkZero = 1;
	while (checkZero) {
		int Zero = 0;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < N; j++) {
				barcode[i][j] = rand() % 10;
				if (barcode[i][j] == 0) {
					Zero = 1;
					break;
				}
			}
			if (Zero == 1) break;
		}
		if (Zero == 0) checkZero = 0;
	}
	for (int i = 0; i < SIZE; i++) discount[i] = rand() % 50;
	

	for (int i = 0; i < SIZE; i++) {
		int ArrToNum = 0;
		for (int j = 0; j < N; j++) {
			ArrToNum = 10 * ArrToNum + barcode[i][j];	
		}
		barcodeCheck[i] = ArrToNum;
	}

	printf("  Shopping time !\n\n");
	printf("Press : '1' to scan the product\n\t");
	printf("'2' for product information\n\t");
	printf("'3' to add product information to the receipt\n\t");
	printf("'4' to generate a receipt for the purchase and calculate the total amount to be paid\n\t");
	printf("'5' to display the menu of the products you can buy\n\t");
	printf("'6' to display the menu of the cash machine\n\n");

	while (isWork) {
		printf("Your input : ");
		scanf_s("%d", &MenuChooser);
		printf("\n");
		switch (MenuChooser) {
			case 1: //scanning the product
				scanProduct = 1;
				while (scanProduct) {
					check = 1;
					int sameNum = 0;
					printf("Enter the barcode : ");
					scanf_s("%d", &usersBarcode);
					while (check) {
						if (usersBarcode >= 1000 && usersBarcode <= 9999) {
							for (int i = 0; i < SIZE; i++)
								if (barcodeCheck[i] == usersBarcode) {
									sameNum = 1;
									lastScannedProduct = i;
									printf("Product has been scanned!\n");
									break;
								}
							if (sameNum == 0) {
								printf("\nYou've entered the wrong barcode, try again, please!\n");
								break;
							}
						}
						else {
							printf("You've entered the wrong barcode, try again, please!\n\n");
							check = 0;
						}
						if (check == 1) break;
					}
					if (check == 1) {
						scanProduct = 0;
					}
				}
				printf("\n");
				break;
			case 2: //info about the last scanned product
				printf("Information about the scanned product:\n\n");
				printf("|^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^|\n");
				printf("|---------------------------------------------------------------|\n");
				printf("| Barcode\t| Name   \t| Price\t\t| Discount(%%)\t|\n");
				printf("|_______________|_______________|_______________|_______________|\n");
				printf("| %d\t\t| %s   \t| %d rub.\t| %d %%\t\t|\n", barcodeCheck[lastScannedProduct], products[lastScannedProduct], price[lastScannedProduct], discount[lastScannedProduct]);
				printf("|_______________|_______________|_______________|_______________|\n\n");
				break;
			case 3: //adding last scanned product to the receipt
				receipt[lastScannedProduct]++;
				k++;
				printf("The product has been added to the receipt\n\n");
				break;
			case 4: //check output && amount to pay output
				printf("|^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^|\n");
				printf("| Your check\t\t\t\t\t\t\t\t\t\t\t\t|\n");
				printf("|-------------------------------------------------------------------------------------------------------|\n");
				printf("| Name   \t\t| Price\t\t| Discount(%%)\t| Price w/ discount | Quantity  | Amount to pay\t|\n");
				printf("|_______________________|_______________|_______________|___________________|___________|_______________|\n");
				for (int i = 0; i < SIZE; i++) { 
					if (receipt[i] == 0) {
						continue;
					}
					priceWithDiscount = price[i] - (price[i] * discount[i] * 0.01);
					amountToPay = receipt[i] * priceWithDiscount;
					totalPrice += amountToPay;
					printf("| %s   \t\t| %d rub.\t| %d%%\t\t| %d\t\t    | %d\t\t| %d\t\t|\n", products[i], price[i], discount[i], priceWithDiscount, receipt[i], amountToPay);
					printf("|_______________________|_______________|_______________|___________________|___________|_______________|\n");
				}
				printf("| \t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
				printf("| Total price : %d\t\t\t\t\t\t\t\t\t\t\t|\n", totalPrice);
				printf("|_______________________________________________________________________________________________________|\n");
				printf("\n");
				system("pause");
				totalPrice = amountToPay = priceWithDiscount = 0;
				system("cls"); //Clearing the console 
				break;
			case 5: //Menu of products
				printf("|^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^|\n");
				printf("| All products\t\t\t\t\t\t\t\t|\n");
				printf("|-----------------------------------------------------------------------|\n");
				printf("| Name   \t\t| Price\t\t| Barcode\t| Discount(%%)\t|\n");
				printf("|_______________________|_______________|_______________|_______________|\n");
				for (int i = 0; i < SIZE; i++) {
					printf("| %s   \t\t| %d rub.\t| %d\t\t| %d %%\t\t|\n", products[i], price[i], barcodeCheck[i], discount[i]);
					printf("|_______________________|_______________|_______________|_______________|\n");
				}
				printf("\n");
				break;
			case 6: //Menu of cash machine
				printf("Press : '1' to scan the product\n\t");
				printf("'2' for product information\n\t");
				printf("'3' to add product information to the receipt\n\t");
				printf("'4' to generate a receipt for the purchase and calculate the total amount to be paid\n\t");
				printf("'5' to display the menu of the products you can buy\n\t");
				printf("'6' to display the menu of the cash machine\n\n");
				break;
			default: 
				printf("ERROR! You've entered the wrong operation!\n\n");
				break;
		}
	}
	return 0;
} 