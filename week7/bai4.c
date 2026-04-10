#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

// tạo node
Node* makeNode(int x) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->key = x;
    p->prev = p->next = NULL;
    return p;
}

// tìm node theo key
Node* find(int x) {
    Node* cur = head;
    while (cur) {
        if (cur->key == x) return cur;
        cur = cur->next;
    }
    return NULL;
}

// thêm đầu
void addFirst(int x) {
    if (find(x)) return;

    Node* p = makeNode(x);
    if (head == NULL) {
        head = tail = p;
        return;
    }

    p->next = head;
    head->prev = p;
    head = p;
}

// thêm cuối
void addLast(int x) {
    if (find(x)) return;

    Node* p = makeNode(x);
    if (tail == NULL) {
        head = tail = p;
        return;
    }

    tail->next = p;
    p->prev = tail;
    tail = p;
}

// thêm sau v
void addAfter(int u, int v) {
    if (find(u)) return;

    Node* nodeV = find(v);
    if (nodeV == NULL) return;

    Node* p = makeNode(u);

    p->next = nodeV->next;
    p->prev = nodeV;

    if (nodeV->next)
        nodeV->next->prev = p;
    else
        tail = p;

    nodeV->next = p;
}

// thêm trước v
void addBefore(int u, int v) {
    if (find(u)) return;

    Node* nodeV = find(v);
    if (nodeV == NULL) return;

    Node* p = makeNode(u);

    p->prev = nodeV->prev;
    p->next = nodeV;

    if (nodeV->prev)
        nodeV->prev->next = p;
    else
        head = p;

    nodeV->prev = p;
}

// xóa key
void removeKey(int x) {
    Node* cur = find(x);
    if (cur == NULL) return;

    if (cur->prev)
        cur->prev->next = cur->next;
    else
        head = cur->next;

    if (cur->next)
        cur->next->prev = cur->prev;
    else
        tail = cur->prev;

    free(cur);
}

// đảo list (không tạo node mới)
void reverseList() {
    Node* cur = head;
    Node* tmp = NULL;

    while (cur) {
        tmp = cur->prev;
        cur->prev = cur->next;
        cur->next = tmp;
        cur = cur->prev;
    }

    tmp = head;
    head = tail;
    tail = tmp;
}

// in trái → phải
void printForward() {
    Node* cur = head;
    while (cur) {
        printf("%d ", cur->key);
        cur = cur->next;
    }
    printf("\n");
}

// in phải → trái
void printBackward() {
    Node* cur = tail;
    while (cur) {
        printf("%d ", cur->key);
        cur = cur->prev;
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
            int k; scanf("%d", &k);
            addLast(k);
        }

        else if (strcmp(cmd, "addfirst") == 0) {
            int k; scanf("%d", &k);
            addFirst(k);
        }

        else if (strcmp(cmd, "addafter") == 0) {
            int u, v; scanf("%d %d", &u, &v);
            addAfter(u, v);
        }

        else if (strcmp(cmd, "addbefore") == 0) {
            int u, v; scanf("%d %d", &u, &v);
            addBefore(u, v);
        }

        else if (strcmp(cmd, "remove") == 0) {
            int k; scanf("%d", &k);
            removeKey(k);
        }

        else if (strcmp(cmd, "reverse") == 0) {
            reverseList();
        }

        else if (strcmp(cmd, "output") == 0) {
            int o; scanf("%d", &o);
            if (o == 1) printForward();
            else printBackward();
        }
    }

    return 0;
}