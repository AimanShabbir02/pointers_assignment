//2.	Write a program in C to add two numbers using pointers.
#include <stdio.h>
void addNumbers(int *a, int *b, int *result) 
{
    *result = *a + *b;
}
int main()
 {
    int num1, num2, sum;
    
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    addNumbers(&num1, &num2, &sum);
    printf("sum of %d and %d is %d\n", num1, num2, sum); 
    return 0;
}
