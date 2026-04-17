#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node * next;
}Node;

Node * head = NULL;

Node * makeNode(int v){
    Node * p = (Node*)malloc(sizeof(Node));
    p -> value = v;
    p -> next = NULL;
    return p;
}

void push(int v){
    Node * new_node = makeNode(v);
    new_node -> next = head;
    head = new_node;
}

int pop(){
    if(head == NULL) return -1;
    Node * p = head;
    int x = p -> value;
    head = head -> next;
    free(p);
    return x;
}

int main(){
    char cmd[50];
    while(1){
        scanf("%s", cmd);
        if(strcmp(cmd, "PUSH") == 0){
            int x; scanf("%d",&x);
            push(x);
        }
        else if(strcmp(cmd, "POP") == 0 ){
            int x = pop();
            if(x == -1) printf("NULL\n");
            else printf("%d\n",x);
        }
        else if(strcmp(cmd, "#") == 0){
            break;
        }
    }
    return 0;
}
