#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    char c;
    struct Node * next;
}Node;

Node * top;
char s[1000001];
Node * makeNode(char c){
    Node * p = (Node *)malloc(sizeof(Node));
    p -> c = c;
    p -> next = NULL;
    return p;
}

void push(char c){
    Node * p = makeNode(c);
    p -> next = top;
    top = p;
}

char pop(){
    if(top == NULL ) return ' ';
    Node *tmp = top;
    top = top -> next;
    char res = tmp -> c;
    free(tmp);
    return res;
}

int match(char a, char b){
    if(a == '(' && b == ')') return 1;
    if(a == '[' && b == ']') return 1;
    if(a == '{' && b == '}') return 1;
    return 0;
}

int check (char *s){
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') push(s[i]);
        else{
            if (top == NULL) return 0;
            char o = pop();
            if(!match(o, s[i])) return 0;
        }
    }
    return top == NULL;
}

int main(){
    scanf("%s",s);
    int res = check(s);
    printf("%d\n",res);
    return 0;
}