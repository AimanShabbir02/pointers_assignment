//3.	Write a program to append some new text to existing file
#include <stdio.h>

int main() 
{
    char filePath[100];
    
    printf("Enter the path of the file: ");
    scanf("%s", filePath);
    
    FILE *file = fopen(filePath, "a");
    
    if (file == NULL) 
	{
        printf("Failed to open the file.\n");
        return 1;
    }
    
    char text[100];
    
    printf("Enter the text to append to the file: ");
    scanf(" %[^\n]", text);
    
    fprintf(file, "%s", text);
    
    printf("Text appended to the file successfully.\n");
    
    fclose(file);
    
    return 0;
}
