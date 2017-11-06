#include <stdio.h>
#define MAXNUM 1000

main ()
{
	int num, temp, rem;
	for (num=1; num <= MAXNUM; num++)
		{temp=num;
		printf ("%d reversed is ", num);
		while (temp!=0)
			{rem=temp%10;
			printf ("%d", rem);
			temp=temp/10;
			}
		printf ("\n");
	}
}
