/*
ID: nishad.1
PROG: namenum
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialize_struct(void);
int check(void);

char number[13], temp[13];
int digits;

typedef struct mp{
int num;
int alphabet;
} mp;
mp map[9];

int main()
{
    FILE *in  = fopen ("namenum.in", "r");
    FILE *out = fopen ("namenum.out", "w");
    FILE *dict = fopen("dict.txt","r");
    int flag = 1, flag2=0;
    char BUFFER[20];
    initialize_struct();
    fscanf(in,"%s",number);
    //printf("%s\n",number);
    digits = strlen(number);
    //printf("%d\n",digits);

        while((fscanf(dict,"%s",BUFFER))==1)
        {

        strcpy(temp,BUFFER);
        printf("%s\n",temp);
        if(strlen(temp) == digits)
        {
            //printf("aaaa");
            if(check())
            {
            fprintf(out,"%s\n",temp);
            flag2 = 1;
            }
        }

       }
    if(flag2 == 0)
    fprintf(out,"NONE\n");
    return 0;
}

void initialize_struct(void)
{
    int i, j = 2, k = 'A';
    for(i = 0; i < 8; i++)
    {
        map[i].num = j++;
        map[i].alphabet = k;
        //printf("%c ",map[i].alphabet);
        if(k == 'P')
        k+=4;
        else
        k+=3;
    }
    map[8].num = 8;
    map[8].alphabet = 'Z';
    return;
}

int check(void)
{
    int i, flag = 1, temp_dig,j, k;
    for(i = 0; (i < digits) && (flag == 1); i++)
    {
        //search i'th digit of number[] in map[].num
        temp_dig = ((int)number[i] - '0');
        //printf("%d %d\n",(i+1),temp_dig);
        for(j = 0; j < 8; j++) //searching
        {
            if(map[j].num == temp_dig)
            break;
        }
        //printf("%d %d %c\n",j,map[j].num,map[j].alphabet);
        k = j + 1;
        if(((int)temp[i] >= map[j].alphabet) && ((int)temp[i] < map[k].alphabet))
        ;//printf("AFFIRMATIVE\n");
        else
        flag = 0;
    }
    if(flag == 1)
    return 1;
    else
    return 0;
}
