/*
Name: Gabriel Chan
Date: December 6,2018
Title: Inventory Control System
Description: This program will help your business keep track of your stock, profit, overall profit and the placement of orders
Version:1.0
*/

#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void)
{
    char selection;
    do
	{
		system("cls");

		printf("Please enter your selection => ");
		scanf("%c", &selection);

		switch (selection)
		{

			case 'a':
			case 'A':
				break;

			case 'b':
			case 'B':
				break;

			case 'c':
			case 'C':
				break;

			case 'd':
			case 'D':
				break;

			case 'e':
			case 'E':
				break;

			default:
				if (selection != 'f'  && selection != 'F')
				{
					printf("Invalid entry, try again\n");
					system("pause");
				}
				getchar();
				}

	} while (selection != 'f' && selection != 'F');
	printf("You are exiting the application\n");
    system("pause");
    return (0);
}