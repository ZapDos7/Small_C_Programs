#include <stdio.h>
#define MAXNUM 1000

main ()
{
	int num, div;
	for (num=1; num<=MAXNUM; num++)
		{printf ("Divisors of %d are:", num);
			for (div=1; div<=num/2; div++)
			{if (num%div==0) printf ("%d, ", div);}
		printf ("%d\n", num);
		}
}
