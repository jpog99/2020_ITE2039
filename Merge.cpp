//2019007901_Wan_11802
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int p, int q, int r){
    int temp[r];

    for(int i=p ;i<=r ; i++)
        temp[i] = arr[i];

    int x = p;
    int y = q+1;
    int z = p;

    while(x<=q && y<=r){
        if(temp[x] >= temp[y]){
            arr[z] = temp[x];
            x++;
        }else{
            arr[z] = temp[y];
            y++;
        }
        z++;
    }

    while(x<=q){
        arr[z] = temp[x];
        x++;
        z++;
    }
}

void mergeSort(int arr[], int p, int r)
{
    if (p<r) {
        int q=(p+r)/2;

        mergeSort(arr,p,q);
        mergeSort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}

int main()
{
    int length;
    scanf("%d",&length);
    int a[length];
    for(int i=0 ; i<length ; i++)
        scanf("%d",&a[i]);

    mergeSort(a,0,length-1);

    for(int i=0 ; i<length ; i++)
        printf("%d\n",a[i]);

    return 0;
}