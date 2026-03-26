#include <stdio.h>
#include <string.h>
void doi(char s[100], char x, char y){
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == x){
            s[i] = y;
        }
    }
    printf("%s",s);
}

int main(){
    char s[100], x, y;
    scanf("%s",s);
    scanf(" %c %c",&x,&y);

    doi(s, x, y);
    return 0;
}