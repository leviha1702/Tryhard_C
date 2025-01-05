#include <stdio.h>
#include <string.h>
#define MAX 50

int n;
int values[MAX];
char result[MAX];
int totalSum = 0;
int count = 0;

int isBalanced() {
    int sumA = 0;
    for (int i = 0; i < n; i++) {
        if (result[i] == 'A') {
            sumA += values[i];
        }
    }
    return (sumA == totalSum / 2);
}

void printSolution(FILE *g) {
    for (int i = 0; i < n; i++) {
        fprintf(g, "%c", result[i]);
    }
    fprintf(g, "\n");
}

void Try(int i, FILE *g) {
    for (char option = 'A'; option <= 'B'; option++) {
        result[i] = option;
        if (i == n - 1) {
            if (isBalanced()) {
                count++;
                printSolution(g);
            }
        } else {
            Try(i + 1, g);
        }
    }
}

int main() {
    FILE *f = fopen("chia_tien.inp", "r");
    FILE *g = fopen("chia_tien.out", "w");

    if (f == NULL || g == NULL) {
        printf("Khong the mo tep tin.\n");
        return 1;
    }

    fscanf(f, "%d", &n);
    totalSum = 0;
    for (int i = 0; i < n; i++) {
        fscanf(f, "%d", &values[i]);
        totalSum += values[i];
    }

    if (totalSum % 2 != 0) {
        fprintf(g, "Khong chia duoc\n");
        fclose(f);
        fclose(g);
        return 0;
    }

    Try(0, g);

    if (count == 0) {
        fprintf(g, "Khong chia duoc\n");
    } else {
        fprintf(g, "So cach chia: %d\n", count);
    }

    fclose(f);
    fclose(g);
    return 0;
}
