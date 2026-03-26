#include <stdio.h>
#include <stdlib.h>

typedef struct point{
    double x;
    double y;
} point_t;

typedef struct circle{
    point_t center;
    double radius;
} circle_t;

int two_circle(circle_t *c1, circle_t *c2){

    double dx = c1->center.x - c2->center.x;
    double dy = c1->center.y - c2->center.y;

    double d2 = dx*dx + dy*dy;
    double sum = (c1->radius + c2->radius)*(c1->radius + c2->radius);

    if(d2 <= sum)
        return 1;

    return 0;
}

int main(){

    int n;
    scanf("%d",&n);

    circle_t *c = (circle_t*)malloc(n*sizeof(circle_t));

    for(int i=0;i<n;i++){
        scanf("%lf %lf %lf",&c[i].center.x,&c[i].center.y,&c[i].radius);
    }

    int max = 0;

    for(int i=0;i<n;i++){

        int cnt = 0;

        for(int j=0;j<n;j++){

            if(i!=j && two_circle(&c[i],&c[j]))
                cnt++;
        }

        if(cnt > max)
            max = cnt;
    }

    printf("%d",max);

    free(c);

    return 0;
}