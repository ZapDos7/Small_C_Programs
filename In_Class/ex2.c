#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stud{
	int a;
	char *name;
	char *surname;
};

struct stud *creatstd (int am, char *nam, char *sur)
{
	struct stud *p;
	p=malloc(sizeof(struct stud));
	p->a=am;
	p->name=malloc((strlen(nam)+1)*sizeof(char));
	strcpy (p->name, nam);						/* +1 --> '\0' */
	p->surname=malloc((strlen(sur)+1)*sizeof(char));
	strcpy (p->surname, sur);
	return p;
}

int main (void)
{
	struct stud *allop;
	allop=creatstd(123456, "IOANNA-MITSOS","ZAPALIDI");
	printf("AM      = %d\nNAME    = %s\nSURNAME = %s\n", allop->a, allop->name, allop->surname); 
	return 0;
}
