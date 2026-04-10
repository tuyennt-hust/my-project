#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node {
    int coef;
    int exp;
    struct Node* next;
} Node;

Node* polys[10001];

// tạo node
Node* makeNode(int c, int e) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->coef = c;
    p->exp = e;
    p->next = NULL;
    return p;
}

// xóa đa thức
void destroyPoly(int id) {
    Node* cur = polys[id];
    while (cur) {
        Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    polys[id] = NULL;
}

// thêm 1 term
void addTerm(int id, int coef, int exp) {
    if (coef == 0) return;

    if (polys[id] == NULL) {
        polys[id] = makeNode(coef, exp);
        return;
    }

    Node* head = polys[id];

    // chèn đầu
    if (exp > head->exp) {
        Node* p = makeNode(coef, exp);
        p->next = head;
        polys[id] = p;
        return;
    }

    Node* prev = NULL;
    Node* cur = head;

    while (cur && cur->exp > exp) {
        prev = cur;
        cur = cur->next;
    }

    // trùng exp
    if (cur && cur->exp == exp) {
        cur->coef += coef;
        if (cur->coef == 0) {
            if (prev == NULL)
                polys[id] = cur->next;
            else
                prev->next = cur->next;
            free(cur);
        }
        return;
    }

    // chèn giữa hoặc cuối
    Node* p = makeNode(coef, exp);
    if (prev == NULL) {
        p->next = polys[id];
        polys[id] = p;
    } else {
        p->next = cur;
        prev->next = p;
    }
}

// in đa thức
void printPoly(int id) {
    Node* cur = polys[id];
    while (cur) {
        printf("%d %d ", cur->coef, cur->exp);
        cur = cur->next;
    }
    printf("\n");
}

// tính giá trị đa thức
void evaluatePoly(int id, int x) {
    if (polys[id] == NULL) {
        printf("0\n");
        return;
    }

    long long res = 0;
    Node* cur = polys[id];

    while (cur) {
        res += cur->coef * pow(x, cur->exp);
        cur = cur->next;
    }

    printf("%lld\n", res);
}

// cộng 2 đa thức
void addPoly(int id1, int id2, int id3) {
    destroyPoly(id3);

    Node* p1 = polys[id1];
    Node* p2 = polys[id2];

    while (p1) {
        addTerm(id3, p1->coef, p1->exp);
        p1 = p1->next;
    }

    while (p2) {
        addTerm(id3, p2->coef, p2->exp);
        p2 = p2->next;
    }
}

int main() {
    char cmd[50];

    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "*") == 0) break;

        if (strcmp(cmd, "Create") == 0) {
            int id;
            scanf("%d", &id);
            if (polys[id] == NULL)
                polys[id] = NULL;
        }

        else if (strcmp(cmd, "AddTerm") == 0) {
            int id, c, e;
            scanf("%d %d %d", &id, &c, &e);
            addTerm(id, c, e);
        }

        else if (strcmp(cmd, "PrintPoly") == 0) {
            int id;
            scanf("%d", &id);
            if (polys[id]) printPoly(id);
            else printf("\n");
        }

        else if (strcmp(cmd, "EvaluatePoly") == 0) {
            int id, x;
            scanf("%d %d", &id, &x);
            evaluatePoly(id, x);
        }

        else if (strcmp(cmd, "AddPoly") == 0) {
            int id1, id2, id3;
            scanf("%d %d %d", &id1, &id2, &id3);
            addPoly(id1, id2, id3);
        }

        else if (strcmp(cmd, "Destroy") == 0) {
            int id;
            scanf("%d", &id);
            destroyPoly(id);
        }
    }

    return 0;
}