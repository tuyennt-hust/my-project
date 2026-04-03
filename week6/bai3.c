#include <stdio.h>

int n;
int d[100][100];
int x[100];
int mark[100];
int f;        // chi phí hiện tại
int cnt;      // số tour hợp lệ (đổi từ f_min -> cnt)
int Cm;
int M;        // giới hạn

void Try(int k){
    for(int v = 1; v <= n; v++){
        if(mark[v] == 0){
            x[k] = v;
            f = f + d[x[k-1]][v];
            mark[v] = 1;

            if(k == n){
                int total = f + d[x[n]][x[1]];
                if(total <= M) cnt++;   // ✅ đếm
            } else {
                if(f + Cm*(n-k+1) <= M) // ✅ cắt nhánh theo M
                    Try(k+1);
            }

            // ✅ backtrack (bạn bị thiếu)
            mark[v] = 0;
            f = f - d[x[k-1]][v];
        }
    }
}

void input(){
    scanf("%d %d", &n, &M);

    Cm = 10000000;

    for(int i = 1; i <= n; i++){
        for(int j =1; j <= n; j++){
            scanf("%d", &d[i][j]);
            if(i != j && d[i][j] < Cm) 
                Cm = d[i][j];
        }
    }
}

int main(){
    input();

    for(int v = 1; v <= n; v++) mark[v] = 0;

    x[1] = 1; 
    mark[1] = 1;

    f = 0; 
    cnt = 0;

    Try(2);

    printf("%d", cnt);
    return 0;
}