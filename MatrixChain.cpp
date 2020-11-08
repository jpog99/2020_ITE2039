//2019007901_Wan_11802
#include <stdio.h>
#include <stdlib.h>
int n;
int s[100][100];

void print_result(int i, int j){
    if(i==j)
        printf("%d",i);
    else{
        printf("(");
        print_result(i,s[i][j]);
        print_result(s[i][j]+1,j);
        printf(")");
    }
}

int main(void){

    scanf("%d",&n);

    int p[n+1];
    for(int i=0 ; i<n+1 ; i++)
        scanf("%d",&p[i]);

    int m[n+1][n+1];

    for(int i=1 ; i<=n ; i++)
        m[i][i]=0;


    int i,j,k;
    for(int len=2 ; len<=n ; len++){
        for(i=1 ; i<=n-len+1 ; i++){
            j = i+len-1;
            m[i][j]=1000000;
            for(k=i ; k<=j-1 ; k++){
                int q = m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
                if(q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }

    printf("%d\n",m[1][n]);
    print_result(i-1,j);
    
    return 0;

}