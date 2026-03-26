#include <stdio.h>
#define N 1000000
int A[N];

int main(){
    int n; scanf("%d",&n);
    long long cnt = 0;
    for(int i = 0; i < n; i++){
        scanf("%d",&A[i]);
        cnt += A[i];
    }
    printf("%lld",cnt);
    return 0;
}