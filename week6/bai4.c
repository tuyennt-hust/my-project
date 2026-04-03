#include <stdio.h>

int main(){
    int n, b;
    scanf("%d %d", &n, &b);

    int a[55];
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }

    int dp[105] = {0};
    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        for(int s = b; s >= a[i]; s--){
            dp[s] += dp[s - a[i]];
        }
    }

    printf("%d\n", dp[b]);
    return 0;
}