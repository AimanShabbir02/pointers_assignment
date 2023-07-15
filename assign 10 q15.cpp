//7.	Write a program to read lines in a while loop and display each line
#include <stdio.h>

int main() 
{
    char line[100];
    
    printf("Enter lines of text (press Enter twice to exit):\n");
    
    while (fgets(line, sizeof(line), stdin) != NULL) 
	{
        printf("Line: %s", line);
    }
    
    return 0;
}
