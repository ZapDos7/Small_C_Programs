#include <stdio.h>

int main (void)
{
 int a, count=0, whole=0;
 while (a!=EOF&&a!='\n'){
	a=getchar();
	if (a=='0'){
		a=getchar();
		if (a=='x'){
			a=getchar();
			while ((a>='0'&&a<='9')||(a>='A'&&a<='F')){
				count=1;
				a=getchar();}
			whole+=count;
			count=0;
			if (a==' '){
				continue;}
			else{continue;}
		}
		else{continue;}
	}
	else{a=getchar();}
	continue;
 }
printf("%d hex number(s) in this line.\n", whole);
return 0;
}
