//3.Write a program in C to store n elements in an array and print the elements using pointer.
#include <stdio.h>
int main() 
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
	{
        scanf("%d", &arr[i]);
    }
    
    printf("Elements in the array are:\n");
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", *(arr + i));
    }
    printf("\n");
    return 0;
}
