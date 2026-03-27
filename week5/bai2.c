#include <stdio.h>
#define N 21
int x[N];
int n;

int check(int v, int k){
    if(k == 1) return 1;
    return x[k-1] + v <= 1;
}

void solution(){
    for(int i = 1; i <= n; i++){
        printf("%d",x[i]);
    }
    printf("\n");
}

void Try(int k){
    for(int v = 0; v <= 1; v++){
        if(check(v,k)){
            x[k] = v;
            if(k == n) solution();
            else Try(k+1);
        }
    }
}

int main(){
    scanf("%d",&n);
    Try(1);
    return 0;
}