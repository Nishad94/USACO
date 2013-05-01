/*
ID: nishad.1
PROG: milk
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 200000

void sort_farmers(int left, int right);


typedef struct {
int ppg;
int max_amt;
} dairy;
dairy farmers[MAX];

int main()
{
    FILE *in  = fopen ("milk.in", "r");
    FILE *out = fopen ("milk.out", "w");
    int total_milk_needed, farmers_total, i=0, total_cost=0;
    fscanf(in,"%d %d",&total_milk_needed, &farmers_total);
    while(farmers_total--)
    {
        fscanf(in,"%d %d",&farmers[i].ppg,&farmers[i].max_amt);
        //printf("%d %d\n",farmers[i].ppg,farmers[i].max_amt);
        i++;
    }
    sort_farmers(0,--i);
    i=0;
    while(total_milk_needed) {
            if(farmers[i].max_amt > total_milk_needed)  {
                total_cost += (total_milk_needed * farmers[i].ppg);
                total_milk_needed = 0;
            }
            else {
               total_cost += (farmers[i].max_amt * farmers[i].ppg);
               total_milk_needed -= farmers[i].max_amt;
            }

            i++;
    }
    fprintf(out,"%d\n",total_cost);
    return 0;
}

void sort_farmers(int left, int right) {
    void swap(int a, int b);
    int mid, last,i;
    mid = (left + right) / 2;
    if(left >= right)
    return;

          last=left;
          swap(last,mid);
          last++;
          for(i = last; i <= right; i++) {
              if(farmers[i].ppg <= farmers[left].ppg) {
                  swap(i,last);
                  last++;
                  }
          }
          --last;
          swap(left,last);
          sort_farmers(left,last-1);
          sort_farmers(last+1,right);

    return;
}

void swap(int a, int b) {
    dairy temp;
    temp = farmers[a];
    farmers[a] = farmers[b];
    farmers[b] = temp;
}
