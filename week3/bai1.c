#include <stdio.h>
#include <stdlib.h>

int *even_elements(int a[], int n, int *m){
    int cnt = 0;

    //dem so chan
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            cnt++;
        }
    }

    *m = cnt;

    int *b = (int*)malloc(cnt*sizeof(int));
    int j = 0;
    
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            b[j++] = a[i];
        }
    }
    return b;
}

int main(){
    int n;
    scanf("%d",&n);

    int* a = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }

    int m;
    int* b = even_elements(a,n,&m);

    // in ngược
    for(int i = m-1; i >= 0; i--){
        printf("%d ",b[i]);
    }

    free(a);
    free(b);

    return 0;
}