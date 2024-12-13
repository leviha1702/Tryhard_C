#include <stdio.h>
#include <stdlib.h>

#define MAX 30

int t[MAX]; // Mảng lưu mệnh giá tiền
int n, S;   // Số mệnh giá và số tiền cần trả

// Hàm đọc dữ liệu từ file
void readFile() {
    FILE *f = fopen("ATM.txt", "r");
    if (f == NULL) {
        printf("khong the mo file\n");
        return;
    }
    fscanf(f, "%d %d", &n, &S); // Đọc số lượng mệnh giá và số tiền cần trả
    for (int i = 0; i < n; i++) {
        fscanf(f, "%d", &t[i]); // Đọc mệnh giá tiền
    }
    fclose(f);
}

// Hàm sắp xếp mảng mệnh giá theo thứ tự giảm dần
void sortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
// Hàm tìm cách trả tiền ít tờ nhất
void findSolution() {
    int remaining = S;    // Số tiền còn lại cần trả
    int count[MAX] = {0}; // Mảng lưu số lượng tờ tiền của mỗi mệnh giá

    // Duyệt qua từng mệnh giá (theo thứ tự giảm dần)
    for (int i = 0; i < n; i++) {
        if (remaining >= t[i]) {
            count[i] = remaining / t[i]; // Số tờ tiền mệnh giá t[i] cần dùng
            remaining -=t[i];          // Cập nhật số tiền còn lại
        }
    }

    // Ghi kết quả vào file
    FILE *f = fopen("atm_out.txt", "w");
    if (f == NULL) {
        printf("khong the mo file\n");
        return;
    }

    if (remaining == 0) {
        // Nếu trả được đúng số tiền S
        for (int i = 0; i < n; i++) {
            if (count[i] > 0) {
                fprintf(f, "%d\t", t[i]); // Ghi mệnh giá và số lượng tờ
            }
        }
        fprintf(f, "\nTong so to la: %d\n", S); // Ghi tổng số tờ
    } else {
        // Nếu không trả được số tiền S
        fprintf(f, "-1\n");
    }
    fclose(f);
}

int main() {
    readFile();           // Đọc dữ liệu từ file
    sortDescending(t, n);          // Sắp xếp mệnh giá giảm dần
    findSolution();   // Tìm cách trả tiền và ghi ra file
    printf("ket qua da duoc ghi vao file atm_out.txt\n");
    return 0;
}
