#include <stdio.h>
#include <math.h>
#include <time.h>

main ()
{long i=2;
 int start, end, counter;
 double sum=1.0, cur, value;

 start=clock();

 do {cur=1/(((double)i)*((double)i));
     sum=sum+cur;
     i++;
     counter++;}
 while
 (cur >  1.0e-15);

 value=sqrt(6*sum);

 printf ("Value is %f\n", value);

 end=clock();

 printf ("Time: %f secs\n", 1.0*(end-start)/(CLOCKS_PER_SEC));
 printf ("Counter:%d", counter);
 printf ("\n");
}
