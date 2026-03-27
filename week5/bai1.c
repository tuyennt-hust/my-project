#include <stdio.h>
#define N 21
int x[N];
int n;
void printSolution(){
    for(int k = 1; k <= n; k++){
        printf("%d",x[k]);
    }
    printf("\n");
}

void Try(int k){
    for(int v = 0; v <= 1; v++){
        x[k] = v;
        if(k == n) printSolution();
        else Try(k+1);
    }
}

int main(){
   scanf("%d",&n);
   Try(1);
   return 0;
}