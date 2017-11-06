#include <stdio.h>

void koko(int i, int j, int *sum, int *diff)
{
*sum=i+j;
*diff=i-j;
}

int main(void)
{
	int a,b,i,j;
	scanf("%d %d",&a,&b);
	koko(a,b,&i,&j);
	printf("%d,%d\n", i, j);
}
