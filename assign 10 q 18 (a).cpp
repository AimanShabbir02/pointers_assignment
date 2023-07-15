//10.	Write a program to display all phone records stored in Q9 and 10.
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

void displayPhoneBook(Contact *phoneBook, int contactCount) 
{
    printf("Phone Book Entries:\n");
    for (int i = 0; i < contactCount; i++) 
	{
        printf("Friend %d:\n", i + 1);
        printf("Name: %s\n", phoneBook[i].name);
        printf("Address: %s\n", phoneBook[i].address);
        printf("Phone: %s\n\n", phoneBook[i].phone);
    }
}

int main() 
{
    Contact phoneBook[MAX_CONTACTS];
    int contactCount = 0;
    
    char filePath[100];
    
    printf("Enter the path of the file: ");
    scanf("%s", filePath);
    
    FILE *file = fopen(filePath, "r");
    
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }
    
    char input[MAX_FIELD_LENGTH * 3];  
    
    while (contactCount < MAX_CONTACTS && fgets(input, sizeof(input), file) != NULL) 
	{
        
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
        
        if (token == NULL) {
            printf("Invalid input format. Please use Name, Address, Phone format.\n");
            continue;  
        }
        
        strncpy(phoneBook[contactCount].phone, token, MAX_FIELD_LENGTH);
        phoneBook[contactCount].phone[MAX_FIELD_LENGTH - 1] = '\0';  
        
        contactCount++;
    }
    
    fclose(file);
    
    displayPhoneBook(phoneBook, contactCount);
    
    return 0;
}
