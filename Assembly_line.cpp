//2019007901_Wan_11802
#include <stdio.h>
#include <stdlib.h>

int n,e1,e2,x1,x2,s_star,l_star;



int main(void){
    int i,j;
    scanf("%d",&n);

    scanf("%d%d",&e1,&e2);

    scanf("%d%d",&x1,&x2);

    int a[2][n];
    for(i=0 ; i<2 ; i++){
        for(j=0 ; j<n ; j++)
            scanf("%d",&a[i][j]);
    }

    int t[2][n-1];
    for(i=0 ; i<2 ; i++){
        for(j=0 ; j<n-1; j++)
            scanf("%d",&t[i][j]);
    }

    int s[2][n];
    int l[2][n];


    s[0][0] = e1 + a[0][0];
    s[1][0] = e2 + a[1][0];

    for(int j=1 ; j<n ; j++){
        //s[0][j] = a[0][j];
        if(s[0][j-1]<=s[1][j-1]+t[1][j-1]){
            s[0][j] = s[0][j-1] + a[0][j];
            l[0][j] = 1;
        }else{
            s[0][j] = s[1][j-1] + t[1][j-1] + a[0][j];
            l[0][j] = 2;
        }

        if(s[1][j-1]<=s[0][j-1]+t[0][j-1]){
            s[1][j] = s[1][j-1] + a[1][j];
            l[1][j] = 2;
        }else{
            s[1][j] = s[0][j-1] + t[0][j-1] + a[1][j];
            l[1][j] = 1;
        }
    }


    if(s[0][n-1]+ x1 <= s[1][n-1] + x2){
        s_star = s[0][n-1]+x1;
        l_star = 1;
    }else{
        s_star = s[1][n-1] + x2;
        l_star = 2;
    }

    printf("%d\n",s_star);

    int path[n];
    int k = l_star;
    path[n-1] = k;
    for(int j=n-1 ; j>0 ; j--){
        k = l[k-1][j];
        path[j-1] = k;
    }

    for(int i=0 ; i<n ; i++)
        printf("%d %d\n",path[i],i+1);

    return 0;
}