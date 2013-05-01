/*
ID: nishad.1
PROG: palsquare
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>
#define MIN 1
#define MAX 10000000

char numeric[200], alphanum[200];
static FILE *in;
static FILE *out;

void convert(long long decimal, long long base) //converts to the required base and stores in a character array.
{
    long long digit, temp;
    int num_counter = 0, alphanum_counter = 0;
    while(decimal > 0)
    {
        digit = decimal % base;
        if(digit < 10)
        {
            numeric[num_counter] = '0' + digit;
            num_counter++;
            alphanum[alphanum_counter] = '0' + digit;
            alphanum_counter++;
        }
        else
        {
           alphanum[alphanum_counter] = ('A' - 10 + digit);
           alphanum_counter++;
           temp = digit % 10;
           numeric[num_counter] = '0' + temp;
           num_counter++;
           temp = ((digit/10) % 10);
           numeric[num_counter] = '0' + temp;
           num_counter++;
        }

        decimal /= base;
    }
    numeric[num_counter] = '\0';
    alphanum[alphanum_counter] = '\0';
}

void print(void)  //prints the number in required base.
{
    int i;
   /*i = (strlen(numeric) - 1);  //The numeric part.
    while(i >= 0) {
    fprintf(out,"%c",numeric[i]);
    i--;
    }
    fprintf(out," "); */
    i = (strlen(alphanum) - 1);
    while(i >= 0) {
    fprintf(out,"%c",alphanum[i]);
    i--;
    }
}

int check_palin(void) //checks whether given num is a palindrome
{
    int i, j;
    i = 0;
    j = strlen(alphanum) - 1;
    while(i < j)
    {
        if(alphanum[i] == alphanum[j])
        {
            i++;
            j--;
        }
        else
        break;
    }
    if(i < j)
    return 0;
    else
    return 1;
}

int main()
{
    in = fopen("palsquare.in","r");
    out = fopen("palsquare.out","w");
    long long base, num_decimal, digit;
    long long sq_dec;
    int i = 0;
    fscanf(in,"%d",&base);
    /* Iterating numbers starting from 1 in base 10 upto 300,
       squaring them, converting them to required base and then
       checking whether they are palindromes or not. If they are,
       then they are printed. */
    for(num_decimal = MIN; num_decimal <= MAX; num_decimal++)
    {
        convert(num_decimal,base);
        if(check_palin())
        {
        sq_dec = num_decimal * num_decimal;
        // Conversion of sq_dec to base B.
        convert(sq_dec,base);
        if(check_palin())
        {
            i++;
            printf("%d\n",i);
        convert(num_decimal,base);
        print();
        fprintf(out," ");
        convert(sq_dec,base);
        print();
        fprintf(out,"\n");
        }
        }
    }
    return 0;
}
