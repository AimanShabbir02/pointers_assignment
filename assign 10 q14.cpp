//6.	Write a program to read all lines of data from file into an array
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100
#define MAX_LENGTH 100

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
    
    char lines[MAX_LINES][MAX_LENGTH];
    int lineCount = 0;
 
    while (fgets(lines[lineCount], MAX_LENGTH, file) != NULL) 
	{
        lineCount++;
        if (lineCount == MAX_LINES) 
		{
            break;
        }
    }
    
    printf("Lines read from the file:\n");
    for (int i = 0; i < lineCount; i++) 
	{
        printf("%s", lines[i]);
    }
    
    fclose(file);
    
    return 0;
}
