#include <stdio.h>

int main (void) {
	int a, count=0;
	while (a!=EOF&&a!='\n') {
		a=getchar();
		if (a=='0'){
			a=getchar();
			if (a=='x'){
				a=getchar();
				if (a%1==0||(a>='A'&&a<='F')) {
					count++;
					a=getchar();
				}
				if (a==' ') {
					break;
				}
				else {
					continue;
				}
			}
			else {
				continue;
			}
		}
		else {
			a=getchar();
		}
		continue;
 	}
 	printf("%d hex nums in this line.\n", count);
	count=0;
	return 0;
}