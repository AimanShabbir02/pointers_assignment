//8.	Write a program to show pointer arithmatci
#include <stdio.h>

int main() 
{
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;  
    
    printf("Elements of the array using pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) 
	{
        printf("%d ", *(ptr + i));  
    }
    printf("\n");
    
    return 0;
}
