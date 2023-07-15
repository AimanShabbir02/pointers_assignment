//1.	Write a program to create a file on specified path.
#include <stdio.h>

int main() 
{
    char filePath[100];
    
    printf("Enter the path of the file to create: ");
    scanf("%s", filePath);
    
    FILE *file = fopen(filePath, "w");
    
    if (file == NULL) 
	{
        printf("Failed to create the file.\n");
        return 1;
    }
    
    printf("File created successfully at %s\n", filePath);
    
    fclose(file);
    
    return 0;
}
