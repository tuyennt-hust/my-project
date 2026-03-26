#include <stdio.h>
#include <math.h>
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);

    int delta = b*b - 4*a*c;
    float x1,x2;
    if(delta < 0) printf("NO SOLUTION\n");
    else if(delta == 0){
        x1 = -b/(2*a);
        printf("%.2f",x1);
    }
    else{
        x1 = (-b - sqrt(delta))/(2*a);
        x2 = (-b + sqrt(delta))/(2*a);
        printf("%.2f %.2f",x1,x2);
    }
    return 0;
}