#include <stdio.h>
#include <math.h>

typedef struct{
    double x;
    double y;
    double r;
} circle;

int intersect(circle a, circle b){

    double dx = a.x - b.x;
    double dy = a.y - b.y;

    double d2 = dx*dx + dy*dy;

    double sum = (a.r + b.r) * (a.r + b.r);
    double diff = (a.r - b.r) * (a.r - b.r);

    if(d2 <= sum && d2 >= diff)
        return 1;

    return 0;
}

int main(){

    int n;
    scanf("%d",&n);

    circle c[n];

    for(int i = 0; i < n; i++){
        scanf("%lf %lf %lf",&c[i].x,&c[i].y,&c[i].r);
    }

    int max = 0;

    for(int i = 0; i < n; i++){

        int cnt = 0;

        for(int j = 0; j < n; j++){
            if(i != j && intersect(c[i],c[j])){
                cnt++;
            }
        }

        if(cnt > max)
            max = cnt;
    }

    printf("%d",max);

    return 0;
}