#include <stdio.h>
#include <math.h>
int so_hoan_hao(int x){
    if(x < 1) return 0;
    else{
        int a = sqrt(x);
        if(a*a == x ) return 1;
        else return 0;
    }
}
int main(){
    int n; scanf("%d",&n);
    int cnt = 0, x;
    for(int i = 0; i < n; i++){
        scanf("%d",&x);
        if(so_hoan_hao(x)) cnt++; 
    }
    printf("%d",cnt);
}