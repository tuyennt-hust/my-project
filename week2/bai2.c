#include <stdio.h>
#include <ctype.h>
#define N 100000

int main(){
    char s[N];
    int i = 0;
    char c;
    while(c = getchar() != EOF && i < 99999){
        s[i++] = c;
    }
    s[i] = '\0';

    for(int j = 0;  s[j] != '\0'; j++){
        s[j] = toupper(s[j]);
    }
    printf("%s",s);
}