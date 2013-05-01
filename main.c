/*
ID: nishad.1
PROG: gift1
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct database
{
    char name[20];
    int cash, cash_present, na; //na = num of acquaintances
    char mate[10][15];
};

int main()
{
    FILE *in  = fopen ("gift1.in", "r");
    FILE *out = fopen ("gift1.out", "w");
    struct database person[10];
    int i,np,j,t,cash_to_each;
    char temp[20],trash[100];
    fscanf(in,"%d",&np);
    for(i = 0; i < np; i++)
    fscanf(in,"%s",&person[i].name);
    for(i = 0; i < np; i++) //input data
    {
        fscanf(in,"%s",&temp);
        j = 0;
        while(strcmp(temp,person[j].name) != 0)
        j++;
        fscanf(in,"%d",&person[j].cash);
        person[j].cash_present = person[j].cash;
        fscanf(in,"%d",&person[j].na);
        for(t = 0; t < person[j].na; t++)
        fscanf(in,"%s",person[j].mate[t]);
    }
    for(i = 0; i < np; i++)
    {
        if(person[i].na == 0)
        cash_to_each = 0;
        else
        cash_to_each = (person[i].cash / person[i].na);
        person[i].cash_present -= (person[i].na * cash_to_each);
        for(t = 0; t < person[i].na; t++) //search name of person to give cash.
        {
            j = 0;
            while(strcmp(person[i].mate[t],person[j].name) != 0)
            j++;
            person[j].cash_present += cash_to_each;
        }
    }
    for(i = 0; i < np; i++)
    {
        fprintf(out,"%s %d\n",person[i].name,(person[i].cash_present - person[i].cash));
    }
    return 0;
}
