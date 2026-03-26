#include <stdio.h>

int de_quy(int n){
    if(n == 0 || n == 1) return 1;
    return de_quy(n-1) + de_quy(n-2);
}

int main(){
    int n; 
    scanf("%d",&n);
    printf("%d", de_quy(n));
    return 0;
}