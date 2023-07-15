//1.	Run the following code
# include <stdio.h>
using namespace std;
int main ()
{
	int x = 5;
	int *p;
	int *t;
	int **pp;
	int ***p2;
	p=&x;
	t=p;
	pp=&p;
	p2=&pp;
	printf("%p,%p,%p,%p\n",&x,p,&p,pp);
	*t=3;
	printf("%d,%d,%d,%d,%d,%d,%d",*p,*t,*pp,**pp,*p2,**p2,***p2); 
	  
}
