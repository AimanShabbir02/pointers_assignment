//7.	Write a program to handle 2D array using pointers.
#include <stdio.h>
#define ROWS 3
#define COLS 4

void printArray(int *arr, int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
	{
        for (int j = 0; j < cols; j++) 
		{
            printf("%d ", *(arr + i * cols + j));
        }
        printf("\n");
    }
}

int main() 
{
    int arr[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    printArray((int *)arr, ROWS, COLS);
    
    return 0;
}
