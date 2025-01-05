#include <stdio.h>

#define MAX 20 

int x[MAX];    
int n, k;      
int count = 0; 


int isValid() {
    int consecutiveMiss = 0; 
    int hits = 0;            

    for (int i = 0; i < n; i++) {
        if (x[i] == 1) {
            hits++;
            consecutiveMiss = 0; 
        } else {
            consecutiveMiss++;
            if (consecutiveMiss > 1) 
                return 0;
        }
    }

    return hits >= k; 
}


void printSolution(FILE *f) {
    for (int i = 0; i < n; i++) {
        if (x[i] == 1)
            fprintf(f, "x");
        else
            fprintf(f, "_");
    }
    fprintf(f, "\n");
}

void Try(int i, FILE *f) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n - 1) { 
            if (isValid()) {
                count++;
                printSolution(f);
            }
        } else {
            Try(i + 1, f);
        }
    }
}


int main() {
    FILE *f = fopen("ketqua.txt", "w");
    if (f == NULL) {
        printf("Khong the mo tep tin ketqua.txt de ghi.\n");
        return 1;
    }

    printf("Nhap so mui ten (n): ");
    scanf("%d", &n);
    printf("Nhap so lan trung toi thieu (k): ");
    scanf("%d", &k);

    if (n < 2 || n > 20 || k < 2 || k > n) {
        fprintf(f, "-1\n");
        fclose(f);
        printf("Du lieu khong hop le. Xem ket qua trong tep tin ketqua.txt.\n");
        return 0;
    }

    Try(0, f);

    if (count == 0) {
        fprintf(f, "-1\n");
        printf("Khong co cach nao de chien thang. Xem ket qua trong tep tin ketqua.txt.\n");
    } else {
        fprintf(f, "So cach chien thang: %d\n", count);
        printf("Da tim thay %d cach chien thang. Xem ket qua trong tep tin ketqua.txt.\n", count);
    }

    fclose(f);
    return 0;
}
