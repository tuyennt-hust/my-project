#include <stdio.h>
#define N 1000

int A[N];

void merge(int first, int mid, int last){
    int i = first, j = mid + 1, k = first;
    int t[N];

    while(i <= mid && j <= last){
        if(A[i] < A[j]) 
            t[k++] = A[i++];
        else 
            t[k++] = A[j++];
    }

    while(i <= mid) 
        t[k++] = A[i++];

    while(j <= last) 
        t[k++] = A[j++];

    for(k = first; k <= last; k++){
        A[k] = t[k];
    }
}

void merge_sort(int first, int last){
    if(first >= last) return;

    int mid = (first + last) / 2;

    merge_sort(first, mid);
    merge_sort(mid + 1, last);

    merge(first, mid, last);
}

int main(){
    int n, i;

    printf("Nhap n: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    merge_sort(0, n - 1);

    printf("Mang sau khi sap xep:\n");
    for(i = 0; i < n; i++){
        printf("%d ", A[i]);
    }

    return 0;
}