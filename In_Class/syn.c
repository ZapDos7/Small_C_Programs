#include <stdio.h>
/* int syn(int x); */   /* mporw na grapsw int syn (int) */
int syn(int x)
{
	if(x%2==0)
	{
		return 0;
	}
	else			/* h apla return x%2; h return x&1; */
	{
		return 1;
	}
}
int main(void)
{
	int x=10;
	if(syn(x)==0) printf("artios\n");
	else printf("perittos\n");
	return 0;
}
