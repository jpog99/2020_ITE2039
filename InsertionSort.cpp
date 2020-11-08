//2019007901_Wan_11802
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int length;
    scanf("%d",&length);
    int a[length];
    for(int i=0 ; i<length ; i++)
        scanf( "%d",&a[i]);
    

    for(int i=1 ; i<length ; i++){
        int key = a[i];
        int j=i-1;
        while (j>=0 && a[j]<key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }

    
    for(int i=0 ; i<length ; i++)
        printf("%d\n",a[i]);

    return 0;
}