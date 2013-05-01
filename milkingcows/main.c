/*
ID: nishad.1
PROG: milk2
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *in  = fopen ("milk2.in", "r");
    FILE *out = fopen ("milk2.out", "w");
    int cows, start[5001], end[5001], i=0, flag=1;
    int start_var, longest_cont=0, longest_idle=0, temp=0;
    int current_end = 0, current_start=0, j;
    fscanf(in,"%d",&cows); //number of farmers/cows
    while((cows - i))  //taking start and end times as input
    {
        fscanf(in,"%d",&start[i]);
        fscanf(in,"%d",&end[i]);
        i++;
    }
    for(j=0; j < cows; j++) //sort according to start time(bubble sort)
    {
        for(i = 0; (i+1) < (cows-j); i++)
        {
        if(start[i] > start[(i+1)])
        {
            temp = start[i]; //sort the start time
            start[i] = start[(i+1)];
            start[(i+1)] = temp;
            temp = end[i]; //sort end time, along with sort time
            end[i] = end[(i+1)];
            end[(i+1)] = temp;
        }
        }

    }
    current_start = start[0];
    current_end = end[0];
    longest_cont = current_end - current_start;
    i = 1;
    while(flag == 1)
    {
        while((i < cows) && (start[i] <= current_end))
        {
            if(end[i] > current_end)
            {
                current_end = end[i];
            }
            i++;
        }

           temp = current_end - current_start;
           if(temp > longest_cont)
           longest_cont = temp;

        if(i < cows)
        {
            current_start = start[i];
            temp = current_start - current_end;
            if(temp > longest_idle)
            longest_idle = temp;
            current_end = end[i];
        }
        else
        flag = 0;

    }
    fprintf(out,"%d %d\n",longest_cont, longest_idle);
    fclose(in);
    fclose(out);
    return 0;
}
