//2019007901_Wan_11802
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int len1=2,len2=3;
    scanf("%d %d",&len1,&len2);
    int a[len1], b[len2];

    for(int i=0 ; i<len1; i++)
        scanf("%d",&a[i]);
    for(int i=0 ; i<len2; i++)
        scanf("%d",&b[i]);

    int count=0;
    for(int i=0 ; i<len1 ; i++){
        for(int j=0 ; j<len2 ; j++){
            if(a[i]==b[j]) count++;
        }
    }
    printf("%d",count);

    return 0;
}
