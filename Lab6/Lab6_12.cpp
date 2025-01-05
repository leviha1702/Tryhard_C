#include <stdio.h>

#define MAX 100

int A[MAX], L[MAX][MAX];
int N, S;

void printSubsequence() {
    if (L[N][S] == 0) {
        printf("Khong co day con co tong = %d\n", S);
        return;
    }

    printf("Day con co tong = %d: ", S);
    int s = S;
    for (int i = N; i > 0; i--) {
        if (L[i][s] && L[i - 1][s] == 0) {
            printf("%d ", A[i - 1]);
            s -= A[i - 1];
        }
    }
    printf("\n");
}

int main() {
    printf("Nhap so luong phan tu N: ");
    scanf("%d", &N);
    printf("Nhap tong S: ");
    scanf("%d", &S);
    printf("Nhap day so: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Khởi tạo mảng L
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= S; j++) {
            L[i][j] = 0;
        }
    }

    // Khởi tạo L[i][0] = 1
    for (int i = 0; i <= N; i++) {
        L[i][0] = 1;
    }

    // Quy hoạch động để tính toán L[i][j]
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= S; j++) {
            if (L[i - 1][j] == 1 || (j >= A[i - 1] && L[i - 1][j - A[i - 1]] == 1)) {
                L[i][j] = 1;
            }
        }
    }

    printSubsequence();

    return 0;
}
