/*
ID: nishad.1
PROG: beads
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *in  = fopen ("beads.in", "r");
    FILE *out = fopen ("beads.out", "w");
    int N, i = 1, color1_start,color2_start = 0,color2_end = 0,x = 0,y = 0,total,highest_total = 0,flag = 1,initial,final_white;
    char a[500];
    fscanf(in,"%d",&N);
    fscanf(in,"%s",&a);
    while((i < strlen(a)) && (a[i] == a[i-1]))
    i++;
    if(i == strlen(a))
    highest_total = strlen(a);


    else {
    while(flag == 1)
    {
        total = 0;
        color1_start = color2_start; //imagine 2 pointers c1_start,c2_start and c2_end. c1_s,c2_s initialize tp 0, c2_end starts at a[1] and keeps progressing.
        color2_start = color2_end++;
        x = y;
        if(color1_start > 0) //accounts for additional whites in x before color1_start
        {
            i = 0;
            while(a[(color1_start - i - 1)] == 'w' && ((color1_start- i - 1) >= 0))
            i++;
            x += i;
        }
        if(a[color2_start] == 'w') //skip whites
        {
            i = color2_start;
            while(a[i] == 'w'){
            i++;
            total++;}
        color2_start = i;
        color2_end = 1 + color1_start;}
        while(((a[color2_end] == a[color2_start]) || a[color2_end] == 'w') && (color2_end < strlen(a))){
        color2_end++;
        if(a[color2_end] == 'w')
        final_white = color2_end;
        }
        if((color2_end) == (strlen(a)))
        flag = 0;
        y = color2_end - color2_start;
        if(x == 0)
        initial = y;
        //if(a[color2_start] == 'w')
        total += x + y;
        /*else
        total = x + y;*/
        if(total > highest_total)
        highest_total = total;
    }
    //printf("%d\n",highest_total);
    color2_end = 0;
    //printf("%c\n",a[color1_start]);
    while(((a[color2_end] == a[color2_start]) || a[color2_end] == 'w') && color2_end < (strlen(a)) && color2_end < final_white)
    color2_end++;
    total += color2_end;
    if(total > highest_total)
    highest_total = total;
    //printf("%d\n",highest_total);
    if(color2_end == 0)
    {
        x = y;
        y = initial;
        total = x + y;
        if(total > highest_total)
        highest_total = total;

    }
    else
    {
        x = y + color2_end;
        color1_start = color2_start;
        color2_start = color2_end++;
        i = color2_start;
        //printf("%d\n",color2_end);
        if(color1_start > 0) //accounts for additional whites in x before color1_start
        {
            i = 0;
            while(a[(color1_start - i - 1)] == 'w' && ((color1_start- i - 1) >= 0))
            i++;
            x += i;
            i = (color1_start - i - 1);
        }
       // printf("i = %d, color2_end = %d\n",i,color2_end);
        while(((a[color2_end] == a[color2_start]) || a[color2_end] == 'w') && (color2_end < i))
        color2_end++;
        //printf("%d ",color2_end); }
        y = color2_end - color2_start;
        total = x + y;
        if(total > highest_total)
        highest_total = total;
    }
    }
    fprintf(out,"%d\n",highest_total);
    return 0;
}
