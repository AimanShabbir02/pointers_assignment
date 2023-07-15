//2.	Write a program to write some text to a file.
#include <stdio.h>

int main() 
{
    char filePath[100];
    
    printf("Enter the path of the file: ");
    scanf("%s", filePath);
    
    FILE *file = fopen(filePath, "w");
    
    if (file == NULL) 
	{
        printf("Failed to open the file.\n");
        return 1;
    }
    
    char text[100];
    
    printf("Enter the text to write to the file: ");
    scanf(" %[^\n]", text);
    
    fprintf(file, "%s", text);
    
    printf("Text written to the file successfully.\n");
    
    fclose(file);
    
    return 0;
}
