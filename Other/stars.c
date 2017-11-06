#include <stdio.h>

int main (void)
{
int i,j=50,n,max,a;
printf("Do you like Christmas?(type 1 for yes or 0 for no)\n");
scanf("%d",&a);
while(a!=1){
	printf("Are you sure? How about now?\n");
	scanf("%d",&a);
}
for (n=1;n<=j;n++){
	for(i=1;i<(j-n+1);i++){
		putchar(' ');
	}
	for(i=1;i<=(2*n-1);i++){
		if(n%7==0){
			if((i+39)%6==0){
				putchar('Q');
			}
			else{
				putchar('*');
			}
		}
		else if((n-1)%7==0){
			if((i+37)%6==0){
				if((i+4)<=2*n-1){
					printf("QQ*QQ");
					i+=4;
				}
				else if((i+2)<=2*n-1){
					printf("QQ*");
					i+=2;
				}
				else if(i<=2*n+1){
					printf("Q");
				}
			}
			else if((i+34)%6==0){
				printf("QQ");
				i++;
			}
			else{
				putchar('*');
			}
		}
		else if((n-2)%7==0&&n!=2){
			if((i+34)%6==0){
				printf("Q");
			}
			else{
				putchar('*');
			}
		}
		else{
			putchar('*');
		}
	}
	putchar('\n');
}
if(j<=20){
	max=5;
}
else if(j<=40){
	max=7;
}
else{
	max=9;
}
for(n=1;n<=max;n++){
	for(i=1;i<=(2*j-1)/2-max/2;i++){
		if((i-1)%3==0&&n==1){
			putchar('Q');
		}
		else{
			putchar(' ');
		}
	}
	for(i=1;i<=max;i++){
		if((i-1)%3==0&&n==1){
			putchar('Q');
		}
		else{
			putchar('H');
		}
	}
	for(i=1;i<=(2*j-1)/2-max/2;i++){
		if((i-1)%3==0&&n==1){
			putchar('Q');
		}
		else{
			putchar(' ');
		}
	}
	putchar('\n');
}
printf("\nMerry Christmas!!! HO HO HO!!! =D\n\n");
}

