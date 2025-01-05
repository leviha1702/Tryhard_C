#include <stdio.h>
#define MAX 20

int n, M;              
int weights[MAX];      
int x[MAX];           
int count = 0;         

int calculateSum() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] == 1)
            sum += weights[i];
    }
    return sum;
}

void printSolution(FILE *g) {
    for (int i = 0; i < n; i++) {
        if (x[i] == 1)
            fprintf(g, "%d ", weights[i]);
    }
    fprintf(g, "\n");
}

void Try(int i, FILE *g) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n - 1) { 
            if (calculateSum() == M) {
                count++;
                printSolution(g); 
            }
        } else {
            Try(i + 1, g); 
        }
    }
}

int main() {
    FILE *f = fopen("cannang.inp", "r");
    FILE *g = fopen("cannang.out", "w");

    if (f == NULL || g == NULL) {
        printf("Khong the mo tep tin.\n");
        return 1;
    }

    fscanf(f, "%d %d", &n, &M);
    for (int i = 0; i < n; i++) {
        fscanf(f, "%d", &weights[i]);
    }

    Try(0, g);

    if (count == 0) {
        fprintf(g, "Khong chon duoc\n");
        printf("Khong co cach chon nao phu hop. Xem ket qua trong tep tin cannang.out.\n");
    } else {
        fprintf(g, "So cach chon: %d\n", count);
        printf("Da tim thay %d cach chon phu hop. Xem ket qua trong tep tin cannang.out.\n", count);
    }

    fclose(f);
    fclose(g);
    return 0;
}
