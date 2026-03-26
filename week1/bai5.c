#include<stdio.h>

int main(){
    float x; scanf("%f",&x);
    if(x >= 0){
        int I = (int)x;
        float D = x - I;
        printf("%d %.2f",I,D);
    }
    else{
        int I = (int)x - 1;
        float D = x - I;
        printf("%d %.2f",I,D);
    }

    return 0;
}