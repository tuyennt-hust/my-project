#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double x;
    double y;
} point;

typedef struct{
    double x;
    double y;
    double r;
} circle;

int inside(point p, circle c){

    double dx = p.x - c.x;
    double dy = p.y - c.y;

    double d2 = dx*dx + dy*dy;

    if(d2 <= c.r * c.r)
        return 1;

    return 0;
}

int main(){

    int n;
    scanf("%d",&n);

    point *p = (point*)malloc(n*sizeof(point));

    for(int i=0;i<n;i++){
        scanf("%lf %lf",&p[i].x,&p[i].y);
    }

    int m;
    scanf("%d",&m);

    circle *c = (circle*)malloc(m*sizeof(circle));

    for(int i=0;i<m;i++){
        scanf("%lf %lf %lf",&c[i].x,&c[i].y,&c[i].r);
    }

    int cnt = 0;

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(inside(p[i],c[j])){
                cnt++;
                break;
            }
        }
    }

    printf("%d",cnt);

    free(p);
    free(c);

    return 0;
}