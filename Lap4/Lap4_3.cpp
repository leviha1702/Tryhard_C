#include <stdio.h>
#include <stdlib.h>

#define MAX_N 30
#define INF 99999999

int n, S, t[MAX_N], best_count = INF;
int best_solution[MAX_N], current_solution[MAX_N];

// Hàm tính số tờ tiền tối thiểu cần thiết để trả số tiền còn lại
int min_toi_toi(int remaining, int k) {
    int max_t = 0;
    for (int i = k; i < n; i++) {
        if (t[i] > max_t) {
            max_t = t[i];
        }
    }
    return (remaining + max_t - 1) / max_t;  // Làm tròn lên số tờ cần thiết
}

// Hàm kiểm tra nhánh cận
void branch_and_bound(int k, int current_sum, int count) {
    if (current_sum > S) return; // Nếu số tiền vượt quá S thì không tiếp tục

    if (current_sum == S) {  // Nếu đã tìm ra một cách trả đúng
        if (count < best_count) {  // Nếu số tờ ít hơn cách hiện tại
            best_count = count;
            for (int i = 0; i < n; i++) {
                best_solution[i] = current_solution[i];
            }
        }
        return;
    }

    // Nếu không thể có được số tờ ít hơn, ta không mở rộng nhánh này
    if (count + min_toi_toi(S - current_sum, k) >= best_count) {
        return;
    }

    // Duyệt qua các nhánh (chọn hoặc không chọn tờ tiền t[k])
    if (k < n) {
        // Trường hợp không chọn tờ tiền t[k]
        current_solution[k] = 0;
        branch_and_bound(k + 1, current_sum, count);

        // Trường hợp chọn tờ tiền t[k]
        current_solution[k] = 1;
        branch_and_bound(k + 1, current_sum + t[k], count + 1);
    }
}
int main() {
    FILE *inp = fopen("ATM.inp", "r");
    FILE *out = fopen("ATM_out.out", "w");

    fscanf(inp, "%d %d", &n, &S);
    for (int i = 0; i < n; i++) {
        fscanf(inp, "%d", &t[i]);
    }

    branch_and_bound(0, 0, 0);

    if (best_count == INF) {
        fprintf(out, "-1\n");
    } else {
        for (int i = 0; i < n; i++) {
            fprintf(out, "%d ", best_solution[i]);
        }
        fprintf(out, "\n");
    }

    fclose(inp);
    fclose(out);
    return 0;
}