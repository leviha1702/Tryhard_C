#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int n, P;               
int a[MAX];             
char result[MAX];      
int count = 0;        

void Try(int i, int sum, FILE *g) {
    if (i == n) {
        if (sum == P) { 
            count++;
            for (int j = 0; j < n - 1; j++) {
                fprintf(g, "%d%c", a[j], result[j]);
            }
            fprintf(g, "%d\n", a[n - 1]);
        }
        return;
    }

    result[i] = '+';
    Try(i + 1, sum + a[i], g);

    result[i] = '-';
    Try(i + 1, sum - a[i], g);
}

int main() {
    FILE *f = fopen("dau.inp", "r");
    FILE *g = fopen("dau.out", "w");

    if (f == NULL || g == NULL) {
        printf("Khong the mo tep tin.\n");
        return 1;
    }

    fscanf(f, "%d %d", &n, &P);
    for (int i = 0; i < n; i++) {
        fscanf(f, "%d", &a[i]);
    }

    Try(1, a[0], g);

    if (count == 0) {
        fprintf(g, "0\n");
    }

    fclose(f);
    fclose(g);
    return 0;
}
