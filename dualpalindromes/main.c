/*
ID: nishad.1
PROG: dualpal
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>

int convert_check(int num); //keeps converting into different bases until it verifies its status as dual p. returns 1 on succ, 0 on fail

int main()
{
    FILE *in  = fopen ("dualpal.in", "r");
    FILE *out = fopen ("dualpal.out", "w");
    int n, s;
    fscanf(in,"%d %d",&n,&s);
    while(n--)
    {
        s++;
        //printf("%d %d %d\n",n,s,convert_check(s));
        while(!convert_check(s))
        s++;
        fprintf(out,"%d\n",s);
    }
    return 0;
}

int convert_check(int num)
{
    int n, base, temp,i,j;
    int numstring[35];
    for(base=2, n=0; base<=10 && n<2; base++)
    {
        //***clear the numstring array//
        temp = num;
        i=0;
        while(temp>0)
        {
            numstring[i] = temp%base;
            temp /= base;
            i++;
        }
        for(--i,j=0; j<i; j++,i--) //check for palindrome, --i to denote last last array location.
        {
            if(numstring[j] != numstring[i]) //not matching
            break;
        }
        if(j>=i) //dual palindrome
        n++; //increase no. of dual p's by 1
    }
    if(n==2)
    return 1;
    else
    return 0;
}
