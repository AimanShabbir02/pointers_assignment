//4.	Write a program to read all data from a file.
#include <stdio.h>

int main() 
{
    char filePath[100];
    
    printf("Enter the path of the file: ");
    scanf("%s", filePath);
    
    FILE *file = fopen(filePath, "r");
    
    if (file == NULL) 
	{
        printf("Failed to open the file.\n");
        return 1;
    }
    
    char ch;
    
    printf("Data read from the file:\n");
    while ((ch = fgetc(file)) != EOF) 
	{
        printf("%c", ch);
    }
    
    fclose(file);
    
    return 0;
}
