#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* list1 = NULL;
Node* list2 = NULL;

// tạo node
Node* makeNode(int v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->val = v;
    p->next = NULL;
    return p;
}

// chèn giữ thứ tự tăng dần
void insert(Node** head, int x) {
    Node* p = makeNode(x);

    // chèn đầu
    if (*head == NULL || x <= (*head)->val) {
        p->next = *head;
        *head = p;
        return;
    }

    Node* cur = *head;
    while (cur->next && cur->next->val < x) {
        cur = cur->next;
    }

    p->next = cur->next;
    cur->next = p;
}

// xóa phần tử thứ k
void removeK(Node** head, int k) {
    if (*head == NULL) return;

    Node* cur = *head;

    if (k == 0) {
        *head = cur->next;
        free(cur);
        return;
    }

    Node* prev = NULL;
    int i = 0;

    while (cur && i < k) {
        prev = cur;
        cur = cur->next;
        i++;
    }

    if (cur == NULL) return;

    prev->next = cur->next;
    free(cur);
}

// in danh sách
void printList(Node* head) {
    Node* cur = head;
    while (cur) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

// merge 2 list
Node* merge(Node* l1, Node* l2) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = makeNode(l1->val);
            l1 = l1->next;
        } else {
            tail->next = makeNode(l2->val);
            l2 = l2->next;
        }
        tail = tail->next;
    }

    while (l1) {
        tail->next = makeNode(l1->val);
        l1 = l1->next;
        tail = tail->next;
    }

    while (l2) {
        tail->next = makeNode(l2->val);
        l2 = l2->next;
        tail = tail->next;
    }

    return dummy.next;
}

int main() {
    int x;
    
    // nhập list 1
    while (scanf("%d", &x) && x != -1) {
        insert(&list1, x);
    }

    // nhập list 2
    while (scanf("%d", &x) && x != -1) {
        insert(&list2, x);
    }

    char cmd[20];

    while (scanf("%s", cmd) != EOF) {

        if (strcmp(cmd, "insert") == 0) {
            int id, val;
            scanf("%d %d", &id, &val);

            if (id == 1) insert(&list1, val);
            else insert(&list2, val);
        }

        else if (strcmp(cmd, "remove") == 0) {
            int id, k;
            scanf("%d %d", &id, &k);

            if (id == 1) removeK(&list1, k);
            else removeK(&list2, k);
        }

        else if (strcmp(cmd, "print") == 0) {
            int id;
            scanf("%d", &id);

            if (id == 1) printList(list1);
            else printList(list2);
        }

        else if (strcmp(cmd, "merge") == 0) {
            Node* res = merge(list1, list2);
            printList(res);
        }
    }

    return 0;
}