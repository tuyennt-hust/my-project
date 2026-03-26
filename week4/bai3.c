#include <stdio.h>
//cach 1
int ucln(int a, int b){
    if(b == 0) return a;
    return ucln(b, a % b);
}
//cach 2
int UCLN(int a, int b){
    if(a == b) return a;
    else if(a > b) return UCLN(a-b,b);
    else return UCLN(a, b-a);
}
int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n%d", ucln(a, b), UCLN(a,b));
    return 0;
}