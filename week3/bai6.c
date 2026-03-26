#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, n, *p;

    scanf("%d", &n);

    p = (int *)malloc(n * sizeof(int));

    if (p == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    /* Nhập các số nguyên */
    for(i = 0; i < n; i++){
        scanf("%d", &p[i]);
    }

    /* Hiển thị chúng theo chiều ngược lại */
    for(i = n-1; i >= 0; i--){
        printf("%d", p[i]);
        if(i > 0) printf(" ");
    }

    free(p); /* Giải phóng bộ nhớ */

    return 0;
}