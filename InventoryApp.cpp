/*
Name: Gabriel Chan
Date: December 6,2018
Title: Inventory Control System
Description: This program will help your business keep track of your stock, profit, overall profit and the placement of orders
Version:1.0
*/

#define _CRT_SECURE_NO_WARNINGS
#define size 10

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct {
	char name[15];
	float cost;
	int numberOfItems;
	int numberSold;
	float itemProfit;
}inventory;

void explainProg(void);
void item(inventory itemStock[], int items);
void profit(inventory profitStock[],int profitItem);

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

void explainProg(void)
{
	printf("Inventory Control System\n\n");
	printf("This program will help your business keep track of your stock, profit, overall profit and the placement of orders\n\n\n");

	printf("Selection Menu\n\n\n");
	printf("a) Show the names and number of each item in stock including the cost of\n");
	printf("each item and total value of each item in stock.\n");
	printf("b) Show the number of units sold each time, the profit for each item in stock\n");
	printf("and the total store profit\n");
	printf("c) Order more of existing items\n");
	printf("d) Order new items\n");
	printf("e) Enter the sale of items\n");
	printf("f) Quit\n\n\n");
	return;
}

void item(inventory itemStock[], int items)
{
	float totalValue;
	system("cls");
	printf("\n\t\t\t\t\tItems in Stock\n\n\n");
	printf("Item No.\tItem Name\tStock Number\tCost\t\t\tTotal Value\n");
	for (int index = 0; index < items; index++)
	{
		totalValue = itemStock[index].cost * itemStock[index].numberOfItems;
		printf("%-15d\t%-15s\t%-15d\t$%-15.2f\t$%-15.2f\n", index+1, itemStock[index].name, itemStock[index].numberOfItems, itemStock[index].cost, totalValue);
	}
	printf("\n\n");
	system("pause");
	getchar();
	return;
}

void profit(inventory profitStock[], int profitItem)
{
	float showProfit = 0;

	system("cls");
	printf("\n\t\t\t\t\tItem Profit\n\n\n");
	printf("Item No.\tItem Name\tNumber Sold\tItem Profit\n");
	for (int index = 0; index < profitItem; index++)
	{
		showProfit += profitStock[index].itemProfit;
		printf("%-15d\t%-15s\t%-15d\t$%-15.2f\n", index+1, profitStock[index].name, profitStock[index].numberSold, profitStock[index].itemProfit);
	}
	printf("\n\t\t\t\tTotal Profit is $%-15.2f\n\n\n", showProfit);
	system("pause");
	getchar();
	return;
}