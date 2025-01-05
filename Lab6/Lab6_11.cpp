#include <stdio.h>

#define MAX 100

int A[MAX], L[MAX], P[MAX];
int N;

void printLongestIncreasingSubsequence() {
    int maxLength = 0, maxIndex = -1;
    for (int i = 0; i < N; i++) {
        if (L[i] > maxLength) {
            maxLength = L[i];
            maxIndex = i;
        }
    }

    int result[maxLength];
    int index = maxLength - 1;
    while (maxIndex != -1) {
        result[index--] = A[maxIndex];
        maxIndex = P[maxIndex];
    }

    printf("Day con tang don dieu dai nhat: ");
    for (int i = 0; i < maxLength; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main() {
    printf("Nhap so luong phan tu: ");
    scanf("%d", &N);
    printf("Nhap day so: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < N; i++) {
        L[i] = 1;
        P[i] = -1;
    }

    printf("Tinh toan day con tang don dieu...\n");
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j] && L[i] < L[j] + 1) {
                L[i] = L[j] + 1;
                P[i] = j;
            }
        }
    }

    printLongestIncreasingSubsequence();
    return 0;
}
