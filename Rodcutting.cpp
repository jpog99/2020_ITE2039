//2019007901_Wan_11802
#include <stdio.h>
#include <stdlib.h>
int p[100];
int r[100];
int s[100];

void ext_bottom_up_cut(int* p, int n){
    for(int i=0 ; i<=n ; i++)
        r[i] = s[i] = 0;

    for(int j=1 ; j<=n ; j++){
        int q = -1000000;
        for(int i=1 ; i<=j ; i++){
            if(q < p[i] + r[j-i]){
                q = p[i] + r[j-i];
                s[j] = i;
            }
        }
        r[j] = q;
    }

    printf("%d\n",r[n]);
}

void print_cut_rod(int* p, int n){
    ext_bottom_up_cut(p,n);
    while(n>0){
        printf("%d ",s[n]);
        n = n-s[n];
    }
}

int main(void){
    int n;
    scanf("%d",&n);

    for(int i=1 ; i<=n ; i++)
        scanf("%d",&p[i]);

    print_cut_rod(p,n);

    return 0;
}