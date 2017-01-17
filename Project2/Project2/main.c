#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 10

#include "Item.h"

int main() {
	int size = 0, option, sku, quantity;
	float price;

	struct Item item[MAX_ITEMS];

	printf("Welcome to the Shop\n");
	printf("===================\n");

	printf("Please select from the following options: \n");
	printf("1) Display the inventory.\n");
	printf("2) Add to shop.\n");
	printf("0) Exit.\n");
	printf("Select: ");
	scanf("%d", &option);

	while (option != 0) {
		if (option == 1) {
			printf("Inventory1\n");
			printf("=====================================\n");
			printf("Sku       Price      Quantity\n");
			for (int i = 0; i < size; i++)
				printf("%d      %.2f      %d\n", item[i].sku_, item[i].price_, item[i].quantity_);
			printf("=====================================\n");

			printf("Please select from the following options: \n");
			printf("1) Display the inventory.\n");
			printf("2) Add to shop.\n");
			printf("0) Exit.\n");
			printf("Select: ");
			scanf("%d", &option);
		}
		else if (option == 2) {
				printf("Please input a SKU number:");
				scanf("%d", &sku);
				item[size].sku_ = sku;

				printf("Quantity: ");
				scanf("%d", &quantity);
				item[size].quantity_ = quantity;

				for (int i = 0; i < size; i++) {
					if (item[i].sku_ == sku) {
						item[i].quantity_ += quantity;
						printf("The item exists in the repository, quantity is updated.\n");

						goto SKIP;
					}
				}

				printf("Price: ");
				scanf("%f", &price);
				item[size].price_ = price;

				size++;
				printf("The item is successfully added to the inventory.\n");
				
				SKIP:
				if (size == MAX_ITEMS) {
					printf("Inventory\n");
					printf("=====================================\n");
					printf("Sku       Price      Quantity\n");
					for (int i = 0; i < size; i++)
						printf("%d      %.2f      %d\n", item[i].sku_, item[i].price_, item[i].quantity_);
					printf("=====================================\n");
				}

				printf("Please select from the following options: \n");
				printf("1) Display the inventory.\n");
				printf("2) Add to shop.\n");
				printf("0) Exit.\n");
				printf("Select: ");
				scanf("%d", &option);
		}
		else {
			printf("Invalid input, try again: Please select from the following options:\n");
			printf("1) Display the inventory.\n");
			printf("2) Add to shop.\n");
			printf("0) Exit.\n");
			printf("Select: ");
			scanf("%d", &option);
		}
	}
	printf("Good bye!\n");

	return 0;
}

/*
Welcome to the Shop
===================
Please select from the following options:
1) Display the inventory.
2) Add to shop.
0) Exit.
Select:8
Invalid input, try again: Please select from the following options:
1) Display the inventory.
2) Add to shop.
0) Exit.
Select:2
Please input a SKU number:2341
Quantity:3
Price:12.78
The item is successfully added to the inventory.
Please select from the following options:
1) Display the inventory.
2) Add to shop.
0) Exit.
Select:2
Please input a SKU number:4567
Quantity:9
Price:98.2
The item is successfully added to the inventory.
Please select from the following options:
1) Display the inventory.
2) Add to shop.
0) Exit.
Select:1


Inventory
=========================================
Sku         Price       Quanity
2341        12.78       3
4567        98.20       9
=========================================
Please select from the following options:
1) Display the inventory.
2) Add to shop.
0) Exit.
Select:2
Please input a SKU number:2341
Quantity:5
The item exists in the repository, quanity is updated.
Please select from the following options:
1) Display the inventory.
2) Add to shop.
0) Exit.
Select:1


Inventory
=========================================
Sku         Price       Quanity
2341        12.78       8
4567        98.20       9
=========================================
Please select from the following options:
1) Display the inventory.
2) Add to shop.
0) Exit.
Select:0
Good bye!
*/