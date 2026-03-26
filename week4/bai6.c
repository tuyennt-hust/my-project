#include <stdio.h>
#define N 1000

int M[N][N], n, k, cnt = 0;

void init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            M[i][j] = -1;
        }
    }
}

int C(int k, int n){
    cnt++;

    if(k > n) return 0;
    if(k == 0 || k == n) return 1;

    if(M[k][n] != -1) return M[k][n];

    M[k][n] = C(k-1, n-1) + C(k, n-1);
    return M[k][n];
}

int main(){
    scanf("%d %d",&k,&n);
    init();

    int result = C(k, n);
    printf("%d %d", result, cnt);
}