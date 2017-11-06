#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MINNUM 1990000001
#define MAXNUM 2000000000
#define MAXTRIES 10

int main (void)
{	long start, end, curtime, count=0, c, e, r, num, divisor, first_term;
	long long a;
	int is_prime, tries, i;

        if (MINNUM%2==0){                                                                       /* Check if MINNUM is even */
                first_term=MINNUM+1;}                                                           /* If it is, begin checkin with the next number */
        else{                                                                                   /* If not */
                first_term=MINNUM;}                                                             /* Begin with it */

		/* DETERMINISTIC ALGORITHM */
	printf ("Checking range [%08d, %08d] for primes.\n\n", MINNUM, MAXNUM);
	start=clock();
	for (num=first_term; num<=MAXNUM; num+=2){
		is_prime=1;
		divisor=3;									/* Since num is odd, begin checkin divisors from 3 */
			while (is_prime==1&&divisor*divisor<=num){				/* Check until its square root */
				if (num%divisor==0){						/* If num has a divissor */
					is_prime=0;}						/* num is not a prime */
			divisor=divisor+2;}							/* Skip even divisors */
		if (is_prime==1){								/* If num is prime */
			count++;}								/* Add to count */
		}
	end=clock();
	printf ("Deterministic algorithm: Found %ld primes in %.2f seconds.\n\n", count, 1.0*(end-start)/(CLOCKS_PER_SEC));
		/* PROBABILISTIC ALGORITHM */
	curtime = time (NULL);									/* Current time (secs) since 1/1/1970) */
	srand((unsigned int) curtime);								/* Seed for random number generator */
	printf ("Trying Fermat test with seed %ld.\n\n", curtime);
	for (tries=1; tries<=MAXTRIES; tries++){						/* For tries 1-10 */
		count=0;
		start=clock();
		for (num=first_term; num<=MAXNUM; num++){
			is_prime=1;
			r=num-1;								/* Exponent value */
			for (i=1;i<=tries&&is_prime==1;i++, r=num-1){					/* Find MAXTRIES "a"s and do the following */
				a=rand()%r+1;							/* Find a random "a" */
				c=1;
				while (r>0){							/* While exponent>0 */
					if(r%2==1){						/* If exponent modulo 2 gives 1 */
						c=a*c%num;}					/* c changes value to this */
					r=r>>1;							/* Bitwise change value of exponent */
					a=a*a%num;}						/* Change also value of base */
				if (c!=1){							/* If a^(p-1) mod p is not equal to 1 */
					is_prime=0;}						/* p is not a prime */
				}
			if (is_prime==1){
				count++;}
			}
		end=clock();
	printf("Probabilistic algorithm: Found %ld primes in %.2f seconds (tries=%d)\n", count, 1.0*(end-start)/(CLOCKS_PER_SEC), tries);}
}
