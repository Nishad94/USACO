/*
ID: nishad.1
PROG: friday
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>
#define START_YR 1900
//Sunday 0 Mon 1 Tue 2 Wed 3 Thurs 4 Fri 5 Sat 6

int is_leap(int year);

int day_of_week[7] = {0};

int main()
{
    FILE *in  = fopen ("friday.in", "r");
    FILE *out = fopen ("friday.out", "w");
    int counter = -31,fridays = 0;
    int i,N,current_year;
    fscanf(in,"%d",&N);
    for(current_year = START_YR; N-- ;current_year++)
    {
       for(i = 1; i <= 12; i++) //12 months in a year.
       {
           switch(i)
           {
               case 1:  //Dec-->Jan
               case 2: //Jan --> Feb
               case 4: //March-->April
               case 6: //May--->June
               case 8: //July--> Aug
               case 9: //Aug-->Sep
               case 11: //Oct-->Nov
               counter += 31;
               day_of_week[((counter + 13) % 7)]++;
               break;

               case 3: //Feb-->March
               if(is_leap(current_year))
               counter += 29;
               else
               counter += 28;
               day_of_week[((counter + 13) % 7)]++;
               break;

               default:
               counter += 30;
               day_of_week[((counter + 13) % 7)]++;
               break;

           }

       }
    }

    fprintf(out,"%d %d %d %d %d %d %d\n",day_of_week[6],day_of_week[0],day_of_week[1],day_of_week[2],day_of_week[3],day_of_week[4],day_of_week[5]);
    return 0;
}

int is_leap(int year)
{
    if(year % 100 == 0)
    {
        if(year == 2000)
        return 1;
        else
        return 0;
    }
    else
    {
        if((year % 4) == 0)
        return 1;
        else
        return 0;
    }
}
