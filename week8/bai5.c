#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    long long id;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

Node* makeNode(long long v) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->id = v;
    p->next = NULL;
    return p;
}

void new_id(long long v) {
    Node *new_node = makeNode(v);

    if (head == NULL) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

void get() {
    if (head == NULL) return;

    Node *p = head;
    head = head->next;

    if (head == NULL) tail = NULL;

    free(p);
}

int main() {
    char cmd[21];

    while (1) {
        scanf("%s", cmd);

        if (strcmp(cmd, "#") == 0) break;

        if (strcmp(cmd, "NEW") == 0) {
            long long v;
            scanf("%lld", &v);
            new_id(v);
        }
        else if (strcmp(cmd, "GET") == 0) {
            get();
        }
    }

    Node *p = head;
    while (p != NULL) {
        printf("%lld ", p->id);
        p = p->next;
    }

    return 0;
}