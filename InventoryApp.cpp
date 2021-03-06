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
void orderMore(inventory orderStock[],int moreItem);
int newitem(inventory newStock[], int newTotal);
void sales(inventory saleStock[], int afterSale);

int main(void)
{
	int totalItem=0;
	char selection;
	inventory stock[size];
	FILE *file_pointer;
	FILE *itemTotalp;

	itemTotalp = fopen("F:TOTALITEM.DAT", "r");

	if ((itemTotalp != NULL))
	{
		fscanf(itemTotalp, "%i", &totalItem);
		fclose(itemTotalp);
	}

	file_pointer = fopen("F:INVENTORY.DAT", "rb");

	if (file_pointer != NULL)
	{
		fread(stock, sizeof(inventory), size, file_pointer);
		fclose(file_pointer);
	}
    do
	{
		system("cls");

		explainProg();

		printf("Please enter your selection => ");
		scanf("%c", &selection);

		switch (selection)
		{

			case 'a':
			case 'A':
				item(stock, totalItem);
				break;

			case 'b':
			case 'B':
				profit(stock, totalItem);
				break;

			case 'c':
			case 'C':
				orderMore(stock, totalItem);
				break;

			case 'd':
			case 'D':
				totalItem = newitem(stock, totalItem);
				itemTotalp = fopen("F:TOTALITEM.DAT", "w");
				fprintf(itemTotalp, "%i", totalItem);
				fclose(itemTotalp);
				break;

			case 'e':
			case 'E':
				sales(stock, totalItem);
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
	file_pointer = fopen("F:INVENTORY.DAT", "wb");

	fwrite(&stock, sizeof(inventory), size, file_pointer);

	fclose(file_pointer);
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

void orderMore(inventory orderStock[],int moreItem)
{
	int orderItem;
	int order = 0;
	char selection;

	do
	{
		system("cls");
		

		printf("\n\t\t\t\t\t\t\t\tOrdering Existing Items\n\n");
		printf("When placing an Order please enter \"O\", if returning to the main menu please enter \"M\"\n\n");

		printf("Item No.\tItem Name\tStock Number\tCost\t\tNumber Sold\tItem Profit\n\n");

		for (int index = 0; index < moreItem; index++)
		{

			printf("%-15d\t%-15s\t%-15d\t$%-7.2f\t%-15d\t$%-15.2f\n", index+1, orderStock[index].name, orderStock[index].numberOfItems, orderStock[index].cost, orderStock[index].numberSold, orderStock[index].itemProfit);
		}

		getchar();
		printf("\nPlease enter \"O\" or \"M\": ");
		scanf("%c", &selection);


		if (selection == 'o' || selection == 'O')
		{
			printf("Please enter the item number: ");
			scanf("%d", &orderItem);
			if (orderItem <= moreItem)
			{
				printf("Please enter number of items ordered: ");
				scanf("%d", &order);
				orderStock[orderItem-1].numberOfItems += order;

			}
			else
			{
				printf("This item does not exist, please try again\n");
				system("pause");
			}
		}
		else
		{
			if (selection != 'm' && selection != 'M')
			{
				printf("Invalid selection, please try again\n");
				system("pause");
			}
		}
	} while (selection != 'm' && selection != 'M');
	getchar();
	return;
}

int newitem(inventory newStock[],int newTotal)
{
	char selection;


	do
	{
		system("cls");

		printf("\n\t\t\t\t\t\t\t\tOrdering New Items\n\n");
		printf("When adding a new item please enter \"N\", if returning to the main menu please enter \"M\"\n\n");


		printf("Item No.\tItem Name\tStock Number\tCost\t\tNumber Sold\tItem Profit\n\n");

		for (int index = 0; index < newTotal; index++)
		{

			printf("%-15d\t%-15s\t%-15d\t$%-7.2f\t%-15d\t$%-15.2f\n", index+1, newStock[index].name, newStock[index].numberOfItems, newStock[index].cost, newStock[index].numberSold, newStock[index].itemProfit);
		}
		getchar();
		printf("\nPlease enter \"N\" or \"M\": ");
		scanf("%c", &selection);
		if (selection == 'N' || selection == 'n')
		{
			getchar();
			printf("Please enter the name of new item: ");
			gets_s(newStock[newTotal].name);
			printf("Please enter the cost of new item: ");
			scanf("%f", &newStock[newTotal].cost);
			printf("Please enter number of new items ordered ");
			scanf("%d", &newStock[newTotal].numberOfItems);
			newStock[newTotal].numberSold = 0;
			newStock[newTotal].itemProfit = 0;
			newTotal++;
		}
		else
		{
			if (selection != 'm' && selection != 'M')
			{
				printf("Invalid selection, please try again\n");
				system("pause");
			}
		}
	} while (selection != 'm' && selection != 'M');
	getchar();
	return newTotal;
}

void sales(inventory saleStock[], int afterSale)
{
	int input;
	char selection;
	float profitTotal = 0;
	int itemsSold;

	do
	{
		system("cls");

		printf("\n\t\t\t\t\t\t\t\tSale Of Items\n\n");
		printf("When adding sale of item please enter \"S\", if returning to the main menu please enter \"M\"\n\n");

		printf("Item No.\tItem Name\tStock Number\tCost\t\tNumber Sold\tItem Profit\n\n");

		for (int index = 0; index < afterSale; index++)
		{
			profitTotal += saleStock[index].itemProfit;
			printf("%-15d\t%-15s\t%-15d\t$%-7.2f\t%-15d\t$%-15.2f\n", index+1, saleStock[index].name, saleStock[index].numberOfItems, saleStock[index].cost, saleStock[index].numberSold, saleStock[index].itemProfit);
			
		}
		printf("\n\n\t\t\t\t\t\t\t\tTotal Profit is $%-15.2f\n", profitTotal);

		getchar();
		printf("\nPlease enter \"S\" or \"M\": ");
		scanf("%c", &selection);
		if (selection == 's' || selection == 'S')
		{
			printf("Please enter the item number: ");
			scanf("%d", &input);
			if (input <= afterSale)
			{
				printf("Please enter number of items sold: ");
				scanf("%d", &itemsSold);
				if (itemsSold <= saleStock[input - 1].numberOfItems)
				{
					saleStock[input - 1].itemProfit = saleStock[input - 1].cost * 1.5 * itemsSold;
					saleStock[input - 1].numberOfItems -= itemsSold;
					saleStock[input - 1].numberSold += itemsSold;
				}
				else if (itemsSold > saleStock[input - 1].numberOfItems)
				{
					printf("This is over what is in stock, please order more or input a less amount\n");
					system("pause");
				}
				else
				{
					printf("Invalid entry, please try again");
				}
			}
			else
			{
				printf("This item does not exist, please try again\n");
			}
		}
		else
		{
			if (selection != 'm' && selection != 'M')
			{
				printf("Invalid selection, please try again\n");
				system("pause");
			}
		}
	} while (selection != 'm' && selection != 'M');
	getchar();
	return;
}