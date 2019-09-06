#include <stdio.h>
#include <string.h>

int main (void) {
	int * lala;
	int lolo[5] = {1,2,3,4,5};
	for (int i=0;i<5;i++) {
		printf("\n%d\n", lolo[i]);
	}
	memcpy(lala, lolo, sizeof(int)*5);
	return 0;
}
