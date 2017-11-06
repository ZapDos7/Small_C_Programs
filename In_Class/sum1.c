/* sum1.c */

#include <stdio.h>                                                              /* Standard library I/O */

main ()
   {long int a, b;
    double sumA, sumB, curA, curB, sum; 
       a=1;
       b=2;
       sumA=0.0;
       sumB=0.0;
       sum=0.0;
    do {                                                                       /* First sum */
       curA=1/(((double) a)*((double) a));
       sumA=sumA+curA;
       a=a+2;
       } while (curA>1.0e-15);

   do {                                                                       /* Second sum */
       curB=1/(((double) b)*((double) b));
       sumB=sumB+curB;
       b=b+2;
       } while (curB>1.0e-15);

   sum=sumA-sumB;

   printf ("Summed %8ld terms, sum is %10.8f \n ", a+b-2, sum);
   }
