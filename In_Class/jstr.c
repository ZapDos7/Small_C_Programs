/* 8elw na kanei ena prama (struct to 8ewrei eniaio) me apo panw int to mhkos k apo katw pointers pou deixnoun sto string xwris to \0 meta omws */

#include <stdlib.h>
#include <stdio.h>
struct jstr
{
	int length;
	char *letters;
	};

struct jstr javastrsucks (char *src)
{
	int i=0;
	struct jstr str;
	str.length=0;
	while (src[str.length]!='\0')
		str.length++;
	str.letters=malloc(str.length*sizeof(char))
	while(*src!='\0'){
		str.letters[i]=src[i];
		i++;
		}
	return str;
}
int main (void)
{
	struct jstr str;
	str=javastrsucks("koko");
	printf("%d, %s\n", str.length, /* str.letters  ???  logw apousias \0 */);
	return 0;
}
