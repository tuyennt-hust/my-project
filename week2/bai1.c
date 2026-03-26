#include <stdio.h>

int main(){
    int n; scanf("%d",&n);
    int A[n][n];
    int cnt = n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&A[i][j]);
        }
    }
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            if(A[i][j] == 0){
                cnt--;
                break;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}