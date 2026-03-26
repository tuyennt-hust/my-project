#include <stdio.h>

void chuyen(int n, char a, char b){
    printf("%c => %c\n",a,b);
}
void thap_ha_noi(int n, char a, char b, char c){
    if(n == 1) chuyen(1,a,c);
    else{
        thap_ha_noi(n-1, a, c, b);
        chuyen(n, a, c);
        thap_ha_noi(n-1, b, a, c);
    }
}

int main(){
    int n; scanf("%d",&n);
    char a = 'A', b = 'C', c = 'B';
    thap_ha_noi(n, a, b, c);
    return 0;
}