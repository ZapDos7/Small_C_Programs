#include <stdio.h>

int main (int argc, char *argv[])
{
	int i;
	for (i=0; i<=argc; i++){printf ("argv[%d] --> ", i);
	if (argv[i]!=NULL)printf("%s\n", argv[i]);
	else printf("NULL\n");}
	return 0;
}
