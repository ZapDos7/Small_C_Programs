#include <stdio.h>
#define MAXNUM 1000

main ()
{
	int num, div, p, u;
	for (num=1; num<=MAXNUM; num++)
		{printf ("Divisors of %d are:", num);
		for (div=1; div*div<num; div++)
			{u=num%div;
			p=num/div;
			if (u==0) printf ("%d, %d, ", div, p);}
		if (p==div) printf("%d, ", div);
	printf ("%d\n", num);
	}
}
