#include <stdio.h>
#define N 100000

int main(){
    int n, k;
    scanf("%d %d",&n,&k);
    int a[N];
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }

    int sum = 0, cnt = 0;

    for(int i = 0; i < k; i++){
        sum += a[i];
    }

    if(sum % 2 == 0) cnt++;

    for(int i = 1; i <= n-k; i++){
        sum = sum - a[i-1] + a[i+k-1];
        if(sum % 2 == 0) cnt++;
    }

    printf("%d",cnt);
    return 0;
}