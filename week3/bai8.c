#include <stdio.h>
#include <stdlib.h>

char* subStr(char* s1, int offset, int number){

    int len = 0;
    while(s1[len] != '\0') len++;

    offset--;   // chuyển từ index bắt đầu 1 → 0

    if(offset < 0 || offset >= len || number <= 0)
        return NULL;

    if(offset + number > len)
        number = len - offset;

    char *s2 = (char*)malloc(number + 1);

    for(int i = 0; i < number; i++)
        s2[i] = s1[offset + i];

    s2[number] = '\0';

    return s2;
}

int main(){

    int offset, number;
    scanf("%d %d",&offset,&number);

    char *str = (char*)malloc(81);
    scanf(" %[^\n]",str);

    char *res = subStr(str,offset,number);

    if(res != NULL)

        printf("-%s-",res);

    free(str);
    free(res);

    return 0;
}