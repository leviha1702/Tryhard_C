#include <stdio.h>
#include <stdlib.h>

#define MAX 30

typedef struct {
    int start;
    int end;
    int profit;
} Job;

Job jobs[MAX];
int n;
int dp[MAX];

// Hàm so sánh theo thời gian kết thúc (dùng để sắp xếp các công việc)
int compare(const void* a, const void* b) {
    return ((Job*)a)->end - ((Job*)b)->end;
}

// Tìm công việc không chồng chéo gần nhất
int findNonConflictingJob(int index) {
    for (int i = index - 1; i >= 0; i--) {
        if (jobs[i].end <= jobs[index].start) {
            return i;
        }
    }
    return -1;
}

// Tìm tổng số tiền thu lớn nhất
int findMaxProfit() {
    // Sắp xếp các công việc theo thời gian kết thúc
    qsort(jobs, n, sizeof(Job), compare);

    dp[0] = jobs[0].profit;

    for (int i = 1; i < n; i++) {
        int includeProfit = jobs[i].profit;
        int lastNonConflicting = findNonConflictingJob(i);

        if (lastNonConflicting != -1) {
            includeProfit += dp[lastNonConflicting];
        }

        dp[i] = (includeProfit > dp[i - 1]) ? includeProfit : dp[i - 1];
    }

    return dp[n - 1];
}

int main() {
    // Đọc dữ liệu từ file
    FILE* input = fopen("Lab5_6.inp", "r");
    if (input == NULL) {
        printf("khong the mo file!\n");
        return 1;
    }

    fscanf(input, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(input, "%d", &jobs[i].start);
    }
    for (int i = 0; i < n; i++) {
        fscanf(input, "%d", &jobs[i].end);
    }
    for (int i = 0; i < n; i++) {
        fscanf(input, "%d", &jobs[i].profit);
    }
    fclose(input);

    int maxProfit = findMaxProfit();

    // Ghi kết quả vào file
    FILE* output = fopen("Lab5_6.out", "w");
    if (output == NULL) {
        printf("khong the mo file ra!\n");
        return 1;
    }

    fprintf(output, "%d\n", maxProfit);
    fclose(output);

    printf("tong so tien lon nhat là: %d\n", maxProfit);

    return 0;
}
