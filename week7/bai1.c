#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node *head = NULL;

// tạo node
Node* newNode(int x) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->val = x;
    p->next = NULL;
    return p;
}

// tìm
int exists(int x) {
    Node *p = head;
    while (p) {
        if (p->val == x) return 1;
        p = p->next;
    }
    return 0;
}

// thêm đầu
void addFirst(int x) {
    Node *p = newNode(x);
    p->next = head;
    head = p;
}

// thêm cuối
void addLast(int x) {
    Node *p = newNode(x);
    if (head == NULL) {
        head = p;
        return;
    }

    Node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = p;
}

// thêm sau v
void addAfter(int u, int v) {
    Node *cur = head;
    while (cur) {
        if (cur->val == v) {
            Node *p = newNode(u);
            p->next = cur->next;
            cur->next = p;
            return;
        }
        cur = cur->next;
    }
}

// thêm trước v
void addBefore(int u, int v) {
    if (head == NULL) return;

    if (head->val == v) {
        addFirst(u);
        return;
    }

    Node *cur = head;
    while (cur->next) {
        if (cur->next->val == v) {
            Node *p = newNode(u);
            p->next = cur->next;
            cur->next = p;
            return;
        }
        cur = cur->next;
    }
}

// xóa
void removeVal(int x) {
    if (head == NULL) return;

    if (head->val == x) {
        Node *tmp = head;
        head = head->next;
        free(tmp);
        return;
    }

    Node *cur = head;
    while (cur->next) {
        if (cur->next->val == x) {
            Node *tmp = cur->next;
            cur->next = tmp->next;
            free(tmp);
            return;
        }
        cur = cur->next;
    }
}

// đảo
void reverse() {
    Node *prev = NULL, *cur = head, *next;

    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

// in
void printList() {
    Node *p = head;
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        addLast(x);
    }

    char cmd[20];

    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0) break;

        if (strcmp(cmd, "addlast") == 0) {
            scanf("%d", &x);
            if (!exists(x)) addLast(x);
        }

        else if (strcmp(cmd, "addfirst") == 0) {
            scanf("%d", &x);
            if (!exists(x)) addFirst(x);
        }

        else if (strcmp(cmd, "addafter") == 0) {
            int u, v;
            scanf("%d %d", &u, &v);
            if (!exists(u)) addAfter(u, v);
        }

        else if (strcmp(cmd, "addbefore") == 0) {
            int u, v;
            scanf("%d %d", &u, &v);
            if (!exists(u)) addBefore(u, v);
        }

        else if (strcmp(cmd, "remove") == 0) {
            scanf("%d", &x);
            removeVal(x);
        }

        else if (strcmp(cmd, "reverse") == 0) {
            reverse();
        }
    }

    printList();
    return 0;
}