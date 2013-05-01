/*
ID: nishad.1
PROG: ride
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    int i, total1,total2;
    char comet[6], group[6];
    fscanf(fin,"%s",&comet);
    fscanf(fin,"%s",&group);
    for(i = 0, total1 = 1;comet[i] != '\0'; i++)
        total1 = ((total1 * (comet[i] - 'A' + 1)) % 47);

    for(i = 0, total2 = 1; group[i] != '\0'; i++)
        total2 = ((total2 * (group[i] - 'A' + 1)) % 47);

    if((total1 % 47) == (total2 % 47))
    fprintf(fout,"GO\n");
    else
    fprintf(fout,"STAY\n");
    return 0;
}
