//1.	Run the following code
# include <iostream>
using namespace std;

main ()
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
	cout<<&x <<" "<<p <<" " <<&p<<" "<<pp<<" "<<endl;
	*t=3;
	cout<<" "<<*p <<" "<<*t<<" "<<*pp<<" "<<**pp<<" "<<*p2<<" "<<**p2<<" "<<***p2; 
	  
}
