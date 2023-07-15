//6.	Call a function without using its name using pointers.
#include <stdio.h>
void hello() 
{
    printf("Hello, world!\n");
}

int main() 
{
    void (*funcPtr)();  
    
    funcPtr = &hello;  
  
    (*funcPtr)();  
    
    return 0;
}
