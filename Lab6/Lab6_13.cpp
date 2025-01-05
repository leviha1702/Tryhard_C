#include <stdio.h>

#define MAX 100

int w[MAX], v[MAX], L[MAX][MAX];
int N, W;

int main() {
    printf("Nhap so luong vat N: ");
    scanf("%d", &N);
    printf("Nhap trong luong toi da cua vali W: ");
    scanf("%d", &W);

    printf("Nhap trong luong va gia tri cua cac vat:\n");
    for (int i = 1; i <= N; i++) {
        printf("Vat %d - Trong luong: ", i);
        scanf("%d", &w[i]);
        printf("Vat %d - Gia tri: ", i);
        scanf("%d", &v[i]);
    }

    // Khoi tao mang L
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            L[i][j] = 0;
        }
    }

    // Quy hoach dong tinh toan gia tri lon nhat
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            if (j >= w[i]) {
                L[i][j] = (L[i - 1][j - w[i]] + v[i] > L[i - 1][j]) ? L[i - 1][j - w[i]] + v[i] : L[i - 1][j];
            } else {
                L[i][j] = L[i - 1][j];
            }
        }
    }

    printf("Gia tri lon nhat cua vali: %d\n", L[N][W]);

    // In cac vat duoc chon
    printf("Cac vat duoc chon vao vali:\n");
    int j = W;
    for (int i = N; i > 0; i--) {
        if (L[i][j] != L[i - 1][j]) {
            printf("Vat %d (Gia tri: %d, Trong luong: %d)\n", i, v[i], w[i]);
            j -= w[i];
        }
    }

    return 0;
}
