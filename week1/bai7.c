#include <stdio.h>
#include <string.h>

int main() {
    char P1[1005], P2[1005], T[10005];

    fgets(P1, sizeof(P1), stdin);
    fgets(P2, sizeof(P2), stdin);
    fgets(T, sizeof(T), stdin);

    P1[strcspn(P1, "\n")] = '\0';
    P2[strcspn(P2, "\n")] = '\0';
    T[strcspn(T, "\n")] = '\0';

    char ket_qua[50000] = "";
    int lenP1 = strlen(P1);

    for (int i = 0; i < strlen(T); ) {
        if (strncmp(&T[i], P1, lenP1) == 0) {
            strcat(ket_qua, P2);
            i += lenP1;
        } else {
            int lenR = strlen(ket_qua);
            ket_qua[lenR] = T[i];
            ket_qua[lenR+1] = '\0';
            i++;
        }
    }

    printf("%s\n", ket_qua);
    return 0;
}
