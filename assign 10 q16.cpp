//8.	Write a program to create a phone book. You should enter Name, Address, and phone 
//number of your friends.Each field should be separated using comma. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_FIELD_LENGTH 100

typedef struct 
{
    char name[MAX_FIELD_LENGTH];
    char address[MAX_FIELD_LENGTH];
    char phone[MAX_FIELD_LENGTH];
} Contact;

int main() 
{
    Contact phoneBook[MAX_CONTACTS];
    int contactCount = 0;
    
    char input[MAX_FIELD_LENGTH * 3];  
    
    printf("Enter the details of your friends (Name, Address, Phone), one per line:\n");
    printf("Press Enter twice to finish.\n");
    
    while (contactCount < MAX_CONTACTS) 
	{
        printf("Friend %d: ", contactCount + 1);
        
        if (fgets(input, sizeof(input), stdin) == NULL || strcmp(input, "\n") == 0) 
		{
            break;  
        }
        
        
        input[strcspn(input, "\n")] = '\0';
     
        char *token = strtok(input, ",");
        
        if (token == NULL) 
		{
            printf("Invalid input format. Please use Name, Address, Phone format.\n");
            continue;  
        }
    
        strncpy(phoneBook[contactCount].name, token, MAX_FIELD_LENGTH);
        phoneBook[contactCount].name[MAX_FIELD_LENGTH - 1] = '\0'; 
    
        token = strtok(NULL, ",");
        
        if (token == NULL) 
		{
            printf("Invalid input format. Please use Name, Address, Phone format.\n");
            continue;  
        }
        
        strncpy(phoneBook[contactCount].address, token, MAX_FIELD_LENGTH);
        phoneBook[contactCount].address[MAX_FIELD_LENGTH - 1] = '\0';  
        
        token = strtok(NULL, ",");
        
        if (token == NULL) 
		{
            printf("Invalid input format. Please use Name, Address, Phone format.\n");
            continue; 
        }
        
        strncpy(phoneBook[contactCount].phone, token, MAX_FIELD_LENGTH);
        phoneBook[contactCount].phone[MAX_FIELD_LENGTH - 1] = '\0'; 
        
        contactCount++;
    }
    
    printf("\nPhone Book Entries:\n");
    for (int i = 0; i < contactCount; i++) 
	{
        printf("Friend %d:\n", i + 1);
        printf("Name: %s\n", phoneBook[i].name);
        printf("Address: %s\n", phoneBook[i].address);
        printf("Phone: %s\n\n", phoneBook[i].phone);
    }
    return 0;
}
