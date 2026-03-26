#include <stdio.h>

int to_hop(int k, int n){
    if(k == 0 || k == n) return 1;
    else return to_hop(k-1, n-1) + to_hop(k, n-1);
}

int main(){
    int k, n; scanf("%d %d",&k,&n);
    printf("%d",to_hop(k, n));
    return 0;
}