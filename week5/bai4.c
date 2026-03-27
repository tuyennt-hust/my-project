#include <stdio.h>
#define N 100

int n;
int x[N];
int used[N];

void solution(){
    for(int i = 1; i <= n; i++){
        printf("%d", x[i]);
    }
    printf("\n");
}

void Try(int i){
    for(int v = 1; v <= n; v++){
        if(!used[v]){
            x[i] = v;
            used[v] = 1;

            if(i == n) solution();
            else Try(i + 1);

            used[v] = 0; // backtrack
        }
    }
}

int main(){
    scanf("%d", &n);
    Try(1);
    return 0;
}