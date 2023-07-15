//12.	Write a program for inventory and records of a small shop. The records should 
//contain Item number, Name of item, price, and available stock. On running the program, 
//a menu should be displayed. 
/*a.	Enter 1 to add a new item
b.	Enter 2 to change the values of an item
c.	Enter 3 to delete an item
d.	Enter 4 to create a receipt (e.g., if a customer has bought multiple things, then you 
may keep entering the item number and quantity and a receipt should be created by program 
with each item details and total price. Receipt should show Item name, unit price, and 
total item price. At the end total amount should be displayed.)
e.	Enter 5 to exit*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct 
{
    int itemNumber;
    char itemName[MAX_NAME_LENGTH];
    float price;
    int stock;
} Item;

void printMenu() 
{
    printf("\n----- Shop Inventory and Records -----\n");
    printf("1. Add a new item\n");
    printf("2. Change the values of an item\n");
    printf("3. Delete an item\n");
    printf("4. Create a receipt\n");
    printf("5. Exit\n");
    printf("--------------------------------------\n");
    printf("Enter your choice: ");
}

int searchItem(Item *items, int itemCount, int itemNumber) 
{
    for (int i = 0; i < itemCount; i++) 
	{
        if (items[i].itemNumber == itemNumber) 
		{
            return i;  
        }
    }
    return -1;  
}

void addItem(Item *items, int *itemCount) 
{
    if (*itemCount >= MAX_ITEMS) 
	{
        printf("Maximum item count reached. Cannot add more items.\n");
        return;
    }
    
    Item newItem;
    
    printf("Enter item number: ");
    scanf("%d", &newItem.itemNumber);
    
    int index = searchItem(items, *itemCount, newItem.itemNumber);
    if (index != -1) 
	{
        printf("An item with the same number already exists.\n");
        return;
    }
    
    printf("Enter item name: ");
    scanf(" %[^\n]", newItem.itemName);
    
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    
    printf("Enter item stock: ");
    scanf("%d", &newItem.stock);
    
    items[*itemCount] = newItem;
    (*itemCount)++;
    
    printf("Item added successfully.\n");
}

void changeItem(Item *items, int itemCount) 
{
    if (itemCount == 0) 
	{
        printf("No items in the inventory. Cannot change values.\n");
        return;
    }
    
    int itemNumber;
    printf("Enter item number to change: ");
    scanf("%d", &itemNumber);
    
    int index = searchItem(items, itemCount, itemNumber);
    if (index == -1) 
	{
        printf("Item not found.\n");
        return;
    }
    
    Item *item = &items[index];
    
    printf("Enter new item name (or leave empty to skip): ");
    scanf(" %[^\n]", item->itemName);
    
    printf("Enter new item price (or 0 to skip): ");
    scanf("%f", &item->price);
    
    printf("Enter new item stock (or 0 to skip): ");
    scanf("%d", &item->stock);
    
    printf("Item values changed successfully.\n");
}

void deleteItem(Item *items, int *itemCount) 
{
    if (*itemCount == 0) 
	{
        printf("No items in the inventory. Cannot delete items.\n");
        return;
    }
    
    int itemNumber;
    printf("Enter item number to delete: ");
    scanf("%d", &itemNumber);
    
    int index = searchItem(items, *itemCount, itemNumber);
    if (index == -1) 
	{
        printf("Item not found.\n");
        return;
    }
    
    for (int i = index; i < *itemCount - 1; i++) 
	{
        items[i] = items[i + 1];
    }
    
    (*itemCount)--;
    
    printf("Item deleted successfully.\n");
}

void createReceipt(Item *items, int itemCount) 
{
    if (itemCount == 0) 
	{
        printf("No items in the inventory. Cannot create a receipt.\n");
        return;
    }
    
    int itemNumber, quantity;
    float totalAmount = 0.0;
    
    printf("Enter items and quantities (item number, quantity):\n");
    printf("Enter 0 for item number to finish.\n");
    
    while (1) 
	{
        printf("Item number: ");
        scanf("%d", &itemNumber);
        
        if (itemNumber == 0) 
		{
            break;  
        }
        
        int index = searchItem(items, itemCount, itemNumber);
        if (index == -1) 
		{
            printf("Item not found.\n");
            continue;
        }
        
        printf("Quantity: ");
        scanf("%d", &quantity);
        
        Item *item = &items[index];
        
        printf("Item Name: %s\n", item->itemName);
        printf("Unit Price: %.2f\n", item->price);
        printf("Total Item Price: %.2f\n", item->price * quantity);
        
        totalAmount += item->price * quantity;
    }
    
    printf("Total Amount: %.2f\n", totalAmount);
}

int main() 
{
    Item items[MAX_ITEMS];
    int itemCount = 0;
    
    int choice;
    
    do {
        printMenu();
        scanf("%d", &choice);
        
        switch (choice) 
		{
            case 1:
                addItem(items, &itemCount);
                break;
            case 2:
                changeItem(items, itemCount);
                break;
            case 3:
                deleteItem(items, &itemCount);
                break;
            case 4:
                createReceipt(items, itemCount);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } 
	while (choice != 5);
    
    return 0;
}
