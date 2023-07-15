//5.	Write a program to read all float values form the file and display their sum.
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
    
    float num, sum = 0.0;
    
    while (fscanf(file, "%f", &num) == 1) 
	{
        sum += num;
    }
    
    printf("Sum of the float values: %.2f\n", sum);
    
    fclose(file);
    
    return 0;
}
