#include <stdio.h>
#define N 100

void nhap(int A[][N], int x, int y){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            scanf("%d",&A[i][j]);
        }
    }
}

int main(){
    int n, k, m, k1;

    int A[N][N], B[N][N];

    scanf("%d %d",&n,&k);
    nhap(A, n, k);

    scanf("%d %d",&k1,&m);
    nhap(B, k1, m);

    int C[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            C[i][j] = 0;
            for(int e = 0; e < k; e++){
                C[i][j] += A[i][e] * B[e][j];
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}