#include <stdio.h>
int main (void)
{
int a, j=0, i, flag=0, space=0, new_line=0, autaki, dautaki;	/* j,i~tabs&commands, flag~if you're in a command, space~whitespace, new_line~new line */
a=getchar();
while (a!=EOF){							/* autaki~', dautaki~" */
	if (a=='}'){
		if (flag==0){					/* When you read "}", */
			if (new_line==0){
				putchar('\n');}			/* Go to the next line */
			j--;
			for (i=0;i<=j-1;i++){			/* Print tabs */
				putchar('\t');}			/* According to the amount of commands */
			putchar('}');				/* Then print the character */
			putchar('\n');				/* New line now */
			space=0;
			new_line=1;
			}
		else{putchar(a);}
		}
	else if (a=='{'){
		if (flag==00){					/* When you read "{", */
			j++;
			putchar('\n');				/* Go to the next line */
			for (i=0;i<=j-2;i++){			/* Print the needed amount of tabs */
       		                putchar('\t');}			/* According to the amount of commands */
			putchar('{'); 				/* Print the character */
			putchar('\n');
			new_line=1; 				/* Next line now */
			space=0;
			}
		else{putchar(a);}
		}
	else if (a=='('){					/* When you read "(", */
		flag++;						/* You're in a command */
		putchar('(');
		}
	else if (a==')'){					/* When you read ")", */
		flag--;						/* Command is over */
		putchar(')');
		}
        else if (a==';'){					/* If you're not in a command, such as a "for", and meet a ";" */
                putchar(';');					/* Just print the ";" */
		if (new_line==0){
			putchar('\n');}
		space=0;
		new_line=1;					/* Then go to the next line */
		}
	else if (a==';'){					/* But if you're in a command */
		putchar(';');					/* Just print the ";" */
		}
	else if (a==EOF){					/* When the program is over */
		break;						/* Stop printing */
		}
	else if (a==' '||a=='\t'||a=='\n'||a=='\r'){		/* If you read space or tab or new line */
		space=1;}					/* Point that out */
	else if (a=='#'){					/* If you read # */
		putchar('#');
		a=getchar();
		while (a!= '\n' && a!= EOF){
			putchar(a);
			a=getchar();}				/* Type what you see until new line or EOF */
		putchar('\n');
		new_line=1;
		space=0;					/* New line now */
		}
	else if (a=='\''){
		autaki++;
		putchar('\'');
		}
	else if (a=='\"'){
		dautaki++;
		putchar('\"');
		}
	else{
		if(new_line){
			space=0;
			for (i=1;i<=j;i++){
				putchar('\t');}
			}
		if (space==1){					/* Since you met space/tab/new line */
			putchar(' ');				/* Print a space */
			space=0;				/* You're done */
			}
		if (autaki==1){
			putchar(a);
			while ((a=getchar())!='\''&&a!=EOF){
				putchar(a);}
			autaki--;
			}
		if (dautaki==1){
                        putchar(a);
                        while ((a=getchar())!='\"'&&a!=EOF){
                                putchar(a);}
                	dautaki--;
			}
		putchar(a);
		new_line=0;					/* If none of the above characters are meeted */
		}						/* Just print the character */
	a=getchar();
	}							/* Next character to be checked */
	return 0;
}
