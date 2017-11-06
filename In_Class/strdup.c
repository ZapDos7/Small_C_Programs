#include <stdlib.h>
#include <stdio.h>

char *mystrdup (char *src)
{
	char *dst;
	int a=0, pinakas;
	unsigned long long memory=0;
	while (src[a]!='\0') a++;				/* or *(src+i) ou */
/*	pinakas = malloc ( memory * sizeof(int) );
	if (pinakas==NULL){
		printf("Boo!\n");
		return 7;
		}
*/	dst = malloc ((a+1)*sizeof(char));
	while(*src!='\0'){
		*dst=*src;
		dst++;
		src++;
	}
	*dst='\0';							/*prosoxh stn epistrofh pointers*/
	dst-=a;
	return dst;
}
int main (void)
{
	char *blu="pragmata polla re su se lew re sou lew re.", *blublu;
	blublu = mystrdup (blu);
	return 0;
}
/* copy string se allh 8esh afou desmeusw arketh mnhmh */
