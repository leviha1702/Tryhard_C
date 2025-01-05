#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int n, M;
int weights[MAX];
int selected[MAX];

int compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a; // Sắp xếp giảm dần
}

int main() {
    FILE *f = fopen("can.inp", "r");
    FILE *g = fopen("can.out", "w");

    if (f == NULL || g == NULL) {
        printf("Khong the mo tep tin.\n");
        return 1;
    }

    fscanf(f, "%d %d", &n, &M);
    for (int i = 0; i < n; i++) {
        fscanf(f, "%d", &weights[i]);
    }

    qsort(weights, n, sizeof(int), compare);

    int sum = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (sum + weights[i] <= M) {
            sum += weights[i];
            selected[count++] = weights[i];
        }
        if (sum == M) break;
    }

    if (sum != M) {
        fprintf(g, "Khong chon duoc\n");
    } else {
        fprintf(g, "%d\n", count);
        for (int i = 0; i < count; i++) {
            fprintf(g, "%d ", selected[i]);
        }
        fprintf(g, "\n");
    }

    fclose(f);
    fclose(g);
    return 0;
}
