//11.	Write a program to search phone number by entering name of person.
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20

typedef struct 
{
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

int main() 
{
    Contact phoneBook[MAX_CONTACTS];
    int contactCount = 0;
    
    char name[MAX_NAME_LENGTH];
    
    printf("Enter the details of your friends:\n");
    printf("Press Enter twice to finish.\n");
    
    while (contactCount < MAX_CONTACTS) 
	{
        printf("Friend %d\n", contactCount + 1);
        
        printf("Name: ");
        if (fgets(phoneBook[contactCount].name, sizeof(phoneBook[contactCount].name), stdin) == NULL ||
            phoneBook[contactCount].name[0] == '\n') 
			{
            break;  
        }
   
        phoneBook[contactCount].name[strcspn(phoneBook[contactCount].name, "\n")] = '\0';
        
        printf("Phone: ");
        fgets(phoneBook[contactCount].phone, sizeof(phoneBook[contactCount].phone), stdin);
    
        phoneBook[contactCount].phone[strcspn(phoneBook[contactCount].phone, "\n")] = '\0';
        
        contactCount++;
        printf("\n");
    }
    
    printf("Enter the name to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  
    
    int found = 0;
    for (int i = 0; i < contactCount; i++) 
	{
        if (strcmp(name, phoneBook[i].name) == 0) 
		{
            printf("Phone number for %s: %s\n", phoneBook[i].name, phoneBook[i].phone);
            found = 1;
            break;
        }
    }
    
    if (!found) 
	{
        printf("Phone number not found for %s.\n", name);
    }
    
    return 0;
}
