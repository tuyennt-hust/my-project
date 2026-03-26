#include <stdio.h>

int main(){
    int n; scanf("%d",&n);
    int x[n][4];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            scanf("%d",&x[i][j]);
        }
    }
    int x_min = x[0][0], x_max = x[0][0], y_min = x[0][1], y_max = x[0][1];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            if((x[i][j] < x_min) && (j % 2 == 0)) x_min = x[i][j];
            if((x[i][j] > x_max) && (j % 2 == 0)) x_max = x[i][j];
            if((x[i][j] < y_min) && (j % 2 != 0)) y_min = x[i][j];
            if((x[i][j] > y_max) && (j % 2 != 0)) y_max = x[i][j];
        }
    }
    int S = (x_max - x_min)*(y_max - y_min);
    printf("%d",S);
    return 0;
}