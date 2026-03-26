#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char *str1, *str2, *str;

    str1 = (char*)malloc(40);
    str2 = (char*)malloc(40);

    fgets(str1,40,stdin);
    fgets(str2,40,stdin);

    str1[strcspn(str1,"\n")] = '\0';
    str2[strcspn(str2,"\n")] = '\0';

    str = (char*)malloc(40);

    strcpy(str,str1);

    str = (char*)realloc(str,80);

    strcat(str,str2);

    printf("%lu %s",strlen(str),str);

    free(str1);
    free(str2);
    free(str);

    return 0;
}