/*
ID: nishad.1
PROG: transform
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10 //maximum size of square

void copy(void);
void rotate(void);
int check(void);
void mirror(void);
//void print(void);

char sq_in[MAXSIZE][MAXSIZE],sq_out[MAXSIZE][MAXSIZE],sq_temp[MAXSIZE][MAXSIZE],sq_temp1[MAXSIZE][MAXSIZE]; //this 2D array will hold structure of square.
int N; // size of matrix

int main()
{
    FILE *in  = fopen ("transform.in", "r");
    FILE *out = fopen ("transform.out", "w");
    int i, j;
    fscanf(in,"%d",&N);
    /*Reading of input and output squares*/
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        fscanf(in," %c",&sq_in[i][j]);
    }
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        fscanf(in," %c",&sq_out[i][j]);
    } //end of input
    copy(); //copies input matrix to temp
    //print();

    /* Keep on rotating untill we get the answer, or till we reach max(3 times) */
    i=0;
    do
    {
        rotate();
        i++;
    }
    while((i < 3) && (check()==0));
    if(check() == 1) //matching pattern found
          fprintf(out,"%d\n",i);

    else //further check
    {
      mirror(); //create mirror image matrix in temp
      //print();
      if(check())
      fprintf(out,"%d\n",4);
      else
      {
        for(i = 1; (i <= 3) && (check() == 0); i++) //rotate mirror matrix
        rotate();
        if(check())
        fprintf(out,"%d\n",5);
        else
        {
            copy();
            if(check())
              fprintf(out,"%d\n",6);
            else
            fprintf(out,"%d\n",7);
        }
      }
    }

    return 0;
}

void copy(void)
{
    int i, j;
    for(i=0; i<N; i++)
    for(j=0;j<N;j++)
    sq_temp[i][j] = sq_in[i][j];
    return;
}

void rotate(void) //this function rotates the matrix clockwise by 90 degrees.
{
    int i, j;
    for(i=0; i<N; i++)
    for(j=0;j<N;j++)
    sq_temp1[i][j] = sq_temp[i][j];
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        sq_temp[i][j] = sq_temp1[(N-j-1)][i];
    }
    return;
}

int check(void) //compares temp and output matrix
{
    int i, j,flag = 1;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(sq_out[i][j] != sq_temp[i][j])
            {
                flag = 0;
                break;
            }
        }
    }
    if(flag == 1)
    return 1;
    else
    return 0;
}

void mirror(void)
{
    int i, j, k;
        for(i=0,j=(N-1); i<N; i++,j--)
        {
            for(k=0; k<N; k++)
            sq_temp[k][i] = sq_in[k][j];
        }
    return;
}

/*void print(void)
{
    int i, j;
    for(i = 0; i < N; i++)
    {
    for(j = 0; j < N; j++)
    printf("%c ",sq_temp[i][j]);
    printf("\n");
    }
    return;
}*/
