/*
ID: nishad.1
PROG: barn1
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXSTALLS 200

int stallcmp(const void *va, const void *vb) {
    return(*(int*)va - *(int*)vb);
}

int occ_stall[MAXSTALLS];
int diff[MAXSTALLS];

int main()
{
    FILE *in  = fopen ("barn1.in", "r");
    FILE *out = fopen ("barn1.out", "w");
    int M, S, C, i=1,j, k, blocked=0,temp1,temp2;  //M = num of boards, S = Stalls, C = Occupied stall num
    fscanf(in,"%d %d %d",&M,&S,&C);
    occ_stall[0] = 0;
    //printf("%d %d %d",M,S,C);
    while(C--) {
    fscanf(in,"%d",&occ_stall[i]);
    i++;
    }
    occ_stall[i] = S+1;
    qsort(occ_stall,(i+1),sizeof(int),stallcmp);
    /*for(j=0; j<=i; j++)
    printf("%d\n",occ_stall[j]);*/
    for(j=0,k=1; k < i; j++,k++) {
        diff[j] = (occ_stall[(k+1)] - occ_stall[k] - 1);
        //printf("%d - %d = diff = %d\n",occ_stall[(j+1)],occ_stall[j],diff[j]);
    }
    --j;
    temp1 = occ_stall[1] - 1;
    temp2 = diff[j];
    qsort(diff,j,sizeof(int),stallcmp);
    M--;
    while(M--) {
    blocked += diff[--j];
    //printf("%d %d\n",diff[k],blocked);
    }
    blocked += (temp1 + temp2);
    printf("%d %d\n",temp1,temp2);
    blocked = (S - blocked);
    fprintf(out,"%d\n",blocked);
    return 0;
}


