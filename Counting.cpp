//2019007901_Wan_11802
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input_num,range,query_num,i,j;
    scanf("%d %d %d",&input_num,&range,&query_num);
    int keys[input_num], A[query_num], B[query_num];

    for(i=0 ; i<query_num ; i++)
        scanf("%d %d",&A[i],&B[i]);
    for(i=0 ; i<input_num ; i++){
        scanf("%d",&keys[i]);
        if(keys[i]>range) exit(0);
    }

    int count;

    for(i=0 ; i<query_num ; i++){
        count=0;
        for(j=0 ; j<input_num ; j++){
            if(keys[j]>=A[i] && keys[j]<=B[i]) count++;
        }
        printf("%d\n",count);
    }

    return 0;
}