//9.	Write a program to create a phone book using structures. You should enter Name, 
//Address, and phone number of your friends. 
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PHONE_LENGTH 20

typedef struct 
{
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

int main() 
{
    Contact phoneBook[MAX_CONTACTS];
    int contactCount = 0;
    
    printf("Enter the details of your friends:\n");
    printf("Enter 'q' in the Name field to exit.\n");
    
    while (contactCount < MAX_CONTACTS) 
	{
        printf("Friend %d\n", contactCount + 1);
        
        printf("Name: ");
        if (scanf("%s", phoneBook[contactCount].name) != 1 || phoneBook[contactCount].name[0] == 'q') 
		{
            break;  
        }
        
        printf("Address: ");
        scanf(" %[^\n]", phoneBook[contactCount].address);
        
        printf("Phone: ");
        scanf(" %s", phoneBook[contactCount].phone);
        
        contactCount++;
        printf("\n");
    }
    
    printf("Phone Book Entries:\n");
    for (int i = 0; i < contactCount; i++) 
	{
        printf("Friend %d:\n", i + 1);
        printf("Name: %s\n", phoneBook[i].name);
        printf("Address: %s\n", phoneBook[i].address);
        printf("Phone: %s\n\n", phoneBook[i].phone);
    }
    
    return 0;
}
