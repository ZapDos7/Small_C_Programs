#include "fib.h"
int fib (int a)
{
	int s=0;
	if(a==0||a==1)
	{
		return 1;
	}
	else
	{
		s=fib(a-1)+fib(a-2);
	}
	return s;
}
