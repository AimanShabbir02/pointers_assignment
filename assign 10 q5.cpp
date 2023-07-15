//5.	Write a program to find the sum of 2 numbers returning a pointer.
#include <stdio.h>

int* findSum(int num1, int num2) 
{
    int sum = num1 + num2;
    int *sumPtr = &sum;  
    return sumPtr;
}

int main() 
{
    int num1, num2;
    
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    int *result = findSum(num1, num2);  
    
    printf("The sum is: %d\n", *result);  
    
    return 0;
}
