//by Ravi Prakash vickyravi17@gmail.com
#include<stdio.h>
#include<math.h>
void test( int *);
main()
{
	int a[4];
	a[1]=10;
	test(a);
}

void test(int *a)
{
	printf("%d",a[1]);
}
