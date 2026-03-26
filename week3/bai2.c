#include <stdio.h>
#include <math.h>

typedef struct point{
    double x;
    double y;
} point_t;

typedef struct circle{
    point_t center;
    double radius;
} circle_t;

int is_in_circle(point_t *p, circle_t *c){

    double kc = pow(p->x - c->center.x, 2) + 
                pow(p->y - c->center.y, 2);

    if(sqrt(kc) < c->radius)
        return 1;
    else
        return 0;
}

int main(){

    point_t p;
    circle_t c;

    // nhập tâm hình tròn
    scanf("%lf %lf",&c.center.x,&c.center.y);

    // nhập bán kính
    scanf("%lf",&c.radius);

     // nhập điểm
    scanf("%lf %lf",&p.x,&p.y);

    if(is_in_circle(&p,&c))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}