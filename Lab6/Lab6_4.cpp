#include <stdio.h>
#define MAX 50

int x[MAX]; // Mảng lưu trạng thái (chọn hoặc không chọn) của từng phần tử
int a[] = {2, 5, 7, -2, -6, 8}; // Mảng số nguyên đầu vào
int n; // Số lượng phần tử trong mảng
int check = 0; // Đếm số lần tìm được hai tập con có tổng bằng nhau

// Hàm in ra kết quả khi tìm được 2 tập con
void Print() {
    int sum0 = 0, sum1 = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] == 1)
            sum1 += a[i];
        else
            sum0 += a[i];
    }

    // Nếu tổng 2 tập con bằng nhau
    if (sum0 == sum1) {
        check++;
        printf("\nTap con 1: ");
        for (int i = 0; i < n; i++) {
            if (x[i] == 1)
                printf("%d ", a[i]);
        }
        printf("\nTap con 2: ");
        for (int i = 0; i < n; i++) {
            if (x[i] == 0)
                printf("%d ", a[i]);
        }
        printf("\n");
    }
}

// Hàm quay lui để thử tất cả các cách phân chia
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n - 1)
            Print(); // Nếu đã xét hết các phần tử thì kiểm tra và in kết quả
        else
            Try(i + 1); // Tiếp tục xét phần tử tiếp theo
    }
}

// Hàm kiểm tra tổng của mảng có thể chia đều hay không
int isSplittable() {
    int totalSum = 0;
    for (int i = 0; i < n; i++)
        totalSum += a[i];
    return totalSum % 2 == 0; // Tổng có thể chia đều khi tổng là số chẵn
}

// Hàm main
int main() {
    n = sizeof(a) / sizeof(a[0]); // Tính số lượng phần tử trong mảng

    // Kiểm tra trước khi thực hiện
    if (!isSplittable()) {
        printf("Khong the chia mang thanh 2 tap con co tong bang nhau (tong le).\n");
        return 0;
    }

    printf("Cac cach chia mang thanh 2 tap con co tong bang nhau:\n");
    Try(0);

    if (check == 0)
        printf("\nKhong co cach chia nao phu hop.\n");
    else
        printf("\nTong cong co %d cach chia phu hop.\n", check);

    return 0;
}
