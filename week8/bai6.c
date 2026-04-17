#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
} Node;

Node* makeNode(int v){
    Node *p = (Node*)malloc(sizeof(Node));
    p->value = v;
    p->next = NULL;
    return p;
}

// push vào đầu (stack)
void push(Node **head, int v){
    Node *new_node = makeNode(v);
    new_node->next = *head;
    *head = new_node;
}

// pop khỏi đầu
int pop(Node **head){
    if(*head == NULL) return -1;

    Node *p = *head;
    int x = p->value;

    *head = (*head)->next;
    free(p);

    return x;
}

int main(){
    char cmd[20];
    Node *headA = NULL;
    Node *headB = NULL;

    while(1){
        scanf("%s", cmd);

        if(strcmp(cmd, "PUSH") == 0){
            char x; int v;
            scanf(" %c %d", &x, &v);

            if(x == 'A') push(&headA, v);
            else if(x == 'B') push(&headB, v);
        }
        else if(strcmp(cmd, "POP") == 0){
            char x;
            scanf(" %c", &x);

            if(x == 'A'){ 
                int v = pop(&headA);
                if(v == -1) printf("NULL\n");
                else printf("%d\n", v);
            }
            else if(x == 'B'){ 
                int v = pop(&headB);
                if(v == -1) printf("NULL\n");
                else printf("%d\n", v);
            }
        }
        else if(strcmp(cmd, "#") == 0) break;
    }

    return 0;
}